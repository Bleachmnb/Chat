#pragma once

#include <cstdlib>
#include <fstream>
#include <filesystem>
#include "../HttpsConnection/HttpsConnection.h"

namespace fs = std::filesystem;

namespace UserProfile
{
	enum class UserState { Offline = 0, Online = 1, DoNotDisturb = 2, Invisible = 3};

	class Friend
	{
		private:
			const char		*Name = "gabriel";
			const char		*Username = "SDapocalypse";
			UserState	State = UserState::Offline;

		public:
			const char* GetName() { return Name; }
			const char* GetUserName() { return Username; }
			UserState GetState() { return State; }
			Friend(const char* _Name, const char* _Username, UserState _State) : Name(_Name), Username(_Username), State(_State) {};
	};
	
	class User
	{
		private:
			UserState			State;
			bool				Logged = false;
			char				*Email;
			char				*Password;

		public:
			std::list<Friend>	FriendList{};
			Friend GetFriend(size_t index);
			void InitFriendList();
			User(UserState _State, bool _Logged, bool _Registed, char _Email[25], char _Password[25]) : 
				Logged(_Logged), State(_State), Email(_Email), Password(_Password) {};

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
	
	bool MakeConfigDir();
	bool WriteFile(const char* str);

}