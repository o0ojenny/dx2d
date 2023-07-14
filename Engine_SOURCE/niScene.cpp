#include "niScene.h"

namespace ni
{
	Scene::Scene()
	{
		mLayers.resize((int)ni::enums::eLayerType::End);
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{

	}

	void Scene::Update()
	{
		for (Layer& layer : mLayers)
		{
			layer.Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer& layer : mLayers)
		{
			layer.LateUpdate();
		}
	}
	
	void Scene::Render()
	{
		for (Layer& layer : mLayers)
		{
			layer.Render();
		}
	}

	void Scene::Destroy()
	{
		for (Layer& layer : mLayers)
		{
			layer.Destroy();
		}
	}

	void Scene::OnEnter()
	{
	}

	void Scene::OnExit()
	{
	}

	void Scene::AddGameObject(eLayerType type, GameObject* gameobj)
	{
		mLayers[(int)type].AddGameObject(gameobj);
	}
}