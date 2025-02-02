#include<iostream>
using namespace std;
//Function to remove characters from the left side of a string
void removeLeft(char* destination, int count)
{
	int length = 0;
	while (destination[length] != '\0')
	{
		length++;
	}
  //Remove characters from left side
   for (int i = count; i < length; i++)
   {
   destination[i - count] = destination[i];
   }
   destination[length - count] = '\0';
}
//Function to remove characters from the right side of a string
void removeRight(char* destination, int count)
{
	int length = 0;
	while (destination[length] != '\0')
	{
		length++;
	}
	if (count >= length)
	{
		destination[0] = '\0';
	}
	else
	{
		destination[length - count] = '\0';
	}
}
int main()
{
	char ctring[30] = "LionelMessi";
	cout << "\nOriginal string : " << ctring;
	removeLeft(ctring, 5);
	cout << "\nString after removal from left : " << ctring;
	cout << "\n\n\t-----------------------------------------------------------------\n";
	char btring[30] = "CristianoRonaldo";
	cout << "\nOriginal string : " << btring;
	removeRight(btring, 5);
	cout << "\nString after removal from right : " << btring;
	cout << "\n";
	return 0;
}
