// Fill out your copyright notice in the Description page of Project Settings.

#include "MyArrow.h"


// Sets default values
AMyArrow::AMyArrow()
{
	PrimaryActorTick.bCanEverTick = true;
	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("ARROW"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	CollisionComponent->SetRelativeLocation(FVector(3.0f, 1.0f, 6.0f));
	RootComponent = CollisionComponent;
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("PROJECTILMOVEMENT"));
	ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
	ProjectileMovementComponent->InitialSpeed = 3000.0f;
	ProjectileMovementComponent->MaxSpeed = 3000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->Bounciness = 0.3f;

	Mesh->SetupAttachment(CollisionComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MAIN_ARROW(TEXT("/Game/Models/Arrow.Arrow"));
	if (MAIN_ARROW.Succeeded()) Mesh->SetStaticMesh(MAIN_ARROW.Object);

}

void AMyArrow::ArrowInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

// Called when the game starts or when spawned
void AMyArrow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

