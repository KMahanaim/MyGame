// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyGame.h"
#include "Define/UI/MGUICommon.h"
#include "Define/UI/MGUIPathDefine.h"
#include <Modules/ModuleManager.h>
#include <Internationalization/StringTableRegistry.h>

void FMyGame::StartupModule()
{
	FDefaultGameModuleImpl::StartupModule();

	if (FStringTableRegistry::Get().FindMutableStringTable(LOCALIZING_ID_KOR) == nullptr)
	{
		LOCTABLE_FROMFILE_GAME(LOCALIZING_ID_KOR, "kor", LOCALIZING_KOR_PATH);
	}

	if (FStringTableRegistry::Get().FindMutableStringTable(LOCALIZING_ID_EN) == nullptr)
	{
		LOCTABLE_FROMFILE_GAME(LOCALIZING_ID_EN, "en", LOCALIZING_EN_PATH);
	}

}

void FMyGame::ShutdownModule()
{
	FDefaultGameModuleImpl::ShutdownModule();

	FStringTableRegistry::Get().UnregisterStringTable(LOCALIZING_ID_KOR);
	FStringTableRegistry::Get().UnregisterStringTable(LOCALIZING_ID_EN);
}

IMPLEMENT_PRIMARY_GAME_MODULE(FMyGame, MyGame, "MyGame");