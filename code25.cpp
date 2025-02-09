#include<iostream>
using namespace std;
//Function to validate input string
bool validateInput(char arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!islower(arr[i]))
		{
			return false;
		}
	}
	return true;
}
//Function to calculate letter frequency
void calculateFrequency(char arr[], int size)
{
	int frequency[26] = { 0 };
	for (int i = 0; i < size; i++)
	{
		char c = arr[i];
		frequency[c - 'a']++;
	}
	cout << "\n";
	for (int i = 0; i < 26; i++)
	{
		if (frequency[i] > 0)
		{
			cout << char(i + 'a') << " = " << frequency[i] << "\n";
		}
	}
}
int main()
{
	const int MAX_SIZE = 100;
	char arr[MAX_SIZE];
	int size = 0;
	while (true)
	{
		cout << "\nEnter a string (only lowercase letters) : ";
		cin.getline(arr, MAX_SIZE);
		
		while (arr[size] != '\0')
		{
			size++;
		}
		if (validateInput(arr, size))
		{
			break;
		}
		else
		{
			cout << "\nError : Input contains non-lowercase letters.\nPlease try again.\n";
		}
	}
	calculateFrequency(arr, size);
	return 0;
}