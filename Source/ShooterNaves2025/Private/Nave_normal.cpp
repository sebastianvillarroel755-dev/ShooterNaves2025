#include "Nave_Normal.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Nave normal: equilibrada
ANave_Normal::ANave_Normal()
{
    // Stats
    Vida = 100.0f;
    Velocidad = 300.0f;
    DanioContacto = 15.0f;

    // Cambiar mesh del padre
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CuboMesh(
        TEXT("/Engine/BasicShapes/Cube.Cube"));

    if (CuboMesh.Succeeded())
    {
        MeshNave->SetStaticMesh(CuboMesh.Object);
    }

    MeshNave->SetWorldScale3D(FVector(1.5f, 1.5f, 1.5f));
}