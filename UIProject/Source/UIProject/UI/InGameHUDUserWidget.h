// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameHUDUserWidget.generated.h"

class AUIProjectCharacter;
class UProgressBar;
class UTextBlock;
/**
 * 
 */
UCLASS()
class UIPROJECT_API UInGameHUDUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY()
	UProgressBar* HealthBar;
	UPROPERTY()
	UTextBlock* AmmoText;
	UPROPERTY()
	UTextBlock* PointsCounterText;

public:

	void Init(AUIProjectCharacter* Player);

	virtual void NativeConstruct() override;

	UFUNCTION()
	void UpdateHealthUI(float _Health, float _NormalizedHealth);
	UFUNCTION()
	void UpdateAmmoUI(int32 CurrentAmmo, int32 MaxAmmo);
	UFUNCTION()
	void UpdatePointsUI(int32 Points);

	
	
};
