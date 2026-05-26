#include "ShooterNaves2025GameMode.h"
#include "ShooterNaves2025Pawn.h"
#include "Nave_Liviana.h"
#include "Nave_Normal.h"
#include "Nave_Pesada.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "MiniBoss.h"
#include "ShooterHUD.h"
#include "BossFinal.h"

#include "Nave_Kamikaze.h"
#include "Nave_Francotirador.h"
#include "Nave_Tanque.h"

AShooterNaves2025GameMode::AShooterNaves2025GameMode()
{
    DefaultPawnClass = AShooterNaves2025Pawn::StaticClass();
    HUDClass = AShooterHUD::StaticClass();

    NivelActual = 1;
    EnemigosRestantes = 0;
    MetaEnemigos = 0;
    VidasJugador = 3;
    Puntuacion = 0;
}

void AShooterNaves2025GameMode::BeginPlay()
{
    Super::BeginPlay();
    bJugando = true;
    IniciarNivel();
}

// Inicia el nivel actual
// Calcula la meta y arranca el spawn de enemigos
void AShooterNaves2025GameMode::IniciarNivel()
{

    bFase1Completada = false;

    if (NivelActual <= 6)
    {
        bGoodEnding = false;
        bGameOver = false;
    }

    MetaEnemigos = CalcularMetaEnemigos(NivelActual);
    EnemigosRestantes = MetaEnemigos;
    EnemigosGenerados = 0;
    EnemigosMuertosNivelActual = 0;
    EnemigosGeneradosNivel6 = 0;

    MiniBossActual = nullptr;
    bMiniBossSpawned = false;
    bMiniBossDebilitado = false;
    bMiniBossDerrotado = false;

    bBossFinalSpawned = false;
    bBossFinalDerrotado = false;
    BossFinalActual = nullptr;

    TextoLoreActual = ObtenerTextoLorePorNivel(NivelActual);

    UE_LOG(LogTemp, Warning,
        TEXT("=== NIVEL %d INICIADO === Meta: %d enemigos"),
        NivelActual, MetaEnemigos);

    float Intervalo = CalcularIntervaloSpawn(NivelActual);

    GetWorldTimerManager().SetTimer(
        TimerSpawn,
        this,
        &AShooterNaves2025GameMode::SpawnOleada,
        Intervalo,
        true);

    MostrarMensajeTemporal(TextoLoreActual, 4.0f);
    MostrarMensajeTemporal(TEXT("MINIBOSS APARECIO"), 3.0f);
    MostrarMensajeTemporal(TEXT("MINIBOSS DEBILITADO"), 3.0f);
    MostrarMensajeTemporal(TEXT("GOOD ENDING - La humanidad resistio"), 10.0f);
    MostrarMensajeTemporal(TEXT("BAD ENDING - Has perdido la defensa"), 10.0f);
    MostrarMensajeTemporal(TEXT("FASE 1 COMPLETADA"), 10.0f);
}

// Spawna enemigos segun el nivel actual
// Nivel 1: solo livianas
// Nivel 2: livianas + normales
// Nivel 3: todas + pesadas
void AShooterNaves2025GameMode::SpawnOleada()
{
    UWorld* World = GetWorld();
    if (!World || !bJugando) return;

    if (EnemigosGenerados >= MetaEnemigos)
    {
        GetWorldTimerManager().ClearTimer(TimerSpawn);
        return;
    }

    // Obtener la altura del jugador para spawnar a la misma Z
    float AlturaJugador = 200.0f; // valor por defecto
    APawn* Jugador = UGameplayStatics::GetPlayerPawn(World, 0);
    if (Jugador)
    {
        AlturaJugador = Jugador->GetActorLocation().Z;
    }

    // Spawnear en los bordes del mapa a la misma altura que el jugador
    FVector SpawnPos = FVector(
        FMath::FRandRange(-800.f, 800.f),
        FMath::FRandRange(-800.f, 800.f),
        AlturaJugador);

    AActor* NuevoEnemigo = nullptr;

    // Segun el nivel spawnear diferentes tipos
    if (NivelActual == 1)
    {
        NuevoEnemigo = World->SpawnActor<ANave_Normal>(
            ANave_Normal::StaticClass(),
            SpawnPos,
            FRotator::ZeroRotator);
    }
    else if (NivelActual == 2)
    {
        // Nivel 2: livianas y normales al azar
        if (FMath::RandBool())
            NuevoEnemigo = World->SpawnActor<ANave_Liviana>(
                ANave_Liviana::StaticClass(),
                SpawnPos, FRotator::ZeroRotator);
        else
            NuevoEnemigo = World->SpawnActor<ANave_Normal>(
                ANave_Normal::StaticClass(),
                SpawnPos, FRotator::ZeroRotator);
    }
    else if (NivelActual == 3)
    {
        // Nivel 3: los 3 tipos al azar
        int32 Tipo = FMath::RandRange(0, 2);

        if (Tipo == 0)
            NuevoEnemigo = World->SpawnActor<ANave_Liviana>(
                ANave_Liviana::StaticClass(),
                SpawnPos, FRotator::ZeroRotator);

        else if (Tipo == 1)
            NuevoEnemigo = World->SpawnActor<ANave_Normal>(
                ANave_Normal::StaticClass(),
                SpawnPos, FRotator::ZeroRotator);

        else
            NuevoEnemigo = World->SpawnActor<ANave_Pesada>(
                ANave_Pesada::StaticClass(),
                SpawnPos, FRotator::ZeroRotator);

        bFase1Completada = true;
        MostrarMensajeTemporal(TEXT("FASE 1 COMPLETADA"), 5.0f);
    }

    // Guardar en el contenedor
    if (NuevoEnemigo)
    {
        EnemigosActivos.Add(NuevoEnemigo);
        EnemigosGenerados++;

        UE_LOG(LogTemp, Warning,
            TEXT("Enemigo spawneado. Generados: %d / %d"),
            EnemigosGenerados, MetaEnemigos);
    }

    else if (NivelActual == 4)
    {
        int32 Tipo = FMath::RandRange(0, 2);

        if (Tipo == 0)
            NuevoEnemigo = World->SpawnActor<ANave_Kamikaze>(ANave_Kamikaze::StaticClass(), SpawnPos, FRotator::ZeroRotator);
        else if (Tipo == 1)
            NuevoEnemigo = World->SpawnActor<ANave_Francotirador>(ANave_Francotirador::StaticClass(), SpawnPos, FRotator::ZeroRotator);
        else
            NuevoEnemigo = World->SpawnActor<ANave_Normal>(ANave_Normal::StaticClass(), SpawnPos, FRotator::ZeroRotator);
    }

    else if (NivelActual == 5)
    {
        int32 Tipo = FMath::RandRange(0, 3);

        if (Tipo == 0)
            NuevoEnemigo = World->SpawnActor<ANave_Kamikaze>(ANave_Kamikaze::StaticClass(), SpawnPos, FRotator::ZeroRotator);
        else if (Tipo == 1)
            NuevoEnemigo = World->SpawnActor<ANave_Francotirador>(ANave_Francotirador::StaticClass(), SpawnPos, FRotator::ZeroRotator);
        else if (Tipo == 2)
            NuevoEnemigo = World->SpawnActor<ANave_Tanque>(ANave_Tanque::StaticClass(), SpawnPos, FRotator::ZeroRotator);
        else
            NuevoEnemigo = World->SpawnActor<ANave_Pesada>(ANave_Pesada::StaticClass(), SpawnPos, FRotator::ZeroRotator);
    }

    else if (NivelActual == 6)
    {
        if (!bBossFinalSpawned)
        {
            BossFinalActual = World->SpawnActor<ABossFinal>(
                ABossFinal::StaticClass(),
                SpawnPos,
                FRotator::ZeroRotator
            );

            bBossFinalSpawned = true;

            MostrarMensajeTemporal(TEXT("BOSS FINAL APARECIO"), 4.0f);

            UE_LOG(LogTemp, Warning, TEXT("BOSS FINAL APARECIO"));

            return;
        }

        if (EnemigosGeneradosNivel6 >= MaxEnemigosNivel6)
        {
            return;
        }

        int32 Tipo = FMath::RandRange(0, 2);

        if (Tipo == 0)
            NuevoEnemigo = World->SpawnActor<ANave_Kamikaze>(ANave_Kamikaze::StaticClass(), SpawnPos, FRotator::ZeroRotator);
        else if (Tipo == 1)
            NuevoEnemigo = World->SpawnActor<ANave_Francotirador>(ANave_Francotirador::StaticClass(), SpawnPos, FRotator::ZeroRotator);
        else
            NuevoEnemigo = World->SpawnActor<ANave_Tanque>(ANave_Tanque::StaticClass(), SpawnPos, FRotator::ZeroRotator);

        EnemigosGeneradosNivel6++;
    }
}

void AShooterNaves2025GameMode::MiniBossDestruido()
{
    UE_LOG(LogTemp, Warning, TEXT("MiniBoss destruido. Eliminando enemigos restantes."));

    bMiniBossDerrotado = true;

    DestruirTodosLosEnemigos();

    MiniBossActual = nullptr;
    EnemigosRestantes = 0;

    VerificarMeta();
}

void AShooterNaves2025GameMode::DestruirTodosLosEnemigos()
{
    for (int32 i = EnemigosActivos.Num() - 1; i >= 0; i--)
    {
        AActor* Enemigo = EnemigosActivos[i];

        if (!IsValid(Enemigo))
        {
            EnemigosActivos.RemoveAt(i);
            continue;
        }

        // No destruyas aqui al miniboss, porque ya esta muriendo desde Morir()
        if (Enemigo == MiniBossActual)
        {
            EnemigosActivos.RemoveAt(i);
            continue;
        }

        Enemigo->Destroy();
        EnemigosActivos.RemoveAt(i);
    }

    EnemigosActivos.Empty();
}

// Se llama cada vez que el jugador destruye un enemigo
void AShooterNaves2025GameMode::EnemigoDestruido()
{
    if (!bJugando) return;

    EnemigosRestantes--;
    Puntuacion += 100 * NivelActual;
    EnemigosMuertosNivelActual++;

    if (NivelActual == 3 &&
        !bMiniBossSpawned &&
        EnemigosMuertosNivelActual >= EnemigosParaAparecerMiniBoss)
    {
        FVector SpawnBoss = FVector(0.f, 0.f, 200.f);

        APawn* Jugador = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        if (Jugador)
        {
            SpawnBoss.Z = Jugador->GetActorLocation().Z;
        }

        UWorld* World = GetWorld();

        if (World)
        {
            MiniBossActual = World->SpawnActor<AMiniBoss>(
                AMiniBoss::StaticClass(),
                SpawnBoss,
                FRotator::ZeroRotator
            );

            bMiniBossSpawned = true;
            EnemigosMuertosDesdeMiniBoss = 0;

            UE_LOG(LogTemp, Warning, TEXT("MINIBOSS APARECIO"));
        }
    }
    else if (NivelActual == 3 && bMiniBossSpawned && !bMiniBossDerrotado)
    {
        EnemigosMuertosDesdeMiniBoss++;
    }

    if (NivelActual == 3 &&
        MiniBossActual &&
        !bMiniBossDebilitado &&
        EnemigosMuertosDesdeMiniBoss >= EnemigosParaDebilitarMiniBoss)
    {
        MiniBossActual->Debilitar();
        bMiniBossDebilitado = true;

        UE_LOG(LogTemp, Warning, TEXT("MINIBOSS DEBILITADO POR MATAR ENEMIGOS CERCANOS"));
    }

    UE_LOG(LogTemp, Warning,
        TEXT("Enemigo destruido. Restantes: %d | Puntuacion: %d"),
        EnemigosRestantes, Puntuacion);

    VerificarMeta();
}

// Verifica si el jugador ya destruyo todos los enemigos necesarios
void AShooterNaves2025GameMode::VerificarMeta()
{
    if (NivelActual == 3)
    {
        if (bMiniBossDerrotado)
        {
            GetWorldTimerManager().ClearTimer(TimerSpawn);
            SiguienteNivel();
        }

        return;
    }

    if (NivelActual == 6)
    {
        if (bBossFinalDerrotado)
        {
            GetWorldTimerManager().ClearTimer(TimerSpawn);
            GoodEnding();
        }

        return;
    }

    if (EnemigosRestantes <= 0)
    {
        GetWorldTimerManager().ClearTimer(TimerSpawn);
        SiguienteNivel();
    }
}

// Pasa al siguiente nivel o activa el good ending
void AShooterNaves2025GameMode::SiguienteNivel()
{
    EnemigosActivos.Empty();

    if (NivelActual == 3)
    {
        MostrarMensajeTemporal(TEXT("FASE 1 COMPLETADA"), 5.0f);
        UE_LOG(LogTemp, Warning, TEXT("=== FASE 1 COMPLETADA ==="));
    }

    NivelActual++;

    if (NivelActual > 6)
    {
        GoodEnding();
        return;
    }

    UE_LOG(LogTemp, Warning, TEXT("Pasando al nivel %d"), NivelActual);

    FTimerHandle TimerSiguiente;
    GetWorldTimerManager().SetTimer(
        TimerSiguiente,
        [this]() { IniciarNivel(); },
        3.0f,
        false
    );
}

// Se llama cuando el jugador recibe daño
void AShooterNaves2025GameMode::JugadorRecibioDanio()
{
    if (!bJugando) return;

    VidasJugador--;

    UE_LOG(LogTemp, Warning,
        TEXT("Jugador recibio danio. Vidas: %d"), VidasJugador);

    if (VidasJugador <= 0)
    {
        bJugando = false;
        GetWorldTimerManager().ClearTimer(TimerSpawn);
        BadEnding();
    }
}

// Activa el good ending al pasar todos los niveles
void AShooterNaves2025GameMode::GoodEnding()
{
    bJugando = false;
    bGoodEnding = true;

    MostrarMensajeTemporal(TEXT("GOOD ENDING - La humanidad resistio la invasion"), 10.0f);

    UE_LOG(LogTemp, Warning, TEXT("=== GOOD ENDING ==="));
}

// Activa el bad ending segun en que nivel perdio
void AShooterNaves2025GameMode::BadEnding()
{
    bJugando = false;
    bGameOver = true;

    TextoBadEnding = ObtenerBadEndingPorNivel(NivelActual);

    MostrarMensajeTemporal(TextoBadEnding, 10.0f);

    UE_LOG(LogTemp, Warning,
        TEXT("%s"), *TextoBadEnding);
}

void AShooterNaves2025GameMode::MostrarMensajeTemporal(FString Mensaje, float Duracion)
{
    MensajeTemporal = Mensaje;
    TiempoMensajeTemporal = Duracion;

    GetWorldTimerManager().ClearTimer(TimerMensajeTemporal);

    GetWorldTimerManager().SetTimer(
        TimerMensajeTemporal,
        this,
        &AShooterNaves2025GameMode::LimpiarMensajeTemporal,
        Duracion,
        false
    );
}

void AShooterNaves2025GameMode::LimpiarMensajeTemporal()
{
    MensajeTemporal = "";
    TiempoMensajeTemporal = 0.0f;
}

void AShooterNaves2025GameMode::BossFinalDestruido()
{
    bBossFinalDerrotado = true;
    BossFinalActual = nullptr;

    DestruirTodosLosEnemigos();

    GoodEnding();
}

void AShooterNaves2025GameMode::JugadorMurio()
{
    if (!bJugando)
    {
        return;
    }

    bJugando = false;
    GetWorldTimerManager().ClearTimer(TimerSpawn);

    BadEnding();
}

// Cuantos enemigos hay que destruir segun el nivel
int32 AShooterNaves2025GameMode::CalcularMetaEnemigos(int32 Nivel)
{
    switch (Nivel)
    {
    case 1: return 5;  // 10 livianas
    case 2: return 8;  // 15 entre livianas y normales
    case 3: return 12;  // 20 de todos los tipos
    case 4: return 10;  // Fase 2 empieza
    case 5: return 12;
    case 6: return 1;   // Solo el boss final
    default: return 10;
    }
}

// Cada cuanto aparece un enemigo segun el nivel
// Niveles bajos = aparecen mas despacio
// Niveles altos = aparecen mas rapido
float AShooterNaves2025GameMode::CalcularIntervaloSpawn(int32 Nivel)
{
    switch (Nivel)
    {
    case 1: return 4.0f; // Uno cada 4 segundos, facil
    case 2: return 3.0f;
    case 3: return 2.5f;
    case 4: return 2.0f;
    case 5: return 1.5f;
    case 6: return 5.0f; // Boss, solo aparece uno
    default: return 3.0f;
    }
}

FString AShooterNaves2025GameMode::ObtenerTextoLorePorNivel(int32 Nivel) const
{
    switch (Nivel)
    {
    case 1:
        return TEXT("Nivel 1: La invasion inicia en la alta atmosfera.");
    case 2:
        return TEXT("Nivel 2: El enemigo despliega naves livianas mas veloces.");
    case 3:
        return TEXT("Nivel 3: Una nave nodriza menor entra al campo de batalla.");
    case 4:
        return TEXT("Nivel 4: La segunda fase comienza. Las fuerzas especiales avanzan.");
    case 5:
        return TEXT("Nivel 5: La resistencia enemiga se intensifica.");
    case 6:
        return TEXT("Nivel 6: El comandante enemigo aparece.");
    default:
        return TEXT("");
    }
}

FString AShooterNaves2025GameMode::ObtenerBadEndingPorNivel(int32 Nivel) const
{
    switch (Nivel)
    {
    case 1:
        return TEXT("BAD ENDING: La invasion inicial supero la defensa.");
    case 2:
        return TEXT("BAD ENDING: Las naves livianas rompieron la linea defensiva.");
    case 3:
        return TEXT("BAD ENDING: El miniboss abrio paso a la flota enemiga.");
    case 4:
        return TEXT("BAD ENDING: Las fuerzas especiales dominaron la atmosfera.");
    case 5:
        return TEXT("BAD ENDING: La resistencia humana quedo rodeada.");
    case 6:
        return TEXT("BAD ENDING: El boss final conquisto la orbita terrestre.");
    default:
        return TEXT("BAD ENDING: La defensa fallo.");
    }
}