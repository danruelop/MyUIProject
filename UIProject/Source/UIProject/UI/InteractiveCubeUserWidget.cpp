// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveCubeUserWidget.h"

#include "HealthActorComponent.h"
#include "InteractiveCube.h"
#include "Components/ProgressBar.h"

void UInteractiveCubeUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UInteractiveCubeUserWidget::Init(AInteractiveCube* InteractiveCubeOwner)
{
	HealthBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HealthBar")));
	
	if(IsValid(HealthBar) && IsValid(InteractiveCubeOwner))
	{
		InteractiveCubeOwner->HealthComp->OnHealthUpdateDelegate.AddDynamic(this, &UInteractiveCubeUserWidget::UpdateHealthUI);
		HealthBar->SetPercent(InteractiveCubeOwner->HealthComp->GetNormalizedCurrentHealth());
	}
}

void UInteractiveCubeUserWidget::UpdateHealthUI(float CurrentHealth, float NormalizedCurrentHealth)
{
	HealthBar->SetPercent(NormalizedCurrentHealth);
	PlayHurtAnim();
}
