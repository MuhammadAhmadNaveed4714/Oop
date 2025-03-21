#include<iostream>
#include<string>
class Tree
{
private:
	static int objectCount;
public:
	Tree()
	{
		objectCount++;
	}
	int getObjectCount() const
	{
		return objectCount;
	}
};
int Tree::objectCount = 0;
using namespace std;
int main()
{
	Tree oak; 
	Tree pine;
	Tree elm;
	cout << "\n" << oak.getObjectCount() << "\n";
	return 0;
}