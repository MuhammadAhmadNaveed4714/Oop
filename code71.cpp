
#include<iostream>
using namespace std;
void input(int* r, int size)
{	
	cout << "\n\t\t\t\t\tEnter elements of an array : \n";
	for (int i = 0; i < size; i++)
	{
		cin >> *(r + i);
	}
}
void display(int* r, int size)
{
	cout << "\n\t\t\t\t\tElements of an array       : \n";
	for (int i = 0; i < size; i++)
	{
		cout << "\n*arr = " << *(r + i) << "\t\t\t\t\t&arr = " << (r + i);
	}	
}
int main(){
	int size = 0;
	cout << "\nEnter size : ";
	cin >> size;
	int *arr=nullptr;
	arr = new int[size];
	input(arr, size);
	display(arr, size);
	cout << "\n\n";
	delete[]arr;
	arr = nullptr;
	return 0;
}


































