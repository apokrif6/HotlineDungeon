// HotlineDungeon

#pragma once

#include "CoreMinimal.h"
#include "Attribute.h"
#include "Components/ActorComponent.h"
#include "AttributesComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCurrentAttributeValueChange, EAttribute, CurrentAttribute, float,
                                             CurrentValue);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class HOTLINEDUNGEON_API UAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAttributesComponent();

	float GetCurrentAttributeValue(const EAttribute Attribute);

	float GetBaseAttributeValue(const EAttribute Attribute);

	float GetMaxAttributeValue(const EAttribute Attribute);

	void ModifyCurrentAttributeValue(const EAttribute Attribute, const float ModifierValue);

	void InitializeAttributes();

	void SetBaseAttributeValue(const EAttribute Attribute, const float BaseValue);

	void SetMaxAttributeValue(const EAttribute Attribute, const float MaxValue);

	void TakeDamage(const float Damage);

	void RegenerateCurrentAttributeValue(const EAttribute Attribute);

	FOnCurrentAttributeValueChange OnCurrentAttributeValueChange;

protected:
	UPROPERTY(EditAnywhere, Category = "Attributes")
	TMap<TEnumAsByte<EAttribute>, FBaseAttribute> Attributes;

	UPROPERTY(EditAnywhere, Category = "Stamina")
	float StaminaToRegenerate = 5.0f;

	UPROPERTY(EditAnywhere, Category = "Stamina")
	float StaminaRegenerateRate = 0.1f;

private:
	void SetCurrentAttributeValue(const EAttribute Attribute, const float Value);

	TMap<EAttribute, float> CurrentAttributes;

	FTimerHandle RegenerateAttributeValueTimer;

	UFUNCTION()
	void RegenerateStamina();
};
