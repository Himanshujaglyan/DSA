#include <iostream>
using namespace std;

void solve(int arr[], int n)
{
    arr[0] = 100;
}

int uniqueElement(int arr[], int size)
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result ^= arr[i];
    }
    return result;
}
void printPairs(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            cout << "(" << arr[i] << ", " << arr[j] << ")\t";
        }
        cout << endl;
    }
}
void printTriplets(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                cout << "(" << arr[i] << ", " << arr[j] << ", " << arr[k] << ")\t";
            }
        }
        cout << endl;
    }
}
void sortZeroOne(int arr[], int size)
{
    int zero = 0;
    int one = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            zero++;
        }
        if (arr[i] == 1)
        {
            one++;
        }
    }
    int index = 0;
    while (zero--)
    {
        arr[index++] = 0;
    }
    while (one--)
    {
        arr[index++] = 1;
    }
}
void sortZeroOne2(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        if (arr[end] == 0)
        {
            if (arr[start] == 1)
            {
                swap(arr[start++], arr[end--]);
            }
            else
            {
                start++;
            }
        }
        else
        {
            end--;
        }
    }
}
void sortZeroOne3(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    // while (start < end)
    // {
    //     while (arr[start] == 0 && start < end)
    //     {
    //         start++;
    //     }
    //     while (arr[end] == 1 && start < end)
    //     {
    //         end--;
    //     }
    //     swap(arr[start], arr[end]);
    //     start++;
    //     end--;
    // }
    while (start < end)
    {
        if (arr[start] == 0)
        {
            start++;
        }
        else if (arr[end] == 1)
        {
            end--;
        }
        else
        {
            swap(arr[start++], arr[end--]);
        }
    }
}

void shiftArrayBy1(int arr[], int size)
{
    int temp = arr[size - 1];
    for (int i = size - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}
void shiftArrayByk(int arr[], int size, int k)
{
    int temp[k];
    int index = size - 1;
    int test = k;
    for (int i = k - 1; i >= 0; i--)
    {
        temp[i] = arr[index--];
    }
    for (int i = 0; i < size - k; i++)
    {
        arr[size - i - 1] = arr[size - 1 - i - k];
    }
    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
}
void shiftArrayByk2(int arr[], int size, int k)
{
    int brr[size];
    for (int i = 0; i < size; i++)
    {
        int newIndex = (i + k) % size;
        brr[newIndex] = arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << brr[i] << "\t";
    }
}
void shiftArrayByk3(int arr[], int size, int k)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[size - 1 - i]);
    }
    for (int i = 0; i < k / 2; i++)
    {
        swap(arr[i], arr[k - 1 - i]);
    }
    for (int i = k; i < (size - k) / 2; i++)
    {
        swap(arr[i], arr[size - 1 - i]);
    }
}
int main()
{

    // int arr[] = {1, 2, 4};
    // int size = 3;

    // solve(arr, size);

    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // int a = 50;
    // int *b = &a;
    // cout << b << endl;
    // cout << &a << endl;
    // cout << *b << endl;
    // *b = 100;
    // cout << *b << endl;
    // cout << a << endl;
    // a++;
    // cout << *b << endl;
    // cout << a << endl;
    // (*b)++; // it increases the value of a
    // cout << *b << endl;
    // cout << a << endl;
    // *b++; // it changes the address b is referring to
    // cout << *b << endl;
    // cout << a << endl;
    // *(b++); // it changes the address b is referring to
    // cout << *b << endl;
    // cout << a << endl;
    // b++; // it changes the address b is referring to
    // cout << *b << endl;
    // cout << a << endl;

    // int arr[] = {12, 13, 14, 15, 15, 15, 14, 13, 12};
    // int size = sizeof(arr) / 4;
    // cout << uniqueElement(arr, size) << endl;

    // int arr[] = {10, 20, 30, 40};
    // int size = 4;
    // printPairs(arr, size);
    // printTriplets(arr, size);

    // int arr[] = {1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0};
    // int size = 13;
    // sortZeroOne3(arr, size);
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << "\t";
    // }

    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int size = 10;
    // shiftArrayBy1(arr, size);
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << "\t";
    // }

    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int size = 10;
    // shiftArrayByk3(arr, size, 3);
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << "\t";
    // }
    return 0;
}