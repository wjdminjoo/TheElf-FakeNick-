// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

const FName AMyAIController::HomePosKey(TEXT("HomePos"));
const FName AMyAIController::PatrolPosKey(TEXT("PatrolPos"));
const FName AMyAIController::TargetKey(TEXT("Target"));



AMyAIController::AMyAIController() {
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("BlackboardData'/Game/BlackBoard/DragonBB.DragonBB'"));
	if (BBObject.Succeeded()) BBAsset = BBObject.Object;

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("BehaviorTree'/Game/BehaviorTree/DragonBT.DragonBT'"));
	if (BTObject.Succeeded()) BTAsset = BTObject.Object;
}

void AMyAIController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);
	if (UseBlackboard(BBAsset, Blackboard)) {
		Blackboard->SetValueAsVector(HomePosKey, InPawn->GetActorLocation());
		if (!RunBehaviorTree(BTAsset)) {
			ABLOG(Error, TEXT("AICONTROLLER COULDNT RUN BEHAVIOR TREE"));
		}
	}
}

