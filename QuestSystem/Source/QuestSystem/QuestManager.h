// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestManager.generated.h"

class UQuest;
/**
 * 
 */

UCLASS()
class QUESTSYSTEM_API UQuestManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSet<FName> CompletedQuestsID;

	UPROPERTY(EditAnywhere)
	TArray<UQuest*> Quests;

	UPROPERTY(EditAnywhere)
	UQuest* ActiveQuest = nullptr;
};
