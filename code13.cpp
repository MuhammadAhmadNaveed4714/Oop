#include<iostream>
using namespace std;
//Function to find a substring in a string
int findSubString(char* destination, const char* key, int start = 0)
{
	int keyLength = 0;
	while (key[keyLength] != '\0')
	{
		keyLength++;
	}
	int destinationLength = 0;
	while (destination[destinationLength] != '\0')
	{
		destinationLength++;
	}
	if (start + keyLength > destinationLength)
	{
		return -1;
	}
	for (int i = start; i <= destinationLength - keyLength; i++)
	{
		bool match = true;
		for (int j = 0; j < keyLength; j++)
		{
			if (destination[i + j] != key[j])
			{
				match = false;
				break;
			}
		}
		if (match)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	char str[] = "Hello,World!";
	const char* key1 = "Hell";
	const char* key2 = "Universe";
	int index1 = findSubString(str, key1);
	cout << "\n";
	cout << "\nIndex of ' " << key1 << "' : " << index1 << "\n";
	int index2 = findSubString(str, key2);
	cout << "\n";
	cout << "\nIndex of ' " << key2 << "' : " << index2 << "\n";
	return 0;
}