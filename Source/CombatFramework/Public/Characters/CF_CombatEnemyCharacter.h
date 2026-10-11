// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CF_BaseCharacter.h"
#include "CF_CombatEnemyCharacter.generated.h"

UCLASS()
class COMBATFRAMEWORK_API ACF_CombatEnemyCharacter : public ACF_BaseCharacter
{
	GENERATED_BODY()

public:
	ACF_CombatEnemyCharacter(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
