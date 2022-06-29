// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayAbilities\Public\AbilitySystemInterface.h"
#include "FootSouls/GameplayAbilitySystem/FSAbilityTypes.h"
#include "FSCharacter.generated.h"

class UFSGameplayAbilityComponent;
class UFSGameplayAbility;

UCLASS(config=Game)
class FOOTSOULS_API AFSCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	AFSCharacter();

	UPROPERTY()
	UFSGameplayAbilityComponent* AbilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TSoftClassPtr<UFSGameplayAbility>> StartupAbilities;

	virtual void BeginPlay() override;
protected:

	UFUNCTION(BlueprintCallable, Category = "DSAbilitySystemComponent")
	void GiveFSAbility(TSoftClassPtr<UFSGameplayAbility> AbilityClassPtr, int32 level = 1, EFSGameplayAbilityInputBinds inputOverride = EFSGameplayAbilityInputBinds::NONE);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface
	void PossessedBy(AController* NewController) override;

	UFUNCTION()
	UAbilitySystemComponent* GetAbilitySystemComponent() const;
};

