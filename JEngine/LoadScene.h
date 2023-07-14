#pragma once
#include "niSceneManager.h"
#include "niPlayScene.h"
#include "niIntroScene.h"
#include "niBossScene.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\JEngine.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\JEngine.lib")
#endif

namespace ni
{
	void InitializeScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<IntroScene>(L"IntroScene");
		//SceneManager::CreateScene<BossScene>(L"BossScene");
	}
}