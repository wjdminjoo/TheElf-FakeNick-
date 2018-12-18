// Fill out your copyright notice in the Description page of Project Settings.

#include "DragonAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"



UDragonAnimInstance::UDragonAnimInstance() {
	CurrentPawnSpeed = 0.0f;
	IsInAir = false;
	IsDead = false;
	IsFly = false;
	static ConstructorHelpers::FObjectFinder<UAnimMontage> ATTACK_MONTAGE(TEXT("AnimMontage'/Game/AnimationMTG/SK_DesertDragon_Skeleton_Montage.SK_DesertDragon_Skeleton_Montage'"));
	if (ATTACK_MONTAGE.Succeeded()) AttackMontage = ATTACK_MONTAGE.Object;
	
	static ConstructorHelpers::FObjectFinder<UAnimMontage> FIRE_MONTAGE(TEXT("AnimMontage'/Game/AnimationMTG/SK_DesertDragon_SpreadFIre.SK_DesertDragon_SpreadFIre'"));
	if (FIRE_MONTAGE.Succeeded()) FireMontage = FIRE_MONTAGE.Object;

	static ConstructorHelpers::FObjectFinder<UAnimMontage> FLY_MONTAGE(TEXT("AnimMontage'/Game/AnimationMTG/SK_DesertDragon_Fly.SK_DesertDragon_Fly'"));
	if (FLY_MONTAGE.Succeeded()) FlyMontage = FLY_MONTAGE.Object;
}

void UDragonAnimInstance::NativeUpdateAnimation(float DeltaSeconds) {
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (!::IsValid(Pawn)) return;

	if (!IsDead)
	{
		CurrentPawnSpeed = Pawn->GetVelocity().Size();
		auto Character = Cast<ACharacter>(Pawn);
		if (Character)
		{
			IsInAir = Character->GetMovementComponent()->IsFalling();
			IsFly = Character->GetMovementComponent()->IsFlying();
		}
	}
}

void UDragonAnimInstance::PlayAttackMontage()
{
	ABCHECK(!IsDead);
	Montage_Play(AttackMontage, 1.0f);

}

void UDragonAnimInstance::PlayFireMontage()
{
	ABCHECK(!IsDead);
	Montage_Play(FireMontage, 1.0f);

}
void UDragonAnimInstance::PlayFlyMontage()
{
	ABCHECK(!IsDead);
	Montage_Play(FlyMontage, 1.0f);
}

void UDragonAnimInstance::JumpToAttackMontageSection(int32 NewSection)
{
	ABCHECK(!IsDead);
	ABCHECK(Montage_IsPlaying(AttackMontage));
	Montage_JumpToSection(GetAttackMontageSectionName(NewSection), AttackMontage);
}

void UDragonAnimInstance::AnimNotify_AttackHitCheck()
{
	OnAttackHitCheck.Broadcast();
}

void UDragonAnimInstance::AnimNotify_FireAttackCheck()
{
	OnFireAttack.Broadcast();
}

void UDragonAnimInstance::AnimNotify_FlyCheck()
{
	OnFly.Broadcast();
}

void UDragonAnimInstance::AnimNotify_NextAttackCheck()
{
	OnNextAttackCheck.Broadcast();
}



FName UDragonAnimInstance::GetAttackMontageSectionName(int32 Section)
{
	ABCHECK(FMath::IsWithinInclusive<int32>(Section, 1, 4), NAME_None);
	return FName(*FString::Printf(TEXT("Attack%d"), Section));
}
