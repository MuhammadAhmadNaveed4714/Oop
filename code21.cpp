#include<iostream>
using namespace std;
//Function for removal of a substring
void removalOfSubstring(char* destination, const char* source, int index)
{
	int destinationLength = 0;
	while (destination[destinationLength] != '\0')
	{
		destinationLength++;
	}
	int sourceLength = 0;
	while (source[sourceLength] != '\0')
	{
		sourceLength++;
	}
	if (index < 0 || index >= destinationLength || index + sourceLength>destinationLength)
	{
		cout << "\nMalfunction.\n";
		return ;
	}
	for (int i = index; i < destinationLength - sourceLength; i++)
	{
		destination[i] = destination[i + sourceLength];
	}
	destination[destinationLength - sourceLength] = '\0';
}
int main()
{
	char destination[20] = "Hello,World!";
	const char* source = "World";
	cout << "\nOriginal String : " << destination;
	removalOfSubstring(destination, source, 6);
	cout << "\n\nModifiedString : " << destination<<"\n";
	return 0;
}