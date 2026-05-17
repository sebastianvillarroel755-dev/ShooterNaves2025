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
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AShooterNaves2025GameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ShooterNaves2025,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterNaves2025GameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "ShooterNaves2025GameMode.h" },
		{ "ModuleRelativePath", "ShooterNaves2025GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AShooterNaves2025GameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShooterNaves2025GameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AShooterNaves2025GameMode_Statics::ClassParams = {
		&AShooterNaves2025GameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
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
	IMPLEMENT_CLASS(AShooterNaves2025GameMode, 1612264785);
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
