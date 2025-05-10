#include<iostream>
using namespace std;
// Node structure
struct node
{
	int data;
	node* next;
};
// Function to insert a new node at the end of list
void insertnode(node** head, int data)
{
	node* newnode = new node();
	newnode->data = data;
	newnode->next = nullptr;
	if (*head == nullptr)
	{
		*head = newnode;
		return;
	}
	node* last = *head;
	while (last->next != nullptr)
	{
		last = last->next;
	}
	last->next = newnode;
}
// Function to find the middle of linked list
void findmiddleodd(node* head)
{
	if (head == nullptr)
	{
		cout << "\nList is empty.\n";
		return;
	}
	node* slow = head;
	node* fast = head;
	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << "\nMiddle element : " << slow->data << "\n";
}
// Function to find the middle of linked list
void findmiddleeven(node* head)
{
	if (head == nullptr)
	{
		cout << "\nList is empty.\n";
		return;
	}
	node* slow = head;
	node* fast = head;
	node* mid = nullptr;
	while (fast != nullptr && fast->next != nullptr)
	{
		mid = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << "\nMiddle element : " << mid->data << "\n";
}
// Function to print the linked list
void print(node* head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}
// Function to delete the linked list
void remove(node* h)
{
	node* temp = nullptr;
	while (h != nullptr)
	{
		temp = h;
		h = h->next;
		delete temp;
	}
}
int main()
{
	node* head = nullptr;
	// Insert nodes into the list
	insertnode(&head, 1);
	insertnode(&head, 2);
	insertnode(&head, 3);
	insertnode(&head, 4);
	insertnode(&head, 5);
	insertnode(&head, 6);
	// Print the linked list
	cout << "\nLinked List : ";
	print(head);
	// Find the middle of the linked list
	findmiddleeven(head);
	remove(head);
	head = nullptr;
	return 0;
}