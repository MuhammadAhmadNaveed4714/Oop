#include<iostream>
using namespace std;
int reverseNumber(int num)
{
	int reversedNum = 0;
	while (num != 0)
	{
		int digit = num % 10;
		reversedNum = reversedNum * 10 + digit;
		num = num / 10;
	}
	return reversedNum;
}
int main()
{
	int num = 0;
	cout << "\nEnter a number  : ";
	cin >> num;
	int reversedNum = reverseNumber(num);
	cout << "\nReversed number : " << reversedNum << "\n";
	return 0;
}