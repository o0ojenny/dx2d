#include "niMeshRenderer.h"
#include "niGameObject.h"
#include "niTransform.h"
#include "niRenderer.h"

namespace ni
{
	MeshRenderer::MeshRenderer()
		: Component(eComponentType::MeshRenderer)
	{
	}

	MeshRenderer::~MeshRenderer()
	{
	}

	void MeshRenderer::Initialize()
	{
		/*Transform* tr = GetOwner()->GetComponent<Transform>();
		mImageScale = tr->GetScale();
		Vector3 ImageScale = Vector3(mMaterial->GetTexture()->GetImageWidth() / 250.f, mMaterial->GetTexture()->GetImageHeight() / 250.f, 1.f);
		mScale = ImageScale * mImageScale;*/
	}

	void MeshRenderer::Update()
	{
	}

	void MeshRenderer::LateUpdate()
	{
	}

	void MeshRenderer::Render()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		tr->BindConstantBuffer();
		//tr->SetScale(mScale);
	
		mMesh->BindBuffer();
		mMaterial->Binds();
		mMesh->Render();

		mMaterial->Clear();
	}
}