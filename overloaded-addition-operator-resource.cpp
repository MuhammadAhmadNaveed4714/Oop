#include<cstdlib>
#include<iostream>
using namespace std;
#include"overloaded-addition-operator-header.cpp"
void FeetInches::simplify()
{
	if (inches >= 12)
	{
		feet += (inches / 12);
		inches = inches % 12;
	}
	else if (inches < 0)
	{
		feet = feet - ((abs(inches) / 12) + 1);
		inches = 12 - (abs(inches) % 12);
	}
}
void FeetInches::display()
{
	cout << "\nFeet : " << feet << "\t" << "Inches : " << inches << "\n";
}
FeetInches FeetInches::operator + (const FeetInches& right)
{
	FeetInches temp;
	temp.inches = inches + right.inches;
	temp.feet = feet + right.feet;
	temp.simplify();
	return temp;
}

FeetInches FeetInches::operator - (const FeetInches& right)
{
	FeetInches temp;
	temp.inches = inches - right.inches;
	temp.feet = feet - right.feet;
	temp.simplify();
	return temp;
}

