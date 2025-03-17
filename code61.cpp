#include<iostream>
using namespace std;
//Node Structure
template <typename T>
struct Node
{
	T data;
	Node<T>* next;
};
//Function to delete all occurrences of a given integer k
template <typename T>
void deleteAllOccurrences(Node<T>*& head, int k)
{
	//Check if head node itself needs to be deleted
	while (head != nullptr && head->data == k)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
	}
	//Traveerse the linked list and delete nodes with data == k
	Node<T>* current = head;
	while (current != nullptr && current->next != nullptr)
	{
		if (current->next->data == k)
		{
			Node<T>* temp = current->next;
			current->next = current->next->next;
			delete temp;
			temp = nullptr;
		}
		else
		{
			current = current->next;
		}
	}
}
//Function to print the linked list
template <typename T>
void printList(Node<T>* head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}
int main()
{
	//Create a sample linked list : 2->2->3->2->4->2->5
	Node<int>* head = new Node<int>{ 2 };
	head->next = new Node<int>{ 2 };
	head->next->next = new Node<int>{ 3 };
	head->next->next->next = new Node<int>{ 2 };
	head->next->next->next->next = new Node<int>{ 4 };
	head->next->next->next->next->next = new Node<int>{ 2 };
	head->next->next->next->next->next->next = new Node<int>{ 5 };
	cout << "\n\nOriginal List : ";
	printList(head);
	deleteAllOccurrences(head, 2);
	cout << "\n\nModified list : ";
	printList(head);
	return 0;
}