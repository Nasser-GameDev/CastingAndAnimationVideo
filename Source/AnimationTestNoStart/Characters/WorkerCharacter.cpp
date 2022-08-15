// Fill out your copyright notice in the Description page of Project Settings.


#include "WorkerCharacter.h"
#include "../Animations/WorkerAnim.h" // need this to set bIsInFrontOfCube and bIsOnTopOfBall to true and false
#include "../Interactables/FlippingObstacle.h" // need to include this since we cast to a AFlippingObstacle
#include "../Interactables/BalanceObstacle.h" // need to include this since we cast to a ABalanceObstacle

#include "Components/CapsuleComponent.h" // to use the capsule component in the Character class
#include "Components/SkeletalMeshComponent.h" // to use the SkeletalMesh Component in the Character class
#include "Camera/CameraComponent.h" // To adjust our camera viewport
#include "GameFramework/SpringArmComponent.h" // since we use a spring arm 
#include "Engine/World.h" // for the get world function 
// #include "Animation/AnimInstance.h"
// Sets default values
AWorkerCharacter::AWorkerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// Generate OverlapEvent when some actor overlaps with our Character Capsule 
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera "));
	SpringArm->SetupAttachment(RootComponent);
	CameraComponent->SetupAttachment(SpringArm);
	// Generate Begin Overlap function 
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this ,&AWorkerCharacter::MyOverlapFunction);
	// Generate End Overlap function
	CapsuleComponent->OnComponentEndOverlap.AddDynamic(this,&AWorkerCharacter::MyEndOverlapFunction);
}

// Called to bind functionality to input
void AWorkerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AWorkerCharacter::MoveForward);
}

void AWorkerCharacter::MoveForward(float AmountToMoveForward)
{
	AddMovementInput(GetActorForwardVector(), AmountToMoveForward);
}

void AWorkerCharacter::MyOverlapFunction(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	 AFlippingObstacle* RunTimeObstacle = Cast<AFlippingObstacle>(OtherActor);
	 if(RunTimeObstacle)
	 {
		UAnimInstance* CharacterAnimation =  Mesh->GetAnimInstance();
		UWorkerAnim* WorkerAnim = Cast<UWorkerAnim>(CharacterAnimation);
		if(WorkerAnim && GetWorld())
		{
			WorkerAnim->bIsInFrontOfCube = true;
		}

	 }
	 else 
	 {
		ABalanceObstacle* RunTimeBalanceObstacle = Cast<ABalanceObstacle>(OtherActor);
		if(RunTimeBalanceObstacle)
		{
			UAnimInstance* CharacterAnimation =  Mesh->GetAnimInstance();
			UWorkerAnim* WorkerAnim = Cast<UWorkerAnim>(CharacterAnimation);
			if(WorkerAnim && GetWorld())
			{
				WorkerAnim->bIsOnTopOfBall = true;
			}
		}
	 }
}

void AWorkerCharacter::MyEndOverlapFunction(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	 AFlippingObstacle* RunTimeObstacle = Cast<AFlippingObstacle>(OtherActor);
	 if(RunTimeObstacle)
	 {
		UAnimInstance* CharacterAnimation =  Mesh->GetAnimInstance();
		UWorkerAnim* WorkerAnim = Cast<UWorkerAnim>(CharacterAnimation);
		if(WorkerAnim && GetWorld())
		{
			WorkerAnim->bIsInFrontOfCube = false;
		}

	 }
	 else 
	 {
		ABalanceObstacle* RunTimeBalanceObstacle = Cast<ABalanceObstacle>(OtherActor);
		if(RunTimeBalanceObstacle)
		{
			UAnimInstance* CharacterAnimation =  Mesh->GetAnimInstance();
			UWorkerAnim* WorkerAnim = Cast<UWorkerAnim>(CharacterAnimation);
			if(WorkerAnim && GetWorld())
			{
				WorkerAnim->bIsOnTopOfBall = false;
			}
		}
	 }
}

