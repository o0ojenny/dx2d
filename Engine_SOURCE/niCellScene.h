#pragma once
#include "niEntity.h"
#include "niGameObject.h"
#include "niLayer.h"
#include "niPlayer.h"
#include "niFeed.h"

namespace ni
{
	class CellScene : public Entity
	{
	public: 
		CellScene();
		virtual ~CellScene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

	private:
		std::vector<GameObject*> mGameObjects;

		Player* mPlayer;
		Feed* mFeed;

		double mTime;
	};
}
