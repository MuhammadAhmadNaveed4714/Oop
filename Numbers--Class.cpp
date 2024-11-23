

#include <iostream>
#include <string>
using namespace std;

class Numbers {
private:
    int number;
    static string lessThan20[20];
    static string tens[10];
    static string thousands[2];

public:
    Numbers(int num) {
        if (num < 0 || num > 9999) {
            cout << "Invalid number. Number should be between 0 and 9999." << endl;
            exit(1);
        }
        number = num;
    }

    void print() {
        if (number < 20) {
            cout << lessThan20[number] << endl;
        }
        else if (number < 100) {
            if (number % 10 == 0) {
                cout << tens[number / 10] << endl;
            }
            else {
                cout << tens[number / 10] << " " << lessThan20[number % 10] << endl;
            }
        }
        else if (number < 1000) {
            cout << lessThan20[number / 100] << " " << thousands[0] << " ";
            if (number % 100 != 0) {
                printHelper(number % 100);
            }
            else {
                cout << endl;
            }
        }
        else {
            cout << lessThan20[number / 1000] << " " << thousands[1] << " ";
            int remaining = number % 1000;
            if (remaining >= 100) {
                cout << lessThan20[remaining / 100] << " " << thousands[0] << " ";
                remaining = remaining % 100;
            }
            if (remaining != 0) {
                printHelper(remaining);
            }
            else {
                cout << endl;
            }
        }
    }

    void printHelper(int num) {
        if (num < 20) {
            cout << lessThan20[num] << endl;
        }
        else {
            if (num % 10 == 0) {
                cout << tens[num / 10] << endl;
            }
            else {
                cout << tens[num / 10] << " " << lessThan20[num % 10] << endl;
            }
        }
    }
};

string Numbers::lessThan20[20] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
string Numbers::tens[10] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
string Numbers::thousands[2] = { "hundred", "thousand" };

int main() {
    int num;
    cout << "Enter a number between 0 and 9999: ";
    cin >> num;
    Numbers n(num);
    n.print();
    return 0;
}


