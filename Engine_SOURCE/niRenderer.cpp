#include "niRenderer.h"
#include "niInput.h"
#include "niTime.h"


namespace renderer
{
	Vertex vertexes[4] = {};
	
	// Input Layout (정점 정보)
	ID3D11InputLayout* triangleLayout = nullptr;


	// Vertex Buffer
	ni::Mesh* mesh = nullptr;

	/*ID3D11Buffer* triangleBuffer = nullptr;
	ID3D11Buffer* triangleIdxBuffer = nullptr;*/

	ID3D11Buffer* triangleConstantBuffer = nullptr;

	ni::Shader* shader = nullptr;
	
	// error blob
	ID3DBlob* errorBlob = nullptr;
	
	// Vertex Shader code -> Binary Code
	ID3DBlob* triangleVSBlob = nullptr;

	// Vertex Shader
	ID3D11VertexShader* triangleVSShader = nullptr;

	// Pixel Shader code -> Binary Code
	ID3DBlob* trianglePSBlob = nullptr;

	// Vertex Shader
	ID3D11PixelShader* trianglePSShader = nullptr;

	Vector4 trianglePos = { 0.0f, 0.0f, 0.0f, 1.0f };

	void SetupState()
	{
		

	}

	void LoadBuffer()
	{
		// Vertex Buffer
		mesh = new ni::Mesh();
		mesh->CreateVertexBuffer(vertexes, 4);

		std::vector<UINT> indexes = {};
		indexes.push_back(0);
		indexes.push_back(1);
		indexes.push_back(2);

		indexes.push_back(0);
		indexes.push_back(2);
		indexes.push_back(3);
		mesh->CreateIndexBuffer(indexes.data(), indexes.size());

		// Constant Buffer
		D3D11_BUFFER_DESC triangleCSDesc = {};
		triangleCSDesc.ByteWidth = sizeof(Vector4);
		triangleCSDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_CONSTANT_BUFFER;
		triangleCSDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		triangleCSDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

		ni::graphics::GetDevice()->CreateBuffer(&triangleConstantBuffer, &triangleCSDesc, nullptr);

		Vector4 pos(0.3f, 0.0f, 0.0f, 1.0f);
		ni::graphics::GetDevice()->SetConstantBuffer(triangleConstantBuffer, &pos, sizeof(Vector4));
		ni::graphics::GetDevice()->BindConstantBuffer(eShaderStage::VS, eCBType::Transform, triangleConstantBuffer);
	}

	void LoadShader()
	{
		//ni::graphics::GetDevice()->CreateShader();

		shader = new ni::Shader();
		shader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "main");
		shader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "main");
	}

	void Update()
	{
		//if (Input::KeyP(eKeyCode::W) || Input::KeyD(eKeyCode::W))
		//{
		//	Pos.y += 0.5 * Time::DeltaTime();
		//}
		//else if (Input::KeyP(eKeyCode::S) || Input::KeyD(eKeyCode::S))
		//{
		//	Pos.y -= 0.5 * Time::DeltaTime();
		//}
		//if (Input::KeyP(eKeyCode::A) || Input::KeyD(eKeyCode::A))
		//{
		//	Pos.x -= 0.5 * Time::DeltaTime();
		//}
		//else if (Input::KeyP(eKeyCode::D) || Input::KeyD(eKeyCode::D))
		//{
		//	Pos.x += 0.5 * Time::DeltaTime();
		//}
		////LoadBuffer();
		//ni::graphics::GetDevice()->SetConstantBuffer(triangleConstantBuffer, &Pos, sizeof(Vector4));
		//ni::graphics::GetDevice()->BindConstantBuffer(eShaderStage::VS, eCBType::Transform, triangleConstantBuffer);


	}

	void Initialize()
	{
		// 삼각형 출력
		/*vertexes[0].pos = Vector3(0.0f, 0.5f, 0.0f);
		vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		vertexes[1].pos = Vector3(0.5f, -0.5f, 0.0f);
		vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[2].pos = Vector3(-0.5f, -0.5f, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);*/

		// 사각형 출력
		vertexes[0].pos = Vector3(-0.5f, 0.5f, 0.0f);
		vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		vertexes[1].pos = Vector3(0.5f, 0.5f, 0.0f);
		vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[2].pos = Vector3(0.5f, -0.5f, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		vertexes[3].pos = Vector3(-0.5f, -0.5f, 0.0f);
		vertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

		// 마름모 출력
		/*vertexes[0].pos = Vector3(0.0f, -0.5f, 0.0f);
		vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		vertexes[1].pos = Vector3(-0.5f, 0.0f, 0.0f);
		vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[2].pos = Vector3(0.5f, 0.0f, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		vertexes[3].pos = Vector3(0.5f, 0.0f, 0.0f);
		vertexes[3].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		vertexes[4].pos = Vector3(-0.5f, 0.0f, 0.0f);
		vertexes[4].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[5].pos = Vector3(0.0f, 0.5f, 0.0f);
		vertexes[5].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);*/

		// 사다리꼴 출력
		//vertexes[0].pos = Vector3(-0.5f, -0.5f, 0.0f);
		//vertexes[0].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		//vertexes[1].pos = Vector3(-0.7f, 0.0f, 0.0f);
		//vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		//vertexes[2].pos = Vector3(0.5f, -0.5f, 0.0f);
		//vertexes[2].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		//vertexes[3].pos = Vector3(0.5f, -0.5f, 0.0f);
		//vertexes[3].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		//vertexes[4].pos = Vector3(-0.7f, 0.0f, 0.0f);
		//vertexes[4].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		//vertexes[5].pos = Vector3(0.7f, 0.0f, 0.0f);
		//vertexes[5].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		SetupState();
		LoadBuffer();
		LoadShader();

	}

	void Release()
	{
		if (triangleLayout != nullptr)
			triangleLayout->Release();
		
		if (triangleConstantBuffer != nullptr)
			triangleConstantBuffer->Release();

		if (trianglePSShader != nullptr)
			trianglePSShader->Release();
	}
}


