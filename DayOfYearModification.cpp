


#include <iostream>
#include <string>
using namespace std;

class DayOfYear {
private:
    int day;
    string months[12]={"January", "February", "March", "April","May", "June", "July", "August","September", "October", "November", "December"};
    int daysInMonth[12]={31, 28, 31, 30,31, 30, 31, 31,30, 31, 30, 31 };
public:
    DayOfYear(int day) {
        if (day < 1 || day > 365) {
            cout << "Invalid day. Day must be between 1 and 365." << endl;
            exit(1);
        }
        this->day = day;
    }
    DayOfYear(string month, int dayOfMonth) {
        int monthIndex = -1;
        for (int i = 0; i < 12; i++) {
            if (months[i] == month) {
                monthIndex = i;
                break;
            }
        }
        if (monthIndex == -1) {
            cout << "Invalid month." << endl;
            exit(1);
        }
        if (dayOfMonth < 1 || dayOfMonth > daysInMonth[monthIndex]) {
            cout << "Invalid day of month." << endl;
            exit(1);
        }
        int totalDays = 0;
        for (int i = 0; i < monthIndex; i++) {
            totalDays += daysInMonth[i];
        }
        this->day = totalDays + dayOfMonth;
    }
    void print() {
        int totalDays = 0;
        int month = 0;
        while (totalDays + daysInMonth[month] < day) {
            totalDays += daysInMonth[month];
            month++;
        }
        int dayOfMonth = day - totalDays;
        cout << "Day: " << months[month] << " " << dayOfMonth << endl;
    }
    DayOfYear& operator++() {
        if (day == 365) {
            day = 1;
        }
        else {
            day++;
        }
        return *this;
    }
    DayOfYear& operator--() {
        if (day == 1) {
            day = 365;
        }
        else {
            day--;
        }
        return *this;
    }
};




int main() {
    int day;
    cout << "Enter day number (1-365): ";
    cin >> day;

    DayOfYear dayOfYear(day);
    dayOfYear.print();

    DayOfYear dayOfYearBefore = dayOfYear;
    --dayOfYearBefore;
    cout << "Before ";
    dayOfYearBefore.print();

    DayOfYear dayOfYearAfter = dayOfYear;
    ++dayOfYearAfter;
    cout << "After ";
    dayOfYearAfter.print();

    return 0;
}


