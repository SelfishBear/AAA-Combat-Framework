// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatFramework/CombatFrameworkGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCombatFrameworkGameMode() {}

// Begin Cross Module References
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_ACombatFrameworkGameMode();
COMBATFRAMEWORK_API UClass* Z_Construct_UClass_ACombatFrameworkGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_CombatFramework();
// End Cross Module References

// Begin Class ACombatFrameworkGameMode
void ACombatFrameworkGameMode::StaticRegisterNativesACombatFrameworkGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACombatFrameworkGameMode);
UClass* Z_Construct_UClass_ACombatFrameworkGameMode_NoRegister()
{
	return ACombatFrameworkGameMode::StaticClass();
}
struct Z_Construct_UClass_ACombatFrameworkGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "CombatFrameworkGameMode.h" },
		{ "ModuleRelativePath", "CombatFrameworkGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACombatFrameworkGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ACombatFrameworkGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_CombatFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACombatFrameworkGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACombatFrameworkGameMode_Statics::ClassParams = {
	&ACombatFrameworkGameMode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACombatFrameworkGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ACombatFrameworkGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACombatFrameworkGameMode()
{
	if (!Z_Registration_Info_UClass_ACombatFrameworkGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACombatFrameworkGameMode.OuterSingleton, Z_Construct_UClass_ACombatFrameworkGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACombatFrameworkGameMode.OuterSingleton;
}
template<> COMBATFRAMEWORK_API UClass* StaticClass<ACombatFrameworkGameMode>()
{
	return ACombatFrameworkGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACombatFrameworkGameMode);
ACombatFrameworkGameMode::~ACombatFrameworkGameMode() {}
// End Class ACombatFrameworkGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitHubUnrealEngineProjects_AAA_Combat_Framework_CombatFramework_Source_CombatFramework_CombatFrameworkGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACombatFrameworkGameMode, ACombatFrameworkGameMode::StaticClass, TEXT("ACombatFrameworkGameMode"), &Z_Registration_Info_UClass_ACombatFrameworkGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACombatFrameworkGameMode), 649161346U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHubUnrealEngineProjects_AAA_Combat_Framework_CombatFramework_Source_CombatFramework_CombatFrameworkGameMode_h_3089011652(TEXT("/Script/CombatFramework"),
	Z_CompiledInDeferFile_FID_GitHubUnrealEngineProjects_AAA_Combat_Framework_CombatFramework_Source_CombatFramework_CombatFrameworkGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHubUnrealEngineProjects_AAA_Combat_Framework_CombatFramework_Source_CombatFramework_CombatFrameworkGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
