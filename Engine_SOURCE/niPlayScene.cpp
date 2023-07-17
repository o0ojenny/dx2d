#include "niPlayScene.h"
#include "niTransform.h"
#include "niMeshRenderer.h"
#include "niResources.h"
#include "niMesh.h"
#include "niCamera.h"
#include "niCameraScript.h"
#include "niSceneManager.h"
#include "niObject.h"
#include "niRenderer.h"
#include "niCollider2D.h"



namespace ni
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		{
			// Background
			GameObject* background = new GameObject();
			background->SetName(L"Background");
			AddGameObject(eLayerType::Background, background);
			MeshRenderer* mr = background->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial"));
			//mr->Initialize();
			background->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
			background->GetComponent<Transform>()->SetScale(Vector3(42.0f, 6.0f, 1.0f));

			const float pi = 3.141592f;
			float degree = pi / 2.0f;
		}

		{
			// Player
			GameObject* player = object::Instantiate<GameObject>(Vector3(0.0f, -1.0f, 1.00001f), eLayerType::Player);
			//player->GetComponent<Transform>()->SetScale(Vector3(0.5f, 0.35f, 1.0f));
			player->SetName(L"Knight");
			Collider2D* cd = player->AddComponent<Collider2D>();

			MeshRenderer* mr = player->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"KnightSpriteMaterial"));

		}

		// UI
		{
			GameObject* hp = new GameObject();
			hp->SetName(L"HP");
			AddGameObject(eLayerType::UI, hp);
			MeshRenderer* mr = hp->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"HPFullSpriteMaterial"));
			// mr->Initialize();
			hp->GetComponent<Transform>()->SetPosition(Vector3(-3.0f, 1.9f, 0.0f));
			hp->GetComponent<Transform>()->SetScale(Vector3(0.3f, 0.35f, 1.0f));
			//player->AddComponent<CameraScript>();
		}

		{
			GameObject* hp = new GameObject();
			hp->SetName(L"HP");
			AddGameObject(eLayerType::UI, hp);
			MeshRenderer* mr = hp->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"HPFullSpriteMaterial"));
			// mr->Initialize();
			hp->GetComponent<Transform>()->SetPosition(Vector3(-2.7f, 1.9f, 0.0f));
			hp->GetComponent<Transform>()->SetScale(Vector3(0.3f, 0.35f, 1.0f));
			//player->AddComponent<CameraScript>();
		}

		{
			GameObject* hp = new GameObject();
			hp->SetName(L"HP");
			AddGameObject(eLayerType::UI, hp);
			MeshRenderer* mr = hp->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"HPFullSpriteMaterial"));
			// mr->Initialize();
			hp->GetComponent<Transform>()->SetPosition(Vector3(-2.4f, 1.9f, 0.0f));
			hp->GetComponent<Transform>()->SetScale(Vector3(0.3f, 0.35f, 1.0f));
			//player->AddComponent<CameraScript>();
		}


		{
			GameObject* hp = new GameObject();
			hp->SetName(L"HP");
			AddGameObject(eLayerType::UI, hp);
			MeshRenderer* mr = hp->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"HPFullSpriteMaterial"));
			// mr->Initialize();
			hp->GetComponent<Transform>()->SetPosition(Vector3(-2.1f, 1.9f, 0.0f));
			hp->GetComponent<Transform>()->SetScale(Vector3(0.3f, 0.35f, 1.0f));
			//player->AddComponent<CameraScript>();
		}
		
		{
			GameObject* hp2 = new GameObject();
			hp2->SetName(L"HP2");
			AddGameObject(eLayerType::UI, hp2);
			MeshRenderer* mr2 = hp2->AddComponent<MeshRenderer>();
			mr2->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr2->SetMaterial(Resources::Find<Material>(L"HPHalfSpriteMaterial"));
			// mr2->Initialize();
			hp2->GetComponent<Transform>()->SetPosition(Vector3(-1.8f, 1.9f, 0.0f));
			hp2->GetComponent<Transform>()->SetScale(Vector3(0.3f, 0.35f, 1.0f));
			//hp2->GetComponent<Transform>()->SetParent(hp->GetComponent<Transform>());

		}

		{
			GameObject* gameHUD = new GameObject();
			gameHUD->SetName(L"GameHUD");
			AddGameObject(eLayerType::UI, gameHUD);
			MeshRenderer* mr = gameHUD->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"GameHUDSpriteMaterial"));
			//mr->Initialize();
			gameHUD->GetComponent<Transform>()->SetPosition(Vector3(-3.2f, 1.8f, 0.001f));
			gameHUD->GetComponent<Transform>()->SetScale(Vector3(1.0f, 0.6f, 1.0f));
		}


		//Main Camera
		Camera* cameraComp = nullptr;
		{
			GameObject* camera = new GameObject();
			AddGameObject(eLayerType::Player, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
			cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::UI, false);
			cameraComp->TurnLayerMask(eLayerType::Background, true);
			camera->AddComponent<CameraScript>();
			renderer::cameras.push_back(cameraComp);
			renderer::mainCamera = cameraComp;
			//camera->AddComponent<CameraScript>();
		}

		//UI Camera
		{
			GameObject* camera = new GameObject();
			AddGameObject(eLayerType::Player, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::Player, false);
			cameraComp->TurnLayerMask(eLayerType::Background, false);
			//camera->AddComponent<CameraScript>();
		}

		//GameObject* player2 = new GameObject();
		//AddGameObject(eLayerType::Player, player2);
		//player2->AddComponent<MeshRenderer>();

		//Transform* tr = player->GetComponent<Transform>();
		//tr->SetPosition(Vector3(0.5f, 0.5f, 0.0f));
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Vector3 pos(800, 450, 0.0f);
		Vector3 pos2(800, 450, 1000.0f);
		Viewport viewport;
		viewport.width = 1600.0f;
		viewport.height = 900.0f;
		viewport.x = 0;
		viewport.y = 0;
		viewport.minDepth = 0.0f;
		viewport.maxDepth = 1.0f;

		pos = viewport.Unproject(pos, Camera::GetGpuProjectionMatrix(), Camera::GetGpuViewMatrix(), Matrix::Identity);
		pos2 = viewport.Unproject(pos2, Camera::GetGpuProjectionMatrix(), Camera::GetGpuViewMatrix(), Matrix::Identity);

		Scene::LateUpdate();
	}

	void PlayScene::Render()
	{
		Scene::Render();
	}
}
