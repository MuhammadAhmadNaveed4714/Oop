#include<iostream>
using namespace std;
//Function to replace an old substring with a new substring in a destination string
void replacementOfSubString(char* destination, const char* old, const char* newStr)
{
	int destinationLength = 0;
	while (destination[destinationLength] != '\0')
	{
		destinationLength++;
	}
	int oldLength = 0;
	while (old[oldLength] != '\0')
	{
		oldLength++;
	}
	int newLength = 0;
	while (newStr[newLength] != '\0')
	{
		newLength++;
	}
	char temp[256];
	int tempIndex = 0;
	for (int i = 0; i < destinationLength; i++)
	{
		if (destination[i] == old[0] && i + oldLength <= destinationLength)
		{
			bool match = true;
			for (int j = 1; j < oldLength; j++)
			{
				if (destination[i + j] != old[j])
				{
					match = false;
					break;
				}
			}
			if (match)
			{
				for (int j = 0; j < newLength; j++)
				{
					temp[tempIndex] = newStr[j];
					tempIndex++;
				}
				i += oldLength - 1;
			}
			else
			{
				temp[tempIndex] = destination[i];
				tempIndex++;
			}
		}
		else
		{
			temp[tempIndex] = destination[i];
			tempIndex++;
		}
	}
	temp[tempIndex] = '\0';
	for (int i = 0; i <= tempIndex; i++)
	{
		destination[i] = temp[i];
	}
}
int main()
{
	char str1[20] = "Hello,World!";
	cout << "\n\nOriginal String : " << str1;
	replacementOfSubString(str1, "World", "Universe");
	cout << "\n\nModified String : " << str1 << "\n";
	return 0;
}