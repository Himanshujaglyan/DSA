#include <iostream>
#include <vector>
using namespace std;
void reverseArray(int arr[], int start, int end);
void rotateArrayByK(int arr[], int size, int k)
{
    k = k % size;
    reverseArray(arr, 0, (size - 1));
    reverseArray(arr, 0, k - 1);
    reverseArray(arr, k, (size - 1));
}
void reverseArray(int arr[], int start, int end)
{
    for (start; start <= end; start++, end--)
    {
        swap(arr[start], arr[end]);
    }
}

void rearrangeElementBySign1(int arr[], int size)
{
    int pos[size / 2], neg[size / 2];
    int pointer1 = 0;
    int pointer2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            pos[pointer1++] = arr[i];
        }
        else
        {
            neg[pointer2++] = arr[i];
        }
    }
    int newArr[size];
    int pointer3 = 0;
    for (int i = 0; i < size / 2; i++)
    {
        newArr[pointer3++] = pos[i];
        newArr[pointer3++] = neg[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << newArr[i] << " ";
    }
}
int main()
{
    // int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // int row = 3;
    // int column = 3;
    // int i = 0, j = column - 1;
    // cout << "Printing Reverse Diagonal : " << endl;
    // for (; j >= 0; j--, i++)
    // {
    //     cout << arr[i][j] << " ";
    // }

    // int brr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int k = 13;
    // int size = 9;
    // rotateArrayByK(brr, size, k);
    // for (int i = 0; i < size; i++)
    // {
    //     cout << brr[i] << " ";
    // }

    // int arr[] = {1, 2, 3, -4, -5, -6};
    // rearrangeElementBySign1(arr, 6);

    vector<int> arr{1, 2, -3, -2, -5, 6};
    vector<int> num(arr.size(), 0);
    int even = 0, odd = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            num[even] = arr[i];
            even += 2;
        }
        else
        {
            num[odd] = arr[i];
            odd += 2;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << num[i] << " ";
    }

    return 0;
}