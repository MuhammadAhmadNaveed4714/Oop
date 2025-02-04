#include<iostream>
using namespace std;
//Function to remove all occurrences of a specified character from a string.
int remove(char* destination, char ch)
{
	int length = 0;
	while (destination[length] != '\0')
	{
		length++;
	}
	int removedCount = 0;
	for (int i = 0; i < length; i++)
	{
		if (destination[i] == ch)
		{
			removedCount++;
		}
		else
		{
			destination[i - removedCount] = destination[i];
		}
	}
	destination[length - removedCount] = '\0';
	return removedCount;
}
int main()
{
	char str[45]="111";
	cout << "\nEnter any string : ";
	cin >> str;
	char ch = 'a';
	cout << "\nEnter character to remove : ";
	cin >> ch;
	cout << "\nOriginal String : " << str;
	int rem = remove(str, ch);
	cout << "\nModified String : " << str;
	cout << "\nRemoved Count   : " << rem << "\n";
	return 0;
}