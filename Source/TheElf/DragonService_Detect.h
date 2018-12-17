// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TheElf.h"
#include "BehaviorTree/BTService.h"
#include "DragonService_Detect.generated.h"

/**
 * 
 */
UCLASS()
class THEELF_API UDragonService_Detect : public UBTService
{
	GENERATED_BODY()
	
	
public:
	UDragonService_Detect();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory,
		float DeltaSeconds) override;
	
};
