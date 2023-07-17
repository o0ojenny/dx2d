#include "guiEditor.h"
#include "..\\Engine_SOURCE\\niMesh.h"
#include "..\\Engine_SOURCE\\niResources.h"
#include "..\\Engine_SOURCE\\niTransform.h"
#include "..\\Engine_SOURCE\\niMeshRenderer.h"
#include "..\\Engine_SOURCE\\niMaterial.h"
#include "..\\Engine_SOURCE\\niRenderer.h"

namespace gui
{
	using namespace ni::enums;
	std::vector<Widget*> Editor::mWidgets = {};
	std::vector<EditorObject*> Editor::mEditorObjects = {};
	std::vector<DebugObject*> Editor::mDebugObjects = {};

	void Editor::Initialize()
	{
		mDebugObjects.resize((UINT)eColliderType::End);

		std::shared_ptr<ni::Mesh> mesh = ni::Resources::Find<ni::Mesh>(L"DebugRect");
		std::shared_ptr<ni::Material> material = ni::Resources::Find<ni::Material>(L"DebugMaterial");

		mDebugObjects[(UINT)eColliderType::Rect] = new DebugObject();
		mDebugObjects[(UINT)eColliderType::Rect]->AddComponent<ni::Transform>();
		ni::MeshRenderer* mr = mDebugObjects[(UINT)eColliderType::Rect]->AddComponent<ni::MeshRenderer>();

		mr->SetMaterial(material);
		mr->SetMesh(mesh);

	}

	void Editor::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Editor::Update()
	{

		for (EditorObject* obj : mEditorObjects)
		{
			obj->Update();
		}

	}

	void Editor::LateUpdate()
	{
		for (EditorObject* obj : mEditorObjects)
		{
			obj->LateUpdate();
		}
	}

	void Editor::Render()
	{
		for (EditorObject* obj : mEditorObjects)
		{
			obj->Render();
		}

		for (const ni::graphics::DebugMesh& mesh : renderer::debugMeshes)
		{
			DebugRender(mesh);
		}

		renderer::debugMeshes.clear();
	}
	void Editor::Release()
	{

		for (auto widget : mWidgets)
		{
			delete widget;
			widget = nullptr;
		}

		for (auto editorObj : mEditorObjects)
		{
			delete editorObj;
			editorObj = nullptr;
		}

		for (auto debugObj : mDebugObjects)
		{
			delete debugObj;
			debugObj = nullptr;
		}
	}

	void Editor::DebugRender(const ni::graphics::DebugMesh& mesh)
	{
		DebugObject* debugObj = mDebugObjects[(UINT)mesh.type];
		
		// 위치, 크기, 회전 정보 => 해당 게임오브젝트 위헤 그려주면됨
		ni::Transform* tr = debugObj->GetComponent<ni::Transform>();

		Vector3 pos = mesh.position;
		pos.z -= 0.01f;

		tr->SetPosition(pos);
		tr->SetScale(mesh.scale);
		tr->SetRotation(mesh.rotation);

		tr->LateUpdate();

		ni::Camera* mainCamera = renderer::mainCamera;

		ni::Camera::SetGpuViewMatrix(mainCamera->GetViewMatrix());
		ni::Camera::SetGpuProjectionMatrix(mainCamera->GetProjectionMatrix());

		debugObj->Render();

	}
}
