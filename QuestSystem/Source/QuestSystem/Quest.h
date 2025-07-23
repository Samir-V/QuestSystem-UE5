// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestDataAsset.h"
#include "QuestStep.h"
#include "UObject/NoExportTypes.h"
#include "Quest.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EQuestState : uint8
{
	Locked         UMETA(DisplayName = "Requirements Not Met"),
	Available      UMETA(DisplayName = "Can Start"),
	InProgress     UMETA(DisplayName = "In Progress"),
	Completed      UMETA(DisplayName = "Completed"),
};

UCLASS()
class QUESTSYSTEM_API UQuest : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	UQuestDataAsset* QuestDataAsset;

	UPROPERTY(EditAnywhere)
	EQuestState QuestState = EQuestState::Locked;

	UPROPERTY(EditAnywhere)
	AQuestStep* CurrentQuestStep = nullptr;

	void AdvanceQuest();
	void CreateQuestStep();

	void Initialize(UQuestDataAsset* InDataAsset);

private:

	UPROPERTY(EditAnywhere)
	int32 CurrentStepIndex_ = 0;
};
