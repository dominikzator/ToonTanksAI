// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FollowingActor.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class USoundBase;

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	AFollowingActor* ProjectileTrail;

private:
	UPROPERTY(EditDefaultsOnly, Category = "ProjectileComponents")
	class UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, Category="ProjectileComponents")
	class UProjectileMovementComponent* ProjectileMovementComp;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere)
	float Damage = 50.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	class UParticleSystem* HitParticles;

	UPROPERTY(EditAnywhere, Category="Combat")
	USoundBase* LaunchSound;

	UPROPERTY(EditAnywhere, Category="Combat")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category="Combat")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ProjectileTrailClass;

	UFUNCTION()
	void DestroyProjectile();
};
