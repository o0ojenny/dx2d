#include "niFeed.h"
#include "niRenderer.h"
#include <random>
namespace ni
{
	Feed::Feed()
	{
		std::random_device rPos;
		std::mt19937 genPos(rPos());
		std::uniform_real_distribution<float> disPos(-1.f, 1.f);

		std::random_device rColor;
		std::mt19937 genColor(rColor());
		std::uniform_real_distribution<float> disColor(0.f, 1.f);

		mFeedInfo.pos = Vector4(disPos(genPos), disPos(genPos), 0.f, 1.f);
		mFeedInfo.color = Vector4(disColor(genColor), disColor(genColor), disColor(genColor), 1.f);
		mFeedInfo.scale = Vector4(0.15f, 0.3f, 0.f, 0.f);

		//SetObjectInfo(mFeedInfo);
	}

	Feed::~Feed()
	{
	}

	void Feed::Initialize()
	{
		GameObject::Initialize();
	}

	void Feed::Update()
	{
		GameObject::Update();
	}

	void Feed::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Feed::Render()
	{
		//renderer::constantBuffer->SetData(&mFeedInfo);

		GameObject::Render();
	}
}