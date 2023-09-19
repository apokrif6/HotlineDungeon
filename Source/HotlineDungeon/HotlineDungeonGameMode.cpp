// Copyright Epic Games, Inc. All Rights Reserved.

#include "HotlineDungeonGameMode.h"
#include "HotlineDungeonCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHotlineDungeonGameMode::AHotlineDungeonGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
