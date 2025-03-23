#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
//Function to print linked-list
void printList(node* head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
}
//Function to remove allocated memory
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
	head->next = new node{ 120 };
	head->next->next = new node{ 1 };
	head->next->next->next = new node{ 120 };
	head->next->next->next->next = new node{ 4 };
	head->next->next->next->next->next = new node{ 6 };
	head->next->next->next->next->next->next = new node{ 9 };
	head->next->next->next->next->next->next->next = new node{ 4 };
	head->next->next->next->next->next->next->next->next = new node{ 120 };
	cout << "\n\t\t\t\t\tOriginal List : \n";
	printList(head);
	cout << "\n";
	remove(head);
	return 0;
}