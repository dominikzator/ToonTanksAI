// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTServiceUpdatePlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API UBTServiceUpdatePlayerLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTServiceUpdatePlayerLocation();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
