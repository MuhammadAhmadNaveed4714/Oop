#include<iostream>
using namespace std;
int main()
{
	string name1 = "";
	string name2 = "";
	cout << "\nEntry of Name 1 : " << name1;
	cin >> name1;
	cout << "\nEntry of Name 2 : " << name2;
	cin >> name2;
	if (name1 > name2)
	{
		cout << "\n" << name1 << " is greater";
	}
	else if (name1 < name2)
	{
		cout << "\n" << name2 << " is greater";
	}
	else
	{
		cout << "\n" << name1 << " is equal to " << name2;
	}
	cout << ".\n";
	return 0;
}