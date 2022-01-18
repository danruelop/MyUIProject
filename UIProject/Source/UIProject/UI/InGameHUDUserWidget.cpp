// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameHUDUserWidget.h"
#include <Components/ProgressBar.h>
#include "UIProject/UIProjectCharacter.h"
#include "UIProject/Public/HealthActorComponent.h"


void UInGameHUDUserWidget::Init(AUIProjectCharacter* Player)
{
	if (IsValid(HealthBar) && IsValid(Player))
	{
		Player->HealthComponent->OnHealthUpdateDelegate.AddDynamic(this, &UInGameHUDUserWidget::UpdateHealthUI);
	}
}

void UInGameHUDUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	HealthBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HealthBar")));
}

void UInGameHUDUserWidget::UpdateHealthUI(float _Health, float _NormalizedHealth)
{
	HealthBar->SetPercent(_NormalizedHealth);
}

