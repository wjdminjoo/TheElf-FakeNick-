// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TheElf.h"
#include "BehaviorTree/BTDecorator.h"
#include "DragonDecorator.generated.h"

/**
 * 
 */
UCLASS()
class THEELF_API UDragonDecorator : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UDragonDecorator();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp,
		uint8* NodeMemory) const override;
	
	
};
