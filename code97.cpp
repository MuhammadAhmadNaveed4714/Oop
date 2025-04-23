#include<iostream>
using namespace std;
// Struct node
struct node
{
	int data;
	node* next;
};
// Function to insert a node
void insert(node** h,int n)
{
	node* newnode = new node();
	newnode->data = n;
	newnode->next = nullptr;
	if (*h == nullptr)
	{
		*h = newnode;
		return;
	}
	else
	{
		node* lastnode = *h;
		while (lastnode->next != nullptr)
		{
			lastnode = lastnode->next;
		}
		lastnode->next = newnode;
	}
}
// Function to remove a singly linked list
void remove(node* h)
{
	while (h != nullptr)
	{
		node* temp = h;
		h = h->next;
		delete temp;
	}
}
// Function to print a singly linked list
void print(node* h)
{
	cout << "\n\t\t\t\t\tPrinting of linked list : ";
	while (h != nullptr)
	{
		cout << h->data << " ";
		h = h->next;
	}
	cout << "\n";
}
// Function to reverse a singly linked list
node* reverseList(node* head)
{
	node* prev = nullptr;
	node* curr = head;
	while (curr != nullptr)
	{
		node* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}
int main()
{
	node* ptr = nullptr;
	insert(&ptr, 2);
	insert(&ptr, 4);
	insert(&ptr, 6);
	insert(&ptr, 8);
	insert(&ptr, 9);
	print(ptr);
	ptr = reverseList(ptr);
	print(ptr);
	remove(ptr);
	ptr = nullptr;
	return 0;
}