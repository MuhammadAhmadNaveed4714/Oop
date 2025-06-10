#include<iostream>
using namespace std;
// struct node
struct node
{
	int data;
	node* next;
	node* prev;
};
// Function to create a new node
node* create(int data)
{
	node* newnode = new node();
	newnode->data = data;
	newnode->next = nullptr;
	newnode->prev = nullptr;
	return newnode;
}
// Function to insert a node at end of linked list
void insert(node** head, int data)
{
	node* newnode = create(data);
	if (*head == nullptr)
	{
		*head = newnode;
		return;
	}
	node* lastnode = *head;
	while (lastnode->next != nullptr)
	{
		lastnode = lastnode->next;
	}
	lastnode->next = newnode;
	newnode->prev = lastnode;
}
// Function to reverse the doubly linked list
void reverse(node** head)
{
	node* current = *head;
	node* temp = nullptr;
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
// Function to print the doubly linked list forward
void printforward(node* head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}
// Function to remove a doubly linked list
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
	// insert nodes in doubly linked list
	insert(&head, 11);
	insert(&head, 12);
	insert(&head, 13);
	insert(&head, 14);
	insert(&head, 15);
	insert(&head, 16);
	cout << "\nOriginal List (forward) : ";
	printforward(head);
	reverse(&head);
	cout << "\nReversed List (forward) : ";
	printforward(head);
	remove(head);
	head = nullptr;
	return 0;
}