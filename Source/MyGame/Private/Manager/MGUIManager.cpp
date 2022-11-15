// Fill out your copyright notice in the Description page of Project Settings.

#include "MGUIManager.h"
#include "UI/Base/MGUserWidget.h"

UMGUIManager::UMGUIManager()
{
	// None을 제외하기 위해서 1부터 시작
	for (uint8 WidgetIndex = 1; WidgetIndex < (uint8)EWidgetType::MAX; WidgetIndex++)
	{
		EWidgetType WidgetType = static_cast<EWidgetType>(WidgetIndex);
		FString WidgetBPName = UIUtil::GetUIBPName(WidgetType);

		TArray<FStringFormatArg> Arg;
		Arg.Add(FStringFormatArg(WidgetBPName));
		Arg.Add(FStringFormatArg(WidgetBPName));

		FString WidgetBPPath = FString::Format(TEXT("WidgetBlueprint'/Game/Asset/UI/{0}.{1}_C'"), Arg);
		ConstructorHelpers::FClassFinder<UUserWidget> WidgetClass(*WidgetBPPath);
		if (WidgetClass.Succeeded())
		{
			WidgetClassMap.Emplace(WidgetType, WidgetClass.Class);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to construct %s, Reference path : %s"), *WidgetBPName, *WidgetBPPath);
		}
	}// for : Widget Type
}

void UMGUIManager::Initialize(FSubsystemCollectionBase& Collection)
{
	// 싱글톤 포인터 등록
	Set(this);
}

void UMGUIManager::Deinitialize()
{
	for (auto& Widget : WidgetMap)
	{
		RemoveUI(Widget.Value);
	}

	WidgetMap.Empty();
	Clear();
}

void UMGUIManager::CreateUI(const EWidgetType WidgetType)
{
	if (WidgetClassMap.Contains(WidgetType) == false) return;

	UMGUserWidget* pWidget = CreateWidget<UMGUserWidget>(GetWorld(), WidgetClassMap[WidgetType]);
	if (pWidget == nullptr)
	{
		// 실패했을 경우, 
		// 1. 위젯의 부모가 UMGUserWidget을 상속 받고 있는지 확인이 필요하다.
		UE_LOG(LogTemp, Error, TEXT("Failed to create %s"), *UIUtil::GetUIBPName(WidgetType));
		return;
	}

	// 갈비지 컬렉터가 자동으로 삭제하지 않도록 방지한다.
	pWidget->AddToRoot();
	pWidget->SetWidgetType(WidgetType);

	WidgetMap.Emplace(WidgetType, pWidget);
}

void UMGUIManager::RemoveUI(UUserWidget* pWidget)
{
	if (pWidget == nullptr) return;
	
	pWidget->RemoveFromRoot();
	pWidget->ConditionalBeginDestroy();
}

void UMGUIManager::InputKey(const FKey Key, const EInputEvent Event)
{
	// TODO 
	// 입력 동작 로직 구현 필요

	switch (Event)
	{
	case IE_Pressed:
		break;
	case IE_Released:
		break;
	case IE_Repeat:
		break;
	case IE_DoubleClick:
		break;
	case IE_Axis:
		break;
	case IE_MAX:
		break;
	default:
		break;
	}
}

void UMGUIManager::OpenUI(const EWidgetType WidgetType)
{
	if (WidgetMap.Contains(WidgetType) == false)
		CreateUI(WidgetType);
	
	if (WidgetMap.Contains(WidgetType))
		WidgetMap[WidgetType]->AddToViewport();
}

void UMGUIManager::CloseUI(const EWidgetType WidgetType, const bool bRemove)
{
	if (WidgetClassMap.Contains(WidgetType) == false) return;

	if (WidgetMap.Contains(WidgetType))
		WidgetMap[WidgetType]->RemoveFromRoot();

	if (bRemove)
	{
		RemoveUI(WidgetMap[WidgetType]);
		WidgetMap.Remove(WidgetType);
	}
}

const bool UMGUIManager::IsOpen(const EWidgetType WidgetType) const
{
	if (WidgetClassMap.Contains(WidgetType) == false) return false;

	if (WidgetMap.Contains(WidgetType))
	{
		UUserWidget* pWidget = Cast<UUserWidget>(WidgetMap[WidgetType]);
		if (pWidget) return pWidget->GetIsVisible();
	}
	return false;
}
