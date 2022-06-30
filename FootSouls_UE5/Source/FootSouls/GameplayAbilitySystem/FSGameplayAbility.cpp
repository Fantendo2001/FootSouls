#include "FSGameplayAbility.h"
#include "FootSouls/GameFrameWork/Character/FSCharacter.h"

UFSGameplayAbility::UFSGameplayAbility(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	:Super(ObjectInitializer)
	, DefaultInputBind(EFSGameplayAbilityInputBinds::NONE)
{

}

void UFSGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (DefaultInputBind != EFSGameplayAbilityInputBinds::NONE && (int32)DefaultInputBind != Spec.InputID)
	{
		FGameplayAbilitySpec* MutableSpec = const_cast<FGameplayAbilitySpec*>(&Spec);
		MutableSpec->InputID = (int32)DefaultInputBind;
	}
}

AFSCharacter* UFSGameplayAbility::GetFSActor()
{
	return Cast<AFSCharacter>(GetAvatarActorFromActorInfo());
}

