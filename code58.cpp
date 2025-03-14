#include<iostream>
using namespace std;
class DynIntStack
	  {
          private:
	      // Structure for stack nodes 
		      struct StackNode
		      {
		          int value;        // Value in the node 
		          StackNode * next;  // Pointer to the next node 
		      };
		      StackNode * top;       // Pointer to the stack top 
          public:
	      // Constructor 
		      DynIntStack()
		          { top = nullptr; }
		      // Destructor 
		      ~DynIntStack()
			  {
				        StackNode * nodePtr = nullptr, *nextNode = nullptr;
						// Position nodePtr at the top of the stack. 
						      nodePtr = top;
						
							      // Traverse the list deleting each node. 
							      while (nodePtr != nullptr)
							      {
							          nextNode = nodePtr->next;
							          delete nodePtr;
							          nodePtr = nextNode;
							      }
			  }
		     // Stack operations 
		      void push(int num)
			  {
				        StackNode * newNode = nullptr; // Pointer to a new node 
					    // Allocate a new node and store num there. 
					        newNode = new StackNode;
				        newNode->value = num;
					   // If there are no nodes in the list
					   // make newNode the first node. 
					        if (isEmpty())
					        {
					            top = newNode;
					            newNode->next = nullptr;
					        }
				          else  // Otherwise, insert NewNode before top. 
					      {
					            newNode->next = top;
					            top = newNode;
					      }
			  }
	    void pop(int& num)
		{
			      StackNode * temp = nullptr; // Temporary pointer 
				      // First make sure the stack isn't empty. 
				      if (isEmpty())
				      {
				          cout << "The stack is empty.\n";
				      }
			    else // pop value off top of stack 
			    {
						            num = top->value;
						            temp = top->next;
						            delete top;
						            top = temp;
						  
			    }
		}
	      bool isEmpty()
		  {
			        bool status;
				       if (!top)
				          status = true;
			           else
				            status = false;
				       return status;
		  }
	  };
int main()
{
	          int catchVar=0; // To hold values popped off the stack 
		      // Create a DynIntStack object. 
		      DynIntStack stack;
		      // Push 5, 10, and 15 onto the stack. 
		      cout << "Pushing 5\n";
	          stack.push(5);
	          cout << "Pushing 10\n";
			  stack.push(10);
			  cout << "Pushing 15\n";
			  stack.push(15);
			  // Pop the values off the stack and display them. 
			  cout << "Popping...\n";
			  stack.pop(catchVar);
			  cout << catchVar << endl;
			  stack.pop(catchVar);
			  cout << catchVar << endl;
			  stack.pop(catchVar);
			  cout << catchVar << endl;
			  // Try to pop another value off the stack. 
			  cout << "\nAttempting to pop again... ";
			  stack.pop(catchVar);
	return 0;
}