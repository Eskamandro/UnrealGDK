// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "GA_IncrementSpyValue.h"
#include "GameplayTagContainer.h"
#include "SpyValueGASTestActor.h"

UGA_IncrementSpyValue::UGA_IncrementSpyValue()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::NonInstanced;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::ServerOnly;

	AbilityTags.AddTag(FGameplayTag::RequestGameplayTag(FName(TEXT("GameplayAbility.Trigger"))));
}

void UGA_IncrementSpyValue::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
											const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	if (HasAuthorityOrPredictionKey(ActorInfo, &ActivationInfo))
	{
		if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
		{
			EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
			return;
		}

		ASpyValueGASTestActor* TestActor = static_cast<ASpyValueGASTestActor*>(ActorInfo->OwnerActor.Get());
		if (TestActor == nullptr)
		{
			UE_LOG(LogTemp, Error, TEXT("Ability was activated with null OwnerActor"));
			EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
			return;
		}

		UE_LOG(LogTemp, Log, TEXT("Activated ability"));
		TestActor->IncrementCounter();

		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
	}
}
