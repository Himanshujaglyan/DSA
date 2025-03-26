#include <iostream>
using namespace std;

class Heap
{
public:
    int *arr;
    int capacity;
    int size;

    Heap(int _capacity)
    {
        arr = new int[_capacity];
        this->capacity = _capacity;
        this->size = 0;
    }

    void insert(int data)
    {
        if (size == capacity)
        {
            cout << "Heap Overflow." << endl;
            return;
        }

        size++;
        int index = size;
        arr[index] = data;

        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void printHeap()
    {
        cout << "Printing the content of heap : ";
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int deleteHeap()
    {
        int ans = arr[1];
        arr[1] = arr[size];
        size--;

        int index = 1;

        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            int largestIndex = index;

            if (leftIndex <= size && arr[largestIndex] < arr[leftIndex])
            {
                largestIndex = leftIndex;
            }
            if (rightIndex <= size && arr[largestIndex] < arr[rightIndex])
            {
                largestIndex = rightIndex;
            }
            if (index == largestIndex)
            {
                break;
            }
            else
            {
                swap(arr[index], arr[largestIndex]);
                index = largestIndex;
            }
        }

        return ans;
    }
};

void heapify(int *arr, int n, int index)
{
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int largestIndex = index;

    if (leftIndex <= n && arr[largestIndex] < arr[leftIndex])
    {
        largestIndex = leftIndex;
    }
    if (rightIndex <= n && arr[largestIndex] < arr[rightIndex])
    {
        largestIndex = rightIndex;
    }

    if (index != largestIndex)
    {
        swap(arr[index], arr[largestIndex]);
        index = largestIndex;
        heapify(arr, n, index);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    while (n != 1)
    {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}
int main()
{
    // Heap h(20);
    // h.insert(10);
    // h.insert(20);
    // h.insert(5);
    // h.insert(11);
    // h.insert(6);

    // h.printHeap();

    // cout << "Deleted element is : " << h.deleteHeap() << endl;
    // h.printHeap();

    // cout << "Deleted element is : " << h.deleteHeap() << endl;
    // h.printHeap();

    // cout << "Deleted element is : " << h.deleteHeap() << endl;
    // h.printHeap();

    int arr[] = {-1, 5, 10, 15, 20, 25, 12};
    buildHeap(arr, 6);
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    heapSort(arr, 6);
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}