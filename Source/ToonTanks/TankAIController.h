// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehahior;
	
protected:
	virtual void BeginPlay() override;
};
