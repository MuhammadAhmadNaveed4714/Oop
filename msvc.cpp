#include <iostream>
using namespace std;
template <typename T>
class MySpecialVector 
{
private:
    T* elements;  
    int size;     
    int capacity; 
    void resize(int newCapacity) 
    {
        T* newElements = new T[newCapacity]; 
        for (int i = 0; i < size; ++i)
        {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
    }
public:
    MySpecialVector(int initialCapacity = 10) : size(0), capacity(initialCapacity)
    {
        elements = new T[capacity];  
    }
    MySpecialVector(const MySpecialVector& other) : size(other.size), capacity(other.capacity)
    {
        elements = new T[capacity];  
        for (int i = 0; i < size; ++i)
        {
            elements[i] = other.elements[i];
        }
    }
    ~MySpecialVector() 
    {
        delete[] elements;  
    }
    void insertAtEnd(const T& value)
    {
        if (size == capacity) 
        {
            resize(capacity * 2); 
        }
        elements[size] = value;  
        ++size;  
    }
    void removeFromEnd()
    {
        if (size > 0) 
        {
            --size;  
        }
        else
        {
            cout << "Vector is empty, cannot remove element!" << endl;
        }
    }
    bool isEmpty() 
    {
        return size == 0;
    }
    bool isFull() 
    {
        return size == capacity;
    }
    T getLast() const
    {
        if (size > 0)
        {
            return elements[size - 1];  
        }
        else
        {
            cout<<"Vector is empty!";  
        }
    }
    int getCount() const
    {
        return size;
    }
    void print() const
    {
        if (size == 0) 
        {
            cout << "Vector is empty." << endl;
            return;
        }
        for (int i = 0; i < size; ++i) 
        {
            cout << elements[i] << " ";  
        }
        cout << endl;
    }
};
int main()
{
    MySpecialVector<int> vec;
    vec.insertAtEnd(10);
    vec.insertAtEnd(20);
    vec.insertAtEnd(30);
    vec.insertAtEnd(40);
    vec.print();  
    cout << "Last element: " << vec.getLast() << endl; 
    cout << "Count: " << vec.getCount() << endl; 
    vec.removeFromEnd();
    vec.print();  
    cout << "Is empty: " << (vec.isEmpty() ? "Yes" : "No") << endl; 
    cout << "Is full: " << (vec.isFull() ? "Yes" : "No") << endl; 
    return 0;
}
