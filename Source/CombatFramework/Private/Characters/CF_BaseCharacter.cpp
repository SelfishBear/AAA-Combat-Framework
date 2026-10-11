// Fill out your copyright notice in the Description page of Project Settings.

#include "CombatFramework/Public/Characters/CF_BaseCharacter.h"

ACF_BaseCharacter::ACF_BaseCharacter(const FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACF_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ACF_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


