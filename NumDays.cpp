#include <iostream>
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

int main() 
{
    double hours1, hours2;
    cout << "Enter the number of hours for NumDays1: ";
    cin >> hours1;
    cout << "Enter the number of hours for NumDays2: ";
    cin >> hours2;
    NumDays numDays1(hours1);
    NumDays numDays2(hours2);
    NumDays sum = numDays1 + numDays2;
    cout << "Sum of hours of NumDays1 and NumDays2: " << sum.getHours() << endl;
    cout << "Sum of  days of NumDays1 and NumDays2: " << sum.getDays() << endl;
    NumDays difference = numDays1 - numDays2;
    cout << "Difference of hours of NumDays1 and NumDays2: " << difference.getHours() << endl;
    cout << "Difference of  days of NumDays1 and NumDays2: " << difference.getDays() << endl;
    NumDays originalNumDays1 = numDays1;
    NumDays originalNumDays2 = numDays2;
    cout << "\n\n";
    cout << "Incrementing hours for NumDays1: " << originalNumDays1.getHours() << " + 1 = ";
    ++numDays1;
    cout << numDays1.getHours() << endl;
    cout << "Incrementing  days for NumDays1: " << numDays1.getDays() << endl;
    cout << "Decrementing hours for NumDays1: " << originalNumDays1.getHours() << " - 1 = ";
    originalNumDays1--;
    cout << originalNumDays1.getHours() << endl;
    cout << "Decrementing  days for NumDays1: " << originalNumDays1.getDays() << endl;
    cout << "Incrementing hours for NumDays2: " << originalNumDays2.getHours() << " + 1 = ";
    ++numDays2;
    cout << numDays2.getHours() << endl;
    cout << "Incrementing  days for NumDays2: " << numDays2.getDays() << endl;
    cout << "Decrementing hours for NumDays2: " << originalNumDays2.getHours() << " - 1 = ";
    originalNumDays2--;
    cout << originalNumDays2.getHours() << endl;
    cout << "Decrementing  days for NumDays2: " << originalNumDays2.getDays() << endl;
    return 0;
}
