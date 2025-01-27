#include<iostream>
using namespace std;
//Function to compare two strings
int compare(const char* a, const char* b, bool caseSensitive = true)
{
	int i = 0;
	while (a[i] != '\0' && b[i] != '\0')
	{
		char charA = caseSensitive ? a[i] : tolower(a[i]);
		char charB = caseSensitive ? b[i] : tolower(b[i]);
		if (charA < charB)
		{
			return -1;
		}
		else if (charA > charB)
		{
			return 1;
		}
		i++;
	}
	//Check for string length
	if (a[i] == '\0' && b[i] != '\0')
	{
		return -1;
	}
	else if (a[i] != '\0' && b[i] == '\0')
	{
		return 1;
	}
	return 0;
}
int main()
{
	const char* str1 = "Hello";
	const char* str2 = "hello";
	const char* str3 = "world";
	const char* str4 = "helloo";
	cout << "\n\n";
	cout << "\nComparison of '" << str1 << "' and '" << str2 << "' (case sensitive) : " << compare(str1, str2);
	cout << "\nComparison of '" << str1 << "' and '" << str2 << "' (case sensitive) : " << compare(str1, str2,false);
	cout << "\nComparison of '" << str1 << "' and '" << str3 << "' (case sensitive) : " << compare(str1, str3);
	cout << "\nComparison of '" << str2 << "' and '" << str4 << "' (case sensitive) : " << compare(str1, str2);
	cout << "\n\n";
	return 0;
}