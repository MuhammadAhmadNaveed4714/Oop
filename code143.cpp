#include<iostream>
using namespace std;
// struct node
struct node
{
	int data;
	node* next;
};
// Function to insert a node in linked list
void insert(node** head, int d)
{
	node* newnode = new node();
	newnode->data = d;
	newnode->next = nullptr;
	if (*head == nullptr)
	{
		*head = newnode;
		return;
	}
	node* lastnode = *head;
	while (lastnode->next != nullptr)
	{
		lastnode = lastnode -> next;
	}
	lastnode->next = newnode;
}
// Function to print a linked list
void print(node* head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}
// Function to remove a node in the linked list
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
// Function to reverse a singly linked list
void reverse(node** head)
{
	node* current = *head;
	node* nex = nullptr;
	node* prev = nullptr;
	while (current != nullptr)
	{
		nex = current->next;
		current->next = prev;
		prev = current;
		current = nex;
	}
	*head = prev;;
}
int main()
{
	node* n = nullptr;
	insert(&n, 1);
	insert(&n, 2);
	insert(&n, 3);
	insert(&n, 4);
	insert(&n, 5);
	cout << "\nLinked   list : ";
	print(n);
	reverse(&n);
	cout << "\nModified list : ";
	print(n);
	remove(n);
	n = nullptr;
	return 0;
}