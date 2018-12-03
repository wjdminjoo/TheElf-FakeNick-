// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TheElf.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class THEELF_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	virtual void PostInitializeComponents() override;
	virtual void Possess(APawn* aPawn) override;
	
protected:
	virtual void BeginPlay() override;
};
