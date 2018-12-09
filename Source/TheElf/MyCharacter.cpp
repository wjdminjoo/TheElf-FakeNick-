// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"
#include "MyArrow.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeLocation(FVector(0.0f, 100.0f, 50.0f));
	SpringArm->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MAIN_CHAR(TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin"));
	if (MAIN_CHAR.Succeeded()) GetMesh()->SetSkeletalMesh(MAIN_CHAR.Object);

	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	static ConstructorHelpers::FClassFinder<UAnimBlueprint> MAIN_ANIME(TEXT("/Game/Mannequin/Animations/ThirdPerson_AnimBP.ThirdPerson_AnimBP"));
	if (MAIN_ANIME.Succeeded()) GetMesh()->SetAnimInstanceClass(MAIN_ANIME.Class); 

	
	ArmLengthTo = 3.0f;
	ArmRotationSpeed = 10.0f;

	SetControlMode(EControlMode::THIRD);

	
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyCharacter::SetControlMode(EControlMode NewControlMode)
{
	CurrnetControlMode = NewControlMode;

	switch (CurrnetControlMode) {
	case EControlMode::THIRD:
		ArmLengthTo = 400.0f;
		SpringArm->bUseAttachParentBound = true;
		SpringArm->bInheritPitch = true;
		SpringArm->bInheritRoll = true;
		SpringArm->bInheritYaw = true;
		SpringArm->bDoCollisionTest = true;
		bUseControllerRotationYaw = true;
		GetCharacterMovement()->bOrientRotationToMovement = true;
		GetCharacterMovement()->bUseControllerDesiredRotation = false;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
		break;
	case EControlMode::FOCUS:
		ArmLengthTo = 100.0f;
		SpringArm->bUseAttachParentBound = true;
		SpringArm->bInheritPitch = true;
		SpringArm->bInheritRoll = true;
		SpringArm->bInheritYaw = true;
		SpringArm->bDoCollisionTest = true;
		bUseControllerRotationYaw = true;
		GetCharacterMovement()->bOrientRotationToMovement = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
		break;
	}
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SpringArm->TargetArmLength = FMath::FInterpTo(SpringArm->TargetArmLength, ArmLengthTo, DeltaTime, ArmLengthSpeed);

	switch (CurrnetControlMode)
	{
	case EControlMode::THIRD:
		SpringArm->RelativeRotation = FMath::RInterpTo(SpringArm->RelativeRotation, ArmRotationTo, DeltaTime, ArmRotationSpeed);
		break;
	case EControlMode::FOCUS:
		SpringArm->RelativeRotation = FMath::RInterpTo(SpringArm->RelativeRotation, ArmRotationTo, DeltaTime, ArmRotationSpeed);
		break;
	
	}

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("Focus"), EInputEvent::IE_Pressed, this, &AMyCharacter::Focus);
	PlayerInputComponent->BindAction(TEXT("Focus"), EInputEvent::IE_Released, this, &AMyCharacter::Focus);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AMyCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Pressed, this, &AMyCharacter::Fire);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMyCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMyCharacter::Turn);


}

void AMyCharacter::StartJump()
{
	bPressedJump = true;
}

void AMyCharacter::StopJump()
{
	bPressedJump = false;
}

void AMyCharacter::MoveForward(float NewAxisValue)
{
	switch (CurrnetControlMode)
	{
	case EControlMode::THIRD:
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), NewAxisValue);
		break;
	case EControlMode::FOCUS:
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), NewAxisValue);
		break;
	}
}

void AMyCharacter::MoveRight(float NewAxisValue)
{
	switch (CurrnetControlMode)
	{

	case EControlMode::THIRD:
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), NewAxisValue);
		break;
	case EControlMode::FOCUS:
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), NewAxisValue);
		break;
	}
}

void AMyCharacter::LookUp(float NewAxisValue)
{
	switch (CurrnetControlMode) {
		case EControlMode::THIRD:
			AddControllerPitchInput(NewAxisValue);
			break;
		case EControlMode::FOCUS:
			AddControllerPitchInput(NewAxisValue);
			break;
	}
}

void AMyCharacter::Turn(float NewAxisValue)
{
	switch (CurrnetControlMode) {
	case EControlMode::THIRD:
		AddControllerYawInput(NewAxisValue);
		break;
	case EControlMode::FOCUS:
		AddControllerYawInput(NewAxisValue);
		break;
	}

}

void AMyCharacter::Focus()
{
	switch (CurrnetControlMode)
	{
	case EControlMode::THIRD:
		GetController()->SetControlRotation(GetActorRotation());
		SetControlMode(EControlMode::FOCUS);
		break;

	case EControlMode::FOCUS:
		GetController()->SetControlRotation(SpringArm->RelativeRotation);
		SetControlMode(EControlMode::THIRD);
		break;
	}
}


void AMyCharacter::Fire()
{
	if (ArrowClass) {
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);
		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);
		FRotator MuzzleRotation = CameraRotation;
		MuzzleRotation.Pitch += 10.0f;
		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;
			AMyArrow* Arrow = World->SpawnActor<AMyArrow>(ArrowClass, MuzzleLocation, MuzzleRotation, SpawnParams);
			if (Arrow)
			{
				FVector LaunchDirection = MuzzleRotation.Vector();
				Arrow->ArrowInDirection(LaunchDirection);
			}
		}
	}
}

