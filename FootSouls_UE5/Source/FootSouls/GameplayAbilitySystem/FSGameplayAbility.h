#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "FSAbilityTypes.h"
#include "FSGameplayAbility.generated.h"

class AFSCharacter;

UCLASS(abstract)
class FOOTSOULS_API UFSGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

	UFSGameplayAbility(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

	UFUNCTION(BlueprintPure)
	AFSCharacter* GetFSActor();
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameplayAbility")
	EFSGameplayAbilityInputBinds DefaultInputBind;
};