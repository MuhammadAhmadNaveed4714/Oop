#include<iostream>
using namespace std;
// struct node
struct node
{
	int data;
	node* next;
};
// function to insert a node in linked list
void insert(node** h, int d)
{
	node* newnode = new node();
	newnode->data = d;
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
// function to print a node in linked list
void print(node* h)
{
	while (h != nullptr)
	{
		cout << h->data << " ";
		h = h->next;
	}
	cout << "\n";
}
// function to delete a node in linked list
void remove(node* h)
{
	node* t = nullptr;
	while (h != nullptr)
	{
		t = h;
		h = h->next;
		delete t;
	}
}
// function to reverse a singly linked list
void reverse(node** h)
{
	node* c = *h;
	node* p = nullptr;
	node* n = nullptr;
	while (c != nullptr)
	{
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	*h = p;
}
int main()
{
	node* ptr = nullptr;
	// inserting nodes in linked list
	insert(&ptr, 15);
	insert(&ptr, 25);
	insert(&ptr, 35);
	insert(&ptr, 45);
	insert(&ptr, 55);
	insert(&ptr, 65);
	insert(&ptr, 75);
	insert(&ptr, 85);
	insert(&ptr, 95);
	// printing a singly linked list
	cout << "\nOriginal List : ";
	print(ptr);
	reverse(&ptr);
	cout << "\nModified List : ";
	print(ptr);
	remove(ptr);
	ptr = nullptr;
	return 0;
}