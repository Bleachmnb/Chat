#pragma once

#include "../User/user.h"
#include "../HttpsConnection/HttpsConnection.h"
#include "../../ImGui/imgui.h"
#include "../../ImGui/imgui_impl_dx11.h"
#include "../../ImGui/imgui_impl_win32.h"
#include "../EngineGui/EngineGui.h"

namespace gui
{
	inline bool				ServerOff = false;
	inline bool				SendChatMessage;
	inline bool				bDraw;
	inline LPCSTR			lpWindowName;
	inline ImVec2			vWindowSize;
	inline ImGuiWindowFlags	WindowFlags;
	inline bool				ErrorMessage;
	inline bool				HidePassword;
	inline const char		*NameState;
	inline ImVec2			ScreenSize;
	inline ImVec2			LastMessagePos;

	void	Active(bool x);
	bool	isActive();
	void	Init();
	/*  function for customizing the style/colors of the gui   */
	void	ChatStyle();
	void	FormStyle();

	/*  Helper function for UI component */

	void	TextWithPos(const char *Text, ImVec2 Pos, bool IsTextDisabilited);
	bool	CheckBoxWithPos(const char *label, bool *v, ImVec2 Pos);
	bool	ButtonWithPos(const char* Label, ImVec2 Size, ImVec2 Pos);
	void	InputTextWithPos(const char *label, char *buf, size_t size ,ImVec2 Pos, ImGuiInputTextFlags_ flag = ImGuiInputTextFlags_None);
	bool	BeginChildWithPos(const char* Label, ImVec2 Size, bool Border, ImVec2 Pos);
	void	TextWithBox(const char* Text, ImVec2 Pos, bool IsTextDisabilited);

	/* Chat UI*/
	void	ChatPage();
	void	LoginForm();
	void	RegiterForm();
	void	ServerDownPage();
	
	/* Main gui manager*/
	void	MainGui(HttpsConnection::ConnectioServer &Server);

}