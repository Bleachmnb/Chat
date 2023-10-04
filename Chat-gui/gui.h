#pragma once

#include <d3d9.h>
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_dx9.h"
#include "../imgui/imgui_impl_win32.h"

namespace gui
{

	const int WIDTH = 1280;
	const int HEIGHT = 800;

	const int LineX = gui::WIDTH / 2 - 390;

	inline bool exit = true;

	inline	HWND window = nullptr;
	inline	WNDCLASSEX windowClass = { };

	inline POINTS position = {  };

	inline PDIRECT3D9 d3d = nullptr;
	inline LPDIRECT3DDEVICE9 device = nullptr;
	inline D3DPRESENT_PARAMETERS presentParameters = { };
	
	void CreateHWindow(const char* windowName, int width, int height) noexcept;
	void DestroyHWindow() noexcept;

	bool CreateDevice() noexcept;
	void ResetDevice() noexcept;
	void DestroyDevice() noexcept;

	void CreateImGui() noexcept;
	void DestroyImGui() noexcept;

	void BeginRender() noexcept;
	void EndRender() noexcept;


}