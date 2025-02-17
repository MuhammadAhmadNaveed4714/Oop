#include<iostream>
using namespace std;
void Loneliest(int* arr, int* sum, int size)
{
	int st = 0;
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			st = (arr[i] - arr[j]);
			if (st < 0)
			{
				st = (st * (-1));
			}
			sum[i] += st;
		}
	}
	int loneliest = sum[0];
	for (int k = 1; k < size; k++)
	{
		if (sum[k] > loneliest)
		{
			loneliest = sum[k];
			counter = k;
		}
	}
	cout << "\nThe loneliest element's sum : " << loneliest << "\n";
	cout << "\nThe loneliest element : " << arr[counter] << "\n";
}
void input(int* a, int size)
{
	cout << "\nEnter elements of an array : \n";
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
}
void input1(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = 0;
	}
}
int main()
{
	int size = 0;
	cout << "\nEnter size of the array : ";
	cin >> size;
	int* arr = new int[size];
	int* sum = new int[size];
	input1(sum, size);
	input(arr, size);
	Loneliest(arr, sum, size);
	delete[]arr;
	arr = sum;
	delete[]sum;
	sum = nullptr;
	return 0;
}
