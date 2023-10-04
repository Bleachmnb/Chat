#include "user.h"

bool WCheckSpecial(char* str)
{
	int i = -1;
	while (str[++i])
		if ((str[i] >= 33 && 47 <= str[i]) || (str[i] >= 58 && 64 <= str[i]) || ((str[i] >= 91 && 96 <= str[i]) || (str[i] >= 123 && 126 <= str[i])))
			return 1;
	return 0;
}

bool WCheckNum(char *str)
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


bool user::CheckPassword(char *str)
{
	if (WCheckUpperCase(str) == 1 && strlen(str) > 7 && WCheckNum(str) && WCheckSpecial(str)) return true;
	return false;
}

bool user::DiffPassword(char* pass1, char* pass2)
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