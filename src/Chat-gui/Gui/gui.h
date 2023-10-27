#pragma once

#include "../Chat.h"
#include "../EngineGui/EngineGui.h"
#include "../HttpsConnection/HttpsConnection.h"
#include "GuiUtils/GuiUtils.h"

using namespace ChatSystem;

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

	/* Chat UI*/
	void	FrientList(ChatSystem::App& chat);
	void	ChatPage(ChatSystem::App& chat);
	void	LoginForm();
	void	RegiterForm();
	void	ServerDownPage();
	
	/* Main gui manager*/
	void	MainGui(HttpsConnection::ConnectioServer& Server , ChatSystem::App &chat);

}