
#include <iostream>
#include <string>
using namespace std;
// Base class
class Vehicle 
{
protected:
    string brand;
    string model;
    int year;
public:
    Vehicle(string b, string m, int y)
    {
        brand = b;
        model = m;
        year = y;
    }
    void displayInfo() 
    {
        cout << "Brand: " << brand << std::endl;
        cout << "Model: " << model << std::endl;
        cout << "Year: " << year << std::endl;
    }
};
// Derived class
class Car : public Vehicle 
{
private:
    int numDoors;
public:
    Car(string b, std::string m, int y, int doors) : Vehicle(b, m, y) 
    {
        numDoors = doors;
    }
    void displayCarInfo() 
    {
        displayInfo();
        cout << "Number of Doors: " << numDoors << std::endl;
    }
};
// Derived class
class Truck : public Vehicle 
{
private:
    int cargoCapacity;
public:
    Truck(string b, string m, int y, int capacity) : Vehicle(b, m, y)
    {
        cargoCapacity = capacity;
    }
    void displayTruckInfo()
    {
        displayInfo();
        cout << "Cargo Capacity: " << cargoCapacity << " tons" << std::endl;
    }
};
int main() 
{
    Car car("Toyota", "Camry", 2020, 4);
    car.displayCarInfo();
    cout << endl;
    Truck truck("Ford", "F-150", 2015, 2);
    truck.displayTruckInfo();
    return 0;
}


