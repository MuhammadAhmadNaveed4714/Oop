#include<iostream>
using namespace std;
//Function to remove characters from the left or right side of a string
int remove(char* destination, int count)
{
	int length = 0;
	while (destination[length] != '\0')
	{
		length++;
	}
	if (count < 0)
	{
		//remove characters from right side
		for (int i = length + count; i < length; i++)
		{
			destination[i] = destination[i + 1];
		}
		destination[length + count] = '\0';
	}
	else
	{
		//Remove characters from left side
		for (int i = count; i < length; i++)
		{
			destination[i - count] = destination[i];
		}
		destination[length - count] = '\0';
	}
	return length - abs(count);
}
//Function to remove a specific character from a string
int remove(char* destination, char ch)
{
	int length = 0;
	int removedCount = 0;
	while (destination[length] != '\0')
	{
		if (destination[length] == ch)
		{
			removedCount++;
		}
		else
		{
			destination[length - removedCount] = destination[length];
		}
		length++;
	}
	destination[length - removedCount] = '\0';
	return removedCount;
}
int main()
{
	char str1[20] = "Hello,World!";
	char str2[20] = "Hello,World!";
	cout << "\n\nOriginal string : " << str1;
	int newLength = remove(str1, 7);
	cout << "\n\nModified string : " << str1;
	cout << "\n\nNew length : " << newLength;
	cout << "\n\n-----------------------------------------\n";
	cout << "\nOriginal string : " << str2;
	int removedCount = remove(str2, 'l');
	cout << "\n\nModified string : " << str2;
	cout << "\n\nRemoved count : " << removedCount << "\n\n";
	return 0;
}