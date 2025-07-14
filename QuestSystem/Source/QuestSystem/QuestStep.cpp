// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestStep.h"

// Sets default values
AQuestStep::AQuestStep()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AQuestStep::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuestStep::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

