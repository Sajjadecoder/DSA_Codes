#include <iostream>
#include <string>
using namespace std;

class maxHeap
{
    int *arr;
    int currentSize;
    int maxSize;

public:
    maxHeap(int s)
    {
        maxSize = s;
        arr = new int[maxSize];
        currentSize = 0;
    }
    void insert(int val)
    {
        if (currentSize == maxSize)
        {
            cout << "Heap is full\n";
            return;
        }

        arr[currentSize] = val;
        int index = currentSize;
        currentSize++;
        // compare it with its parent(present at (i-1)/2)
        while (index > 0 && arr[(index - 1) / 2] < val)
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    void print()
    {
        for (int i = 0; i < currentSize; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void heapify(int index)
    {
        int largest = index;
        int leftChild = (2 * index) + 1;
        int rightChild = (2 * index) + 2;
        if (leftChild < currentSize && arr[leftChild] > arr[largest])
        {
            largest = leftChild;
        }
        else if (rightChild < currentSize && arr[rightChild] > arr[largest])
        {
            largest = rightChild;
        }
        if (largest!=index)
        {
            swap(arr[index],arr[largest]);
            heapify(largest);
        }
        
    }
    void deleteElement()
    {
        if (currentSize == 0)
        {
            cout << "Heap is empty\n";
            return;
        }
        cout << arr[0] << " is deleted from heap\n";
        arr[0] = arr[currentSize - 1];

        currentSize--;

        if (currentSize == 0)
        {
            return;
        }
        heapify(0);
    }
};
int main()
{
    maxHeap heap1(6);
    heap1.insert(10);
    heap1.insert(8);
    heap1.insert(9);
    heap1.insert(80);
    heap1.insert(32);
    heap1.insert(16);
    heap1.print();
    heap1.deleteElement();
    heap1.print();
    return 0;
}