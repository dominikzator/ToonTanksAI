// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

#include "Kismet/GameplayStatics.h"

void ATankAIController::BeginPlay()
{
	UE_LOG(LogTemp, Display, TEXT("ATankAIController::BeginPlay"));
	Super::BeginPlay();
	
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	SetFocus(PlayerPawn);
	MoveToActor(PlayerPawn, 200);
	//RunBehaviorTree(AIBehahior);
}