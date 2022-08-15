// Fill out your copyright notice in the Description page of Project Settings.


#include "WorkerAnim.h"
#include "../Characters/WorkerCharacter.h"

UWorkerAnim::UWorkerAnim()
{
        Speed = 0.0f;
        bIsInFrontOfCube = false;
        bIsOnTopOfBall = false;
}

void UWorkerAnim::NativeUpdateAnimation(float DeltaSeconds)
{
        APawn* PawnOwner = TryGetPawnOwner(); 
        AWorkerCharacter* WorkerCharacter = Cast<AWorkerCharacter>(PawnOwner);
        if(PawnOwner)
        {
              Speed = PawnOwner->GetVelocity().Size();
        }
}