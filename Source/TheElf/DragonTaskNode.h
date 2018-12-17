// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "DragonTaskNode.generated.h"

/**
 * 
 */
UCLASS()
class THEELF_API UDragonTaskNode : public UBTTaskNode
{
	GENERATED_BODY()
	
	
public:
	UDragonTaskNode();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
