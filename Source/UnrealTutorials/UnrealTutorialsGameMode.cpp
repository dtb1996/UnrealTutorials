// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealTutorialsGameMode.h"
#include "UnrealTutorialsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealTutorialsGameMode::AUnrealTutorialsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
