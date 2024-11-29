#include <iostream>
#include <string>

using namespace std;

class Month
{
private:
    string name;
    int monthNumber;

    
    string months[12] =
    {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
    };

public:
    
    Month()
    {
        monthNumber = 1;
        name = months[monthNumber - 1];
    }

    
    Month(const string& monthName) 
    {
        setName(monthName);
    }

    
    Month(int monthNum) 
    {
        setMonthNumber(monthNum);
    }

    
    void setName(const string& monthName) 
    {
        name = monthName;
        for (int i = 0; i < 12; ++i)
        {
            if (months[i] == monthName)
            {
                monthNumber = i + 1;
                return;
            }
        }
        monthNumber = 1;
        name = "January";
    }

    void setMonthNumber(int monthNum)
    {
        if (monthNum >= 1 && monthNum <= 12)
        {
            monthNumber = monthNum;
            name = months[monthNum - 1];
        }
        else 
        {
            monthNumber = 1;
            name = "January";
        }
    }

    string getName() const 
    {
        return name;
    }

    int getMonthNumber() const 
    {
        return monthNumber;
    }

    // Prefix ++ operator overload (It increments month)
    Month& operator++()
    {
        monthNumber = (monthNumber % 12) + 1;
        name = months[monthNumber - 1];
        return *this;
    }

    // Postfix ++ operator overload (It increments month)
    Month operator++(int) 
    {
        Month temp = *this;
        ++(*this);
        return temp;
    }

    // Prefix -- operator overload (It decrements month)
    Month& operator--()
    {
        monthNumber = (monthNumber == 1) ? 12 : monthNumber - 1;
        name = months[monthNumber - 1];
        return *this;
    }

    // Postfix -- operator overload (It decrements month)
    Month operator--(int)
    {
        Month temp = *this;
        --(*this);
        return temp;
    }

    // Overloading << operator to print month details
    friend ostream& operator<<(ostream& os, const Month& m) 
    {
        os << m.name;
        return os;
    }

    // Overloading >> operator to input month
    friend istream& operator>>(istream& is, Month& m)
    {
        string monthName;
        is >> monthName;
        m.setName(monthName);
        return is;
    }
};




int main() {
    // Test the class and overloaded operators
    Month m1;  
    cout << "Default constructor: " << m1 << endl;

    // Create a month using a name
    Month m2("March");
    cout << "Constructor with month name : " << m2 << endl;

    // Create a month using a number
    Month m3(8);  
    cout << "Constructor with month number : " << m3 << endl;

    // Testing increment operator (++)
    ++m2;
    cout << "After incrementing m2: " << m2 << endl;

    m2++;  
    cout << "After postfix incrementing m2: " << m2 << endl;

    // Testing decrement operator (--)
    --m3;  
    cout << "After decrementing m3: " << m3 << endl;

    m3--;  
    cout << "After postfix decrementing m3: " << m3 << endl;

    // Testing input and output via >> and <<
    Month m4;
    cout << "Enter a month : ";
    cin >> m4;
    cout << "You entered: " << m4 << endl;

    return 0;
}
