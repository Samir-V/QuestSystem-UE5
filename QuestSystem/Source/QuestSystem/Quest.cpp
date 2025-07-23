// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest.h"

#include "QuestStep.h"

void UQuest::Initialize(UQuestDataAsset* InDataAsset)
{
	QuestDataAsset = InDataAsset;
}


void UQuest::AdvanceQuest()
{
	++CurrentStepIndex_;
}

void UQuest::CreateQuestStep()
{
	auto type = QuestDataAsset->QuestSteps[CurrentStepIndex_];

	CurrentQuestStep = GetWorld()->SpawnActor<AQuestStep>(type, FVector(0, 0, 0), FRotator::ZeroRotator);
}

