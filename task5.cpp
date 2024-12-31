//#include<iostream>
//using namespace std;
//void partitionArray(int* originalArray, int leftSize, int rightSize, int totalSize)
//{
//    if (leftSize + rightSize != totalSize)
//    {
//        cout << "Error: Partition sizes do not match the total size of the array." << endl;
//        return;
//    }
//    cout << "Original array: ";
//    for (int i = 0; i < totalSize; i++) 
//    {
//        cout << originalArray[i] << " ";
//    }
//    cout << endl;
//    int* leftPartition = originalArray;
//    int* rightPartition = originalArray + leftSize;
//    cout << "Left partition: ";
//    for (int i = 0; i < leftSize; i++)
//    {
//        cout << leftPartition[i] << " ";
//    }
//    cout << endl;
//    cout << "Right partition: ";
//    for (int i = 0; i < rightSize; i++) 
//    {
//        cout << rightPartition[i] << " ";
//    }
//    cout << endl;
//}
//int main()
//{
//    int size = 0, lsize = 0, rsize = 0;
//    cout << "\nEnter size of an array : ";
//    cin >> size;
//    cout << "\nEnter left partition size of an array : ";
//    cin >> lsize;
//    cout << "\nEnter right partition size of an array : ";
//    cin >> rsize;
//    int* originalArray = new int[size];
//    cout << "\nEnter elements of an array : \n";
//    for (int i = 0; i < size; i++)
//    {
//        cin >> originalArray[i];
//    }
//    partitionArray(originalArray, lsize, rsize, size);
//    delete[]originalArray;
//    originalArray = nullptr;
//	return 0;
//}