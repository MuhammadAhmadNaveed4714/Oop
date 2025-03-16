#include<iostream>
using namespace std;
//Node Structure
template <typename T>
struct Node
{
	T data;
	Node<T>* next;
};
//Function to rearrange the linked list in a zigzag pattern
template<typename T>
void zigzagList(Node<T>* head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return;//List has zero or one node,no need to rearrange
	}
	Node<T>* current = head;
	bool flag = true;//Flag to track the direction of the zigzag
	while (current->next != nullptr)
	{
		if (flag)
		{
			//Swap current node's data with next node's data
			T temp = current->data;
			current->data = current->next->data;
			current->next->data = temp;
			flag = false;//Toggle flag
		}
		else
		{
			flag = true;//Toggle flag
		}
		current = current->next;//Move to next node
	}
}
//Function to print the linked list
template <typename T>
void printList(Node<T>* head)
{
	while (head != nullptr)
	{
		cout << head->data<<" ";
		head = head->next;
	}
	cout << "\n";
}
int main()
{
	//Create a sample linked list : 4->3->7->->8->6->2->1
	Node<int>* head = new Node<int>{ 4 };
	head->next = new Node<int>{ 3 };
	head->next->next = new Node<int>{ 7 };
	head->next->next->next = new Node<int>{ 8 };
	head->next->next->next->next = new Node<int>{ 6 };
	head->next->next->next->next->next = new Node<int>{ 2 };
	head->next->next->next->next->next->next = new Node<int>{ 1 };
	cout << "\nOriginal List : \n";
	printList(head);
	zigzagList(head);
	cout << "\n\nRearranged List : ";
	printList(head);
	return 0;
}