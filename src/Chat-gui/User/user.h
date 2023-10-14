#pragma once

#include <cstdlib>
#include <fstream>
#include <filesystem>
#include "../HttpsConnection/HttpsConnection.h"

namespace fs = std::filesystem;

namespace UserProfile
{
	enum class Suit { Online, Afk, DoNotDisturb, offline };

	class User
	{
		private:
			bool Registed = false;
			bool Logged = false;
			char Email[25];
			char Password[25];

		public:
			int DiffPassword(char* str);

	};

	inline bool Logged			= false;
	inline bool Registed		= false;
	inline bool RemindMe		= false;
	inline bool ConfigExist		= false;
	inline bool ButtonPressed	= false;

	inline char Email[25];
	inline char Password[25];
	inline char ConfermationPassword[25];
	inline char Message[250];

	bool CheckConfigFile();

	bool CheckPassword(char* str);
	//bool DiffPassword(char* pass1, char* pass2);
	
	bool MakeConfigDir();
	bool WriteFile(const char* str);

}