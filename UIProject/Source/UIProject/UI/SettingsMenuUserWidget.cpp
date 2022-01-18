// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsMenuUserWidget.h"
#include <Components/Slider.h>
#include <Components/CheckBox.h>

void USettingsMenuUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	MusicSlider = Cast<USlider>(GetWidgetFromName(TEXT("SLR_Music")));
	SFXSlider = Cast<USlider>(GetWidgetFromName(TEXT("SLR_SFX")));
	SoundMuteCheckBox = Cast<UCheckBox>(GetWidgetFromName(TEXT("CBX_SoundMute")));
}
