#pragma once
#include "niResource.h"
#include "niShader.h"
#include "niTexture.h"

namespace ni::graphics
{

	class Material : public Resource
	{
	public:
		Material();
		~Material();

		virtual HRESULT Load(const std::wstring& path) override;

		void Binds();
		void Clear();

		void SetShader(std::shared_ptr<Shader> shader) { mShader = shader; }
		void SetTexture(std::shared_ptr<Texture> texture) { mTexture = texture; }
		void SetRenderingMode(eRenderingMode mode) { mMode = mode; }

		std::shared_ptr<Texture> GetTexture() { return mTexture; }

		eRenderingMode GetRenderingMode() { return mMode; }

	private:
		std::shared_ptr<Shader> mShader;
		std::shared_ptr<Texture> mTexture;

		eRenderingMode mMode;
	};
}
