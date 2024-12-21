//Here is the modified code with using namespace std; at the top :

#include <iostream>
#include <string>
using namespace std;
// Base class
class Shape {
protected:
    string color;

public:
    Shape(string c) 
    {
        color = c;
    }

    void displayColor() 
    {
        cout << "Color: " << color << endl;
    }

    virtual void calculateArea() = 0;
};

// Derived class
class Circle : public Shape {
private:
    double radius;

public:
    Circle(string c, double r) : Shape(c) {
        radius = r;
    }

    void calculateArea() {
        double area = 3.14159 * radius * radius;
        cout << "Area of Circle: " << area << endl;
    }
};

// Derived class
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(string c, double l, double w) : Shape(c)
    {
        length = l;
        width = w;
    }

    void calculateArea() 
    {
        double area = length * width;
        cout << "Area of Rectangle: " << area << endl;
    }
};

int main()
{
    cout << "\n\n";
    Circle circle("Red", 5.0);
    circle.displayColor();
    circle.calculateArea();

    cout << endl;

    Rectangle rectangle("Blue", 4.0, 6.0);
    rectangle.displayColor();
    rectangle.calculateArea();
    cout << "\n\n";
    return 0;
}


//By adding using namespace std; at the top of the code, we can avoid having to prefix standard library elements(such as cout, endl, and string) with std::.This can make the code a bit more concise and easier to read.However, it's worth noting that some programmers prefer to avoid using using namespace std; and instead use the std:: prefix to avoid potential naming conflicts.