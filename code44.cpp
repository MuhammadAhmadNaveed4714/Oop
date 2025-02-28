#include<iostream>
using namespace std;
//Function to find the mode of an array
int findMode(int array[], int size)
{
	if (size == 0)
	{
		return -1;
	}
	int maxCount = 0;
	int mode = -1;
	for (int i = 0; i < size; i++)
	{
		int count = 0;
		for (int j = 0; j < size; j++)
		{
			if (array[i] == array[j])
			{
				count++;
			}
		}
		if (count > maxCount)
		{
			maxCount = count;
			mode = array[i];
		}
	}
	if (maxCount == 1)
	{
		return -1;
	}
	return mode;
}
int main()
{
	int array[] = { 5,5,5,6,6,6,6,7,7,8,8,8,8,8,8,9,9,9,9,9,9,9 };
	int size = sizeof(array) / sizeof(array[0]);
	int mode = findMode(array, size);
	if (mode == -1)
	{
		cout << "\nNo Mode found.\n";
	}
	else
	{
		cout << "\nMode : " << mode << "\n";
	}
	return 0;
}