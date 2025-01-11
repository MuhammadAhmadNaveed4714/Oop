#include<iostream>
using namespace std;
template <typename T>
class Container
{
private:
	T value;
public:
	Container()
	{
		value = 0;
	}
	Container(T val)
	{
		value = val;
	}
	void setValue(T val)
	{
		value = val;
	}
	T getValue() const
	{
		return value;
	}
};
int main()
{
	Container <int> intContainer(10);
	cout << "\n\t\t\tRepresentation of numbers : \n";
	cout << "\n\t\t\t\Integer value : " << intContainer.getValue();
	Container <double> doubleContainer(10.00);
	cout << "\n\t\t\t\Double value : " << doubleContainer.getValue();
	cout << "\n\n";
	return 0;
}