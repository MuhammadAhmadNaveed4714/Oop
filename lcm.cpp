#include<iostream>
using namespace std;
int findLCM(int num1, int num2)
{
	int max = (num1 > num2) ? num1 : num2;
	while (true)
	{
		if (max % num1 == 0 && max % num2 == 0)
		{
			return max;
		}
		max++;
	}
}
int main()
{
	int num1 = 0, num2 = 0;
	cout << "\nEnter first  number : ";
	cin >> num1;
	cout << "\nEnter second number : ";
	cin >> num2;
	cout << "\nLCM of " << num1 << " and " << num2 << " is " << findLCM(num1, num2) << ".\n";
	return 0;
}