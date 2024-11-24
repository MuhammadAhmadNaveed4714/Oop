#include <iostream>
#include <string>
using namespace std;

class DayOfYear 
{
private:
    int day;
    static string months[12];
    static int daysInMonth[12];

public:
    DayOfYear(int day)
    {
        if (day < 1 || day > 365) {
            cout << "Invalid day. Day must be between 1 and 365." << endl;
            exit(1);
        }
        this->day = day;
    }

    void print() 
    {
        int totalDays = 0;
        int month = 0;
        while (totalDays + daysInMonth[month] < day) {
            totalDays += daysInMonth[month];
            month++;
        }
        int dayOfMonth = day - totalDays;
        cout << months[month] << " " << dayOfMonth << endl;
    }
};

string DayOfYear::months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
int DayOfYear::daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
    int day;
    cout << "Enter the day number (1-365): ";
    cin >> day;

    DayOfYear dayOfYear(day);
    dayOfYear.print();

    return 0;
}


