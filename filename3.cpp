#include<iostream>
using namespace std;
class vehicle
{
private:
	int model;
	int wheels;
public:
	vehicle()
	{
		cout << "\nVehicle default constructor called.\n";
		model = -10;
		wheels = -20;
	}
	vehicle(int m,int w)
	{
		cout << "\nVehicle overloaded constructor called.\n";
		model = m;
		wheels = w;
	}
	~vehicle()
	{
		cout << "\nVehicle destructor called.\n";
	}
	void display()
	{
		cout << "\nImplementing display function of vehicle.\n";
		cout << "\nModel : " << model;
		cout << "\nWheels : " << wheels;
	}
};
class car : public vehicle
{
private:
	int passengers;
public:
	car(): vehicle()
	{
		cout << "\nCar default constructor called.\n";
		passengers = -30;
	}
	car(int m, int w,int p):vehicle(m,w)
	{
		cout << "\nCar overloaded constructor called.\n";
		passengers = p;
	}
	~car()
	{
		cout << "\nCar destructor called.\n";
	}
	void display()
	{
		vehicle::display();
		cout << "\nImplementing display function of car.\n";
		cout << "\nPassengers : " << passengers;
	}
};
class truck : public vehicle
{
private:
	int load;
public:
	truck() : vehicle()
	{
		cout << "\nTruck default constructor called.\n";
		load = -40;
	}
    truck(int m, int w, int l) :vehicle(m, w)
	{
		cout << "\nTruck overloaded constructor called.\n";
		load = l;
	}
	~truck()
	{
		cout << "\nTruck destructor called.\n";
	}
	void display()
	{
		vehicle::display();
		cout << "\nImplementing display function of truck.\n";
		cout << "\nLoad : " << load;
	}
};
int main()
{
	cout << "\n---\n";
	car c1;
	cout << "\n---\n";
	c1.display();
	cout << "\n---\n";
	car c2(100,200,300);
	cout << "\n---\n";
	c2.display();
	cout << "\n---\n";
	truck t1;
	cout << "\n---\n";
	t1.display();
	cout << "\n---\n";
	truck t2(1000, 2000, 4000);
	cout << "\n---\n";
	t2.display();
	cout << "\n---\n";
	return 0;
}