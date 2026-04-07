// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovePlatform.h"
#include "PhasePlatform.h"
#include "RotatePlatform.h"
#include "PlatformType.h"
#include "Utils.h"
#include "GameFramework/Actor.h"
#include "PlatformSpawnner.generated.h"

UCLASS()
class HW01_API APlatformSpawnner : public AActor
{
	GENERATED_BODY()
public:	
	APlatformSpawnner();

	UPROPERTY(EditAnywhere, Category="Spawn Objects")
	TSubclassOf<AMovePlatform> MovePlatform;
	
	UPROPERTY(EditAnywhere, Category="Spawn Objects")
	TSubclassOf<ARotatePlatform> RotatePlatform;
	
	UPROPERTY(EditAnywhere, Category="Spawn Objects")
	TSubclassOf<APhasePlatform> PhasePlatform;
	
	UPROPERTY(EditAnywhere, Category="Location Limit")
	FVector LocationLimit_Min;	
	
	UPROPERTY(EditAnywhere, Category="Location Limit")
	FVector LocationLimit_Max;	
	
	UPROPERTY(EditAnywhere, Category="Rotation Limit")
	FRotator RotationLimit_Min;	
	
	UPROPERTY(EditAnywhere, Category="Rotation Limit")
	FRotator RotationLimit_Max;
	
	
protected:
	virtual void BeginPlay() override;
	
private:
	void SpawnPlatform(const EPlatformType &Type, const FVector &Location, const FRotator & Rotation);
};
