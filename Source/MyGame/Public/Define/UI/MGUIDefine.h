#pragma once

#define PASSWORD_LENGTH_MIN 6	// 비밀번호 최소 길이
#define PASSWORD_LENGTH_MAX 20	// 비밀번호 최대 길이

#define INVENTORY_ROW_MAX 5				// 인벤토리
#define INVENTORY_STACK_MAX 99			// 인벤토리 슬롯 최대 중첩
#define INVENTORY_CLICK_INTERVAL 1.0f	// 인벤토리 클릭 간격 강제 쿨타임


#define GetObjectAsset(RETURN_POINTER, CLASS_TYPE, PATH)\
static ConstructorHlpers::FObjectFinder<CLASS_TYPE> __##RETURN_POINTER(TEXT(PATH));\
if (__##RETURN_POINTER.Succeeded())\
{\
	RETURN_POINTER = __##RETURN_POINTER.Object;\
}\
else\
{\
	RETURN_POINTER = nullptr;\
}


#define GetClassAsset(RETURN_POINTER, CLASS_TYPE, PATH)\
static ConstructorHelpers::FClassFinder<CLASS_TYPE> __##RETURN_POINTER(TEXT(PATH));\
if (__##RETURN_POINTER.Succeeded())\
{\
    RETURN_POINTER = __##RETURN_POINTER.Class;\
}\
else\
{\
RETURN_POINTER = nullptr;\
}


#if WITH_EDITOR
#define BIND_WIDGET(WidgetType, WidgetVariable)																																\
	WidgetVariable = Cast<WidgetType>(GetWidgetFromName(TEXT(#WidgetVariable)));																							\
	if (WidgetVariable == nullptr)																																			\
	{	FString _TempWidgetTypeName = #WidgetType, _TempWidgetVariableName = #WidgetVariable, _TempFunctionName = __FUNCTION__;												\
	ensureMsgf(false, TEXT("\n%s : <%s> %s binding failed.\n"), *_TempFunctionName, *_TempWidgetTypeName, *_TempWidgetVariableName);	}
#else//WITH_EDITOR
#define BIND_WIDGET(WidgetType, WidgetVariable)																																\
	WidgetVariable = Cast<WidgetType>(GetWidgetFromName(TEXT(#WidgetVariable)));																							\
	if (WidgetVariable == nullptr)																																			\
	{	FString _TempWidgetTypeName = #WidgetType, _TempWidgetVariableName = #WidgetVariable, _TempFunctionName = __FUNCTION__; }
#endif//WITH_EDITOR


#if WITH_EDITOR
#define BIND_BUTTON_CLICK(BUTTON, CLASS, FUNCTION)\
	if (##BUTTON)\
		##BUTTON->OnClicked.AddDynamic(this, &##CLASS::FUNCTION);\
	else\
		UE_LOG(LogTemp, Error, TEXT("%s is nullptr"), #BUTTON);
#else // WITH_EDITOR
#define BIND_BUTTON_CLICK(BUTTON, CLASS, FUNCTION)\
	if (##BUTTON)\
		##BUTTON->OnClicked.AddDynamic(this, &##CLASS::FUNCTION);
#endif // WITH_EDITOR
