#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
int Count(char* s, const char* cs)
{
	int k = 0,
		pos = 0;
	char* t;
	while (t = strpbrk(s + pos, cs))
	{
		pos = t - s + 1;
		k++;
	}
	return k;
}
char* Change(char* s)
{
	char* tmp = new char[strlen(s)];
	char* t = tmp;
	tmp[0] = '\0';
	int i = 0;
	while (s[i] != 0)
	{
		if (s[i] == '+' || s[i] == '-' || s[i] == '=')
		{
			strcat_s(t, 101, "**");
			t += 2;
			i += 1;

		}
		else {
			*t++ = s[i++];
			*t = '\0';
		}
	}
	*t++ = s[i++];
	*t++ = s[i++];
	*t = '\0';
	strcpy(s, tmp);
	return tmp;

	return 0;
}



int main()
{
	char s[101];
	cout << "Enter string:" << endl;
	cin.getline(s, 100);
	char cs[] = "+-=";
	cout << "String consist of " << Count(s, cs) << " '=' or '+' or '-'" << endl;
	cout << "Modified string (result): " << endl;
	cout << Change(s) << endl;
	cout << endl;


	return 0;
}