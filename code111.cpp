#include <iostream>
using namespace std;
// Function to insert at a specific position
void insertAtPosition(int arr[], int& size, int capacity, int position, int value) {
    if (size >= capacity) 
    {
        cout << "Array is full. Cannot insert more elements." << endl;
        return;
    }
    if (position < 0 || position > size) 
    {
        cout << "Invalid position." << endl;
        return;
    }
    // Shift elements to the right
    for (int i = size; i > position; i--) 
    {
        arr[i] = arr[i - 1];
    }
    // Insert the new element
    arr[position] = value;
    size++;
}
// Function to print an array
void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << " \n\n";
}
int main() 
{
    const int capacity = 10;
    int arr[capacity] = { 1, 2, 3, 4, 5 };
    int size = 5;
    cout << "\t\t\t\t\tOriginal Array: ";
    printArray(arr, size);
    int position = 2;
    int value = 10;
    insertAtPosition(arr, size, capacity, position, value);
    cout << "\t\t\t\t\tModified Array: ";
    printArray(arr, size);
    return 0;
}