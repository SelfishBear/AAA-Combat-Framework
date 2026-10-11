// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CF_CombatCharacterMovementComponent.generated.h"


struct FInputActionValue;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COMBATFRAMEWORK_API UCF_CombatCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UCF_CombatCharacterMovementComponent();

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
