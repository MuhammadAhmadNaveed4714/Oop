#include<iostream>
using namespace std;
enum weekday
{
	MONDAY=1,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY,SUNDAY
};
int main()
{
	int daynumber = 0;
	cout << "\nEnter day number (1 to 7) : ";
	cin >> daynumber;
	if (daynumber >= 1 && daynumber <= 7)
	{
		weekday day = static_cast<weekday>(daynumber);
		switch (day)
		{
		case MONDAY:
			cout << "\nMonday\n";
			break;
		case TUESDAY:
			cout << "\nTuesday\n";
			break;
		case WEDNESDAY:
			cout << "\nWednesday\n";
			break;
		case THURSDAY:
			cout << "\nThursday\n";
			break;
		case FRIDAY:
			cout << "\nFriday\n";
			break;
		case SATURDAY:
			cout << "\nSaturday\n";
			break;
		case SUNDAY:
			cout << "\nSunday\n";
			break;
		}
	}
	else
	{
		cout << "\nInvalid day number.\n";
	}
	return 0;
}