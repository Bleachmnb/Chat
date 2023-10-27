#pragma once

//#pragma execution_character_set("utf-8")
//#include <boost/array.hpp>
//#include <boost/asio.hpp>

#include <iostream>
#include "User/user.h"
#include <list>

namespace ChatSystem
{
	struct TwoPeopleChat
	{
		int						IdOtherPersone;
		std::string				ChatMessage[1000];
		void AddMessage(char* str)
		{
			int i = 0;
			while (ChatMessage[i] != "")
			{
				i++;
			}
			ChatMessage[i] = str;
		}
		char *ReturnMessage(int index)
		{
			return (char *)ChatMessage[index].c_str();
		}
	};

	class App
	{
		private:

		public:
			std::list<const char*>	UserOnDatabase;
			UserProfile::User	User = UserProfile::User(UserProfile::UserState::Offline, false, false, NULL, NULL);;
			TwoPeopleChat		ChatFriend;
			
			App();
			void ReturnOnlinePeople();
			void test() { UserOnDatabase.push_back((char *)"gabrielone"); }
	};
}

