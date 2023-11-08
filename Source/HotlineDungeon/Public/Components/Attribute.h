// HotlineDungeon

#pragma once

#include "Attribute.generated.h"

USTRUCT()
struct FBaseAttribute
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Values)
	float BaseValue;

	UPROPERTY(EditAnywhere, Category = Values)
	float MaxValue;

	FBaseAttribute()
	{
		BaseValue = 100.f;
		MaxValue = 100.f;
	}

	FBaseAttribute(const float NewBaseValue, const float NewMaxValue)
	{
		BaseValue = NewBaseValue;
		MaxValue = NewMaxValue;
	}
};

UENUM(BlueprintType)
enum EAttribute
{
	Health UMETA(DisplayName = "Health"),
	Stamina UMETA(DisplayName = "Stamina"),
};