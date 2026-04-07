// Fill out your copyright notice in the Description page of Project Settings.


#include "MovePlatform.h"

#include <typeinfo>

// Sets default values
AMovePlatform::AMovePlatform()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovePlatform::BeginPlay()
{
	Super::BeginPlay();
	InitData();
	SetStartLocation();
}

// Called every frame
void AMovePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);
}

float AMovePlatform::GetDistance(const EAxis::Type& Axis, const FVector& Vec1, const FVector &Vec2)
{
	return FMath::Abs(Vec1.GetComponentForAxis(Axis) - Vec2.GetComponentForAxis(Axis));
}

void AMovePlatform::Move(float DeltaTime)
{
	FVector MoveVector = FVector::ZeroVector;
	MoveVector.SetComponentForAxis(MoveAxis, MoveSpeed * MoveDirection);

	AddActorLocalOffset(MoveVector * DeltaTime);

	
	float Distance = GetDistance(MoveAxis, GetActorLocation(), StartLocation);
	UE_LOG(LogTemp, Warning, TEXT("Distance: %f"), Distance);

	if (MoveDirection > 0 && Distance >= MaxRange)
	{
		FVector CorrectedLocation = GetActorLocation();
		CorrectedLocation.SetComponentForAxis(MoveAxis, StartLocation.GetComponentForAxis(MoveAxis) + MaxRange);
		SetActorLocation(CorrectedLocation);
		
		// to -
		MoveDirection = -MoveDirection;
	}
	else if (MoveDirection < 0 && (Distance <= 1.0f || GetActorLocation().GetComponentForAxis(MoveAxis) < StartLocation.GetComponentForAxis(MoveAxis)))
	{
		FVector CorrectedLocation = GetActorLocation();
		CorrectedLocation.SetComponentForAxis(MoveAxis, StartLocation.GetComponentForAxis(MoveAxis));
		SetActorLocation(CorrectedLocation);
		
		// to +
		MoveDirection = -MoveDirection;
	}
}

void AMovePlatform::InitData()
{
	MoveSpeed = FMath::RandRange(MOVE_SPEED_MIN, MOVE_SPEED_MAX);
	MaxRange = FMath::RandRange(MOVE_RANGE_MIN, MOVE_RANGE_MAX);
	MoveDirection = 1;
	int RandomAxis = FMath::RandRange((int)EAxis::Type::X, (int)EAxis::Type::Z);
	MoveAxis = static_cast<EAxis::Type>(RandomAxis);
}

void AMovePlatform::SetStartLocation()
{
	if (!bUseCustomStartLocation)
	{
		StartLocation = GetActorLocation();
	}

	SetActorLocation(StartLocation);
}
