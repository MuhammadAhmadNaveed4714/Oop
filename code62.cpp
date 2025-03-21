#include<iostream>
using namespace std;
//Node structure
struct node
{
	int data;
	node* next;
};
//Function to delete all occurrences of a given integer K
void deleteAllOccurrences(node*& head, int k)
{
	//Handle edge case where head is nullptr
	if (head == nullptr)
	{
		return;
	}
	//Remove occurrences of K from the beginning of the list
	while (head != nullptr && head->data == k)
	{
		node* temp = head;
		head = head->next; 
		delete temp;
	}
	//Traverse the list and remove occurrences of k
	node* current = head;
	while (current != nullptr && current->next != nullptr)
	{
		if (current->next->data == k)
		{
			node* temp = current->next;
			current->next = current->next->next;
			delete temp;
		}
		else
		{
			current = current->next;
		}
	}
}
//Function to print the linked list
void printList(node* head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}
void remove(node* head)
{
	node* current = head;
	node* nextnode=nullptr;
	while (current != nullptr)
	{
		nextnode = current->next;
		delete current;
		current = nextnode;
	}
}
int main()
{
	//Create a sample linked list : 2->2->3->2->4->2->5
	node* head = new node{ 2 };
	head->next = new node{ 2 };
	head->next->next = new node{ 3 };
	head->next->next->next = new node{ 2 };
	head->next->next->next->next = new node{ 4 };
	head->next->next->next->next->next = new node{ 2 };
	head->next->next->next->next->next->next = new node{ 5 };
	cout << "\nOriginal List : \n";
	printList(head);
	deleteAllOccurrences(head, 2);
	cout << "\nModified List : \n";
	printList(head);
	remove(head);
	head = nullptr;
	return 0;
}