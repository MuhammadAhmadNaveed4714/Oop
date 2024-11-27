#include <iostream>
#include <string>
using namespace std;
class NumDays
{
private:
    double hours;
    double days;
public:
    NumDays(double hours = 0)
    {
        this->hours = hours;
        this->days = hours / 8;
    }
    void setHours(double hours)
    {
        this->hours = hours;
        this->days = hours / 8;
    }
    double getHours() const
    {
        return hours;
    }
    double getDays() const
    {
        return days;
    }
    NumDays operator+(const NumDays& right) const
    {
        return NumDays(hours + right.hours);
    }
    NumDays operator-(const NumDays& right) const
    {
        return NumDays(hours - right.hours);
    }
    NumDays& operator++()
    {
        hours++;
        days = hours / 8;
        return *this;
    }
    NumDays operator++(int)
    {
        NumDays temp(hours);
        hours++;
        days = hours / 8;
        return temp;
    }
    NumDays& operator--()
    {
        hours--;
        days = hours / 8;
        return *this;
    }
    NumDays operator--(int)
    {
        NumDays temp(hours);
        hours--;
        days = hours / 8;
        return temp;
    }
};
class TimeOff
{
private:
    string employeeName;
    string employeeID;
    NumDays maxSickDays;
    NumDays sickTaken;
    NumDays maxVacation;
    NumDays vacTaken;
    NumDays maxUnpaid;
    NumDays unpaidTaken;
public:
    TimeOff(string name, string id, double maxSick, double maxVacationHours, double maxUnpaidHours)
    {
        employeeName = name;
        employeeID = id;
        maxSickDays.setHours(maxSick);
        sickTaken.setHours(0);
        maxVacation.setHours(maxVacationHours);
        if (maxVacation.getHours() > 240)
        {
            maxVacation.setHours(240);
        }
        vacTaken.setHours(0);
        maxUnpaid.setHours(maxUnpaidHours);
        if (maxUnpaid.getHours() > 240)
        {
            maxUnpaid.setHours(240);
        }
        unpaidTaken.setHours(0);
    }
    void setEmployeeName(string name)
    {
        employeeName = name;
    }
    void setEmployeeID(string id)
    {
        employeeID = id;
    }
    void setMaxSickDays(double maxSick)
    {
        maxSickDays.setHours(maxSick);
    }
    void setSickTaken(double sick)
    {
        sickTaken.setHours(sick);
    }
    void setMaxVacation(double maxVacationHours)
    {
        maxVacation.setHours(maxVacationHours);
        if (maxVacation.getHours() > 240)
        {
            maxVacation.setHours(240);
        }
    }
    void setVacTaken(double vac)
    {
        vacTaken.setHours(vac);
    }
    void setMaxUnpaid(double maxUnpaidHours)
    {
        maxUnpaid.setHours(maxUnpaidHours);
    }
    void setUnpaidTaken(double unpaid)
    {
        unpaidTaken.setHours(unpaid);
    }
    string getEmployeeName() const
    {
        return employeeName;
    }
    string getEmployeeID() const
    {
        return employeeID;
    }
    NumDays getMaxSickDays() const
    {
        return maxSickDays;
    }
    NumDays getSickTaken() const
    {
        return sickTaken;
    }
    NumDays getMaxVacation() const
    {
        return maxVacation;
    }
    NumDays getVacTaken() const
    {
        return vacTaken;
    }
    NumDays getMaxUnpaid() const
    {
        return maxUnpaid;
    }
    NumDays getUnpaidTaken() const
    {
        return unpaidTaken;
    }
};



int main()
{
    string employeeName, employeeID;
    double sickDaysTaken, vacationDaysTaken, unpaidDaysTaken;
    cout << "Enter Employee Name: ";
    getline(cin, employeeName);
    cout << "Enter Employee ID: ";
    cin >> employeeID;
    cin.ignore();
    cout << "Enter Sick Days Taken (in hours): ";
    cin >> sickDaysTaken;
    cout << "Enter Vacation Days Taken (in hours): ";
    cin >> vacationDaysTaken;
    cout << "Enter Unpaid Days Taken (in hours): ";
    cin >> unpaidDaysTaken;
    const double maxSickDays = 120;
    const double maxVacationDays = 240;
    const double maxUnpaidDays = 80;
    TimeOff employee(employeeName, employeeID, maxSickDays, maxVacationDays, maxUnpaidDays);
    employee.setSickTaken(sickDaysTaken);
    employee.setVacTaken(vacationDaysTaken);
    employee.setUnpaidTaken(unpaidDaysTaken);
    cout << "\n\n\t\t\t\t\t\Employee Information:" << endl << endl;
    cout << "Employee Name: " << employee.getEmployeeName() << endl << endl;
    cout << "Employee ID: " << employee.getEmployeeID() << endl << endl;
    cout << "Max Sick Days: " << employee.getMaxSickDays().getHours() << " hours or " << employee.getMaxSickDays().getDays() << " days" << endl << endl;
    cout << "Sick Days Taken: " << employee.getSickTaken().getHours() << " hours or " << employee.getSickTaken().getDays() << " days" << endl << endl;
    cout << "Max Vacation Days: " << employee.getMaxVacation().getHours() << " hours or " << employee.getMaxVacation().getDays() << " days" << endl << endl;
    cout << "Vacation Days Taken: " << employee.getVacTaken().getHours() << " hours or " << employee.getVacTaken().getDays() << " days" << endl << endl;
    cout << "Max Unpaid Days: " << employee.getMaxUnpaid().getHours() << " hours or " << employee.getMaxUnpaid().getDays() << " days" << endl << endl;
    cout << "Unpaid Days Taken: " << employee.getUnpaidTaken().getHours() << " hours or " << employee.getUnpaidTaken().getDays() << " days" << endl << endl;
    return 0;
}
