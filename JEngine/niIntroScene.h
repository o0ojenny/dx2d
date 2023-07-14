#pragma once
#include "..\Engine_SOURCE\niScene.h"

namespace ni
{
	class IntroScene : public Scene
	{
	public:
		IntroScene();
		virtual ~IntroScene();

		virtual void Initialize() override; 
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
	};
}
