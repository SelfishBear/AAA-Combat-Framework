// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CF_CombatComponent.generated.h"

class UCF_CombatDataAsset;
class UAnimMontage;
class ACF_CombatPlayerCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COMBATFRAMEWORK_API UCF_CombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCF_CombatComponent();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat")
	UCF_CombatDataAsset* CombatDataAsset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat")
	bool bCanAttack = true;

	void TryAttack();
	void HandleOwnerLanded();

	void SetChainStatus(bool bChainStatus);

	bool CanAttack() const { return bCanAttack; }

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	ACF_CombatPlayerCharacter* OwnerCharacter;

	int32 CurrentGroundAttackIndex = 0;
	int32 CurrentAirAttackIndex = 0;

	void GetOwnerCharacter();
	
	void SubscribeAttackMontageEnded(UAnimMontage* AttackMontage, int32 AttackIndex);
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	void PlayAppropriateAttack(const TArray<UAnimMontage*>& AttackMontages, int32& AttackIndex);
	void ResetAttackAbility();
};
