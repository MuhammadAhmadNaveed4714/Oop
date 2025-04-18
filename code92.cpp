#include<iostream>
using namespace std;
// struct node
struct node
{
	int data;
	node* next;
};
// Function to insert a node
void insert(node** k, int d)
{
	node* newnode = new node();
	newnode->data = d;
	newnode->next = nullptr;
	if (*k == nullptr)
	{
		*k = newnode;
		return;
	}
	else
	{
		node* lastnode = *k;
		while (lastnode->next != nullptr)
		{
			lastnode = lastnode->next;
		}
		lastnode->next = newnode;
	}
}
// Function to find middle even number
void findmideven(node* k)
{
	node* fast = k;
	node* slow = k;
	node* prev = nullptr;
	while (fast != nullptr && fast->next != nullptr)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << "\n\nSuitable middle number : " << prev->data << "\n";
}
// Function to find odd middle number
void findmidodd(node* k)
{
	node* fast = k;
	node* slow = k;
	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << "\n\nSuitable middle number : " << slow->data << "\n";
}
// Function to get mid number
void getmid(node* head)
{
	int count = 0;
	char ch = 'a';
	int dat = 0;
	cout << "\nDo you want to enter : ";
	cin >> ch;
	while (ch == 'y' || ch == 'Y')
	{
		cout << "\nEnter data to enter in the node : ";
		cin >> dat;
		insert(&head,dat);
		count++;
		cout << "\nDo you want to enter : ";
		cin >> ch;
	}
	if (count % 2 == 0)
	{
		findmideven(head);
	}
	else
	{
		findmidodd(head);
	}
}
// Function to remove
void remove(node* head)
{
	while (head != nullptr)
	{
		node* t = head;
		head = head->next;
		delete t;
	}
}
int main()
{
	node* ptr=nullptr;
	getmid(ptr);
	remove(ptr);
	ptr = nullptr;
	return 0;
}