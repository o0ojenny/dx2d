#pragma once
#include "JEngine.h"
#include "niGraphicDevice_Dx11.h"
#include "niMesh.h"
#include "niShader.h"
#include "niConstantBuffer.h"
#include "niCamera.h"

using namespace ni::math;
using namespace ni::graphics;
namespace renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
		Vector2 uv;
	};

	struct ObjectInfo
	{
		Vector4 pos;
		Vector4 color;
		Vector4 scale;
	};

	CBUFFER(TransformCB, CBSLOT_TRANSFORM)
	{
		Matrix mWorld;
		Matrix mView;
		Matrix mProjection;
	};

	extern Vertex vertexes[];
	extern ni::graphics::ConstantBuffer* constantBuffer[(UINT)eCBType::End];

	extern Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState[];
	extern Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[];
	extern Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[];
	extern Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[];

	extern ni::Camera* mainCamera;
	extern std::vector<ni::Camera*> cameras;
	extern std::vector<DebugMesh> debugMeshes;

	void Initialize();
	void Render();
	void Release();

	void PushDebugMeshAttribute(DebugMesh mesh);
}
