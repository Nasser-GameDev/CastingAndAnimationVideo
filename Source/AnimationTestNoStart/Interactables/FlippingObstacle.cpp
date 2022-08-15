// Fill out your copyright notice in the Description page of Project Settings.
#include "FlippingObstacle.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
// Sets default values
AFlippingObstacle::AFlippingObstacle()
{
	PrimaryActorTick.bCanEverTick = false;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Static Mesh"));
	StaticMesh->SetupAttachment(RootComponent);
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("My Sphere Component"));
	Sphere->InitSphereRadius(700.0f);
	Sphere->SetupAttachment(StaticMesh);
}
