// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManager.h"

#include "EventRouterSubsystem.h"
#include "Quest.h"

void UQuestManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UE_LOG(LogTemp, Warning, TEXT("Quest Subsystem Initialized!"));

	FTimerHandle Handle;
	GetWorld()->GetTimerManager().SetTimer(Handle, this, &UQuestManager::DelayedInit, 0.1f, false);
}

void UQuestManager::DelayedInit()
{
	auto* eventRouter = GetGameInstance()->GetSubsystem<UEventRouterSubsystem>();
	if (eventRouter)
	{
		eventRouter->OnQuestStart.AddDynamic(this, &UQuestManager::StartQuest);
		eventRouter->OnQuestAdvance.AddDynamic(this, &UQuestManager::AdvanceQuest);
		eventRouter->OnQuestFinish.AddDynamic(this, &UQuestManager::FinishQuest);
	}
}


UQuest* UQuestManager::GetQuestByID(FName questId)
{
	for (UQuest* Quest : Quests)
	{
		if (Quest->QuestDataAsset->QuestID == questId)
		{
			return Quest;
		}
	}

	return nullptr;
}

void UQuestManager::StartQuest(FName id)
{
	FString Message = FString::Printf(TEXT("Start Quest: %s"), *id.ToString());
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
}

void UQuestManager::AdvanceQuest(FName id)
{
	FString Message = FString::Printf(TEXT("Advance Quest: %s"), *id.ToString());
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
}

void UQuestManager::FinishQuest(FName id)
{
	FString Message = FString::Printf(TEXT("Finish Quest: %s"), *id.ToString());
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
}


