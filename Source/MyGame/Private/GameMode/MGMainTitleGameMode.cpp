// Fill out your copyright notice in the Description page of Project Settings.
#include "MGMainTitleGameMode.h"
#include "Manager/MGUIManager.h"
#include "Actor/Player/MGMainTitlePlayer.h"
#include "Controller/MGPlayerController.h"

AMGMainTitleGameMode::AMGMainTitleGameMode()
{
	DefaultPawnClass = AMGMainTitlePlayer::StaticClass();
	PlayerControllerClass = AMGPlayerController::StaticClass();
}

void AMGMainTitleGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
}

void AMGMainTitleGameMode::StartPlay()
{
	Super::StartPlay();

	UMGUIManager::Get()->OpenUI(EWidgetType::MainTitle);
}