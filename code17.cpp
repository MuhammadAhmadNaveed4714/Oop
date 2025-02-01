#include<iostream>
using namespace std;
//Function to remove leading and trailing white spaces from a string
void trim(char* destination)
{
	int length = 0;
	while (destination[length] != '\0')
	{
		length++;
	}
	int start = 0;
	while (start < length && destination[start] == ' ')
	{
		start++;
	}
	int end = length - 1;
	while (end >= 0 && destination[end] == ' ')
	{
		end--;
	}
	if (start > 0 || end < length - 1)
	{
		for (int i = start; i <= end; i++)
		{
			destination[i - start] = destination[i];
		}
		destination[end - start + 1] = '\0';
	}
}
//Function to replace an old substring with a new substring in a destination string
void replace(char* destination, const char* old, const char* newStr)
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
					temp[tempIndex++] = newStr[j];
				}
				i += oldLength - 1;
			}
			else
			{
				temp[tempIndex++] = destination[i];
			}
		}
		else
		{
			temp[tempIndex++] = destination[i];
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
	char str2[20] = "Hello,World!";
	cout << "\n\nOriginal String : " << str1;
	trim(str1);
	cout << "\n\nTrimmed String : " << str1;
	cout << "\n\n\t---------------------------------------------------------------------------------------------------------";
	cout << "\n\nOriginal String : " << str2;
	replace(str2, "World", "Universe");
	cout << "\n\nModified String : " << str2 << "\n\n";
	return 0;
}