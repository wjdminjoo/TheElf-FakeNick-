// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "DragoneTask_Fly.generated.h"

/**
 * 
 */
UCLASS()
class THEELF_API UDragoneTask_Fly : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UDragoneTask_Fly();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp,
		uint8* NodeMemory) override;
protected:
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp,
		uint8* NodeMemory, float Deltaseconds) override;

private:
	bool IsFlying = false;

	
	
};
