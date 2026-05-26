#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProyectilEnemigo.generated.h"

UCLASS()
class SHOOTERNAVES2025_API AProyectilEnemigo : public AActor
{
	GENERATED_BODY()

public:
	AProyectilEnemigo();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	class UStaticMeshComponent* MeshProyectil;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movimiento")
	class UProjectileMovementComponent* MovimientoProyectil;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float Danio = 20.0f;

	UFUNCTION()
	void OnOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);
};