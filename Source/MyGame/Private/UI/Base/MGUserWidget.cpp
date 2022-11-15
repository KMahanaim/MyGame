// Fill out your copyright notice in the Description page of Project Settings.

#include "MGUserWidget.h"
#include "Define/UI/MGUICommon.h"
#include "GameFramework/PlayerController.h"

UMGUserWidget::UMGUserWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void UMGUserWidget::Close(const bool bRemove/* = false */)
{
	UMGUIManager::Get()->CloseUI(WidgetType, bRemove);
}

void UMGUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

#if WITH_EDITOR
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		PlayerController->SetShowMouseCursor(true);
	}
#endif // WITH_EDITOR
}

void UMGUserWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UMGUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UMGUserWidget::NativeDestruct()
{
	Super::NativeDestruct();
}

void UMGUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UMGUserWidget::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);

	ChangeInputMode(EInputMode::UIOnly);
}

void UMGUserWidget::NativeOnMOuseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);

	ChangeInputMode(EInputMode::GameAndUI);
}

void UMGUserWidget::SetColorAndOpacity(FLinearColor InColorAndOpacity)
{
	Super::SetColorAndOpacity(InColorAndOpacity);
}

void UMGUserWidget::ChangeInputMode(EInputMode InInputMode)
{
	if (InputMode == InInputMode) return;
	
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController == nullptr) return;
	
	if (InInputMode == EInputMode::UIOnly)
	{
		FInputModeUIOnly NewInputMode;
		PlayerController->SetInputMode(NewInputMode);
	}
	else if (InInputMode == EInputMode::GameOnly)
	{
		FInputModeGameOnly NewInputMode;
		PlayerController->SetInputMode(NewInputMode);
	}
	else if (InInputMode == EInputMode::GameAndUI)
	{
		FInputModeGameAndUI NewInputMode;
		PlayerController->SetInputMode(NewInputMode);
	}

	InputMode = InInputMode;
}
