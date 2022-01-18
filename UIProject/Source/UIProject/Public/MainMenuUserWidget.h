// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuUserWidget.generated.h"

class UButton;
class AUIProjectHUD;
/**
 * 
 */
UCLASS()
class UIPROJECT_API UMainMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()

private:

	UPROPERTY()
	AUIProjectHUD* GameHUD;

public:

	UPROPERTY()
	UButton* StartGameButton;
	UPROPERTY()
	UButton* SettingsButton;
	UPROPERTY()
	UButton* ExitGameButton;

	void Init();
	virtual void NativeConstruct() override;

	private:

	UFUNCTION()
	void StartGameButton_OnClicked();

	UFUNCTION()
	void ExitGameButton_OnClicked();

	
};
