// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WorkerCharacter.generated.h"

UCLASS()
class ANIMATIONTESTNOSTART_API AWorkerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWorkerCharacter();


public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float AmountToMoveForward);
	UFUNCTION()
	void MyOverlapFunction(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void MyEndOverlapFunction(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UPROPERTY(EditAnywhere , BlueprintReadWrite)	
	class USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	class UCameraComponent* CameraComponent;	
};
