// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowingActor.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AFollowingActor::AFollowingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileTrail = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Projectile Trail"));
	RootComponent = ProjectileTrail;
}

// Called when the game starts or when spawned
void AFollowingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFollowingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(Target == nullptr)
	{
		ProjectileTrail->Deactivate();
		if(!ProjectileTrail->IsActive())
		{
			Destroy();
		}
	}
	else
	{
		SetActorLocation(Target->GetActorLocation());
	}
}
