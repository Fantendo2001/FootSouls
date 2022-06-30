#pragma once

#include "AbilitySystemComponent.h"
#include "FSAbilityTypes.h"
#include "FSGameplayAbilityComponent.generated.h"

class UFSGameplayAbility;


UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class FOOTSOULS_API UFSGameplayAbilityComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	UFSGameplayAbilityComponent();
};