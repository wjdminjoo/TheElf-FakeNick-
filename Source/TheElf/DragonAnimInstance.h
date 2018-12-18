// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TheElf.h"
#include "Animation/AnimInstance.h"
#include "DragonAnimInstance.generated.h"


DECLARE_MULTICAST_DELEGATE(FOnNextAttackCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnAttackHitCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnFireAttackDelegate);
DECLARE_MULTICAST_DELEGATE(FOnFlyDelegate);




/**
 * 
 */
UCLASS()
class THEELF_API UDragonAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UDragonAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	void PlayAttackMontage();
	void PlayFireMontage();
	void PlayFlyMontage();
	void JumpToAttackMontageSection(int32 NewSection);
	void SetDeadAnim() { IsDead = true; }

	FOnNextAttackCheckDelegate OnNextAttackCheck;
	FOnAttackHitCheckDelegate OnAttackHitCheck;
	FOnFireAttackDelegate OnFireAttack;
	FOnFlyDelegate OnFly;
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		float CurrentPawnSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool IsInAir;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool IsFly;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		UAnimMontage* AttackMontage;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		UAnimMontage* FireMontage;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		UAnimMontage* FlyMontage;
	UFUNCTION()
		void AnimNotify_NextAttackCheck();
	UFUNCTION()
		void AnimNotify_AttackHitCheck();
	UFUNCTION()
		void AnimNotify_FireAttackCheck();
	UFUNCTION()
		void AnimNotify_FlyCheck();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool IsDead;

	FName GetAttackMontageSectionName(int32 Section);
};
