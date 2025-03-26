#include <iostream>
using namespace std;

void merge(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;

    int lenLeft = mid - s + 1;
    int lenRight = e - mid;

    int *left = new int[lenLeft];
    int *right = new int[lenRight];

    int k = s;
    for (int i = 0; i <= lenLeft; i++)
    {
        left[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i <= lenRight; i++)
    {
        right[i] = arr[k++];
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mainIndex = s;
    while (leftIndex < lenLeft && rightIndex < lenRight)
    {
        if (left[leftIndex] <= right[rightIndex])
        {
            arr[mainIndex++] = left[leftIndex++];
        }
        else
        {
            arr[mainIndex++] = right[rightIndex++];
        }
    }

    while (leftIndex < lenLeft)
    {
        arr[mainIndex++] = left[leftIndex++];
    }

    while (rightIndex < lenRight)
    {
        arr[mainIndex++] = right[rightIndex++];
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
        return;
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

void quickSort(int a[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivot = end;
    int i = start - 1;
    int j = start;
    while (j < pivot)
    {
        if (a[j] < a[pivot])
        {
            i++;
            swap(a[i], a[j]);
        }
        j++;
    }
    i++;
    swap(a[i], a[pivot]);
    quickSort(a, start, i - 1);
    quickSort(a, i + 1, end);
}
int main()
{

    int arr[] = {2, 1, 6, 9, 4, 5};
    int size = 6;
    int s = 0;
    int e = size - 1;

    cout << "Before : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // mergeSort(arr, s, e);
    quickSort(arr, s, e);
    cout << "After : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}