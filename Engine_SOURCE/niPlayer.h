#pragma once
#include "JEngine.h"
#include "niGameObject.h"
#include "niGraphicDevice_Dx11.h"
#include "niMesh.h"
#include "niShader.h"
#include "niConstantBuffer.h"
#include "niRenderer.h"
#include "niTime.h"
#include "niInput.h"

namespace ni
{
	using namespace renderer;

	class Player : public GameObject
	{
	public:
		Player();
		~Player();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		ObjectInfo GetPlayerInfo() { return mPlayerInfo; }
		
		void SetPlayerInfo(ObjectInfo info) { mPlayerInfo = info; }
		void PlayerScaleUp(float Scale);


	private:
		ObjectInfo mPlayerInfo;

	};
}
