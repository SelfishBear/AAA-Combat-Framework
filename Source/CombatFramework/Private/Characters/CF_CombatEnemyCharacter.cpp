// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatFramework/Public/Characters/CF_CombatEnemyCharacter.h"

ACF_CombatEnemyCharacter::ACF_CombatEnemyCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACF_CombatEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ACF_CombatEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


