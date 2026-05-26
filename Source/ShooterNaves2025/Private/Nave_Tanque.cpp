#include "Nave_Tanque.h"
#include "ProyectilEnemigo.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"

ANave_Tanque::ANave_Tanque()
{
	Vida = 500.0f;
	Velocidad = 120.0f;
	DanioContacto = 45.0f;
	DistanciaMinima = 130.0f;
	MultiplicadorDanioRecibido = 0.75f;
}

void ANave_Tanque::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(
		TimerDisparo,
		this,
		&ANave_Tanque::Disparar,
		TiempoEntreDisparos,
		true
	);
}

void ANave_Tanque::Disparar()
{
	if (!Jugador || bEstaMuerta)
	{
		return;
	}

	FVector Direccion = Jugador->GetActorLocation() - GetActorLocation();
	Direccion.Z = 0.0f;

	if (Direccion.SizeSquared() <= 0.0f)
	{
		return;
	}

	FRotator RotacionDisparo = Direccion.Rotation();
	FVector SpawnLocation = GetActorLocation() + RotacionDisparo.RotateVector(FVector(140.0f, 0.0f, 0.0f));

	AProyectilEnemigo* Bala = GetWorld()->SpawnActor<AProyectilEnemigo>(
		AProyectilEnemigo::StaticClass(),
		SpawnLocation,
		RotacionDisparo
	);

	if (Bala)
	{
		Bala->Danio = 45.0f;
		Bala->MovimientoProyectil->InitialSpeed = 900.0f;
		Bala->MovimientoProyectil->MaxSpeed = 900.0f;
		Bala->MeshProyectil->SetWorldScale3D(FVector(0.45f, 0.45f, 0.45f));
	}
}