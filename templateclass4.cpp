#include<iostream>
using namespace std;
int main()
{
	int numerator = 0, denominator = 0;
	cout << "\n\nEnter numerator : ";
	cin >> numerator;
	cout << "\nEnter denominator : ";
	cin >> denominator;
	try
	{
		if (denominator == 0)
		{
			throw denominator;
		}
		int result = numerator / denominator;
		cout << "\nResult : " << result << "\n";
	}
	catch (int e)
	{
		cout << "\nError : Division by zero is not allowed ! \n";
	}
	return 0;
}