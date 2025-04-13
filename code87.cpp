#include<iostream>
using namespace std;
//struct node
struct node
{
	int data;
	node* next;
};
//Function to reverse a singly linked list
node* reverse(node* head)
{
	node* prev = nullptr;
	node* current = head;
	node* next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}
//Function to delete a node
void remove(node* head)
{
	while (head != nullptr)
	{
		node* temp = head;
		head = head->next;
		delete temp;
	}
}
//Function to print a node
void print(node* head)
{
	while (head != nullptr)
	{
		cout<< head->data<<" ";
		head = head->next;
	}
}
int main()
{
	node* head = new node { 1 };
	head->next = new node{ 2 };
	head->next->next = new node{ 3 };
	head->next->next->next = new node{ 4 };
	head->next->next->next->next = new node{ 5 };
	head->next->next->next->next->next = new node{ 6 };
	head->next->next->next->next->next->next = new node{ 7 };
	head->next->next->next->next->next->next->next = new node{ 8 };
	cout << "\n";
	print(head);
	head=reverse(head);
	cout << "\n";
	print(head);
	cout << "\n";
	remove(head);
	head = nullptr;
	return 0;
}