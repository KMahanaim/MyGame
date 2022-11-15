// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Enum/MGWidgetEnum.h"
#include "MGUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class UMGUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UMGUserWidget(const FObjectInitializer& ObjectInitializer);

	void SetWidgetType(const EWidgetType InWidgetType) { WidgetType = InWidgetType; };

	const bool IsOpen() const { return GetIsVisible(); }

	virtual void ChangeLanguage() {};
	void Close(const bool bRemove = false);

protected:
	virtual void NativeOnInitialized();
	virtual void NativePreConstruct();
	virtual void NativeConstruct();
	virtual void NativeDestruct();

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);

	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);
	virtual void NativeOnMOuseLeave(const FPointerEvent& InMouseEvent);

	void SetColorAndOpacity(FLinearColor InColorAndOpacity);
	void ChangeInputMode(EInputMode InputMode);

private:
	EWidgetType WidgetType;
	EInputMode InputMode;
};
