#include<iostream>
using namespace std;
//Function to convert all characters of destination array to lower case
void makeLower(char* destination)
{
	int i = 0;
	while (destination[i] != '\0')
	{
		if (destination[i] >= 'A' && destination[i] <= 'Z')
		{
			destination[i] = destination[i] - 'A' + 'a';
		}
		i++;
	}
}
//Function to reverse characters in destination array
void reverse(char* destination)
{
	int length = 0;
	while (destination[length] != '\0')
	{
		length++;
	}
	int start = 0;
	int end = length - 1;
	while (start < end)
	{
		char temp = destination[start];
		destination[start] = destination[end];
		destination[end] = temp;
		start++;
		end--;
	}
}
int main()
{
	char str1[] = "HELLO,WORLD!";
	cout << "\n\nOriginal string : " << str1 << "\n";
	makeLower(str1);
	cout << "\n\nLower case string : " << str1 << "\n";
	char str2[] = "Hello,World!";
	cout << "\n\nOriginal string : " << str2 << "\n";
	reverse(str2);
	cout << "\n\nReversed string : " << str2 << "\n";
	return 0;
}