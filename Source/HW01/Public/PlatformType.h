#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EPlatformType : uint8
{
	Move    UMETA(DisplayName = "Move Platform"),
	Rotate  UMETA(DisplayName = "Rotate Platform"),
	Phase   UMETA(DisplayName = "Phase Platform"),
};
