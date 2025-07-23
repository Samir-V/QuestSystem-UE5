// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManager.h"

#include "EventRouterSubsystem.h"
#include "Quest.h"
#include "QuestDataAsset.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

void UQuestManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UE_LOG(LogTemp, Warning, TEXT("Quest Subsystem Initialized!"));

	TArray<FAssetData> AssetDataList;

	FARFilter Filter;
	Filter.ClassPaths.Add(UQuestDataAsset::StaticClass()->GetClassPathName());
	Filter.PackagePaths.Add(FName("/Game/Quests"));
	Filter.bRecursivePaths = true;

	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	AssetRegistryModule.Get().GetAssets(Filter, AssetDataList);

	for (const FAssetData& AssetData : AssetDataList)
	{
		UQuestDataAsset* LoadedAsset = Cast<UQuestDataAsset>(AssetData.GetAsset());
		if (LoadedAsset)
		{
			UQuest* Quest = NewObject<UQuest>(this);
			Quest->Initialize(LoadedAsset);
			Quests.Add(Quest);
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("%d"), Quests.Num());

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

	auto quest = GetQuestByID("DestinationQuest");

	if (quest && quest->QuestDataAsset)
	{
		FText questName = quest->QuestDataAsset->QuestName;
		UE_LOG(LogTemp, Warning, TEXT("%s"), *questName.ToString());
	}

	for (UQuest* Quest : Quests)
	{
		eventRouter->TriggerQuestStateChange(Quest);	
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


