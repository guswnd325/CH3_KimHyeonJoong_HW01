#pragma once

#include "CoreMinimal.h"

class HW01_API FUtils
{
public:
	FUtils() = delete;

	static FVector GetRandVector(const FVector& Min, const FVector& Max)
	{
		return FVector(
			FMath::FRandRange(Min.X, Max.X),
			FMath::FRandRange(Min.Y, Max.Y),
			FMath::FRandRange(Min.Z, Max.Z)
		);
	}
};