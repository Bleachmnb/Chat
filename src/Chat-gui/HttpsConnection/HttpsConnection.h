#pragma once


#include <iostream>


namespace HttpsConnection
{
	inline std::string ServerIp = "http://25.53.147.26";
	inline std::string CheckServerIp = "http://25.53.147.26/login/?email=&password=";
	enum class  StateTryConnection {FirstTry = 0,ServerDown = 1,ServerOn = 2};

	class ConnectioServer
	{
		private:
			int	ConnectionState;


		public:
			bool	CheckServer();
			void	SetConnectionState(int NewState) { ConnectionState = NewState; }
			int		GetConnectionState() { return this->ConnectionState;}

					ConnectioServer();
					~ConnectioServer();
	};

	bool Register(const char* email, const char* password);
	bool Login(const char* email, const char* password);


}