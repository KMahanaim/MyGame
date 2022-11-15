#pragma once

UENUM()
enum class EWidgetType : uint8
{
	NONE,
	MainTitle,
	Option,
	MAX
};

UENUM()
enum class ESystemMsgType : uint8
{
	NORMAL,
	IMPORTANT,
	MAX
};

UENUM()
enum class EFontColor : uint8
{
	NORMAL,
	ERROR,
	COLOR1,
	COLOR2,
	COLOR3,
	COLOR4,
	COLOR5,
	COLOR6,
	COLOR7,
	COLOR8,
	COLOR9,
	COLOR10,
	COLOR11,
	COLOR12,
	COLOR13,
	DEFAULT,
	MAX,
};

UENUM()
enum class EInputMode : uint8
{
	UIOnly,
	GameOnly,
	GameAndUI,
	MAX,
};

namespace UIUtil
{
	static const FString GetUIBPName(EWidgetType WidgetType)
	{
		switch (WidgetType)
		{
		case EWidgetType::MainTitle:			return "WBP_MainTitle";
		case EWidgetType::Option:				return "WBP_Option";
		}

		return "";
	}

	inline FColor GetFontColor(EFontColor InType)
	{
		switch (InType)
		{
		case EFontColor::NORMAL:			return FColor::FromHex(TEXT("#D4BD9B"));	// ���� Ȳ��
		case EFontColor::ERROR:				return FColor::FromHex(TEXT("#FA0000"));	// ����
		case EFontColor::COLOR1:			return FColor::FromHex(TEXT("#9BA4D1"));	// ���� ����
		case EFontColor::COLOR2:			return FColor::FromHex(TEXT("#c1ad8e"));	// ���� Ȳ��
		case EFontColor::COLOR3:			return FColor::FromHex(TEXT("#E74141"));	// ���� ����
		case EFontColor::COLOR4:			return FColor::FromHex(TEXT("#687587"));	// ���� �ƽ���Ʈ
		case EFontColor::COLOR5:			return FColor::FromHex(TEXT("#F9D78A"));	// ���� Ȳ��
		case EFontColor::COLOR6:			return FColor::FromHex(TEXT("#97774F"));	// £�� Ȳ��
		case EFontColor::COLOR7:			return FColor::FromHex(TEXT("#4DDD2B"));	// ������
		case EFontColor::COLOR8:			return FColor::FromHex(TEXT("#D62B2B"));	// ä���� ���� ����
		case EFontColor::COLOR9:			return FColor::FromHex(TEXT("#00FF00"));	// ������
		case EFontColor::COLOR10:			return FColor::FromHex(TEXT("#FBBA18"));	// ���� Ȳ��
		case EFontColor::COLOR11:			return FColor::FromHex(TEXT("#FF0000"));	// ����
		case EFontColor::COLOR12:			return FColor::FromHex(TEXT("#FF9900"));	// ��Ȳ
		case EFontColor::COLOR13:			return FColor::FromHex(TEXT("#868686"));	// £�� ȸ��
		case EFontColor::DEFAULT:			return FColor::FromHex(TEXT("#FFFFFF"));	// ���
		}

		return FColor::FromHex(TEXT("#FFFFFF"));
	}
}