#include<iostream>
using namespace std;
//Function to insert a string
int insertString(char* destination, int index, const char* src)
{
	int srcLength = 0;
	while (src[srcLength] != '\0')
	{
		srcLength++;
	}
	int destinationLength = 0;
	while (destination[destinationLength] != '\0')
	{
		destinationLength++;
	}
	//Check if index is within bounds
	if (index<0 || index>destinationLength)
	{
		return -1;
	}
	for (int i = destinationLength; i >= index; i--)
	{
		destination[i + srcLength] = destination[i];
	}
	//Insert the new string
	for (int i = 0; i < srcLength; i++)
	{
		destination[index + i] = src[i];
	}
	destination[destinationLength + srcLength] = '\0';
	return destinationLength + srcLength;
}
int main()
{
	char str[20] = "HelloWorld";
	const char* src = " to ";
	cout << "\n\nOriginal string : " << str;
	int newLength = insertString(str, 5, src);
	cout << "\n\nModified string : " << str;
	cout << "\n\nNew length : " << newLength << "\n";
	return 0;
}