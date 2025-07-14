// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "QuestDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class QUESTSYSTEM_API UQuestDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, Category = "Quest Metadata")
    FName QuestID;

    UPROPERTY(EditAnywhere, Category = "Quest Info")
    FText QuestName;

    UPROPERTY(EditAnywhere, Category = "Quest Info")
    TSet<FName> QuestIDPrerequisites;

    UPROPERTY(EditAnywhere, Category = "Quest Info")
    TArray<TSubclassOf<class AQuestStep>> QuestSteps;

};
