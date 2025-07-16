// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManager.h"

#include "Quest.h"

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
