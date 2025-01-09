#include <iostream>
using namespace std;
class MyVector
{
private:
    int size;     
    int capacity; 
    int* arr;    
    void resize(int newCapacity) 
    {
        if (newCapacity == capacity)
        {
            return;
        }
        if (newCapacity < size) 
        {
            newCapacity = size;  
        }
        int* newArr = new int[newCapacity]; 
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;  
        arr = newArr;  
        capacity = newCapacity;  
    }
public:
    MyVector()
    {
        size = 0;
        capacity = 5;
        arr = new int[capacity];
    }
    MyVector(int cap) 
    {
        size = 0;
        capacity = cap;
        arr = new int[capacity];
    }
    MyVector(const MyVector& v)
    {
        size = v.size;
        capacity = v.capacity;
        arr = new int[size];  
        for (int i = 0; i < size; ++i)
        {
            arr[i] = v.arr[i];  
        }
    }
    ~MyVector() 
    {
        delete[] arr;
        arr = nullptr;
    }
    void push_back(int element) 
    {
        if (size == capacity) 
        {  
            resize(capacity * 2);  
        }
        arr[size] = element;
        ++size;
    }
    void pop_back() 
    {
        if (size > 0) 
        {
            --size;  
        }
    }
    int get_size() 
    {
        return size;
    }
    int get_capacity() 
    {
        return capacity;
    }
    void print() 
    {
        for (int i = 0; i < size; ++i) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void reverse() 
    {
        int left = 0;
        int right = size - 1;
        while (left < right)
        {
            swap(arr[left], arr[right]);
            ++left;
            --right;
        }
    }
    void insert(int index, int element) 
    {
        if (index < 0 || index > size) 
        {
            cout << "Invalid index!" << endl;
            return;
        }
        if (size == capacity)
        {  
            resize(capacity * 2);
        }
        for (int i = size; i > index; --i)
        {
            arr[i] = arr[i - 1];  
        }
        arr[index] = element;
        ++size;
    }
    int search(int element) 
    {
        for (int i = 0; i < size; ++i)
        {
            if (arr[i] == element)
            {
                return i;  
            }
        }
        return -1;  
    }
    void remove(int element)
    {
        int index = search(element);
        if (index != -1) 
        {
            for (int i = index; i < size - 1; ++i) 
            {
                arr[i] = arr[i + 1];  
            }
            --size;
        }
    }
    void clear()
    {
        size = 0;  
    }
    bool isEmpty() 
    {
        return size == 0;
    }
    bool isMonotonicallyIncreasing() 
    {
        for (int i = 1; i < size; ++i)
        {
            if (arr[i] < arr[i - 1]) 
            {
                return false;  
            }
        }
        return true; 
    }
};
int main() 
{
    MyVector vec;
    cout << "Adding elements to the vector:" << endl;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    cout << "Vector after adding 5 elements: ";
    vec.print();
    vec.push_back(60);
    cout << "Vector after adding one more element (resize should have occurred): ";
    vec.print();
    cout << "Current size: " << vec.get_size() << endl;
    cout << "Current capacity: " << vec.get_capacity() << endl;
    vec.pop_back();
    cout << "Vector after pop_back(): ";
    vec.print();
    vec.insert(2, 25);
    cout << "Vector after inserting 25 at index 2: ";
    vec.print();
    int index = vec.search(30);
    cout << "Element 30 found at index: " << index << endl;
    vec.remove(20);
    cout << "Vector after removing 20: ";
    vec.print();
    vec.reverse();
    cout << "Vector after reversing: ";
    vec.print();
    vec.clear();
    cout << "Vector after clearing (should be empty): ";
    vec.print();
    cout << "Is the vector empty? " << (vec.isEmpty() ? " Yes" : " No") << endl;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    cout << "Is the vector monotonically increasing? " << (vec.isMonotonicallyIncreasing() ? " Yes" : " No") << endl;
    vec.push_back(35);
    cout << "Is the vector monotonically increasing after adding 25? " << (vec.isMonotonicallyIncreasing() ? " Yes" : " No") << endl;
    vec.print();
    cout << "\n";
    return 0;
}

