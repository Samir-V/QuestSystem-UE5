// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EventRouterSubsystem.generated.h"

class UQuest;
/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestStart, FName, QuestId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestAdvance, FName, QuestId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestFinish, FName, QuestId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestStateChange, UQuest*, Quest);

UCLASS()
class QUESTSYSTEM_API UEventRouterSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "Events")
	FOnQuestStart OnQuestStart;

	UPROPERTY(EditAnywhere, Category = "Events")
	FOnQuestAdvance OnQuestAdvance;

	UPROPERTY(EditAnywhere, Category = "Events")
	FOnQuestFinish OnQuestFinish;

	UPROPERTY(EditAnywhere, Category = "Events")
	FOnQuestStateChange OnQuestStateChange;

	void TriggerQuestStart(FName QuestId) const;
	void TriggerQuestAdvance(FName QuestId) const;
	void TriggerQuestFinish(FName QuestId) const;
	void TriggerQuestStateChange(UQuest* Quest) const;
};
