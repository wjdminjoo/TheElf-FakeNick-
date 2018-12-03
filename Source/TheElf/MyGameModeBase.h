// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TheElf.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class THEELF_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

		AMyGameModeBase();
	
public:
	virtual void PostLogin(APlayerController* NewPlayer) override;
};
