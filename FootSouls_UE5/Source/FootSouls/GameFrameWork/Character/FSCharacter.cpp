// Copyright Epic Games, Inc. All Rights Reserved.
#include "FSCharacter.h"
#include "GameplayAbilities\Public\AbilitySystemComponent.h"
#include "FootSouls/GameplayAbilitySystem/FSGameplayAbilityComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FootSouls/GameplayAbilitySystem/FSGameplayAbility.h"
#include "GameplayAbilitySpec.h"

//////////////////////////////////////////////////////////////////////////
// AFSCharacter

AFSCharacter::AFSCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UFSGameplayAbilityComponent>(TEXT("AbilitySystemComponent"));
}

void AFSCharacter::BeginPlay()
{
	Super::BeginPlay();

	//¸³Óè¼¼ÄÜ
	for (TSoftClassPtr<UFSGameplayAbility>& ClassPtr : StartupAbilities)
	{
		GiveFSAbility(ClassPtr);
	}
}

void AFSCharacter::GiveFSAbility(TSoftClassPtr<UFSGameplayAbility> AbilityClassPtr, int32 level /*= 1*/, EFSGameplayAbilityInputBinds inputOverride /*= EFSGameplayAbilityInputBinds::NONE*/)
{
	if (UClass* gaClass = AbilityClassPtr.LoadSynchronous())
	{
		UFSGameplayAbility* cdo = gaClass->GetDefaultObject<UFSGameplayAbility>();
		if (cdo)
		{
			int32 InputID;
			if (inputOverride != EFSGameplayAbilityInputBinds::NONE)
			{
				InputID = (int32)inputOverride;
			}
			else
			{
				InputID = cdo->DefaultInputBind == EFSGameplayAbilityInputBinds::NONE ? INDEX_NONE : (int)cdo->DefaultInputBind;
			}
			GetAbilitySystemComponent()->GiveAbility(FGameplayAbilitySpec(gaClass, level, InputID, this));
			
		}
	}
}

void AFSCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	AbilitySystemComponent->BindAbilityActivationToInputComponent(PlayerInputComponent, FGameplayAbilityInputBinds("ConfirmInput", "CancelInput", "EFSGameplayAbilityInputBinds"));
	/*PlayerInputComponent->BindAxis("MoveForward", this, &ALinkLegendCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALinkLegendCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ALinkLegendCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ALinkLegendCharacter::LookUpAtRate);*/
}


UAbilitySystemComponent* AFSCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void AFSCharacter::PossessedBy(AController* NewController) {
	Super::PossessedBy(NewController);

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
	
	SetOwner(NewController);
}
