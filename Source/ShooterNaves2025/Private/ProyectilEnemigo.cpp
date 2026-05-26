#include "ProyectilEnemigo.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "../ShooterNaves2025Pawn.h"

AProyectilEnemigo::AProyectilEnemigo()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshProyectil = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshProyectil"));
	RootComponent = MeshProyectil;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshEsfera(TEXT("/Engine/BasicShapes/Sphere.Sphere"));

	if (MeshEsfera.Succeeded())
	{
		MeshProyectil->SetStaticMesh(MeshEsfera.Object);
	}

	MeshProyectil->SetWorldScale3D(FVector(0.25f, 0.25f, 0.25f));
	MeshProyectil->SetGenerateOverlapEvents(true);
	MeshProyectil->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MeshProyectil->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshProyectil->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	MeshProyectil->OnComponentBeginOverlap.AddDynamic(this, &AProyectilEnemigo::OnOverlap);

	MovimientoProyectil = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovimientoProyectil"));
	MovimientoProyectil->UpdatedComponent = MeshProyectil;
	MovimientoProyectil->InitialSpeed = 1200.0f;
	MovimientoProyectil->MaxSpeed = 1200.0f;
	MovimientoProyectil->ProjectileGravityScale = 0.0f;
	MovimientoProyectil->bRotationFollowsVelocity = true;

	InitialLifeSpan = 4.0f;
}

void AProyectilEnemigo::OnOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
)
{
	AShooterNaves2025Pawn* Jugador = Cast<AShooterNaves2025Pawn>(OtherActor);

	if (Jugador)
	{
		UE_LOG(LogTemp, Warning, TEXT("Proyectil enemigo hizo danio por overlap: %f"), Danio);
		Jugador->RecibirDanio(Danio);
		Destroy();
	}
}