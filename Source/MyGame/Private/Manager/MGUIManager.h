// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Singleton/MGSingleton.h"
#include "Enum/MGWidgetEnum.h"
#include "MGUIManager.generated.h"

/** UI 매니저가 생성해서 들고 있는 위젯 읽어오기 */
#define GETUI_POINTER(class, type) UMGUIManager::Get()->GetUI<class>(type)

/**
 * 모든 Widget을 관리한다.
 * 생성, 삭제, 저장 모든 것에 관여한다.
 */
UCLASS()
class UMGUIManager : public UGameInstanceSubsystem, public MGSingleton<UMGUIManager>
{
	GENERATED_BODY()
	
public:
	UMGUIManager();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	void RemoveUI(class UUserWidget* pWidget);
	void InputKey(const FKey Key, const EInputEvent Event);
	void OpenUI(const EWidgetType WidgetType);
	void CloseUI(const EWidgetType WidgetType, const bool bRemove);

	template<typename T>
	T* GetUI(const EWidgetType WidgetType)
	{
		if (WidgetMap.Contains(WidgetType))
		{
			return Cast<T>(WidgetMap[WidgetType]);
		}

		return nullptr;
	}

	const bool IsOpen(const EWidgetType WidgetType) const;

private:
	void CreateUI(const EWidgetType WidgetType);

private:
	TMap<EWidgetType, TSubclassOf<class UUserWidget>> WidgetClassMap;	// 생성 가능한 모든 위젯 클래스 맵
	TMap<EWidgetType, class UUserWidget*> WidgetMap;					// 생성된 위젯 맵
};
