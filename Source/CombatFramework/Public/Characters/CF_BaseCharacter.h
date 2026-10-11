// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CF_BaseCharacter.generated.h"

UCLASS()
class COMBATFRAMEWORK_API ACF_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACF_BaseCharacter(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
