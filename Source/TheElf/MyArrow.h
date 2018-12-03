// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TheElf.h"
#include "Runtime/Engine/Classes/GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/Actor.h"
#include "MyArrow.generated.h"

UCLASS()
class THEELF_API AMyArrow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyArrow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = Visual)
		UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		UBoxComponent* CollisionComponent;
	UPROPERTY(VisibleAnywhere, Category = Movement)
		UProjectileMovementComponent* ProjectileMovementComponent;

	void ArrowInDirection(const FVector& ShootDirection);
};
