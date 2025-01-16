#include<iostream>
using namespace std;
int findHCF(int num1, int num2)
{
	int min = (num1 < num2) ? num1 : num2;
	int hcf = 1;
	for (int i = 2; i <= min; i++)
	{
		if (num1 % i == 0 && num2 % i == 0)
		{
			hcf = i;
		}
	}
	return hcf;
}
int main()
{
	int num1 = 0, num2 = 0;
	cout << "\nEnter first number : ";
	cin >> num1;
	cout << "\nEnter second number : ";
	cin >> num2;
	cout << "\nHCF of " << num1 << " and " << num2 << " is " << findHCF(num1, num2) << ".\n";
	return 0;
}