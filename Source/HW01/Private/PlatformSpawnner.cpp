// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformSpawnner.h"

// Sets default values
APlatformSpawnner::APlatformSpawnner()
{
	PrimaryActorTick.bCanEverTick = false;
}

void APlatformSpawnner::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnPlatform(EPlatformType::Move, FUtils::GetRandVector(LocationLimit_Min, LocationLimit_Max), FUtils::GetRandRotator(RotationLimit_Min, RotationLimit_Max));
	SpawnPlatform(EPlatformType::Rotate, FUtils::GetRandVector(LocationLimit_Min, LocationLimit_Max), FUtils::GetRandRotator(RotationLimit_Min, RotationLimit_Max));
	SpawnPlatform(EPlatformType::Phase, FUtils::GetRandVector(LocationLimit_Min, LocationLimit_Max), FUtils::GetRandRotator(RotationLimit_Min, RotationLimit_Max));
	
}

void APlatformSpawnner::SpawnPlatform(const EPlatformType &Type, const FVector &Location, const FRotator &Rotation)
{
	UClass * Target = nullptr;
	switch (Type)
	{
	case EPlatformType::Move:
		Target = MovePlatform;
		break;
	case EPlatformType::Rotate:
		Target = RotatePlatform;
		break;
	case EPlatformType::Phase:
		Target = PhasePlatform;
		break;
	default:
		break;
	}
	
	if (Target == nullptr) return;
	
	GetWorld()->SpawnActor<AActor>(Target, Location, Rotation);
}
