#include "PowerUpDanioExtra.h"
#include "../ShooterNaves2025Pawn.h"

APowerUpDanioExtra::APowerUpDanioExtra()
{
	Cantidad = 2.0f;
	Duracion = 8.0f;
}

void APowerUpDanioExtra::AplicarEfecto(AShooterNaves2025Pawn* Jugador)
{
	if (Jugador)
	{
		Jugador->ActivarDanioExtra(Cantidad, Duracion);
	}
}