// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestActivationPoint.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "MainCharacter.h"

// Sets default values
AQuestActivationPoint::AQuestActivationPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TriggerArea = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerArea"));
	RootComponent = TriggerArea;
	TriggerArea->InitSphereRadius(150.f);
	TriggerArea->SetCollisionProfileName(TEXT("Trigger"));
	TriggerArea->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerArea->SetCollisionObjectType(ECC_WorldDynamic);
	TriggerArea->SetCollisionResponseToAllChannels(ECR_Ignore);
	TriggerArea->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	TriggerArea->SetGenerateOverlapEvents(true);

	// Visualization for the area
	VisualMarker = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMarker"));
	VisualMarker->SetupAttachment(RootComponent);
	VisualMarker->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void AQuestActivationPoint::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AQuestActivationPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AQuestActivationPoint::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	ACharacter* PlayerChar = Cast<ACharacter>(OtherActor);
	if (PlayerChar)
	{
		if (AMainCharacter* MainChar = Cast<AMainCharacter>(PlayerChar))
		{
			MainChar->CurrentQuestPoint = this;
			bPlayerInArea = true;
			UE_LOG(LogTemp, Warning, TEXT("Player entered quest area"));
		}
	}
}

void AQuestActivationPoint::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	ACharacter* PlayerChar = Cast<ACharacter>(OtherActor);
	if (PlayerChar)
	{
		if (AMainCharacter* MainChar = Cast<AMainCharacter>(PlayerChar))
		{
			if (MainChar->CurrentQuestPoint == this)
			{
				MainChar->CurrentQuestPoint = nullptr;
			}
			bPlayerInArea = false;
			UE_LOG(LogTemp, Warning, TEXT("Player exited quest area"));
		}
	}
}



void AQuestActivationPoint::OnInteractTriggered()
{
	if (bPlayerInArea)
	{
		UE_LOG(LogTemp, Warning, TEXT("Interact input triggered in quest area"));
	}
}
