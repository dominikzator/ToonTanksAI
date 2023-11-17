// Fill out your copyright notice in the Description page of Project Settings.


#include "BTServiceUpdatePlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTServiceUpdatePlayerLocation::UBTServiceUpdatePlayerLocation()
{
	NodeName = "Update Player Location";
}

void UBTServiceUpdatePlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if(PlayerPawn == nullptr)
	{
		return;
	}
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
}
