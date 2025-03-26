#include <iostream>
#include <limits.h>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (element == arr[i])
        {
            return true;
        }
    }
    return false;
}

int countZeroOne(int arr[], int size)
{
    int countZero = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            countZero++;
        }
    }
    return countZero;
}

int minimumArray(int arr[], int size)
{
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
int maximumArray(int arr[], int size)
{
    int maxNum = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        maxNum = max(arr[i], maxNum);
    }
    return maxNum;
}

void reverseArray(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[size - i - 1]);
    }
    printArray(arr, size);
}
void reverseArray2(int arr[], int size)
{
    int left = 0;
    int right = size - 1;
    while (left < right)
    {
        swap(arr[left++], arr[right--]);
    }
    printArray(arr, size);
}
void extremePrintArray(int arr[], int size)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        if (left == right)
        {
            cout << arr[left++];
        }
        else
        {
            cout << arr[left++] << " " << arr[right--] << " ";
        }
    }
}
int main()
{

    // int arr[101];
    // char ch[202];
    // bool flag[12];
    // long num[12];
    // short snum[22];

    // cout << "Array successfully created." << endl;

    // int a = 5;
    // cout << "Address of a is : " << &a << endl;

    // int arr[10];
    // cout << "Base address of arr is  " << &arr << endl;
    // cout << "Base address of arr is  " << arr << endl;

    // cout << "Size of a is : " << sizeof(a) << endl;
    // cout << "Size of arr is : " << sizeof(arr) << endl;

    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // cout << sizeof(arr) << endl;

    // int brr[5] = {2, 4, 6};
    // cout << sizeof(brr) << endl;
    // cout << brr[0] << endl;
    // cout << brr[1] << endl;
    // cout << brr[2] << endl;
    // cout << brr[3] << endl; // NOT INITIALIZED SO START WITH 0
    // cout << brr[4] << endl; // NOT INITIALIZED SO START WITH 0

    // int crr[5] = {2, 4, 6, 8, 10, 12}; // ERROR // EXCESS ELEMENTS

    // int drr[5];
    // cout << drr[0] << endl;
    // cout << drr[1] << endl;
    // cout << drr[2] << endl;
    // cout << drr[3] << endl;
    // cout << drr[4] << endl;
    // // cout << drr[5] << endl;// ERROR
    // cout << endl;
    // int err[5] = {};
    // cout << err[0] << endl;
    // cout << err[1] << endl;
    // cout << err[2] << endl;
    // cout << err[3] << endl;
    // cout << err[4] << endl;
    // // cout << err[5] << endl;// ERROR

    // int arr[0] = {}; // WE CAN CREATE AN ARRAY OF SIZE ZERO
    // int arr[-2];     // ERROR

    // BAD PRACTISE SO WE USE DYNAMIC ARRAYS
    // int n;
    // cin >> n;
    // int xrr[n] = {};
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << xrr[i] << endl;
    // }

    // int arr[5];
    // cout << "Enter the elements in array : ";
    // for (int i = 0; i < 5; i++)
    // {
    //     cin >> arr[i];
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // int arr[10];
    // cout << "Enter the elements : ";
    // for (int i = 0; i < 10; i++)
    // {
    //     cin >> arr[i];
    //     arr[i] *= 2;
    // }
    // cout << "Printing the elements : ";
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // int arr[10];
    // cout << "Enter the elements : ";
    // int sum = 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     cin >> arr[i];
    //     sum += arr[i];
    // }
    // cout << sum << endl;

    // LINEAR SEARCH IN AN ARRAY
    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int element;
    // cout << "Enter the element : ";
    // cin >> element;
    // int flag = 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     if (arr[i] == element)
    //     {
    //         flag = 1;
    //         cout << "Element Found." << endl;
    //         break;
    //     }
    // }
    // if (flag == 0)
    // {
    //     cout << "Element not found." << endl;
    // }

    // int arr[5] = {2, 4, 6, 8, 10};
    // int size = 5;

    // printArray(arr, size);
    // if (linearSearch(arr, size, 4))
    // {
    //     cout << "Element found." << endl;
    // }
    // else
    // {
    //     cout << "Element not found." << endl;
    // }

    // int arr[10] = {0,1,1,1,0,1,0,1,1,1};
    // int size = 10;
    // int zero = countZeroOne(arr, size);
    // int one = size - zero;
    // cout << "Number of zero's are : " << zero << endl;
    // cout << "Number of one's are : " << one << endl;

    // cout << INT_MIN << endl;
    // cout << INT_MAX << endl;

    // int arr[] = {12,14,54,88,96,03,44,965,-65};
    // int size = sizeof(arr)/4;
    // cout << "minimum number is : " << minimumArray(arr,size) << endl;
    // cout << "maximum number is : " << maximumArray(arr,size) << endl;

    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int size = sizeof(arr) / 4;
    // reverseArray2(arr, size);
    // extremePrintArray(arr, size);
    return 0;
}