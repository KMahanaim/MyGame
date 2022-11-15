// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameMode/Base/MGGameModeBase.h"
#include "MGMainTitleGameMode.generated.h"

/**
 * 
 */
UCLASS()
class AMGMainTitleGameMode : public AMGGameModeBase
{
	GENERATED_BODY()
	
public:
	AMGMainTitleGameMode();
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) final;
	virtual void StartPlay() final;
};
