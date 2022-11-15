// Fill out your copyright notice in the Description page of Project Settings.

#include "MGUIMainTitle.h"
#include "Define/UI/MGUICommon.h"

UMGUIMainTitle::UMGUIMainTitle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UMGUIMainTitle::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	UE_LOG(LogTemp, Log, TEXT("===> MainTitle::NativeOnInitialized"));

	// Text
	if (NewStartTextBlock)
	{
		NewStartTextBlock->SetText(FText::FromStringTable(LOCALIZING_ID_KOR, "MainTitle_NewStartButton"));
	}

	if (ContinueTextBlock)
	{
		ContinueTextBlock->SetText(FText::FromStringTable(LOCALIZING_ID_KOR, "MainTitle_ContinueButton"));
	}

	if (LoadTextBlock)
	{
		LoadTextBlock->SetText(FText::FromStringTable(LOCALIZING_ID_KOR, "MainTitle_LoadGameButton"));
	}

	if (OptionTextBlock)
	{
		OptionTextBlock->SetText(FText::FromStringTable(LOCALIZING_ID_KOR, "MainTitle_OptionButton"));
	}

	if (EndGameTextBlock)
	{
		EndGameTextBlock->SetText(FText::FromStringTable(LOCALIZING_ID_KOR, "MainTitle_EndGameButton"));
	}

	// Bind
	BIND_BUTTON_CLICK(SingleButton, UMGUIMainTitle, OnClickedSingle);
	BIND_BUTTON_CLICK(MultiButton, UMGUIMainTitle, OnClickedMulti);

	BIND_BUTTON_CLICK(NewStartButton, UMGUIMainTitle, OnClickedNewStart);
	BIND_BUTTON_CLICK(ContinueButton, UMGUIMainTitle, OnClickedContinue);
	BIND_BUTTON_CLICK(LoadButton, UMGUIMainTitle, OnClickedLoad);

	BIND_BUTTON_CLICK(CreateButton, UMGUIMainTitle, OnClickedCreate);
	BIND_BUTTON_CLICK(JoinButton, UMGUIMainTitle, OnClickedJoin);

	BIND_BUTTON_CLICK(OptionButton, UMGUIMainTitle, OnClickedOption);
	BIND_BUTTON_CLICK(BackButton, UMGUIMainTitle, OnClickedBack);
	BIND_BUTTON_CLICK(EndGameButton, UMGUIMainTitle, OnClickedEndGame);

	SetMenuState(EMainMenuState::GameMode);
}

void UMGUIMainTitle::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UMGUIMainTitle::NativeConstruct()
{
	Super::NativeConstruct();
}

void UMGUIMainTitle::NativeDestruct()
{
	Super::NativeDestruct();
}

void UMGUIMainTitle::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UMGUIMainTitle::OnClickedSingle()
{
	SetMenuState(EMainMenuState::Single);
}

void UMGUIMainTitle::OnClickedMulti()
{
	SetMenuState(EMainMenuState::Multi);
}

void UMGUIMainTitle::OnClickedNewStart()
{
}

void UMGUIMainTitle::OnClickedContinue()
{
}

void UMGUIMainTitle::OnClickedLoad()
{
}

void UMGUIMainTitle::OnClickedCreate()
{
}

void UMGUIMainTitle::OnClickedJoin()
{
}

void UMGUIMainTitle::OnClickedOption()
{
}

void UMGUIMainTitle::OnClickedBack()
{
	SetMenuState(EMainMenuState::GameMode);
}

void UMGUIMainTitle::OnClickedEndGame()
{
	APlayerController* pPlayerController = GetWorld()->GetFirstPlayerController();
	if (pPlayerController)
	{
		pPlayerController->ConsoleCommand("quit");
	}
}

void UMGUIMainTitle::SetMenuState(const EMainMenuState InMenuState)
{
	if (CurrentMenuState == InMenuState)
		return;

	switch (InMenuState)
	{
		case EMainMenuState::GameMode:
		{
			if (GameModeVerticalBox)
				GameModeVerticalBox->SetVisibility(ESlateVisibility::SelfHitTestInvisible);

			if (SingleMenuVerticalBox)
				SingleMenuVerticalBox->SetVisibility(ESlateVisibility::Collapsed);

			if (MultiMenuVerticalBox)
				MultiMenuVerticalBox->SetVisibility(ESlateVisibility::Collapsed);

			if (BackButton)
				BackButton->SetVisibility(ESlateVisibility::Collapsed);
		}
		break;
		case EMainMenuState::Single:
		{
			if (GameModeVerticalBox)
				GameModeVerticalBox->SetVisibility(ESlateVisibility::Collapsed);

			if (SingleMenuVerticalBox)
				SingleMenuVerticalBox->SetVisibility(ESlateVisibility::SelfHitTestInvisible);

			if (MultiMenuVerticalBox)
				MultiMenuVerticalBox->SetVisibility(ESlateVisibility::Collapsed);

			if (BackButton)
				BackButton->SetVisibility(ESlateVisibility::Visible);
		}
		break;
		case EMainMenuState::Multi:
		{
			if (GameModeVerticalBox)
				GameModeVerticalBox->SetVisibility(ESlateVisibility::Collapsed);

			if (SingleMenuVerticalBox)
				SingleMenuVerticalBox->SetVisibility(ESlateVisibility::Collapsed);

			if (MultiMenuVerticalBox)
				MultiMenuVerticalBox->SetVisibility(ESlateVisibility::SelfHitTestInvisible);

			if (BackButton)
				BackButton->SetVisibility(ESlateVisibility::Visible);
		}
		break;
	}

	CurrentMenuState = InMenuState;
}