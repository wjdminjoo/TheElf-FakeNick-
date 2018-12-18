// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "DragonDecorator_RangeCheck.generated.h"

/**
 * 
 */
UCLASS()
class THEELF_API UDragonDecorator_RangeCheck : public UBTDecorator
{
	GENERATED_BODY()
	
	
public:
	UDragonDecorator_RangeCheck();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp,
		uint8* NodeMemory) const override;


	
};
