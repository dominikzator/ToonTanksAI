// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	void HandleDestruction();
protected:
	void RotateTurret(FVector LookAtTarget);
	void Fire();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PawnComponents", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComp;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PawnComponents", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PawnComponents", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PawnComponents", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Super Variables", meta = (AllowPrivateAccess = "true"))
	int32 VisibleAnywhereInt = 12;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Super Variables", meta = (AllowPrivateAccess = "true"))
	int32 EditAnywhereInt = 12;

	UPROPERTY(EditDefaultsOnly, Category="Particles")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category="Particles")
	TSubclassOf<class AFollowingActor> ProjectileTrailClass;

	UPROPERTY(EditAnywhere, Category="Particles")
	UParticleSystem* DeathParticleSystem;

	UPROPERTY(EditAnywhere, Category="Combat")
	class USoundBase* DeathSound;

	UPROPERTY(EditAnywhere, Category="Combat")
	TSubclassOf<class UCameraShakeBase> DeathCameraShakeClass;
};
