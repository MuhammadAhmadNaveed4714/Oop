#include<iostream>
#include<string>
using namespace std;
enum Day 
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};
int main()
{
    int dayNumber;
    cout << "Enter a day number (1-7) representing the days of the week (Monday to Sunday): ";
    cin >> dayNumber;
    if (dayNumber < 1 || dayNumber > 7) 
    {
        cout << "Invalid day number. Please enter a number between 1 and 7." << endl;
        return 1;
    }
    Day day = static_cast<Day>(dayNumber - 1);

    // Print the corresponding weekday name
    switch (day) {
    case MONDAY:
        cout << "Monday" << endl;
        break;
    case TUESDAY:
        cout << "Tuesday" << endl;
        break;
    case WEDNESDAY:
        cout << "Wednesday" << endl;
        break;
    case THURSDAY:
        cout << "Thursday" << endl;
        break;
    case FRIDAY:
        cout << "Friday" << endl;
        break;
    case SATURDAY:
        cout << "Saturday" << endl;
        break;
    case SUNDAY:
        cout << "Sunday" << endl;
        break;
    }

    return 0;
}