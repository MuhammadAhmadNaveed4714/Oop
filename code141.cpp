#include<iostream>
using namespace std;
// struct node
struct node
{
	int data;
	node* next;
};
// Function to insert a node
void insert(node** h, int k)
{
	node* newnode = new node();
	newnode->data = k;
	newnode->next = nullptr;
	if (*h == nullptr)
	{
		*h = newnode;
		return;
	}
	node* lastnode = *h;
	while (lastnode->next != nullptr)
	{
		lastnode = lastnode->next;
	}
	lastnode->next = newnode;
}
// Function to print a node
void print(node* h)
{
	while (h != nullptr)
	{
		cout << h->data << " ";
		h = h->next;
	}
	cout << "\n";
}
// Function to remove a node
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
// Function to find middle of linked list
void mid(node* h)
{
	node* fast = h;
	node* small = h;
	while (fast != nullptr && fast->next != nullptr)
	{
		small = small->next;
		fast = fast->next->next;
	}
	cout << "\nMiddle element : " << small->data << "\n";
}
int main()
{
	node* head = nullptr;
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 5);
	insert(&head, 6);
	insert(&head, 7);
	insert(&head, 8);
	cout << "\nLinked List : ";
	print(head);
	mid(head);
	remove(head);
	head = nullptr;
	return 0;
}