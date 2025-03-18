#include<iostream>
using namespace std;
template<typename t>
class container
{
private:
	t val;
	public:
		container()
		{
			val =100;
		}
		container(t v)
		{
			val = v;
		}
		t get()
		{
			return val;
		}
};
int main()
{
	container <int> intc(200.15);
	cout << "\n\n\t\t\tDisplay of int values of a container  ";
	cout << "\nInt    value : " << intc.get();
	container <double> douc(200.15);
	cout << "\n\n\t\t\tDisplay of double values of a container  ";
	cout << "\nDouble value : " << douc.get();
	cout << "\n\n";
	return 0;
}