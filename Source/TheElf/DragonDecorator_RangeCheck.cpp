// Fill out your copyright notice in the Description page of Project Settings.

#include "DragonDecorator_RangeCheck.h"
#include "MyAIController.h"
#include "MyCharacter.h"
#include "DragonCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UDragonDecorator_RangeCheck::UDragonDecorator_RangeCheck() {
	NodeName = TEXT("RangeCheck");
}

bool UDragonDecorator_RangeCheck::CalculateRawConditionValue(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory) const
{

	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn) return false;
	auto Target = Cast<AMyCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AMyAIController::TargetKey));
	if (nullptr == Target) return false;

	bResult = (Target->GetDistanceTo(ControllingPawn) < 1500.0f);
	if((Target->GetDistanceTo(ControllingPawn) < 1300.0f))
		bResult = (Target->GetDistanceTo(ControllingPawn) <= 750.0f);

	return bResult;
}
