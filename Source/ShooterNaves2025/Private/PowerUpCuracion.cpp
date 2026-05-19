#include "PowerUpCuracion.h"
#include "../ShooterNaves2025Pawn.h"

APowerUpCuracion::APowerUpCuracion()
{
	Cantidad = 30.0f;
	Duracion = 0.0f;
}

void APowerUpCuracion::AplicarEfecto(AShooterNaves2025Pawn* Jugador)
{
	if (Jugador)
	{
		Jugador->Curar(Cantidad);
	}
}