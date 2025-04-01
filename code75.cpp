#include<iostream>
using namespace std;
//Node Structure
struct node
{
	int data;
	node* next;
};
//Function to create a new node
node* createnode(int data)
{
	node* newnode = new node();
	if (!newnode)
	{
		cout << "\nMemory Error.\n";
		return NULL;
	}
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
//Function to insert a node at the end of the list
void insertnode(node** head, int data)
{
	node* newnode = createnode(data);
	if (*head == NULL)
	{
		*head = newnode;
		return;
	}
	node* lastnode = *head;
	while (lastnode->next)
	{
		lastnode = lastnode->next;
	}
	lastnode->next = newnode;
}
//Function to print the linked list
void printlist(node* head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
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
	node* head = nullptr;
	//create the linked list : 1->1->2->2->3->3->3
	insertnode(&head, 1);
	insertnode(&head, 1);
	insertnode(&head, 2);
	insertnode(&head, 2);
	insertnode(&head, 3);
	insertnode(&head, 3);
	insertnode(&head, 3);
	cout << "\n\nOriginal list : ";
	printlist(head);
	remove(head);
	head = nullptr;
	return 0;
}