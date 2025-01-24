#include<iostream>
using namespace std;
//Function to copy a string
void copyString(char* destination, const char* source)
{
	int i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}
//Function to convert a string to an integer
int convertToInteger(const char* source)
{
	int num = 0;
	int sign = 1;
	int i = 0;
	if (source[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (source[i] != '\0')
	{
		if (source[i] >= '0' && source[i] <= '9')
		{
			num = num * 10 + (source[i] - '0');
			i++;
		}
		else
		{
			break;
		}
	}
	return num * sign;
}
int main()
{
	const char* source = "Hello,World!";
	char destination[20];
	cout << "\n\nSource string      : "<<source;
	copyString(destination, source);
	cout << "\nDestination string : " << destination << "\n\n";
	 source = "4569";
	int num = convertToInteger(source);
	cout << "\nConverted Integer : " << num;
	source = "-123";
	num = convertToInteger(source);
	cout << "\nConverted Integer : " << num << "\n\n";
	return 0;
}