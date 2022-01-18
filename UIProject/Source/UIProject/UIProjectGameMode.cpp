// Copyright Epic Games, Inc. All Rights Reserved.

#include "UIProjectGameMode.h"
#include "UI/UIProjectHUD.h"
#include "UIProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUIProjectGameMode::AUIProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUIProjectHUD::StaticClass();
}
