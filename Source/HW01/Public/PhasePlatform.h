// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhasePlatform.generated.h"

UCLASS()
class HW01_API APhasePlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APhasePlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void Disappear();
	void Appear();
	void InitData();
	void SetStartLocation();
	
	FTimerHandle PhaseTimer;

	UPROPERTY(EditAnywhere, Category = "Phase")
	float PhaseTime;
	
	UPROPERTY(EditAnywhere, Category = "CustomStartLocation")
	bool bUseCustomStartLocation;
	
	UPROPERTY(EditAnywhere, Category = "CustomStartLocation")
	FVector StartLocation;

private:
	const float PHASE_MIN = 4.f;
	const float PHASE_MAX = 8.f;
};
