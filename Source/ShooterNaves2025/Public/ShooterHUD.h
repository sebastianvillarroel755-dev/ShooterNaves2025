#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ShooterHUD.generated.h"

UCLASS()
class SHOOTERNAVES2025_API AShooterHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void DrawHUD() override;
};