#include<iostream>
using namespace std;
// Node Structure
struct node
{
	int data;
	node* prev;
	node* next;
};
// Function to insert a new node at the end of list
void insert(node** head, int data)
{
	node* newnode = new node();
	newnode->data = data;
	newnode->next = nullptr;
	if (*head == nullptr)
	{
		newnode->prev = nullptr;
		*head = newnode;
		return;
	}
	node* last = *head;
	while (last->next != nullptr)
	{
		last = last->next;
	}
	last->next = newnode;
	newnode->prev = last;
}
// Function to reverse the doubly linked list
void reverse(node** head)
{
	node* temp = nullptr;
	node* current = *head;
	while (current != nullptr)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	if (temp != nullptr)
	{
		*head = temp->prev;
	}
}
// Function to print the doubly linked list
void print(node* head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}
// Function to remove the doubly linked list
void remove(node* head)
{
	node* temp = nullptr;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}
int main()
{
	node* head = nullptr;
	// Insert nodes into the list
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 5);
	// Print the original list
	cout << "\nOriginal List : ";
	print(head);
	// Reverse the list
	reverse(&head);
	// Print the reversed List
	cout << "\nReversed List : ";
	print(head);
	remove(head);
	head = nullptr;
	return 0;
}