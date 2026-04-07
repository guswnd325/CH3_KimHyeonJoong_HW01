// Fill out your copyright notice in the Description page of Project Settings.


#include "PhasePlatform.h"

// Sets default values
APhasePlatform::APhasePlatform()
{
 	PrimaryActorTick.bCanEverTick = false;
}

void APhasePlatform::BeginPlay()
{
	Super::BeginPlay();
	InitData();
	SetStartLocation();
	
	GetWorldTimerManager().SetTimer(PhaseTimer, this, &APhasePlatform::Disappear, PhaseTime);
}

void APhasePlatform::Disappear()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	
	GetWorldTimerManager().SetTimer(PhaseTimer, this, &APhasePlatform::Appear, PhaseTime);
}

void APhasePlatform::Appear()
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);

	GetWorldTimerManager().SetTimer(PhaseTimer, this, &APhasePlatform::Disappear, PhaseTime);
}

void APhasePlatform::InitData()
{
	PhaseTime = FMath::RandRange(PHASE_MIN, PHASE_MAX);
}

void APhasePlatform::SetStartLocation()
{
	if (!bUseCustomStartLocation)
	{
		StartLocation = GetActorLocation();
	}
	
	SetActorLocation(StartLocation);
}


