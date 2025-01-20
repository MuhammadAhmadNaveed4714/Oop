#include<iostream>
using namespace std;
int power(int base, int exponent)
{
	int result = 1;
	for (int i = 0; i < exponent; i++)
	{
		result *= base;
	}
	return result;
}
bool isArmstrong(int num)
{
	int originalNum = num;
	int sum = 0;
	int digitCount = 0;
	int tempNum = num;
	while (tempNum != 0)
	{
		tempNum /= 10;
		digitCount++;
	}
	tempNum = num;
	while (tempNum != 0)
	{
		int digit = tempNum % 10;
		sum += power(digit, digitCount);
		tempNum /= 10;
	}
	if (sum == originalNum)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int num = 0;
	cout << "\nEnter a number : ";
	cin >> num;
	if (isArmstrong(num))
	{
		cout << "\n" << num << " is an Armstrong number.\n";
	}
	else
	{
		cout << "\n" << num << " is not an Armstrong number.\n";
	}
	return 0;
}