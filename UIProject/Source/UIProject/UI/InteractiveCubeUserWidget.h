// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractiveCubeUserWidget.generated.h"

class UProgressBar;
class AInteractiveCube;
/**
 * 
 */
UCLASS()
class UIPROJECT_API UInteractiveCubeUserWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	
	UPROPERTY()
	UProgressBar* HealthBar;
	
public:

	virtual void NativeConstruct() override;
	void Init(AInteractiveCube* InteractiveCubeOwner);
	UFUNCTION()
	void UpdateHealthUI(float CurrentHealth, float NormalizedCurrentHealth);
	UFUNCTION(BlueprintImplementableEvent)
	void PlayHurtAnim();
	
};
