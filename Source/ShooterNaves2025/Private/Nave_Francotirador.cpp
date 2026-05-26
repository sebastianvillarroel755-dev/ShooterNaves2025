#include "Nave_Francotirador.h"
#include "ProyectilEnemigo.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "GameFramework/ProjectileMovementComponent.h" // Agregamos esto para el proyectil
#include "GameFramework/Pawn.h" // Usamos la clase base genérica en vez de la que no existe

ANave_Francotirador::ANave_Francotirador()
{
	Vida = 80.0f;
	Velocidad = 250.0f;
	DanioContacto = 10.0f;
	DistanciaMinima = 80.0f;
	bPerseguirJugador = false;
}

void ANave_Francotirador::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(
		TimerDisparo,
		this,
		&ANave_Francotirador::Disparar,
		TiempoEntreDisparos,
		true
	);
}

void ANave_Francotirador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MantenerDistancia(DeltaTime);
}

void ANave_Francotirador::MantenerDistancia(float DeltaTime)
{
	if (!Jugador || bEstaMuerta)
	{
		return;
	}

	FVector DireccionAJugador = Jugador->GetActorLocation() - GetActorLocation();
	DireccionAJugador.Z = 0.0f;

	float Distancia = DireccionAJugador.Size();

	if (Distancia <= 1.0f)
	{
		return;
	}

	FVector Direccion = DireccionAJugador.GetSafeNormal();
	FVector Movimiento = FVector::ZeroVector;

	if (Distancia < DistanciaEscape)
	{
		Movimiento = -Direccion * Velocidad * DeltaTime;
	}
	else if (Distancia > DistanciaIdeal)
	{
		Movimiento = Direccion * Velocidad * DeltaTime;
	}

	FVector NuevaUbicacion = GetActorLocation() + Movimiento;
	NuevaUbicacion.Z = Jugador->GetActorLocation().Z;
	SetActorLocation(NuevaUbicacion);

	SetActorRotation(Direccion.Rotation());
}

void ANave_Francotirador::Disparar()
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
	FVector SpawnLocation = GetActorLocation() + RotacionDisparo.RotateVector(FVector(120.0f, 0.0f, 0.0f));

	AProyectilEnemigo* Bala = GetWorld()->SpawnActor<AProyectilEnemigo>(
		AProyectilEnemigo::StaticClass(),
		SpawnLocation,
		RotacionDisparo
	);

	if (Bala && Bala->MovimientoProyectil)
	{
		Bala->Danio = 35.0f;
		Bala->MovimientoProyectil->InitialSpeed = 1800.0f;
		Bala->MovimientoProyectil->MaxSpeed = 1800.0f;
	}
}