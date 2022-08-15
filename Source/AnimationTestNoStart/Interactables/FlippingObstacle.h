// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FlippingObstacle.generated.h"

UCLASS()
class ANIMATIONTESTNOSTART_API AFlippingObstacle : public AActor
{
	GENERATED_BODY()
	
	public:	
	// Sets default values for this actor's properties
	AFlippingObstacle();
	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	class UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	class USphereComponent* Sphere;
};
