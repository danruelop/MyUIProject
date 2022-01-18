// Copyright Epic Games, Inc. All Rights Reserved.

#include "UIProjectHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"
#include "MainMenuUserWidget.h"
#include <Kismet/GameplayStatics.h>
#include "UIProject/UIProjectCharacter.h"
#include "InGameHUDUserWidget.h"

AUIProjectHUD::AUIProjectHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;
}


void AUIProjectHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X),
										   (Center.Y + 20.0f));

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );
}

void AUIProjectHUD::BeginPlay()
{
	Super::BeginPlay();

	GameWorld = GetWorld();

	if(GameWorld)
	{
		PlayerController = UGameplayStatics::GetPlayerController(GameWorld, 0);
		FString CurrentLevelName = GameWorld->GetMapName();
		if (IsValid(MainMenuClass) && CurrentLevelName.Contains(MainMenuLvlName.ToString()))
		{
			ShowMainMenu();
		}
		else if (IsValid(InGameHUDClass) && CurrentLevelName.Contains(GameLvlName.ToString()))
		{
			Player = Cast<AUIProjectCharacter>(UGameplayStatics::GetPlayerCharacter(GameWorld, 0));
			if (IsValid(Player))
			{
				ShowInGameHUD();
			}
		}
	}
}

void AUIProjectHUD::ShowMainMenu()
{
	if (IsValid(MainMenuClass))
	{
		MainMenu = CreateWidget<UMainMenuUserWidget>(GameWorld, MainMenuClass);
		if (IsValid(MainMenu) && !MainMenu->IsInViewport())
		{
			UpdateLastAddedWidgetToViewport(MainMenu);
			MainMenu->AddToViewport();
			MainMenu->Init();
		}
	}
}

void AUIProjectHUD::ShowSettingsMenu()
{


}

void AUIProjectHUD::ShowInGameHUD()
{
	InGameHUD = CreateWidget<UInGameHUDUserWidget>(GameWorld, InGameHUDClass);
	if (IsValid(InGameHUD) && !InGameHUD->IsInViewport())
	{
		UpdateLastAddedWidgetToViewport(InGameHUD);
		InGameHUD->AddToViewport();
		InGameHUD->Init(Player);
	}
}

void AUIProjectHUD::UpdateLastAddedWidgetToViewport(UUserWidget* LastWidget)
{
	if(IsValid(LastWidgetAddedToViewport))
	{
		LastWidgetAddedToViewport->RemoveFromViewport();
	}
	LastWidgetAddedToViewport = LastWidget;
}
