#include "PowerUpVelocidadExtra.h"
#include "../ShooterNaves2025Pawn.h"

APowerUpVelocidadExtra::APowerUpVelocidadExtra()
{
	Cantidad = 1.5f;
	Duracion = 8.0f;
}

void APowerUpVelocidadExtra::AplicarEfecto(AShooterNaves2025Pawn* Jugador)
{
	if (Jugador)
	{
		Jugador->ActivarVelocidadExtra(Cantidad, Duracion);
	}
}