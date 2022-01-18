// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UIProjectHUD.generated.h"

class UMainMenuUserWidget;
class UInGameHUDUserWidget;
class AUIProjectCharacter;

UCLASS()
class AUIProjectHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	UWorld* GameWorld;

	UPROPERTY()
	APlayerController* PlayerController;

	UPROPERTY()
	AUIProjectCharacter* Player;

public:

	AUIProjectHUD();

	/*Classes*/
	UPROPERTY(EditDefaultsOnly, Category="Widget Class")
	TSubclassOf<UUserWidget> MainMenuClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widget Class")
	TSubclassOf<UUserWidget> SettingsMenuClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widget Class")
	TSubclassOf<UUserWidget> InGameHUDClass;

	UPROPERTY(EditAnywhere, Category = "Level Names")
	FName MainMenuLvlName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Names")
    FName GameLvlName;

	/*Instances*/
	UPROPERTY()
	UMainMenuUserWidget* MainMenu;

	UPROPERTY()
	UInGameHUDUserWidget* InGameHUD;
	
	
	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;
	
	virtual void BeginPlay() override;

	void ShowMainMenu();
	void ShowSettingsMenu();
	void ShowInGameHUD();

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

	UPROPERTY()
	UUserWidget* LastWidgetAddedToViewport;

	void UpdateLastAddedWidgetToViewport(UUserWidget* LastWidget);

};

