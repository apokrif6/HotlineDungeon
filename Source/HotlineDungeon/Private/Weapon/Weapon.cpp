// HotlineDungeon


#include "HotlineDungeon/Public/Weapon/Weapon.h"

AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AWeapon::Attack()
{
	GEngine->AddOnScreenDebugMessage(2, 2.f, FColor::Purple, "Make attack");
}
