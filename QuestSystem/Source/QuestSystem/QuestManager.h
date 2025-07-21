// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestManager.generated.h"

class UQuest;
/**
 * 
 */

UCLASS(Blueprintable)
class QUESTSYSTEM_API UQuestManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	void DelayedInit();

	UFUNCTION()
	void StartQuest(FName id);

	UFUNCTION()
	void AdvanceQuest(FName id);

	UFUNCTION()
	void FinishQuest(FName id);

public:
	UPROPERTY(EditAnywhere)
	TSet<FName> CompletedQuestsID;

	UPROPERTY(EditAnywhere)
	TArray<UQuest*> Quests;

	UPROPERTY(EditAnywhere)
	UQuest* ActiveQuest = nullptr;

	UQuest* GetQuestByID(FName questId);
};
