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
	static void InitApp();
	static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

public:
	inline static ImGuiConfigFlags   ConfFlags;
	inline static HWND hwnd;
	inline static WNDCLASSEX wc;
	static HMODULE hCurrentModule;
	inline static bool bDone = false;
	inline static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	static void Render();
	static void DestroyAll();

};

#endif