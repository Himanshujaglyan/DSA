#include <iostream>
#include <math.h>
// #include <conio.h>
#include <vector>
using namespace std;

int getQuotient(int divisor, int dividend)
{
    int s = 0;
    int e = dividend;
    int mid = s + (e - s) / 2;
    int result = -1;
    while (s <= e)
    {
        if ((divisor * mid) == dividend)
        {
            return mid;
        }
        else if ((divisor * mid) > dividend)
        {
            e = mid - 1;
        }
        else
        {
            result = mid;
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return result;
}

double getQuotient1(int divisor, int dividend, int k)
{
    double s = 0;
    double e = dividend;
    int mid = s + (e - s) / 2;
    double result = -1;
    while (s <= e)
    {
        if ((divisor * mid) == dividend)
        {
            return mid;
        }
        else if ((divisor * mid) > dividend)
        {
            e = mid - 1;
        }
        else
        {
            result = mid;
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    for (double i = 0; i < k; i++)
    {
        s = result;
        e = result + 9 / (pow(10, i + 1));
        for (double j = s; j <= e; j += (1 / pow(10, i + 1)))
        {
            if (j * divisor == dividend)
            {
                return j;
            }
            else if (j * divisor > dividend)
            {
                break;
            }
            else
            {
                result = j;
            }
        }
    }
    return result;
}

int nearlySortedArray(int arr[], int size, int target)
{
    int s = 0;
    int e = size - 1;
    int mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid - 1] == target && (mid - 1) >= 0)
        {
            return mid - 1;
        }
        else if (arr[mid + 1] == target && (mid + 1) < size)
        {
            return mid + 1;
        }
        else if (target > arr[mid])
        {
            s = mid + 2;
        }
        else
        {
            e = mid - 2;
        }
    }
    return -1;
}
int oddOccuringElement(int arr[], int size)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (s == e)
        {
            return s;
        }
        if (mid & 1) // Odd Number
        {
            if (arr[mid] == arr[mid - 1] && (mid - 1) >= 0)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        else
        {
            if (arr[mid] == arr[mid + 1] && (mid + 1) < size)
            {
                s = mid + 2;
            }
            else
            {
                e = mid;
            }
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}
int oddOccuringElement2(int arr[], int size)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (s == e)
        {
            return s;
        }
        if (mid & 1) // Odd Number
        {
            if (arr[mid] == arr[mid - 1] && (mid - 1) >= 0)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        else
        {
            if (arr[mid] == arr[mid + 1] && (mid + 1) < size)
            {
                s = mid + 2;
            }
            else if (arr[mid] == arr[mid - 1] && (mid - 1) >= 0)
            {
                e = mid - 2;
            }
            else
            {
                return mid;
            }
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}
int main()
{
    // dividend = (divisor * quotient) + remainder;
    // int divisor = 7;
    // int dividend = 29;
    // int ans = getQuotient(abs(divisor), abs(dividend)); // absolute abs()
    // if ((divisor < 0 && dividend > 0) || (divisor > 0 && dividend < 0))
    // {
    //     ans = 0 - ans;
    // }
    // cout << "The quotient is : " << ans << endl;

    // cout << "Answer is : " << getQuotient1(3, 10, 4) << endl;

    // int arr[] = {20, 10, 30, 50, 40, 70, 60};
    // int index = nearlySortedArray(arr, 7, 20);
    // if (index == -1)
    // {
    //     cout << "Not found." << endl;
    // }
    // else
    // {
    //     cout << "Founf at index : " << index << endl;
    // }

    int arr[] = {20, 20, 10, 10, 30, 50, 50, 40, 40, 70, 70, 60, 60};
    int index = oddOccuringElement2(arr, 13);
    if (index == -1)
    {
        cout << "Not found." << endl;
    }
    else
    {
        cout << "Found at index : " << arr[index] << endl;
    }
    return 0;
}