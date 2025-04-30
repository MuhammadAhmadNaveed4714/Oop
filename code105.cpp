#include<iostream>
using namespace std; 
// Function to count digits
int count(int num)
{
	int c = 0;
	while (num != 0)
	{
		num = num / 10;
		c++;
	}
	return c;
}
// Function to reverse a number
int reverse(int n)
{
	int c = 0;
	while (n != 0)
	{
		c = (c * 10) + n % 10;
		n = n / 10;
	}
	return c;
}
int main()
{
	int v = 0;
	cout << "\n\n\t\t\t\t\tEnter a number : ";
	cin >> v;
	cout << "\n\n\t\t\t\t\tDigits in a number : " << count(v) << "\n";
	cout << "\n\n\t\t\t\t\tReverse of a number : " << reverse(v) << "\n";
	return 0;
}