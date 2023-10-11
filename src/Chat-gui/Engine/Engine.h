#pragma once

#ifndef ENGINE_H
#define ENGINE_H

#include "../pch.h"
#include "../User/user.h"
#include "../Gui/gui.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class ENGINE
{
private:
	static ID3D11Device*			pd3dDevice;
	static ID3D11DeviceContext*		pd3dDeviceContext;
	static IDXGISwapChain*			pSwapChain;
	static ID3D11RenderTargetView*	pMainRenderTargetView;

	static bool CreateDeviceD3D(HWND hWnd);
	static void CleanupDeviceD3D();
	static void CreateRenderTarget();
	static void CleanupRenderTarget();
	static void DestroyAll();
	static void InitImGui();
	static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

public:
	static HMODULE hCurrentModule;
	inline static WNDCLASSEX wc;
	inline static HWND hwnd;

	static void Render();

};

#endif