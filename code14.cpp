#include<iostream>
using namespace std;
//Function to insert a character at a specific index in a string
int insertString(char* destination, int index, char ch)
{
	int length = 0;
	while (destination[length] != '\0')
	{
		length++;
	}
	//Check if index is within bounds
	if (index<0 || index>length)
	{
		return -1;
	}
	//Shift characters to make space for a new character
	for (int i = length; i > index; i--)
	{
		destination[i] = destination[i - 1];
	}
	//Insert the new character
	destination[index] = ch;
	//Update the null terminator
	destination[length + 1] = '\0';
	return length + 1;
}
int main()
{
	char str[20] = "HelloWorld";
	char ch = ',';
	int index = 5;
	cout << "\nOriginal String : " << str << "\n";
	int newLength = insertString(str, index, ch);
	cout << "\nModified String : " << str << "\n";
	cout << "\nNew length : " << newLength << "\n";
	return 0;
}