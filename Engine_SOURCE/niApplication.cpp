#include "niApplication.h"
#include "niInput.h"
#include "niTime.h"
#include "niRenderer.h"
#include "niSceneManager.h"


namespace ni
{
	Application::Application()
		: graphicDevice(nullptr)
		, mHwnd(NULL)
		, mWidth(-1)
		, mHeight(-1)
	{

	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
		Destroy();
	}

	void Application::Initialize()
	{
		Time::Initiailize();
		Input::Initialize();

		renderer::Initialize();
		SceneManager::Initialize();

	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();

		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		Time::Render();

		graphicDevice->ClearTarget();
		graphicDevice->UpdateViewPort();

		SceneManager::Render();
		
		graphicDevice->Present();
	}

	void Application::Destroy()
	{
		SceneManager::Destroy();
	}

	void Application::SetWindow(HWND hwnd, UINT width, UINT height)
	{
		if (graphicDevice == nullptr)
		{
			mHwnd = hwnd;
			mWidth = width;
			mHeight = height;

			graphicDevice = std::make_unique<ni::graphics::GraphicDevice_Dx11>();
			ni::graphics::GetDevice() = graphicDevice.get();
		}

		RECT rt = { 0, 0, (LONG)width , (LONG)height };
		AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
		SetWindowPos(mHwnd, nullptr, 0, 0, rt.right - rt.left, rt.bottom - rt.top, 0);
		ShowWindow(mHwnd, true);
		UpdateWindow(mHwnd);
	}

}