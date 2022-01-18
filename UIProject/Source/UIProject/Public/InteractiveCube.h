// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractiveCube.generated.h"

class AUIProjectCharacter;
class UUIProjectGameInstance;

UENUM()
enum class ECubeType
{
	Points,
	Heal,
	Damage,
};

UCLASS()
class UIPROJECT_API AInteractiveCube : public AActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECubeType CubeType = ECubeType::Points;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* CubeMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ColorParamName = FName(TEXT("BaseColor"));

private:

	UPROPERTY()
	AUIProjectCharacter* Player;

	UPROPERTY()
	UUIProjectGameInstance* GameInstance;

private:

	UPROPERTY()
	UMaterialInstanceDynamic* CubeDynamicMaterial;

public:	
	// Sets default values for this actor's properties
	AInteractiveCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnCubeHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
