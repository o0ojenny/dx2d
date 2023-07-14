#pragma once
#include "../Engine_SOURCE/niScene.h"

namespace ni
{
	class BossScene : public Scene
	{
	public:
		BossScene();
		virtual ~BossScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	};
}
