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

float AMovePlatform::GetDist(const EAxis::Type& Axis, const FVector& Vec1, const FVector &Vec2)
{
	switch (Axis)
	{
	case EAxis::X:
		return FMath::Abs(Vec1.X - Vec2.X);
		break;
	case EAxis::Y:
		return FMath::Abs(Vec1.Y - Vec2.Y);
		break;
	case EAxis::Z:
		return FMath::Abs(Vec1.Z - Vec2.Z);
		break;
	default:
		break;
	}

	return 0;
}

void AMovePlatform::Move(float DeltaTime)
{
	FVector MoveVector = FVector::ZeroVector;
	MoveVector.SetComponentForAxis(MoveAxis, MoveSpeed);

	AddActorLocalOffset(MoveVector * DeltaTime);

	float Dist = GetDist(MoveAxis, GetActorLocation(), StartLocation);

	UE_LOG(LogTemp, Warning, TEXT("Dist = %f"), Dist);

	if (MoveSpeed > 0 && Dist >= MaxRange)
	{
		MoveSpeed = -MoveSpeed;
	}

	else if (MoveSpeed < 0 && Dist <= 1)
	{
		MoveSpeed = -MoveSpeed;
	}
}

void AMovePlatform::InitData()
{
	MoveSpeed = FMath::RandRange(MOVE_SPEED_MIN, MOVE_SPEED_MAX);
	MaxRange = FMath::RandRange(MOVE_RANGE_MIN, MOVE_RANGE_MAX);
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
