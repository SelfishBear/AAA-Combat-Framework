// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatFramework/Public/Characters/CF_CombatPlayerCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "CombatFramework/Public/Components/CF_CombatCharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/CF_CombatComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

DEFINE_LOG_CATEGORY(LogCombatCharacter);

class UEnhancedInputLocalPlayerSubsystem;
class UCF_CombatCharacterMovementComponent;

ACF_CombatPlayerCharacter::ACF_CombatPlayerCharacter(const FObjectInitializer& ObjectInitializer) : Super(
	ObjectInitializer.SetDefaultSubobjectClass<UCF_CombatCharacterMovementComponent>(CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	CombatComponent = CreateDefaultSubobject<UCF_CombatComponent>(TEXT("CombatComponent"));
}

void ACF_CombatPlayerCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	CacheMovementComponent();
}

void ACF_CombatPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	BindMappingContext();
}

void ACF_CombatPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACF_CombatPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this,
		                                   &ACF_CombatPlayerCharacter::Move);

		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this,
		                                   &ACF_CombatPlayerCharacter::Look);

		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Started, this,
		                                   &ACF_CombatPlayerCharacter::TryAttack);
	}
	else
	{
		UE_LOG(LogCombatCharacter, Error,
		       TEXT(
			       "'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."
		       ), *GetNameSafe(this));
	}
}

void ACF_CombatPlayerCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UnbindMappingContext();
	Super::EndPlay(EndPlayReason);
}

void ACF_CombatPlayerCharacter::CacheMovementComponent()
{
	CombatMovementComponent = Cast<UCF_CombatCharacterMovementComponent>(GetMovementComponent());
}

void ACF_CombatPlayerCharacter::BindMappingContext()
{
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(PlayerMappingContext, 0);
		}
	}
}

void ACF_CombatPlayerCharacter::UnbindMappingContext()
{
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->RemoveMappingContext(PlayerMappingContext);
		}
	}
}

void ACF_CombatPlayerCharacter::Move(const FInputActionValue& Value)
{
	UE_LOG(LogCombatCharacter, Log, TEXT("Move called with value: %s"), *Value.Get<FVector2D>().ToString());

	if (!CombatMovementComponent) return;

	CombatMovementComponent->Move(Value);
}

void ACF_CombatPlayerCharacter::Look(const FInputActionValue& Value)
{
	if (!CombatMovementComponent) return;

	CombatMovementComponent->Look(Value);
}

void ACF_CombatPlayerCharacter::TryAttack()
{
	if (!CombatComponent) return;

	CombatComponent->TryAttack();
}
