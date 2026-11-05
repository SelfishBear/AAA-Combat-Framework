// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CF_CombatDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFRAMEWORK_API UCF_CombatDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat")
	TArray<UAnimMontage*> GroundAttackMontages;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat")
	TArray<UAnimMontage*> AirAttackMontages;
};
