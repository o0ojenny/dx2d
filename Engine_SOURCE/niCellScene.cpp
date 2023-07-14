#include "niCellScene.h"

namespace ni
{
	CellScene::CellScene()
		: mPlayer(nullptr)
		, mFeed(nullptr)
		, mTime(1.f)
	{
	}

	CellScene::~CellScene()
	{
	}

	void CellScene::Initialize()
	{
		// 게임 초기 맵데이터 세팅
		mPlayer = new Player;
		mGameObjects.push_back(mPlayer);

		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Initialize();
		}

		// feed 생성
		for (int i = 0; i < 50; i++)
		{ 
			mFeed = new Feed;
			mGameObjects.push_back(mFeed);
		}

	}

	void CellScene::Update()
	{

		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Update();
		}

		std::vector<GameObject*>::iterator Playeriter = mGameObjects.begin();
		std::vector<GameObject*>::iterator Feediter = mGameObjects.begin() + 1;

		for (; Feediter != mGameObjects.end();)
		{

			if (fabs(mPlayer->GetPlayerInfo().pos.x - (*Feediter)->GetObjectInfo().pos.x) < 0.05 * ((mPlayer->GetPlayerInfo().scale.x + (*Feediter)->GetObjectInfo().scale.x))
				&& fabs(mPlayer->GetPlayerInfo().pos.y - (*Feediter)->GetObjectInfo().pos.y) < 0.1 * ((mPlayer->GetPlayerInfo().scale.y + (*Feediter)->GetObjectInfo().scale.y)))
			{
				mPlayer->PlayerScaleUp(0.03f);

				(*Feediter)->SetState(GameObject::Dead);
				Feediter++;
			}

			else
			{
				Feediter++;
			}
		}

		mTime += Time::DeltaTime();

		if (mTime >= 2.f)
		{
			mGameObjects.push_back(new Feed());
			mGameObjects.push_back(new Feed());
			mGameObjects.push_back(new Feed());
			mGameObjects.push_back(new Feed());
			mGameObjects.push_back(new Feed());

			mTime = 0.f;
		}
	}


	void CellScene::LateUpdate()
	{
	}

	void CellScene::Render()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Render();
		}

		std::vector<GameObject*> deleteGameObjects = {};

		for (std::vector<GameObject*>::iterator iter = mGameObjects.begin(); iter != mGameObjects.end(); )
		{
			if ((*iter)->GetState() == GameObject::Dead)
			{
				deleteGameObjects.push_back((*iter));

				iter = mGameObjects.erase(iter);
			}
			else
			{
				iter++;
			}
		}

		for (GameObject* deathObj : deleteGameObjects)
		{
			delete deathObj;
			deathObj = nullptr;
		}

	}

}