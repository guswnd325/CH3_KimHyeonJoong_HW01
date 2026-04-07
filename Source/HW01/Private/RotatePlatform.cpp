#include "RotatePlatform.h"

ARotatePlatform::ARotatePlatform()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARotatePlatform::BeginPlay()
{
	Super::BeginPlay();
	InitData();
	SetStartLocation();
}

void ARotatePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Rotate(DeltaTime);
}

void ARotatePlatform::Rotate(float DeltaTime)
{
	float RotateValue = RotateAngle * RotateSpeed * DeltaTime;

	FRotator Rotator = FRotator::ZeroRotator;
	Rotator.SetComponentForAxis(RotateAxis, RotateValue);

	AddActorLocalRotation(Rotator);
}

void ARotatePlatform::InitData()
{
	RotateAngle = FMath::RandRange(ROTATE_ANGLE_MIN, ROTATE_ANGLE_MAX);
	RotateSpeed = FMath::RandRange(ROTATE_SPEED_MIN, ROTATE_SPEED_MAX);

	int randomRotate = FMath::RandRange((int)EAxis::X, (int)EAxis::Z);
	RotateAxis = static_cast<EAxis::Type>(randomRotate);
}

void ARotatePlatform::SetStartLocation()
{
	if (!bUseCustomStartLocation)
	{
		StartLocation = GetActorLocation();
	}
	
	SetActorLocation(StartLocation);
}
