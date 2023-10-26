// HotlineDungeon


#include "Components/AttributesComponent.h"
#include "HotlineDungeon/HotlineDungeonCharacter.h"

UAttributesComponent::UAttributesComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAttributesComponent::InitializeAttributes()
{
	TArray<TEnumAsByte<EAttribute>> OutKeys;
	Attributes.GetKeys(OutKeys);

	for (TEnumAsByte<EAttribute> OutKey : OutKeys)
	{
		SetCurrentAttributeValue(OutKey, Attributes.Find(OutKey)->BaseValue);
	}
}

float UAttributesComponent::GetCurrentAttributeValue(const EAttribute Attribute)
{
	const float* FoundAttributeValue = CurrentAttributes.Find(Attribute);
	if (!FoundAttributeValue) return 0.0f;

	return *FoundAttributeValue;
}

float UAttributesComponent::GetBaseAttributeValue(const EAttribute Attribute)
{
	return Attributes.Find(Attribute)->BaseValue;
}

float UAttributesComponent::GetMaxAttributeValue(const EAttribute Attribute)
{
	return Attributes.Find(Attribute)->MaxValue;
}

void UAttributesComponent::ModifyCurrentAttributeValue(const EAttribute Attribute, const float ModifierValue)
{
	if (ModifierValue == 0.0f) return;

	const float ClampedValue = FMath::Clamp(GetCurrentAttributeValue(Attribute) + ModifierValue, 0.0f,
	                                        GetMaxAttributeValue(Attribute));

	SetCurrentAttributeValue(Attribute, ClampedValue);
}

void UAttributesComponent::SetCurrentAttributeValue(const EAttribute Attribute, const float Value)
{
	CurrentAttributes.Add(Attribute, Value);

	OnCurrentAttributeValueChange.Broadcast(Attribute, Value);
}

void UAttributesComponent::SetBaseAttributeValue(const EAttribute Attribute, const float BaseValue)
{
	Attributes.Find(Attribute)->BaseValue = BaseValue;
}

void UAttributesComponent::SetMaxAttributeValue(const EAttribute Attribute, const float MaxValue)
{
	Attributes.Find(Attribute)->MaxValue = MaxValue;
}

void UAttributesComponent::TakeDamage(const float Damage)
{
	ModifyCurrentAttributeValue(Health, -Damage);

	if (GetCurrentAttributeValue(Health) > 0.0f) return;

	const AHotlineDungeonCharacter* ComponentOwner = Cast<AHotlineDungeonCharacter>(GetOwner());
	if (!ComponentOwner) return;

	//TODO
	//death
}

void UAttributesComponent::RegenerateCurrentAttributeValue(const EAttribute Attribute)
{
	switch (Attribute)
	{
	case Health: break;
	case Stamina:
		GetWorld()->GetTimerManager().SetTimer(RegenerateAttributeValueTimer, this, &ThisClass::RegenerateStamina,
		                                       StaminaRegenerateRate, true);
		break;
	default: ;
	}
}

void UAttributesComponent::RegenerateStamina()
{
	const float AttributeValue = GetCurrentAttributeValue(Stamina);

	if (AttributeValue >= GetMaxAttributeValue(Stamina))
	{
		GetWorld()->GetTimerManager().ClearTimer(RegenerateAttributeValueTimer);
		return;
	}

	ModifyCurrentAttributeValue(Stamina, StaminaToRegenerate);
}
