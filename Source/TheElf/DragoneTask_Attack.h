// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TheElf.h"
#include "BehaviorTree/BTTaskNode.h"
#include "DragoneTask_Attack.generated.h"

/**
 * 
 */
UCLASS()
class THEELF_API UDragoneTask_Attack : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UDragoneTask_Attack();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp,
		uint8* NodeMemory) override;
	
protected:
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, 
		uint8* NodeMemory, float Deltaseconds) override;

private:
	bool IsAttacking = false;

};
