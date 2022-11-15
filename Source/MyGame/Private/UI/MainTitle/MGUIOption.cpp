// Fill out your copyright notice in the Description page of Project Settings.

#include "MGUIOption.h"
#include "Define/UI/MGUICommon.h"

UMGUIOption::UMGUIOption(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UMGUIOption::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (LanguageComboBoxString)
	{
		LanguageComboBoxString->OnSelectionChanged.AddDynamic(this, &UMGUIOption::OnChangeLanguage);
	}
}

void UMGUIOption::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UMGUIOption::NativeConstruct()
{
	Super::NativeConstruct();
}

void UMGUIOption::NativeDestruct()
{
	Super::NativeDestruct();
}

void UMGUIOption::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UMGUIOption::OnClickedGame()
{
}

void UMGUIOption::OnClickedCancel()
{
}

void UMGUIOption::OnClickedReset()
{
}

void UMGUIOption::OnClickedApply()
{
}

void UMGUIOption::OnChangeLanguage(FString SelectedItem, ESelectInfo::Type SelectionType)
{
}