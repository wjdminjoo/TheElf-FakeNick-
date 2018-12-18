// Fill out your copyright notice in the Description page of Project Settings.

#include "DragonTask_Fire.h"
#include "MyAIController.h"
#include "DragonCharacter.h"

UDragonTask_Fire::UDragonTask_Fire() {
	bNotifyTick = true;
	IsAttacking = false;
}

EBTNodeResult::Type UDragonTask_Fire::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto MyCharacter = Cast<ADragonCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == MyCharacter) return EBTNodeResult::Failed;

	MyCharacter->Fire();
	IsAttacking = true;
	MyCharacter->OnAttackEnd.AddLambda([this]()->void {
		IsAttacking = false;
	});

	return EBTNodeResult::InProgress;
}

void UDragonTask_Fire::TickTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float Deltaseconds)
{
	Super::TickTask(OwnerComp, NodeMemory, Deltaseconds);
	if (!IsAttacking)
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
}
