#pragma once


#include "engine.h"
#include "user.h"
#include "ClientChat.h"

namespace gui
{
	inline const char *NameState  = "Register";
	inline bool BlurredPass;

	void DebugStr(const char* str);
	void ChatPage();
	void LoginForm();
	void RegiterForm();
	void MainGui();

}