// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TheElf.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class THEELF_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
	

public:
	AMyAIController();
	virtual void Possess(APawn* InPawn) override;
	
	static const FName HomePosKey;
	static const FName PatrolPosKey;
	static const FName TargetKey;
	
private:
	UPROPERTY()
		class UBehaviorTree* BTAsset;
	UPROPERTY()
		class UBlackboardData* BBAsset;
};
