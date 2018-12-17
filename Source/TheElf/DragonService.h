// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TheElf.h"
#include "BehaviorTree/BTService.h"
#include "DragonService.generated.h"

/**
 * 
 */
UCLASS()
class THEELF_API UDragonService : public UBTService
{
	GENERATED_BODY()
	
public:
	UDragonService();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
	
};
