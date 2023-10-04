#pragma once

#include "ClientChat.h"
#include "user.h"
#include <iostream>


namespace ImGuiChat
{
	inline const char *NameState = "Register";

	void DebugStr(const char* str);
	void LoginForm();
	void RegiterForm();
	void ChatPage();
	void MainGui();


}