// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameHUDUserWidget.h"
#include <Components/ProgressBar.h>

#include "UIProjectGameInstance.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "UIProject/UIProjectCharacter.h"
#include "UIProject/Public/HealthActorComponent.h"


void UInGameHUDUserWidget::Init(AUIProjectCharacter* Player)
{
	if(IsValid(Player))
	{
		if (IsValid(HealthBar))
		{
			Player->HealthComponent->OnHealthUpdateDelegate.AddDynamic(this, &UInGameHUDUserWidget::UpdateHealthUI);
		}
		if(IsValid(AmmoText))
		{
			Player->OnAmmoUpdateDelegate.AddDynamic(this, &UInGameHUDUserWidget::UpdateAmmoUI);
		}
		Player->Recharge();

		UUIProjectGameInstance* GameInstance = Cast<UUIProjectGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
		if(IsValid(GameInstance))
		{
			GameInstance->OnPointsUpdateDelegate.AddDynamic(this, &UInGameHUDUserWidget::UpdatePointsUI);
			GameInstance->UpdatePoints();
		}
	}
}

void UInGameHUDUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	HealthBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HealthBar")));
	AmmoText = Cast<UTextBlock>(GetWidgetFromName(TEXT("TXT_Ammo")));
	PointsCounterText = Cast<UTextBlock>(GetWidgetFromName(TEXT("TXT_PointsCounter")));
}

void UInGameHUDUserWidget::UpdateHealthUI(float _Health, float _NormalizedHealth)
{
	HealthBar->SetPercent(_NormalizedHealth);
}

void UInGameHUDUserWidget::UpdateAmmoUI(int32 CurrentAmmo, int32 MaxAmmo)
{
	const FString stringText = FString::FromInt(CurrentAmmo) + "/" + FString::FromInt(MaxAmmo);
	const FText text = FText::FromString(stringText);
	AmmoText->SetText(text);
}

void UInGameHUDUserWidget::UpdatePointsUI(int32 Points)
{
	const FString stringText = FString::FromInt(Points);
	const FText text = FText::FromString(stringText);
	PointsCounterText->SetText(text);
}
