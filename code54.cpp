#include<iostream>
using namespace std;
enum Weekday
{
	Monday=1,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday
};
int main()
{
	int dayNumber = 0;
	cout << "\nEnter a day number (1-7) : ";
	cin >> dayNumber;
	if (dayNumber >= 1 && dayNumber <= 7)
	{
		Weekday day = static_cast<Weekday>(dayNumber);
		switch (day)
		{
		case Monday:
			cout << "\nMonday\n";
			break;
		case Tuesday:
			cout << "\nTuesday\n";
			break;
		case Wednesday:
			cout << "\nWednesday\n";
			break;
		case Thursday:
			cout << "\nThursday\n";
			break;
		case Friday:
			cout << "\nFriday\n";
			break;
		case Saturday:
			cout << "\nSaturday\n";
			break;
		case Sunday:
			cout << "\nSunday\n";
			break;
		}
	}
	else
	{
		cout << "\nInvalid day number!\n";
	}
	return 0;
}