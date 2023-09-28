// HotlineDungeon


#include "HotlineDungeon/Public/Combat/CombatComponent.h"
#include "HotlineDungeon/Public/Combat/DamageComponent.h"
#include "HotlineDungeon/Public/Weapon/Weapon.h"

UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCombatComponent::DummyAttack() const
{
	if (!Weapon)
	{
		UE_LOG(LogCombat, Warning, TEXT("Weapon isn't set"))
		return;
	}

	Cast<AWeapon>(Weapon)->Attack();
}


void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

