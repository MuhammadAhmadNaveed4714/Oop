#include<iostream>
#include "overloaded-addition-operator-header.cpp"
using namespace std;
int main()
{
	int fit = 0, inche = 0;
	FeetInches first, second, third;
	cout << "\nEnter a distance in feet and inches : ";
	cin >> fit >> inche;
	first.setFeet(fit);
	first.setInches(inche);
	first.display();
	cout << "\nEnter another distance in feet and inches : ";
	cin >> fit >> inche;
	second.setFeet(fit);
	second.setInches(inche);
	second.display();
	third = first + second;
	cout << "\n\nfirst + second = " << third.getFeet() << " feet, " << third.getInches() << " inches.\n";
	third = first - second;
	cout << "\n\nfirst - second = " << third.getFeet() << " feet, " << third.getInches() << " inches.\n\n";
	return 0;
}