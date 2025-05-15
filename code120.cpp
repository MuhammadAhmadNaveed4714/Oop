#include <iostream>
using namespace std;
// Node structure for a singly linked list
struct Node
{
    int data;
    Node* next;
};
// Function to create a new node
Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}
// Function to insert a node at the end of the linked list
void insertNode(Node** head, int data)
{
    Node* newNode = createNode(data);
    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }
    Node* lastNode = *head;
    while (lastNode->next != nullptr)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}
// Function to print the linked list
void printList(Node* head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}
// Function to rotate the linked list to the left by k places
Node* rotateList(Node* head, int k)
{
    if (head == nullptr || head->next == nullptr || k == 0)
    {
        return head;
    }
    // Calculate the length of the linked list
    Node* temp = head;
    int length = 1;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        length++;
    }
    // Connect the last node to the head to form a circular linked list
    temp->next = head;
    // Calculate the new tail node's position
    k = k % length;
    int newTailIndex = length - k - 1;
    // Find the new tail node
    temp = head;
    for (int i = 0; i < newTailIndex; i++)
    {
        temp = temp->next;
    }
    // Find the new head node
    Node* newHead = temp->next;
    // Break the circular linked list at the new tail node
    temp->next = nullptr;
    return newHead;
}
int main()
{
    Node* head = nullptr;
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);
    insertNode(&head, 50);
    cout << "Original Linked List: ";
    printList(head);
    int k = 1;
    head = rotateList(head, k);
    cout << "Rotated Linked List: ";
    printList(head);
    return 0;
}