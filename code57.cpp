#include<iostream>
using namespace std;
class intStack
{
private:
	int* stackArray;
	int stackSize;
	int top;
public:
	intStack(int size)
	{
		stackArray = new int[size];
		stackSize = size;
		top = -1;
	}
	intStack(const intStack& obj)
	{
		if (obj.stackSize > 0)
		{
			stackArray = new int[obj.stackSize];
		}
		else
		{
			stackArray = nullptr;
		}
		stackSize = obj.stackSize;
		top = obj.top;
	}
	~intStack()
	{
		delete[] stackArray;
		stackArray = nullptr;
    }
	bool isFull() const
	{
		return (top == stackSize - 1);
	}
	bool isEmpty() const
	{
		return (top ==  - 1);
	}
	void push(int num)
	{
		if (isFull())
		{
			cout << "\nThe stack is full.";
		}
		else
		{
			top++;
			stackArray[top] = num;
		}
	}
	void pop(int& num)
	{
		if (isEmpty())
		{
			cout << "\nThe stack is empty.";
		}
		else
		{
			num=stackArray[top];
			top--;
		}
	}
};
class MathStack : public intStack
{
     public:
	      // Constructor 
		      MathStack(int s) : intStack(s) {}
		      // MathStack operations 
void add()
{
int num=0, sum=0;
// Pop the first two values off the stack. 
pop(sum);
pop(num);
// Add the two values, store in sum. 
sum += num;
// Push sum back onto the stack. 
push(sum);
}
void sub()
{
int num=0, diff=0;
// Pop the first two values off the stack. 
pop(diff);
pop(num);
// Subtract num from diff. 
 diff -= num;
// Push diff back onto the stack. 
push(diff);
}
};
int main()
{
	int catchVar=0; // To hold values popped off the stack 
	// Create a MathStack object. 
	MathStack stack(5);
	// Push 3 and 6 onto the stack. 
	cout << "Pushing 3\n";
	stack.push(3);
	cout << "Pushing 6\n";
	stack.push(6);
	// Add the two values. 
	stack.add();
	// Pop the sum off the stack and display it. 
	cout << "The sum is ";
	stack.pop(catchVar);
	cout << catchVar << endl << endl;
	// Push 7 and 10 onto the stack 
	cout << "Pushing 7\n";
	stack.push(7);
	cout << "Pushing 10\n";
	stack.push(10);
	// Subtract 7 from 10. 
	stack.sub();
	// Pop the difference off the stack and display it. 
	cout << "The difference is ";
	stack.pop(catchVar);
	cout << catchVar << endl;
	return 0;
}





