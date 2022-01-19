// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveCube.h"
#include "../UIProjectProjectile.h"
#include <Kismet/GameplayStatics.h>
#include "../UIProjectCharacter.h"
#include "UIProjectGameInstance.h"
#include "HealthActorComponent.h"
#include "Components/WidgetComponent.h"
#include "UIProject/UI/InteractiveCubeUserWidget.h"

// Sets default values
AInteractiveCube::AInteractiveCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube Mesh"));
	this->AddOwnedComponent(CubeMesh);

	HealthComp = CreateDefaultSubobject<UHealthActorComponent>(TEXT("HealthComponent"));
	this->AddOwnedComponent(HealthComp);

	HealthWidgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthWidgetComponent"));
	if(HealthWidgetComp)
	{
		static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClassFinder(TEXT("/Game/UI/BP_InteractiveCubeUserWidget"));
		HealthWidgetComp->SetWidgetClass(WidgetClassFinder.Class);
		HealthWidgetComp->AttachToComponent(CubeMesh, FAttachmentTransformRules::KeepRelativeTransform);
	}
}

// Called when the game starts or when spawned
void AInteractiveCube::BeginPlay()
{
	Super::BeginPlay();

	if (CubeMesh)
	{
		CubeMesh->OnComponentHit.AddDynamic(this, &AInteractiveCube::OnCubeHit);

		CubeDynamicMaterial = CubeMesh->CreateAndSetMaterialInstanceDynamicFromMaterial(0, CubeMesh->GetMaterial(0));
		if (CubeDynamicMaterial)
		{
			switch (CubeType)
			{
			default:
				break;
			case ECubeType::Points:
				CubeDynamicMaterial->SetVectorParameterValue(ColorParamName, FLinearColor::Blue);
				break;
			case ECubeType::Damage:
				CubeDynamicMaterial->SetVectorParameterValue(ColorParamName, FLinearColor::Red);
				break;
			case ECubeType::Heal:
				CubeDynamicMaterial->SetVectorParameterValue(ColorParamName, FLinearColor::Green);
				break;
			}
		}
	}

	if(HealthWidgetComp)
	{
		HealthWidgetComp->SetWidgetSpace(EWidgetSpace::Screen);
		HealthWidgetComp->SetVisibility(true);
		HealthWidgetComp->AddLocalOffset(FVector(0, 0, 100));
		HealthWidgetComp->RegisterComponent();
		if(HealthWidgetComp->GetUserWidgetObject())
		{
			UInteractiveCubeUserWidget* UserWidget = Cast<UInteractiveCubeUserWidget>(HealthWidgetComp->GetUserWidgetObject());
			if(UserWidget)
			{
				UserWidget->Init(this);
			}
		}
	}
}

void AInteractiveCube::OnCubeHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->IsA(AUIProjectProjectile::StaticClass()) && GetWorld())
	{
		if (!Player)
		{
			Player = Cast<AUIProjectCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		}

		if (!GameInstance)
		{
			GameInstance = Cast<UUIProjectGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
		}

		if (Player && IsValid(GameInstance))
		{
			switch (CubeType)
			{	
			case ECubeType::Points:
				GameInstance->AddPoints();
				break;
			case ECubeType::Damage:
				Player->HealthComponent->Damage(5.0f);
				break;
			case ECubeType::Heal:
				Player->HealthComponent->Heal(5.0f);
				break;
			default:
				break;
			}

			HealthComp->Damage(10.0f);
		}	
	}
}

// Called every frame
void AInteractiveCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

