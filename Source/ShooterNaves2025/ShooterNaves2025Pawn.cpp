// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooterNaves2025Pawn.h"
#include "ShooterNaves2025Projectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "TimerManager.h"

const FName AShooterNaves2025Pawn::MoveForwardBinding("MoveForward");
const FName AShooterNaves2025Pawn::MoveRightBinding("MoveRight");
const FName AShooterNaves2025Pawn::FireForwardBinding("FireForward");
const FName AShooterNaves2025Pawn::FireRightBinding("FireRight");

AShooterNaves2025Pawn::AShooterNaves2025Pawn()
{	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	
	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	// Movement
	MoveSpeed = 1000.0f;

	VelocidadBase = MoveSpeed;


	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;
}

void AShooterNaves2025Pawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);
}

void AShooterNaves2025Pawn::Tick(float DeltaSeconds)
{
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		
		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}
	
	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	// Try and fire a shot
	FireShot(FireDirection);
}

void AShooterNaves2025Pawn::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AShooterNaves2025Projectile>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AShooterNaves2025Pawn::ShotTimerExpired, FireRate);

			// try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}

			bCanFire = false;
		}
	}
}

void AShooterNaves2025Pawn::ShotTimerExpired()
{
	bCanFire = true;
}

void AShooterNaves2025Pawn::RecibirDanio(float CantidadDanio)
{
	if (bEstaMuerto)
	{
		return;
	}

	Vida -= CantidadDanio;

	if (Vida <= 0.0f)
	{
		Morir();
	}
}

void AShooterNaves2025Pawn::Morir()
{
	bEstaMuerto = true;

	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false);
}

void AShooterNaves2025Pawn::Curar(float Cantidad)
{
	Vida += Cantidad;

	if (Vida > VidaMaxima)
	{
		Vida = VidaMaxima;
	}

	UE_LOG(LogTemp, Warning, TEXT("Jugador curado. Vida actual: %f"), Vida);
}

void AShooterNaves2025Pawn::ActivarDanioExtra(float Multiplicador, float Duracion)
{
	MultiplicadorDanio = Multiplicador;

	GetWorldTimerManager().ClearTimer(TimerDanioExtra);
	GetWorldTimerManager().SetTimer(
		TimerDanioExtra,
		this,
		&AShooterNaves2025Pawn::QuitarDanioExtra,
		Duracion,
		false
	);

	UE_LOG(LogTemp, Warning, TEXT("PowerUp de danio activado"));
}

void AShooterNaves2025Pawn::QuitarDanioExtra()
{
	MultiplicadorDanio = 1.0f;

	UE_LOG(LogTemp, Warning, TEXT("PowerUp de danio terminado"));
}

void AShooterNaves2025Pawn::ActivarVelocidadExtra(float Multiplicador, float Duracion)
{
	MoveSpeed = VelocidadBase * Multiplicador;

	GetWorldTimerManager().ClearTimer(TimerVelocidadExtra);
	GetWorldTimerManager().SetTimer(
		TimerVelocidadExtra,
		this,
		&AShooterNaves2025Pawn::QuitarVelocidadExtra,
		Duracion,
		false
	);

	UE_LOG(LogTemp, Warning, TEXT("PowerUp de velocidad activado"));
}

void AShooterNaves2025Pawn::QuitarVelocidadExtra()
{
	MoveSpeed = VelocidadBase;

	UE_LOG(LogTemp, Warning, TEXT("PowerUp de velocidad terminado"));
}
