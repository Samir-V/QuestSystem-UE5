// Fill out your copyright notice in the Description page of Project Settings.


#include "EventRouterSubsystem.h"

void UEventRouterSubsystem::TriggerQuestStart(FName QuestId) const
{
	OnQuestStart.Broadcast(QuestId);
}

void UEventRouterSubsystem::TriggerQuestAdvance(FName QuestId) const
{
	OnQuestAdvance.Broadcast(QuestId);
}

void UEventRouterSubsystem::TriggerQuestFinish(FName QuestId) const
{
	OnQuestFinish.Broadcast(QuestId);
}

void UEventRouterSubsystem::TriggerQuestStateChange(UQuest* Quest) const
{
	OnQuestStateChange.Broadcast(Quest);
}



