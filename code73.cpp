#include<iostream>
using namespace std;
//struct node
struct node
{
	int data;
	node* next;
};
//Function to remove duplicates
void removeAllDuplicates(node*& head, int k)
{
	while (head != nullptr && head->data == k)
	{
		node* temp = head;
		head = head->next;
		delete temp;
	}
	node* current = head;
	while (current != nullptr && current->next != nullptr)
	{
		if (current->next->data == k)
		{
			node* temp = current->next;
			current->next = current->next->next;
			delete temp;
		}
		else
		{
			current = current->next;
		}
	}
}
//Function to print 
void print(node* head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
}
//Function to remove
void remove(node* head)
{
	while (head != nullptr)
	{
		node* temp = head;
		head = head->next;
		delete temp;
	}
}
int main()
{
	node* head = new node{ 2 };
	head->next = new node{ 3 };
	head->next->next = new node{ 4 };
	head->next->next->next = new node{ 5 };
	head->next->next->next->next = new node{ 2 };
	head->next->next->next->next->next = new node{ 7 };
	head->next->next->next->next->next->next = new node{ 2 };
	head->next->next->next->next->next->next->next = new node{ 8 };
	print(head);
	cout << "\n\n";
	removeAllDuplicates(head, 2);
	print(head);
	cout << "\n\n";
	remove(head);
	head = nullptr;
	return 0;
}