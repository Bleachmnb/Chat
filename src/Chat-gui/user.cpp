#include "user.h"

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

bool UserProfile::DiffPassword(char* pass1, char* pass2)
{
	int i = 0;

	if (strlen(pass1) != strlen(pass2)) return 1;
	while (pass1[i] && pass2[i])
	{
		if (pass1[i] != pass2[i]) return 1;
		i++;
	}
	return 0;
}

bool UserProfile::MakeConfigDir()
{
	ofstream Config;

	fs::current_path(fs::temp_directory_path());

	string TmpPath = string(fs::temp_directory_path().string());
	
	TmpPath.append("ChatConfig");
	
	filesystem::path filepath = TmpPath;
	
	if (!fs::exists(filepath))
	{
		printf("test\n");
		fs::create_directory(filepath);
	}

	TmpPath.append("\\ConfigFile.txt");
	
	filesystem::path correct_path = filesystem::path(TmpPath);

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
	ifstream	Config;
	string		email;
	string		password;
	std::string ConfigText;

	fs::current_path(fs::temp_directory_path());
	
	string TmpPath = string(fs::temp_directory_path().string());
	
	TmpPath.append("ChatConfig\\ConfigFile.txt");
	
	filesystem::path correct_path = filesystem::path(TmpPath);
	
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
				UserProfile::Logged = true;
				i++;
			}
			else if (ConfigText.find("Email"))
			{
				email = string(ReturnString(ConfigText));
				i++;
			}
			else if (ConfigText.find("Password"))
			{
				password = string(ReturnString(ConfigText));
				i++;
			}
		}
	}
	Config.close();
	if (i == 3)
	{
		cout << UserProfile::Email;
		cout << UserProfile::Password;
		cout << "123as\n";
		if (!ClientChat::Login(email.c_str(), password.c_str()))
		{
			cout << UserProfile::Email;
			cout << "\n";
			cout << UserProfile::Password;

			return false;
		}
		else
		{
			cout << "3333333123as\n";
			return true;
		}
	}
	return false;
}

bool UserProfile::WriteFile(const char* str)
{
	ofstream Config;

	fs::current_path(fs::temp_directory_path());

	string TmpPath = string(fs::temp_directory_path().string());

	TmpPath.append("ChatConfig\\ConfigFile.txt");

	filesystem::path correct_path = filesystem::path(TmpPath);

	Config.open(correct_path);

	Config << str;

	Config.close();
	
	return true;
}