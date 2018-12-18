// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "DragonDecorator_CanFly.generated.h"

/**
 * 
 */
UCLASS()
class THEELF_API UDragonDecorator_CanFly : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UDragonDecorator_CanFly();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp,
		uint8* NodeMemory) const override;
	
};
