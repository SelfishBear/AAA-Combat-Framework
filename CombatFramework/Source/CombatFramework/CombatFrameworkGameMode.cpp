// Copyright Epic Games, Inc. All Rights Reserved.

#include "CombatFrameworkGameMode.h"
#include "CombatFrameworkCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACombatFrameworkGameMode::ACombatFrameworkGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
