// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuUserWidget.h"
#include "Components/Button.h"
#include <Kismet/GameplayStatics.h>
#include "../UI/UIProjectHUD.h"

void UMainMenuUserWidget::Init()
{
	FInputModeUIOnly inputMode;
	inputMode.SetWidgetToFocus(this->TakeWidget());
	inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	if (GetWorld())
	{
		APlayerController* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

		if (IsValid(playerController))
		{
			playerController->bShowMouseCursor = true;
			playerController->SetInputMode(inputMode);
			GameHUD = Cast<AUIProjectHUD>(playerController->GetHUD());
		}
	}
}

void UMainMenuUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	StartGameButton = Cast<UButton>(GetWidgetFromName(TEXT("BTN_StartGame")));
	SettingsButton = Cast<UButton>(GetWidgetFromName(TEXT("BTN_Settings")));
	ExitGameButton = Cast<UButton>(GetWidgetFromName(TEXT("BTN_ExitGame")));

	if (StartGameButton)
	{
		StartGameButton->OnClicked.AddDynamic(this, &UMainMenuUserWidget::StartGameButton_OnClicked);
	}
	if (ExitGameButton)
	{
		ExitGameButton->OnClicked.AddDynamic(this, &UMainMenuUserWidget::ExitGameButton_OnClicked);
	}
}

void UMainMenuUserWidget::StartGameButton_OnClicked()
{
	if (IsValid(GameHUD) && IsValid(GameHUD->GameWorld) && IsValid(GameHUD->PlayerController))
	{
		FInputModeGameOnly inputMode;
		GameHUD->PlayerController->SetInputMode(inputMode);
		UGameplayStatics::OpenLevel(GameHUD->GameWorld, GameHUD->GameLvlName, true);
	}
}

void UMainMenuUserWidget::ExitGameButton_OnClicked()
{
	if (IsValid(GameHUD) && IsValid(GameHUD->GameWorld) && IsValid(GameHUD->PlayerController))
	{
		UKismetSystemLibrary::QuitGame(GameHUD->GameWorld, GameHUD->PlayerController, EQuitPreference::Quit, true);
	}
}
