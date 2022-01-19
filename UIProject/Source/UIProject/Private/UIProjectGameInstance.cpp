// Fill out your copyright notice in the Description page of Project Settings.


#include "UIProjectGameInstance.h"

UUIProjectGameInstance::UUIProjectGameInstance()
: Super()
{
	Points = 0;
}

float UUIProjectGameInstance::GetMusicVolume()
{
	return MusicVolume;
}

void UUIProjectGameInstance::SetMusicVolume(float Volume)
{
	MusicVolume = Volume;
}

float UUIProjectGameInstance::GetSFXVolume()
{
	return SFXVolume;
}

void UUIProjectGameInstance::SetSFXVolume(float Volume)
{
	SFXVolume = Volume;
}

int32 UUIProjectGameInstance::GetPoints()
{
	return Points;
}

void UUIProjectGameInstance::SetPoints(int32 _Points)
{
	Points = _Points;
	UpdatePoints();
}

void UUIProjectGameInstance::AddPoints(int32 _Points /*= 1*/)
{
	Points += _Points;
	UpdatePoints();
}

void UUIProjectGameInstance::UpdatePoints()
{
	OnPointsUpdateDelegate.Broadcast(Points);
}
