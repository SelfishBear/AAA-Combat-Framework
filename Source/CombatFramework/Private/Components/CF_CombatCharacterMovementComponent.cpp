// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatFramework/Public/Components/CF_CombatCharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"

UCF_CombatCharacterMovementComponent::UCF_CombatCharacterMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCF_CombatCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCF_CombatCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                         FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCF_CombatCharacterMovementComponent::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (!GetController()) return;

	const FRotator ControlRotation = GetController()->GetControlRotation();
	const FRotator YawRotation(0, ControlRotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	GetController()->GetCharacter()->AddMovementInput(ForwardDirection, MovementVector.Y);
	GetController()->GetCharacter()->AddMovementInput(RightDirection, MovementVector.X);
}

void UCF_CombatCharacterMovementComponent::Look(const FInputActionValue& Value)
{
	FVector2D LookVector = Value.Get<FVector2D>();

	if (!GetController()) return;

	GetController()->GetPawn()->AddControllerYawInput(-LookVector.X);
	GetController()->GetPawn()->AddControllerPitchInput(LookVector.Y);
}

void UCF_CombatCharacterMovementComponent::StartSprint()
{
	if (IsFalling()) return;
	CurrentMovementState = EMovementState::Sprinting;
	MaxWalkSpeed = MovementSettings.SprintSpeed;
}

void UCF_CombatCharacterMovementComponent::StopSprint()
{
	CurrentMovementState = EMovementState::Walking;
	MaxWalkSpeed = MovementSettings.WalkSpeed;
}
