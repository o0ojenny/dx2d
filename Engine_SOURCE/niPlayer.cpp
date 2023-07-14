#include "niPlayer.h"

namespace ni
{

	Player::Player()
	{
		mPlayerInfo.pos = Vector4(0.f, 0.f, 0.f, 1.f);
		mPlayerInfo.color = Vector4(1.f, 1.f, 1.f, 1.f);
		mPlayerInfo.scale = Vector4(0.5f, 1.f, 0.f, 0.f);
	}

	Player::~Player()
	{
	}

	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		

		//if (Input::GetKeyState(eKeyCode::A) == eKeyState::Pressed)
		//{
		//	mPlayerInfo.pos.x -= (float)(0.7f * Time::DeltaTime());
		//}

		//if (Input::GetKeyState(eKeyCode::D) == eKeyState::Pressed)
		//{
		//	mPlayerInfo.pos.x += (float)(0.7f * Time::DeltaTime());
		//}

		//if (Input::GetKeyState(eKeyCode::W) == eKeyState::Pressed)
		//{
		//	mPlayerInfo.pos.y += (float)(1.0f * Time::DeltaTime());
		//}

		//if (Input::GetKeyState(eKeyCode::S) == eKeyState::Pressed)
		//{
		//	mPlayerInfo.pos.y -= (float)(1.0f * Time::DeltaTime());
		//}

		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Player::Render()
	{
		// 상수버퍼로 위치, 크기, 색 정보 업뎃
		//renderer::constantBuffer->SetData(&mPlayerInfo);

		GameObject::Render();
	}

	void Player::PlayerScaleUp(float Scale)
	{
		mPlayerInfo.scale.x += Scale / 2;
		mPlayerInfo.scale.y += Scale;
	}

}
