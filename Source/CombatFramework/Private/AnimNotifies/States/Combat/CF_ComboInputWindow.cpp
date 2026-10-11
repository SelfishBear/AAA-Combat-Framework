// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifies/States/Combat/CF_ComboInputWindow.h"

#include "Characters/CF_CombatPlayerCharacter.h"
#include "Components/CF_CombatComponent.h"

void UCF_ComboInputWindow::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                       float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	SetComboInputStatus(MeshComp, true);
}

void UCF_ComboInputWindow::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                     const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);
	SetComboInputStatus(MeshComp, false);
}

void UCF_ComboInputWindow::SetComboInputStatus(USkeletalMeshComponent* MeshComp, bool bStatus)
{
	ACF_CombatPlayerCharacter* CombatPlayerCharacter = MeshComp->GetOwner<ACF_CombatPlayerCharacter>();
	if (!CombatPlayerCharacter) return;

	UCF_CombatComponent* CombatComponent = CombatPlayerCharacter->GetCombatComponent();
	if (!CombatComponent) return;

	CombatComponent->SetChainStatus(bStatus);
}
