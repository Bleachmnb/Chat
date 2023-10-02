#pragma once

#include<d3d9.h>
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_dx9.h"
#include "../imgui/imgui_impl_win32.h"
#include "user.h"

namespace gui
{

	const int WIDTH = 500;
	const int HEIGHT = 500;

	inline bool exit = true;

	inline	HWND window = nullptr;
	inline	WNDCLASSEXA windowClass = { };

	inline POINTS position = {  };

	inline PDIRECT3D9 d3d = nullptr;
	inline LPDIRECT3DDEVICE9 device = nullptr;
	inline D3DPRESENT_PARAMETERS presentParameters = { };

	bool InputTextWithButtonInline(const char* NameInput, const char* NameButton, char* InputBuf, size_t SizeBuf, const ImVec2& posInput, float OffSet);
	
	void CreateHWindow(const char* windowName, int width, int height) noexcept;
	void DestroyHWindow() noexcept;

	bool CreateDevice() noexcept;
	void ResetDevice() noexcept;
	void DestroyDevice() noexcept;

	void CreateImGui() noexcept;
	void DestroyImGui() noexcept;

	void BeginRender() noexcept;
	void EndRender() noexcept;
	void Render() noexcept;


}