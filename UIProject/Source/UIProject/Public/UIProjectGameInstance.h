// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UIProjectGameInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPointsUpdate, int32, Points);

/**
 * 
 */
UCLASS()
class UIPROJECT_API UUIProjectGameInstance : public UGameInstance
{
	GENERATED_BODY()

	private:

	UPROPERTY()
	float MusicVolume;

	UPROPERTY()
	float SFXVolume;

	UPROPERTY()
	int32 Points;

	public:

	UPROPERTY()
	FOnPointsUpdate OnPointsUpdateDelegate;
	UUIProjectGameInstance();

	UFUNCTION(BlueprintCallable)
	float GetMusicVolume();

	UFUNCTION()
	void SetMusicVolume(float Volume);

	UFUNCTION(BlueprintCallable)
	float GetSFXVolume();

	UFUNCTION()
	void SetSFXVolume(float Volume);

	UFUNCTION()
	int32 GetPoints();

	UFUNCTION()
	void SetPoints(int32 _Points);

	UFUNCTION()
	void AddPoints(int32 _Points = 1);

	UFUNCTION()
	void UpdatePoints();
};
