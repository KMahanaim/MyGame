// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Singleton/MGSingleton.h"
#include "Enum/MGWidgetEnum.h"
#include "MGUIManager.generated.h"

/** UI �Ŵ����� �����ؼ� ��� �ִ� ���� �о���� */
#define GETUI_POINTER(class, type) UMGUIManager::Get()->GetUI<class>(type)

/**
 * ��� Widget�� �����Ѵ�.
 * ����, ����, ���� ��� �Ϳ� �����Ѵ�.
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
	TMap<EWidgetType, TSubclassOf<class UUserWidget>> WidgetClassMap;	// ���� ������ ��� ���� Ŭ���� ��
	TMap<EWidgetType, class UUserWidget*> WidgetMap;					// ������ ���� ��
};
