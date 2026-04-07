// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovePlatform.generated.h"

UCLASS()
class HW01_API AMovePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovePlatform();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:
	void Move(float DeltaTime);
	void InitData();
	void SetStartLocation();
	float GetDist(const EAxis::Type& Axis, const FVector& Vec1, const FVector &Vec2);

	UPROPERTY(EditAnywhere, Category = "Move")
	float MoveSpeed;
	
	UPROPERTY(EditAnywhere, Category = "Move")
	float MaxRange;
	
	UPROPERTY(EditAnywhere, Category = "Move")
	TEnumAsByte<EAxis::Type> MoveAxis;

	UPROPERTY(EditAnywhere, Category = "CustomStartLocation")
	bool bUseCustomStartLocation;
	
	UPROPERTY(EditAnywhere, Category = "CustomStartLocation")
	FVector StartLocation;
private:
	const float MOVE_SPEED_MIN = 40.f;
	const float MOVE_SPEED_MAX = 80.f;

	const float MOVE_RANGE_MIN = 70.f;
	const float MOVE_RANGE_MAX = 140.f;
};
