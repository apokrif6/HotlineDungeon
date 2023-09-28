// HotlineDungeon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class HOTLINEDUNGEON_API AWeapon : public AActor
{
	GENERATED_BODY()

public:
	AWeapon();

	void Attack();
};
