// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "UI/Base/MGUserWidget.h"
#include "MGUIOption.generated.h"

/**
 * 
 */
UCLASS()
class UMGUIOption : public UMGUserWidget
{
	GENERATED_BODY()
	
public:
	UMGUIOption(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeOnInitialized();
	virtual void NativePreConstruct();
	virtual void NativeConstruct();
	virtual void NativeDestruct();

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);

private:
	UFUNCTION()
		void OnClickedGame();

	UFUNCTION()
		void OnClickedCancel();
	UFUNCTION()
		void OnClickedReset();
	UFUNCTION()
		void OnClickedApply();

	UFUNCTION()
		void OnChangeLanguage(FString SelectedItem, ESelectInfo::Type SelectionType);

private:
	// Button
	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UButton* GameButton = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UButton* CancelButton = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UButton* ResetButton = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UButton* ApplyButton = nullptr;

	// Text block
	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* LanguageTextBlock = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* GameTextBlock = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* CancelTextBlock = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* ResetTextBlock = nullptr;

	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UTextBlock* ApplyTextBlock = nullptr;

	// Game tab
	UPROPERTY(Transient, meta = (AllowPrivateAccess = "true", BindWidget))
		class UComboBoxString* LanguageComboBoxString = nullptr;
};
