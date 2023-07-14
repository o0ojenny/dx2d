#include "niIntroScene.h"
#include "niGameObject.h"
#include "niTransform.h"
#include "niMeshRenderer.h"
#include "niResources.h"
#include "niMesh.h"
#include "niCamera.h"
#include "niCameraScript.h"
#include "niSceneManager.h"
#include "niApplication.h"
#include "niInput.h"

extern ni::Application MyApplication;

namespace ni
{
	IntroScene::IntroScene()
	{
	}

	IntroScene::~IntroScene()
	{
	}

	void IntroScene::Initialize()
	{
		// Background
		{
			GameObject* background = new GameObject();
			background->SetName(L"IntroBackground");
			AddGameObject(eLayerType::Background, background);
			MeshRenderer* mr = background->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"IntroSpriteMaterial"));
			//mr->Initialize();

			background->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
			background->GetComponent<Transform>()->SetScale(Vector3(8.5f, 4.5f, 0.f));

		}

		{
			GameObject* background = new GameObject();
			background->SetName(L"IntroTitle");
			AddGameObject(eLayerType::Background, background);
			MeshRenderer* mr = background->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"TitleSpriteMaterial"));
			//mr->Initialize();

			background->GetComponent<Transform>()->SetPosition(Vector3(0.1f, 1.0f, 0.0f));
			background->GetComponent<Transform>()->SetScale(Vector3(5.2f, 2.0f, 0.f));

		}

		//Main Camera
		{
			GameObject* camera = new GameObject();
			AddGameObject(eLayerType::Player, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::UI, false);
			camera->AddComponent<CameraScript>();
		}

		//UI Camera
		{
			GameObject* camera = new GameObject();
			AddGameObject(eLayerType::Player, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::Player, false);
			//camera->AddComponent<CameraScript>();
		}
		// Button
	}

	void IntroScene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::Z))
			SceneManager::LoadScene((L"PlayScene"));
		
		Scene::Update();
	}

	void IntroScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void IntroScene::Render()
	{
		Scene::Render();
	}
}