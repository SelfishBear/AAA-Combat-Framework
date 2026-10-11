// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CF_BaseCharacter.h"
#include "CF_CombatPlayerCharacter.generated.h"

class UCF_CombatComponent;
struct FInputActionValue;
class UCF_CombatCharacterMovementComponent;
DECLARE_LOG_CATEGORY_EXTERN(LogCombatCharacter, Log, All);

class UInputAction;
class UInputMappingContext;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class COMBATFRAMEWORK_API ACF_CombatPlayerCharacter : public ACF_BaseCharacter
{
	GENERATED_BODY()

public:
	ACF_CombatPlayerCharacter(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat")
	TObjectPtr<UCF_CombatComponent> CombatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<UCameraComponent> FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> PlayerMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> AttackAction;
	
	FORCEINLINE UCF_CombatComponent* GetCombatComponent() const { return CombatComponent; }

protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UPROPERTY()
	UCF_CombatCharacterMovementComponent* CombatMovementComponent;
	
	void CacheMovementComponent();
	
	void BindMappingContext();
	void UnbindMappingContext();
	
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	
	void TryAttack();
};
