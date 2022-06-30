#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EFSGameplayAbilityInputBinds : uint8
{
	NONE = 0,
	Jump,
	Sprint,
	Attack_1,
	Attack_2,
	SwitchWeapon,
};