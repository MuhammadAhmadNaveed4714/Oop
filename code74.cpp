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
	lastnode->next=newnode;
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
//Function to compress the linked list
node* compresslist(node* head)
{
	if (!head || !head->next)
	{
		return head;
	}
	node* dummy = new node();
	dummy->next = head;
	node* prev = dummy;
	node* curr = head;
	int count = 1;
	while (curr->next)
	{
		if (curr->data == curr->next->data)
		{
			count++;
			curr = curr->next;
		}
		else
		{
			if(count > 1)
			{
				prev->next = createnode(curr->data);
				prev->next->next = createnode(count);
				prev = prev->next->next;
			}
			else
			{
				prev->next = curr;
				prev = prev->next;
			}
			curr = curr->next;
			count = 1;
		}
	}
	if (count > 1)
	{
		prev->next = createnode(curr->data);
		prev->next->next = createnode(count);
	}
	else
	{
		prev->next = curr;
	}
	node* newhead = dummy->next;
	delete dummy;
	dummy = nullptr;
	return newhead;
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
	head = compresslist(head);
	cout << "\n\nCompressed list : ";
	printlist(head);
	remove(head);
	head = nullptr;
	return 0;
}