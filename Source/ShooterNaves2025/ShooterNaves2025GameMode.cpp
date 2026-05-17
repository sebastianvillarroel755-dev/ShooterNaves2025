// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooterNaves2025GameMode.h"
#include "ShooterNaves2025Pawn.h"

AShooterNaves2025GameMode::AShooterNaves2025GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AShooterNaves2025Pawn::StaticClass();
}

