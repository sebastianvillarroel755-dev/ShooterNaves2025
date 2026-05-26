// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ShooterNaves2025/ShooterNaves2025GameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShooterNaves2025GameMode() {}
// Cross Module References
	SHOOTERNAVES2025_API UClass* Z_Construct_UClass_AShooterNaves2025GameMode_NoRegister();
	SHOOTERNAVES2025_API UClass* Z_Construct_UClass_AShooterNaves2025GameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ShooterNaves2025();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	void AShooterNaves2025GameMode::StaticRegisterNativesAShooterNaves2025GameMode()
	{
	}
	UClass* Z_Construct_UClass_AShooterNaves2025GameMode_NoRegister()
	{
		return AShooterNaves2025GameMode::StaticClass();
	}
	struct Z_Construct_UClass_AShooterNaves2025GameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NivelActual_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_NivelActual;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnemigosRestantes_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_EnemigosRestantes;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MetaEnemigos_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MetaEnemigos;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VidasJugador_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_VidasJugador;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Puntuacion_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Puntuacion;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bGameOver_MetaData[];
#endif
		static void NewProp_bGameOver_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bGameOver;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bGoodEnding_MetaData[];
#endif
		static void NewProp_bGoodEnding_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bGoodEnding;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bFase1Completada_MetaData[];
#endif
		static void NewProp_bFase1Completada_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFase1Completada;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TextoLoreActual_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_TextoLoreActual;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MensajeTemporal_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_MensajeTemporal;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TiempoMensajeTemporal_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TiempoMensajeTemporal;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TextoBadEnding_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_TextoBadEnding;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EnemigosActivos_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnemigosActivos_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_EnemigosActivos;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AShooterNaves2025GameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ShooterNaves2025,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterNaves2025GameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "// GameMode principal del juego\n// Maneja los 6 niveles, las oleadas de enemigos,\n// el sistema de vidas y la logica de victoria/derrota\n" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "ShooterNaves2025GameMode.h" },
		{ "ModuleRelativePath", "ShooterNaves2025GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
		{ "ToolTip", "GameMode principal del juego\nManeja los 6 niveles, las oleadas de enemigos,\nel sistema de vidas y la logica de victoria/derrota" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_NivelActual_MetaData[] = {
		{ "Category", "Nivel" },
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80 SISTEMA DE NIVELES \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n// Nivel actual del juego (1 al 6)\n" },
		{ "ModuleRelativePath", "ShooterNaves2025GameMode.h" },
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80 SISTEMA DE NIVELES \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\nNivel actual del juego (1 al 6)" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_NivelActual = { "NivelActual", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooterNaves2025GameMode, NivelActual), METADATA_PARAMS(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_NivelActual_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_NivelActual_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_EnemigosRestantes_MetaData[] = {
		{ "Category", "Nivel" },
		{ "Comment", "// Enemigos que quedan por destruir en el nivel actual\n" },
		{ "ModuleRelativePath", "ShooterNaves2025GameMode.h" },
		{ "ToolTip", "Enemigos que quedan por destruir en el nivel actual" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_EnemigosRestantes = { "EnemigosRestantes", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooterNaves2025GameMode, EnemigosRestantes), METADATA_PARAMS(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_EnemigosRestantes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_EnemigosRestantes_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_MetaEnemigos_MetaData[] = {
		{ "Category", "Nivel" },
		{ "Comment", "// Enemigos que hay que destruir para pasar el nivel\n" },
		{ "ModuleRelativePath", "ShooterNaves2025GameMode.h" },
		{ "ToolTip", "Enemigos que hay que destruir para pasar el nivel" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_MetaEnemigos = { "MetaEnemigos", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooterNaves2025GameMode, MetaEnemigos), METADATA_PARAMS(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_MetaEnemigos_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_MetaEnemigos_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_VidasJugador_MetaData[] = {
		{ "Category", "Jugador" },
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80 SISTEMA DE VIDAS \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n// Vidas del jugador\n" },
		{ "ModuleRelativePath", "ShooterNaves2025GameMode.h" },
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80 SISTEMA DE VIDAS \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\nVidas del jugador" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_VidasJugador = { "VidasJugador", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooterNaves2025GameMode, VidasJugador), METADATA_PARAMS(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_VidasJugador_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_VidasJugador_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_Puntuacion_MetaData[] = {
		{ "Category", "Jugador" },
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80 SISTEMA DE PUNTUACION \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
		{ "ModuleRelativePath", "ShooterNaves2025GameMode.h" },
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80 SISTEMA DE PUNTUACION \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_Puntuacion = { "Puntuacion", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooterNaves2025GameMode, Puntuacion), METADATA_PARAMS(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_Puntuacion_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_Puntuacion_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bGameOver_MetaData[] = {
		{ "Category", "Estado" },
		{ "ModuleRelativePath", "ShooterNaves2025GameMode.h" },
	};
#endif
	void Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bGameOver_SetBit(void* Obj)
	{
		((AShooterNaves2025GameMode*)Obj)->bGameOver = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bGameOver = { "bGameOver", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AShooterNaves2025GameMode), &Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bGameOver_SetBit, METADATA_PARAMS(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bGameOver_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bGameOver_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bGoodEnding_MetaData[] = {
		{ "Category", "Estado" },
		{ "ModuleRelativePath", "ShooterNaves2025GameMode.h" },
	};
#endif
	void Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bGoodEnding_SetBit(void* Obj)
	{
		((AShooterNaves2025GameMode*)Obj)->bGoodEnding = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bGoodEnding = { "bGoodEnding", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AShooterNaves2025GameMode), &Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bGoodEnding_SetBit, METADATA_PARAMS(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bGoodEnding_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bGoodEnding_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bFase1Completada_MetaData[] = {
		{ "Category", "Estado" },
		{ "ModuleRelativePath", "ShooterNaves2025GameMode.h" },
	};
#endif
	void Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bFase1Completada_SetBit(void* Obj)
	{
		((AShooterNaves2025GameMode*)Obj)->bFase1Completada = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bFase1Completada = { "bFase1Completada", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AShooterNaves2025GameMode), &Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bFase1Completada_SetBit, METADATA_PARAMS(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bFase1Completada_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bFase1Completada_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_TextoLoreActual_MetaData[] = {
		{ "Category", "Lore" },
		{ "ModuleRelativePath", "ShooterNaves2025GameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_TextoLoreActual = { "TextoLoreActual", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooterNaves2025GameMode, TextoLoreActual), METADATA_PARAMS(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_TextoLoreActual_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_TextoLoreActual_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_MensajeTemporal_MetaData[] = {
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "ShooterNaves2025GameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_MensajeTemporal = { "MensajeTemporal", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooterNaves2025GameMode, MensajeTemporal), METADATA_PARAMS(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_MensajeTemporal_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_MensajeTemporal_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_TiempoMensajeTemporal_MetaData[] = {
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "ShooterNaves2025GameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_TiempoMensajeTemporal = { "TiempoMensajeTemporal", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooterNaves2025GameMode, TiempoMensajeTemporal), METADATA_PARAMS(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_TiempoMensajeTemporal_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_TiempoMensajeTemporal_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_TextoBadEnding_MetaData[] = {
		{ "Category", "Estado" },
		{ "ModuleRelativePath", "ShooterNaves2025GameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_TextoBadEnding = { "TextoBadEnding", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooterNaves2025GameMode, TextoBadEnding), METADATA_PARAMS(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_TextoBadEnding_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_TextoBadEnding_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_EnemigosActivos_Inner = { "EnemigosActivos", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_EnemigosActivos_MetaData[] = {
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80 CONTENEDOR DE ENEMIGOS ACTIVOS \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
		{ "ModuleRelativePath", "ShooterNaves2025GameMode.h" },
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80 CONTENEDOR DE ENEMIGOS ACTIVOS \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_EnemigosActivos = { "EnemigosActivos", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AShooterNaves2025GameMode, EnemigosActivos), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_EnemigosActivos_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_EnemigosActivos_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AShooterNaves2025GameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_NivelActual,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_EnemigosRestantes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_MetaEnemigos,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_VidasJugador,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_Puntuacion,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bGameOver,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bGoodEnding,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_bFase1Completada,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_TextoLoreActual,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_MensajeTemporal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_TiempoMensajeTemporal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_TextoBadEnding,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_EnemigosActivos_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterNaves2025GameMode_Statics::NewProp_EnemigosActivos,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AShooterNaves2025GameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShooterNaves2025GameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AShooterNaves2025GameMode_Statics::ClassParams = {
		&AShooterNaves2025GameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AShooterNaves2025GameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::PropPointers),
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AShooterNaves2025GameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AShooterNaves2025GameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AShooterNaves2025GameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AShooterNaves2025GameMode, 2678974741);
	template<> SHOOTERNAVES2025_API UClass* StaticClass<AShooterNaves2025GameMode>()
	{
		return AShooterNaves2025GameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShooterNaves2025GameMode(Z_Construct_UClass_AShooterNaves2025GameMode, &AShooterNaves2025GameMode::StaticClass, TEXT("/Script/ShooterNaves2025"), TEXT("AShooterNaves2025GameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShooterNaves2025GameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
