#pragma once

#include <iostream>

namespace user
{
	inline bool Logged = false;
	inline bool Registed = false;
	inline bool RemindMe = false;
	inline bool ButtonPressed = false;

	//Login Info
	inline char Email[25];
	inline char Password[25];
	inline char ConfermationPassword[25];

	bool CheckPassword(char* str);
	bool DiffPassword(char* pass1, char* pass2);
//	bool CheckLoginInfo();

}