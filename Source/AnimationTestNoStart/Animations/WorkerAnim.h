// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "WorkerAnim.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONTESTNOSTART_API UWorkerAnim : public UAnimInstance
{
	GENERATED_BODY()
	public:
	UWorkerAnim();
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	float Speed;	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	bool bIsInFrontOfCube;	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	bool bIsOnTopOfBall;	
	/* Used to update the Characters speed */
	virtual void NativeUpdateAnimation(float DeltaSeconds);
};
