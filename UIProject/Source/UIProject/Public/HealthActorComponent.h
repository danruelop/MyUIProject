// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthActorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthUpdate, float, Health, float, NormalizedHealth);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UIPROJECT_API UHealthActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY()
	FOnHealthUpdate OnHealthUpdateDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Parameters")
	float MaxHealth = 100.0f;


private:

	UPROPERTY()
	float CurrentHealth;

	UPROPERTY()
	float NormalizedCurrentHealth;

public:	
	// Sets default values for this component's properties
	UHealthActorComponent();

	UFUNCTION()
	float GetMaxHealth();

	UFUNCTION()
	float GetCurrentHealth();

	UFUNCTION()
	float GetNormalizedCurrentHealth();

	UFUNCTION()
	void SetMaxHealth(float _MaxHealth);

	UFUNCTION()
	void SetCurrentHealth(float _CurrentHealth);

	UFUNCTION()
	void Damage(float _HealthAmount);

	UFUNCTION()
	void Heal(float _HealthAmount);

	void UpdateHealth();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
