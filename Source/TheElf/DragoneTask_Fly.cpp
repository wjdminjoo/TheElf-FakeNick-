// Fill out your copyright notice in the Description page of Project Settings.

#include "DragoneTask_Fly.h"
#include "MyAIController.h"
#include "MyAIController.h"
#include "DragonCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UDragoneTask_Fly::UDragoneTask_Fly() {
	NodeName = TEXT("CanFly");
}



EBTNodeResult::Type UDragoneTask_Fly::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto MyCharacter = Cast<ADragonCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == MyCharacter) return EBTNodeResult::Failed;

	//MyCharacter->Fly();
	IsFlying = true;

	return EBTNodeResult::InProgress;
}


void UDragoneTask_Fly::TickTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float Deltaseconds)
{
	Super::TickTask(OwnerComp, NodeMemory, Deltaseconds);
	if (!IsFlying)
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
}
