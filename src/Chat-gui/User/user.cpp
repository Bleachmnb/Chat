#include "user.h"

using namespace UserProfile;

std::string ReturnString(std::string StringToParse)
{
	int			i = 0;
	bool		IsEqual = false;
	std::string StringParsed = "";

	while (StringToParse[i])
	{
		if (IsEqual) StringParsed.push_back(StringToParse[i]);
		if ((char)StringToParse[i] == '=') IsEqual = true;
		i++;
	}
	//(char *)StringParsed.c_str();
	return StringParsed;
}

bool WCheckSpecial(char* str)
{
	int i = -1;
	while (str[++i])
		if ((str[i] >= 33 && 47 <= str[i]) || (str[i] >= 58 && 64 <= str[i]) || ((str[i] >= 91 && 96 <= str[i]) || (str[i] >= 123 && 126 <= str[i])))
			return 1;
	return 0;
}

bool WCheckNum(char* str)
{
	int i = -1;
	while (str[++i])
		if (iswalnum(str[i]) != 0) return 1;
	return 0;
}

bool WCheckUpperCase(char* str)
{
	int i = -1;

	while (str[++i])
		if (iswupper(str[i]) != 0) return 1;
	return 0;
}

bool UserProfile::CheckPassword(char *str)
{
	if (WCheckUpperCase(str) == 1 && strlen(str) > 7 && WCheckNum(str) && WCheckSpecial(str)) return true;
	return false;
}

bool UserProfile::MakeConfigDir()
{
	std::ofstream Config;
	fs::current_path(fs::temp_directory_path());

	std::string TmpPath = std::string(fs::temp_directory_path().string());
	
	TmpPath.append("ChatConfig");
	
	std::filesystem::path filepath = TmpPath;
	
	if (!fs::exists(filepath))
	{
		printf("test\n");
		fs::create_directory(filepath);
	}

	TmpPath.append("\\ConfigFile.txt");
	
	std::filesystem::path correct_path = std::filesystem::path(TmpPath);

	if (fs::exists(correct_path))
		return true;

	Config.open(correct_path);
	Config.close();
	ConfigExist = true;

	return true;
}

bool UserProfile::CheckConfigFile()
{
	int			i = 0;
	std::ifstream	Config;
	std::string		email;
	std::string		password;
	std::string ConfigText;

	fs::current_path(fs::temp_directory_path());
	
	std::string TmpPath = std::string(fs::temp_directory_path().string());
	
	TmpPath.append("ChatConfig\\ConfigFile.txt");
	
	std::filesystem::path correct_path = std::filesystem::path(TmpPath);
	
	if (!fs::exists(correct_path))
		return false;

	Config.open(correct_path);
	
	if (Config.is_open())
	{
		while (getline(Config, ConfigText))
		{
			if (i == 3) break ;
			if (ConfigText == "Logged")
			{
				i++;
			}
			else if (ConfigText.find("Email"))
			{
				email = std::string(ReturnString(ConfigText));
				i++;
			}
			else if (ConfigText.find("Password"))
			{
				password = std::string(ReturnString(ConfigText));
				i++;
			}
		}
	}
	Config.close();
	if (i != 3)
		return false;
	if (!HttpsConnection::Login(email.c_str(), password.c_str()))
		return false;
	else
	{
		UserProfile::Logged = true;
		return true;
	}
}

bool UserProfile::WriteFile(const char* str)
{
	std::ofstream Config;

	fs::current_path(fs::temp_directory_path());

	std::string TmpPath = std::string(fs::temp_directory_path().string());

	TmpPath.append("ChatConfig\\ConfigFile.txt");

	std::filesystem::path correct_path = std::filesystem::path(TmpPath);

	Config.open(correct_path);

	Config << str;

	Config.close();
	
	return true;
}

Friend UserProfile::User::GetFriend(size_t index)
{
	auto l_front = FriendList.begin();

	std::advance(l_front, index);

	return *l_front;
}

void UserProfile::User::InitFriendList()
{

	FriendList.push_back(Friend("edoardo","redadoo",UserState::Offline));
	FriendList.push_back(Friend("gabrielone", "Sdapocalypse", UserState::Offline));
	FriendList.push_back(Friend("Davidone", "ZredScorpion", UserState::Offline));
	FriendList.push_back(Friend("Antone", "LordLor", UserState::Offline));
	FriendList.push_back(Friend("Wizantibus di dio", "wiz", UserState::Offline));
	FriendList.push_back(Friend("Giosuè", "Terrone", UserState::Offline));
}
