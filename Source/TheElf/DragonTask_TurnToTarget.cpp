// Fill out your copyright notice in the Description page of Project Settings.

#include "DragonTask_TurnToTarget.h"
#include "MyAIController.h"
#include "DragonCharacter.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UDragonTask_TurnToTarget::UDragonTask_TurnToTarget() {
	NodeName = TEXT("TurnToTarget");
}

EBTNodeResult::Type UDragonTask_TurnToTarget::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto MyCharacter = Cast<ADragonCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == MyCharacter) return EBTNodeResult::Failed;

	auto Target = Cast<AMyCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AMyAIController::TargetKey));
	if (nullptr == Target) return EBTNodeResult::Failed;

	FVector LookVector = Target->GetActorLocation() - MyCharacter->GetActorLocation();
	LookVector.Z = 0.0f;

	FRotator TargetRot = FRotationMatrix::MakeFromX(LookVector).Rotator();
	MyCharacter->SetActorRotation(FMath::RInterpTo(MyCharacter->GetActorRotation(), TargetRot, 
		GetWorld()->GetDeltaSeconds(), 2.0f));

	return EBTNodeResult::Succeeded;
}
