#pragma once
#include "niComponent.h"
#include "niMesh.h"
#include "niMaterial.h"

namespace ni
{
	class MeshRenderer : public Component
	{
	public:
		MeshRenderer();
		~MeshRenderer();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetMesh(std::shared_ptr<Mesh> mesh) { mMesh = mesh; }
		void SetMaterial(std::shared_ptr<Material> material) { mMaterial = material; }
		void SetTexture(std::shared_ptr<Texture> texture) { mTexture = texture; }
		std::shared_ptr<Material> GetMaterial() { return mMaterial; }


	private:
		std::shared_ptr<Mesh> mMesh;
		std::shared_ptr<Texture> mTexture;
		std::shared_ptr<Material> mMaterial;

		Vector3 mScale;
		Vector3 mImageScale;
	};
}
