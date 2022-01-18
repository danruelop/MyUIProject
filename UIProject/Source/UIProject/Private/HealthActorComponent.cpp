// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthActorComponent.h"

// Sets default values for this component's properties
UHealthActorComponent::UHealthActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	CurrentHealth = MaxHealth;
	NormalizedCurrentHealth = CurrentHealth / MaxHealth;
}


float UHealthActorComponent::GetMaxHealth()
{
	return MaxHealth;
}

float UHealthActorComponent::GetCurrentHealth()
{
	return CurrentHealth;
}

float UHealthActorComponent::GetNormalizedCurrentHealth()
{
	return NormalizedCurrentHealth;
}

void UHealthActorComponent::SetMaxHealth(float _MaxHealth)
{
	MaxHealth = _MaxHealth;
}

void UHealthActorComponent::SetCurrentHealth(float _CurrentHealth)
{
	CurrentHealth = _CurrentHealth;
	CurrentHealth = FMath::Clamp(CurrentHealth, 0.0f, MaxHealth);
	NormalizedCurrentHealth = CurrentHealth/MaxHealth;
	UpdateHealth();
}

void UHealthActorComponent::Damage(float _HealthAmount)
{
	float health = CurrentHealth - _HealthAmount;
	SetCurrentHealth(health);
}

void UHealthActorComponent::Heal(float _HealthAmount)
{
	float health = CurrentHealth + _HealthAmount;
	SetCurrentHealth(health);
}

void UHealthActorComponent::UpdateHealth()
{
	OnHealthUpdateDelegate.Broadcast(CurrentHealth, NormalizedCurrentHealth);
}

// Called when the game starts
void UHealthActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

