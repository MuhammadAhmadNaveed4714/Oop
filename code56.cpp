
#include<iostream>
using namespace std;

class IntStack
{
private:
	int* stackArray;  // Pointer to the stack array
	int stackSize;    // The stack size
	int top;          // Indicates the top of the stack

public:
	// Constructor
	IntStack(int size)
	{
		stackArray = new int[size];
		stackSize = size;
		top = -1;  // Fix the minus sign here
	}

	// Copy constructor
	IntStack(const IntStack& obj)
	{
		if (obj.stackSize > 0)
			stackArray = new int[obj.stackSize];
		else
			stackArray = nullptr;

		stackSize = obj.stackSize;

		// Copy the stack contents
		for (int count = 0; count < stackSize; count++)
			stackArray[count] = obj.stackArray[count];

		top = obj.top;
	}

	// Destructor
	~IntStack()
	{
		delete[] stackArray;
		stackArray = nullptr;
	}

	// Stack operations
	void push(int num)
	{
		if (isFull())
		{
			cout << "The stack is full.\n";
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
			cout << "The stack is empty.\n";
		}
		else
		{
			num = stackArray[top];
			top--;  // Fix the decrement here to use top--
		}
	}

	bool isFull() const
	{
		return (top == stackSize - 1);  // Fix the minus sign here
	}

	bool isEmpty() const
	{
		return (top == -1);  // Fix the minus sign here
	}
};

int main()
{
	int catchVar; // To hold values popped off the stack
	// Define a stack object to hold 5 values.
	IntStack stack(5);

	// Push the values 5, 10, 15, 20, and 25 onto the stack.
	cout << "Pushing 5\n";
	stack.push(5);
	cout << "Pushing 10\n";
	stack.push(10);
	cout << "Pushing 15\n";
	stack.push(15);
	cout << "Pushing 20\n";
	stack.push(20);
	cout << "Pushing 25\n";
	stack.push(25);

	// Pop the values off the stack.
	cout << "Popping...\n";
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;

	return 0;
}