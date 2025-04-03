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
	void get(int i)
	{
		cout<<*(stackArray + i);
	}
};
class MathStack : public intStack
{
     public:
	      // Constructor 
		      MathStack(int s) : intStack(s) {}
		      // MathStack operations 
void add(){
int num=0, sum=0;
// Pop the first two values off the stack. 
pop(sum);
pop(num);
// Add the two values, store in sum. 
sum += num;
// Push sum back onto the stack. 
push(sum);
}
void sub(){
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
	MathStack stack(2);
	// Push 3 and 6 onto the stack. 
	cout << "Pushing 3\n";
	stack.push(3);
	cout << "Pushing 6\n";
	stack.push(6);
	// Add the two values. 
	stack.add();
	// Pop the sum off the stack and display it. 
	cout << "\nThe sum is ";
	stack.pop(catchVar);
	cout << catchVar << endl ;
	cout << "\nArray : ";
	for (int i = 0; i < 2; i++)
	{
		stack.get(i); cout << " ";
	}
	// Push 7 and 10 onto the stack 
	cout << "\n\nPushing 7\n";
	stack.push(7);
	cout << "Pushing 10\n";
	stack.push(10);
	// Subtract 7 from 10. 
	stack.sub();
	// Pop the difference off the stack and display it. 
	cout << "\n\nThe difference is ";
	stack.pop(catchVar);
	cout << catchVar << endl;
	cout << "\nArray : ";
	for (int i = 0; i < 2; i++)
	{
		stack.get(i); cout << " ";
	}
	cout << "\n";
	return 0;
}

























































#include<iostream>
using namespace std;
class intStack
{
private:
	int* stackArray;
	int stackSize;
	int top;
public:
	intStack(int s)
	{
		stackArray = new int[s];
		stackSize = s;
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
		return (top == - 1);
	}
	void push(int num)
	{
		if (isFull())
		{
			cout << "\nThe stack is full.\n";
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
			cout << "\nThe stack is empty.\n";
		}
		else
		{
			num=stackArray[top] ;
			top--;
		}
	}
	void get(int i)
	{
		cout << *(stackArray + i);
	}
};
class mathStack : public intStack
{
public:
	mathStack(int s): intStack(s){}
	void add()
	{
		int num = 0, sum = 0;
		pop(sum);
		pop(num);
		sum += num;
		push(sum);
	}
	void sub()
	{
		int num = 0, diff = 0;
		pop(diff);
		pop(num);
		diff -= num;
		push(diff);
	}
};
int main()
{
	int cv = 0;
	mathStack stack(2);
	cout << "\nPushing 3.";
	stack.push(3);
	cout << "\nPushing 6.";
	stack.push(6);
	stack.add();
	stack.pop(cv);
	cout << "\n\nSum = "<<cv<<"\n";
	cout << "\nArray : ";
	for (int i = 0; i < 2; i++)
	{
		stack.get(i); cout << " ";
	}
	cout << "\n";
	cout << "\nPushing 7.";
	stack.push(7);
	cout << "\nPushing 10.";
	stack.push(10);
	stack.sub();
	stack.pop(cv);
	cout << "\n\nDifference = " << cv << "\n";
	cout << "\nArray : ";
	for (int i = 0; i < 2; i++)
	{
		stack.get(i); cout << " ";
	}
	cout << "\n";
	return 0;
}



