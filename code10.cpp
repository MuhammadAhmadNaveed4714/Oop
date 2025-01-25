#include<iostream>
using namespace std;
//Function to convert a string to a float
float convertToFloat(const char* source)
{
	float num = 0.0f;
	int sign = 1; //1 for +ive,-1 for -ive
	int i = 0;
	int decimalPoint = 0;
	//For negative sign
	if (source[i] == '-')
	{
		sign = -1;
		i++;
	}
	//Convert string to float
	while (source[i] != '\0')
	{
		if (source[i] == '.')
		{
			decimalPoint = 1;
			i++;
		}
		else if (source[i] >= '0' && source[i] <= '9')
		{
			if (decimalPoint == 0)
			{
				num = (num * 10) + (source[i] - '0');
			}
			else
			{
				num = num + (source[i] - '0') / (10.0f * decimalPoint);
				decimalPoint *= 10;
			}
			i++;
		}
		else
		{
			break;
		}
	}
	return num * sign;
}
//Function to convert all characters to uppercase
void makeUpper(char* destination)
{
	int i = 0;
	while (destination[i] != '\0')
	{
		if (destination[i] >= 'a' && destination[i] <= 'z')
		{
			destination[i] = destination[i] - 'a' + 'A';
		}
		i++;
	}
}
int main()
{
	const char* source = "3.14159";
	float num = convertToFloat(source);
	cout << "\nConverted float : " << num << "\n";
	char str[] = "hello,world!";
	cout << "\nOriginal string : " << str << "\n";
	makeUpper(str);
	cout << "\nUpper case string : " << str << "\n";
	return 0;
}