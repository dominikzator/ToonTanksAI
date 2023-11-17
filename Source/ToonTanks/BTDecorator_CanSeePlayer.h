// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_BlackboardBase.h"
#include "BTDecorator_CanSeePlayer.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API UBTDecorator_CanSeePlayer : public UBTDecorator_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTDecorator_CanSeePlayer();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
