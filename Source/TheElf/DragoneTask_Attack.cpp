// Fill out your copyright notice in the Description page of Project Settings.

#include "DragoneTask_Attack.h"
#include "MyAIController.h"
#include "DragonCharacter.h"


UDragoneTask_Attack::UDragoneTask_Attack() {
	bNotifyTick = true;
	IsAttacking = false;
}


EBTNodeResult::Type UDragoneTask_Attack::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto MyCharacter = Cast<ADragonCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == MyCharacter) return EBTNodeResult::Failed;

	MyCharacter->Attack();
	IsAttacking = true;
	MyCharacter->OnAttackEnd.AddLambda([this]()->void {
		IsAttacking = false;
	});

	return EBTNodeResult::InProgress;
}

void UDragoneTask_Attack::TickTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float Deltaseconds)
{
	Super::TickTask(OwnerComp, NodeMemory, Deltaseconds);
	if(!IsAttacking)
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
}
