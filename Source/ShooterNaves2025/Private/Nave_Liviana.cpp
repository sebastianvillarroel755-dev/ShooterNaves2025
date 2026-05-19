#include "Nave_Liviana.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

ANave_Liviana::ANave_Liviana()
{
	// Stats
	Vida = 40.0f;
	Velocidad = 450.0f;
	DanioContacto = 10.0f;
	DistanciaMinima = 80.0f;

	// Esfera
	static ConstructorHelpers::FObjectFinder<UStaticMesh> EsferaMesh(
		TEXT("/Engine/BasicShapes/Sphere.Sphere"));

	if (EsferaMesh.Succeeded())
	{
		MeshNave->SetStaticMesh(EsferaMesh.Object);
	}

	// Escala pequeña
	MeshNave->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
}