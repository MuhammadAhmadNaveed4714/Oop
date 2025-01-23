#include<iostream>
using namespace std;
int getStringLength(const char* str)
{
	int length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return length;
}
void concatenate(char* destination, const char* source)
{
	int i = 0;
	while (destination[i] != '\0')
	{
		i++;
	}
	int j = 0;
	while (source[j] != '\0')
	{
		destination[i] = source[j];
		i++;
		j++;
	}
	destination[i] = '\0';
}
int main()
{
	const char str1[40] = "Hello, World!";
	int length1 = getStringLength(str1);
	cout << "\n\nLength of '" << str1 << "' : " << length1 << "\n";
	char str2[20] = "Hello, ";
	const char* str3 = "World !";
	concatenate(str2, str3);
	cout << "\nConcatenated String : " << str2 << "\n";
	return 0;
}