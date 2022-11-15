// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Base/MGUserWidget.h"
#include "MGUIMainTitle.generated.h"

UENUM()
enum class EMainMenuState : uint8
{
	NONE,
	GameMode,
	Single,
	Multi
};

/**
 * 
 */
UCLASS()
class UMGUIMainTitle : public UMGUserWidget
{
	GENERATED_BODY()
	
public:
	UMGUIMainTitle(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeOnInitialized();
	virtual void NativePreConstruct();
	virtual void NativeConstruct();
	virtual void NativeDestruct();

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);

private:
	UFUNCTION()
		void OnClickedSingle();
	UFUNCTION()
		void OnClickedMulti();

	UFUNCTION()
		void OnClickedNewStart();
	UFUNCTION()
		void OnClickedContinue();
	UFUNCTION()
		void OnClickedLoad();

	UFUNCTION()
		void OnClickedCreate();
	UFUNCTION()
		void OnClickedJoin();

	UFUNCTION()
		void OnClickedOption();
	UFUNCTION()
		void OnClickedBack();
	UFUNCTION()
		void OnClickedEndGame();

private:
	void SetMenuState(const EMainMenuState InMenuState);

private:
	////////////////////////////////////////////////////////////////////////////
	// Game logo
	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* TitleTextBlock = nullptr;


	////////////////////////////////////////////////////////////////////////////
	// Game mode button
	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UButton* SingleButton = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UButton* MultiButton = nullptr;

	// Single game button
	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UButton* NewStartButton = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UButton* ContinueButton = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UButton* LoadButton = nullptr;

	// Multi game button
	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UButton* CreateButton = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UButton* JoinButton = nullptr;

	// Common button
	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UButton* OptionButton = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UButton* BackButton = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UButton* EndGameButton = nullptr;


	////////////////////////////////////////////////////////////////////////////
	// Game mode button text
	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* SingleTextBlock = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* MultiTextBlock = nullptr;

	// Single button text
	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* NewStartTextBlock = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* ContinueTextBlock = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* LoadTextBlock = nullptr;

	// Multi button text
	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* CreateTextBlock = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* JoinTextBlock = nullptr;

	// Common button text
	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* OptionTextBlock = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* BackTextBlock = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* EndGameTextBlock = nullptr;


	////////////////////////////////////////////////////////////////////////////
	// Vertical box
	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UVerticalBox* GameModeVerticalBox = nullptr;
	
	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UVerticalBox* SingleMenuVerticalBox = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UVerticalBox* MultiMenuVerticalBox = nullptr;

private:
	EMainMenuState CurrentMenuState = EMainMenuState::NONE;
};
