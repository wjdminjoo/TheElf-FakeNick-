// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "DragonTask_Fire.generated.h"

/**
 * 
 */
UCLASS()
class THEELF_API UDragonTask_Fire : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UDragonTask_Fire();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp,
		uint8* NodeMemory) override;

protected:
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp,
		uint8* NodeMemory, float Deltaseconds) override;

private:
	bool IsAttacking = false;
	
	
};
