#pragma once

#include "CoreMinimal.h"
#include "Nave_Padre.h"
#include "Nave_Francotirador.generated.h"

UCLASS()
class SHOOTERNAVES2025_API ANave_Francotirador : public ANave_Padre
{
	GENERATED_BODY()

public:
	ANave_Francotirador();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle TimerDisparo;

	UPROPERTY(EditAnywhere, Category = "Ataque")
	float DistanciaIdeal = 700.0f;

	UPROPERTY(EditAnywhere, Category = "Ataque")
	float DistanciaEscape = 450.0f;

	UPROPERTY(EditAnywhere, Category = "Ataque")
	float TiempoEntreDisparos = 2.0f;

	void Disparar();
	void MantenerDistancia(float DeltaTime);
};