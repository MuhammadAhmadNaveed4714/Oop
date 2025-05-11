#include<iostream>
using namespace std;
// Struct node
struct node
{
	int data;
	node* next;
};
// Function to insert a node
void insert(node** h, int d)
{
	node* n = new node();
	n->data = d;
	n->next = nullptr;
	if (*h == nullptr)
	{
		*h = n;
		return;
    }
	node* last = *h;
	while (last->next != nullptr)
	{
		last = last->next;
	}
	last->next = n;
}
// Function to print
void print(node* h)
{
	while (h != nullptr)
	{
		cout << h->data << " ";
		h = h->next;
	}
	cout << "\n";
}
// Function to remove
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
// Function to reverse a singly linked list
node* reverse(node* h)
{
	node* prev = nullptr;
	node* curr = h;
	node* next = nullptr;
	while (curr != nullptr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}
int main()
{
	node* head = nullptr;
	insert(&head, 10);
	insert(&head, 20);
	insert(&head, 30);
	insert(&head, 40);
	insert(&head, 50);
	cout<<"\n\t\t\t\t\tLinked List : ";
	print(head);
	head=reverse(head);
	cout << "\n\t\t\t\tReverse Linked List : ";
	print(head);
	remove(head);
	head = nullptr;
	return  0;
}