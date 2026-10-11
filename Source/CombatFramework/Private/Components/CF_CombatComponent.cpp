// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CF_CombatComponent.h"

#include "Characters/CF_CombatPlayerCharacter.h"

UCF_CombatComponent::UCF_CombatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCF_CombatComponent::BeginPlay()
{
	Super::BeginPlay();

	GetOwnerCharacter();
}

void UCF_CombatComponent::GetOwnerCharacter()
{
	ACF_CombatPlayerCharacter* Character = Cast<ACF_CombatPlayerCharacter>(GetOwner());
	if (!Character) return;

	OwnerCharacter = Character;
}

void UCF_CombatComponent::SubscribeAttackMontageEnded()
{
	UAnimMontage* AnimMontage = AttackMontages[CurrentAttackIndex];
	UAnimInstance* AnimInstance = OwnerCharacter->GetMesh()->GetAnimInstance();
	if (!AnimMontage || !AnimInstance) return;

	FOnMontageEnded EndDelegate;
	EndDelegate.BindUObject(this, &UCF_CombatComponent::OnAttackMontageEnded);
	AnimInstance->Montage_SetEndDelegate(EndDelegate, AnimMontage);
}

void UCF_CombatComponent::TryAttack()
{
	if (!IsValid(OwnerCharacter) || !CanAttack()) return;
	if (!AttackMontages.IsValidIndex(CurrentAttackIndex)) return;

	bCanAttack = false;

	OwnerCharacter->PlayAnimMontage(AttackMontages[CurrentAttackIndex]);
	SubscribeAttackMontageEnded();
	CurrentAttackIndex = (CurrentAttackIndex + 1) % AttackMontages.Num();

	UE_LOG(LogTemp, Warning, TEXT("CurrentAttackIndex: %d"), CurrentAttackIndex);
}

void UCF_CombatComponent::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (bInterrupted) return;
	
	CurrentAttackIndex = 0;
	bCanAttack = true;
}

void UCF_CombatComponent::SetChainStatus(bool bChainStatus)
{
	bCanAttack = bChainStatus;
}
