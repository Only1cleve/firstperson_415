// Copyright Epic Games, Inc. All Rights Reserved.

#include "firstperson_415GameMode.h"
#include "firstperson_415Character.h"
#include "UObject/ConstructorHelpers.h"

Afirstperson_415GameMode::Afirstperson_415GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
