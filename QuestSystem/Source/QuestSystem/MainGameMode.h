// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class QUESTSYSTEM_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay() override;
};
