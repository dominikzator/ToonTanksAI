// Fill out your copyright notice in the Description page of Project Settings.

#include "AIController.h"
#include "BTDecorator_CanSeePlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTDecorator_CanSeePlayer::UBTDecorator_CanSeePlayer()
{
	NodeName = "Player Location If Seen";
}

void UBTDecorator_CanSeePlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if(PlayerPawn == nullptr)
	{
		return;
	}

	if(OwnerComp.GetAIOwner() == nullptr)
	{
		return;
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);

	//if(OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
	//{
	//	OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
	//}
	//else
	//{
	//	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	//}
}
		