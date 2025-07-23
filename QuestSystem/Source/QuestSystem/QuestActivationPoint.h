// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InputAction.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestActivationPoint.generated.h"

class USphereComponent;

UCLASS()
class QUESTSYSTEM_API AQuestActivationPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestActivationPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	// Input handling
	void OnInteractTriggered();

	UPROPERTY(EditAnywhere)
	USphereComponent* TriggerArea;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* VisualMarker;

	bool bPlayerInArea = false;
};
