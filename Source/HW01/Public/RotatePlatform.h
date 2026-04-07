// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatePlatform.generated.h"

UCLASS()
class HW01_API ARotatePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotatePlatform();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:
	void Rotate(float DeltaTime);
	void InitData();
	void SetStartLocation();
	
	UPROPERTY(EditAnywhere, Category = "Rotation")
	float RotateAngle;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	float RotateSpeed;

	UPROPERTY(EditAnywhere, Category = "Rotation")	
	TEnumAsByte<EAxis::Type> RotateAxis;
	
	UPROPERTY(EditAnywhere, Category = "CustomStartLocation")
	bool bUseCustomStartLocation;
	
	UPROPERTY(EditAnywhere, Category = "CustomStartLocation")
	FVector StartLocation;
	

private:
	const float ROTATE_ANGLE_MIN = 30.f;
	const float ROTATE_ANGLE_MAX = 90.f;

	const float ROTATE_SPEED_MIN = 0.5f;
	const float ROTATE_SPEED_MAX = 1.5f;
		
};
