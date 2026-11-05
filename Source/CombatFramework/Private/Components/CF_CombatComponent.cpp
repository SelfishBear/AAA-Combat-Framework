// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CF_CombatComponent.h"

#include "CF_CombatDataAsset.h"
#include "Characters/CF_CombatPlayerCharacter.h"
#include "GameFramework/PawnMovementComponent.h"

UCF_CombatComponent::UCF_CombatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCF_CombatComponent::BeginPlay()
{
	Super::BeginPlay();

	GetOwnerCharacter();
}

void UCF_CombatComponent::TryAttack()
{
	if (!IsValid(OwnerCharacter) || !CanAttack()) return;

	if (OwnerCharacter->GetMovementComponent()->IsFalling())
	{
		PlayAppropriateAttack(CombatDataAsset->AirAttackMontages, CurrentAirAttackIndex);
	}
	else
	{
		PlayAppropriateAttack(CombatDataAsset->GroundAttackMontages, CurrentGroundAttackIndex);
	}
}

void UCF_CombatComponent::PlayAppropriateAttack(const TArray<UAnimMontage*>& AttackMontages, int32& AttackIndex)
{
	if (!IsValid(CombatDataAsset) || !AttackMontages.IsValidIndex(AttackIndex) || !IsValid(AttackMontages[AttackIndex]))
		return;

	bCanAttack = false;

	OwnerCharacter->PlayAnimMontage(AttackMontages[AttackIndex]);
	SubscribeAttackMontageEnded(AttackMontages[AttackIndex], AttackIndex);
	AttackIndex = (AttackIndex + 1) % AttackMontages.Num();

	UE_LOG(LogTemp, Warning, TEXT("CurrentAttackIndex: %d"), AttackIndex);
}

void UCF_CombatComponent::HandleOwnerLanded()
{
	if (!IsValid(OwnerCharacter)) return;

	if (UAnimInstance* AnimInstance = OwnerCharacter->GetMesh()->GetAnimInstance())
	{
		if (AnimInstance->IsAnyMontagePlaying())
		{
			AnimInstance->Montage_Stop(0.15f, AnimInstance->GetCurrentActiveMontage());
		}
	}

	ResetAttackAbility();
}

void UCF_CombatComponent::SetChainStatus(bool bChainStatus)
{
	bCanAttack = bChainStatus;
}

void UCF_CombatComponent::SubscribeAttackMontageEnded(UAnimMontage* AttackMontage, int32 AttackIndex)
{
	UAnimInstance* AnimInstance = OwnerCharacter->GetMesh()->GetAnimInstance();
	if (!AttackMontage || !AnimInstance) return;

	FOnMontageEnded EndDelegate;
	EndDelegate.BindUObject(this, &UCF_CombatComponent::OnAttackMontageEnded);
	AnimInstance->Montage_SetEndDelegate(EndDelegate, AttackMontage);
}

void UCF_CombatComponent::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (bInterrupted) return;

	UE_LOG(LogTemp, Warning, TEXT("Attack montage ended"));
	ResetAttackAbility();
}

void UCF_CombatComponent::GetOwnerCharacter()
{
	ACF_CombatPlayerCharacter* Character = Cast<ACF_CombatPlayerCharacter>(GetOwner());
	if (!Character) return;

	OwnerCharacter = Character;
}

void UCF_CombatComponent::ResetAttackAbility()
{
	CurrentGroundAttackIndex = 0;
	CurrentAirAttackIndex = 0;
	bCanAttack = true;
}
