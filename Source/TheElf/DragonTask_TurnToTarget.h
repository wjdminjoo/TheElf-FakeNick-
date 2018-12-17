// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TheElf.h"
#include "BehaviorTree/BTTaskNode.h"
#include "DragonTask_TurnToTarget.generated.h"

/**
 * 
 */
UCLASS()
class THEELF_API UDragonTask_TurnToTarget : public UBTTaskNode
{
	GENERATED_BODY()
	
	
public:
	UDragonTask_TurnToTarget();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp,
		uint8* NodeMemory) override;
	
	
};
