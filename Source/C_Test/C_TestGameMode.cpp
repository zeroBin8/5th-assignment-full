// Copyright Epic Games, Inc. All Rights Reserved.

#include "C_TestGameMode.h"
#include "C_TestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AC_TestGameMode::AC_TestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
