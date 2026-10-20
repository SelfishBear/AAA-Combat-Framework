// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CF_CombatCharacterMovementComponent.generated.h"

struct FInputActionValue;

UENUM()
enum class EMovementState
{
	Walking,
	Sprinting
};

USTRUCT(BlueprintType, Blueprintable)
struct FMovementSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float WalkSpeed = 450.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float SprintSpeed = 600.0f;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COMBATFRAMEWORK_API UCF_CombatCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UCF_CombatCharacterMovementComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	FMovementSettings MovementSettings;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Movement")
	EMovementState CurrentMovementState = EMovementState::Walking;
	
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	void StartSprint();
	void StopSprint();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
