// Fill out your copyright notice in the Description page of Project Settings.

#include "DragonDecorator_CanFly.h"
#include "MyAIController.h"
#include "MyCharacter.h"
#include "DragonCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UDragonDecorator_CanFly::UDragonDecorator_CanFly() {
	NodeName = TEXT("CanFly");
}



bool UDragonDecorator_CanFly::CalculateRawConditionValue(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);
	
	bResult = FMath::RandRange(0, 1);
	return bResult;
}
