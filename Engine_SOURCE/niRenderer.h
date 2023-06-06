#pragma once
#include "JEngine.h"
#include "niGraphicDevice_Dx11.h"
#include "niMesh.h"
#include "niShader.h"

using namespace ni::math;
namespace renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	extern Vertex vertexes[];
	extern ID3D11InputLayout* triangleLayout;
	extern ni::Mesh* mesh;
	extern ID3D11Buffer* triangleConstantBuffer;
	extern ni::Shader* shader;
	extern ID3D11PixelShader* trianglePSShader;

	void Initialize();
	void Release();
	void Update();
}
