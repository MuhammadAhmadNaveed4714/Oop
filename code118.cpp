#include<iostream>
using namespace std;
// Struct node
struct node
{
	int data;
	node* next;
	node* prev;
};
// Function to insert a new node
void insert(node** h, int d)
{
	node* nn = new node();
	nn->data = d;
	nn->next = nullptr;
	if (*h == nullptr)
	{
		nn->prev = nullptr;
		*h = nn;
		return;
	}
	node* last = *h;
	while (last->next != nullptr)
	{
		last = last->next;
	}
	last->next = nn;
	nn->prev = last;
}
// Function to print a list
void print(node* h)
{
	while (h != nullptr)
	{
		cout << h->data << " ";
		h = h->next;
	}
	cout << "\n";
}
// Function to remove a list
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
	node* f = nullptr;
	insert(&f, 10);
	insert(&f, 11);
	insert(&f, 12);
	insert(&f, 13);
	insert(&f, 14);
	insert(&f, 15);
	insert(&f, 16);
	cout << "\n\t\t\t\t\tLinked List : ";
	print(f);
	remove(f);
	f = nullptr;
	return 0;
}