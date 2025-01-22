#include<iostream>
using namespace std;
void input(int* rr, int size)
{
	cout << "\nAddress of rr pointer                   : " << &rr;
	cout << "\nAddress of box where rr pointer points  : " << rr;
	cout << "\n\n\n\t\t\t\t\tEnter elements of an array : \n";
	for (int i = 0; i < 5; i++)
	{
		cin >> *(rr + i);
	}
}
void display(int* arra, int size)
{
	cout << "\n\t\t\t\t\tElements of an array       : \n";
	for (int i = 0; i < 5; i++)
	{
		cout << "\n(*arra + " <<i<<") = " << * (arra + i) << "\t\t(arra + " << i << ") = " << (arra + i) << "\t\t(&arr + " << i << ") = " << (&arra + i);
	}
}
int main()
{
	int arr[5] = {0,0,0,0,0};
	cout << "\nAddress of arr pointer                  : " << &arr ;
	cout << "\nAddress of box where arr pointer points : " << arr;
	input(arr, 5);
	display(arr, 5);
	cout << "\n\n";
	cout << "\n\t\t\t\t\tElements of an array       : \n";
	for (int i = 0; i < 5; i++)
	{
		cout << "\n(*arr + " << i << ") = " << *(arr + i) << "\t\t(arr + " << i << ") = " << (arr + i) << "\t\t(&arr + " << i << ") = " << (&arr + i);
	}
	cout << "\n\n";
	return 0;
}


































