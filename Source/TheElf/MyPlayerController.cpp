// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"

void AMyPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}


void AMyPlayerController::Possess(APawn * aPawn)
{
	Super::Possess(aPawn);
}


void AMyPlayerController::BeginPlay() {
	Super::BeginPlay();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}