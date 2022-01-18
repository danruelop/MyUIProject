// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SettingsMenuUserWidget.generated.h"

class USlider;
class UCheckBox;
/**
 * 
 */
UCLASS()
class UIPROJECT_API USettingsMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()

	public:

	UPROPERTY()
	USlider* MusicSlider;

	UPROPERTY()
	USlider* SFXSlider;

	UPROPERTY()
	UCheckBox* SoundMuteCheckBox;

	virtual void NativeConstruct() override;
	
};
