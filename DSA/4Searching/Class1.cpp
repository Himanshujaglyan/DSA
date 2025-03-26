#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int arr[], int n, int num)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2; // mid = s/2 + e/2; // mid = (start + end) /2 // PROBLEM
    while (start <= end)
    {
        if (arr[mid] == num)
        {
            return mid;
        }
        else if (num > arr[mid])
        {
            start = mid + 1;
        }
        else if (num < arr[mid])
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}
int findFirstOccurence(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int result = -1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == target)
        {
            result = mid;
            end = mid - 1;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return result;
}
int findLastOccurence(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int result = -1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == target)
        {
            result = mid;
            start = mid + 1;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return result;
}
int totalOccurence(int arr[], int size, int target)
{
    int firstOccurence = findFirstOccurence(arr, size, target);
    int lastOccurence = findLastOccurence(arr, size, target);
    int totalOccurence = lastOccurence - firstOccurence + 1;
    return totalOccurence;
}
int missingElement(int arr[], int size)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    int result = -1;
    while (s <= e)
    {
        int difference = arr[mid] - mid;
        if (difference == 1)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
            result = mid;
        }
        mid = s + (e - s) / 2;
    }
    if (result + 1 == 0)
    {
        return size + 1;
    }
    return result + 1;
}
int missingNumber2(vector<int> &nums)
{
    int s = 0;
    int e = nums.size() - 1;
    int result = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int difference = nums[mid] - mid;
        if (difference == 1)
        {
            if (s == e)
            {
                return mid + 2;
            }
            s = mid + 1;
        }
        else
        {
            result = mid + 1;
            e = mid - 1;
        }
    }
    return result;
}
int peakElement(int arr[], int size)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}
int main()
{
    // int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    // int size = 9;
    // int target = 80;
    // int index = binarySearch(arr, size, target);
    // if (index == -1)
    // {
    //     cout << "Element not found." << endl;
    // }
    // else
    // {
    //     cout << "Element found at index : " << index << endl;
    // }

    // int brr[] = {10, 20, 30, 30, 30, 30, 40, 50, 60};
    // int size1 = 9;
    // int target1 = 30;
    // int index1 = findFirstOccurence(brr, size1, target1);
    // int index2 = findLastOccurence(brr, size1, target1);
    // if (index1 == -1)
    // {
    //     cout << "Element not found." << endl;
    // }
    // else
    // {
    //     cout << "First occurence of element is at index : " << index1 << endl;
    // }
    // if (index2 == -1)
    // {
    //     cout << "Not Found." << endl;
    // }
    // else
    // {
    //     cout << "Last occurence of element is at index : " << index2 << endl;
    // }
    // cout << "Total number of occurence is : " << totalOccurence(brr, size1, target1) << endl;

    // int arr[] = {1, 2, 3, 4, 6, 7, 8};
    // int size = 7; // size we are passing is (n-1)
    // cout << "Missing element is : " << missingElement(arr, size);

    int arr[] = {10, 20, 30, 50, 40, 30};
    int size = 6;
    cout << "Peak element is : " << arr[peakElement(arr, size)] << endl;
    return 0;
}