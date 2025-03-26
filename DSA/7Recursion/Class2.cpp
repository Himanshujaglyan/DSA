#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// LEETCODE 70 (CLIMBING STAIRS)
int climbStairs(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
}

void printArray(int arr[], int size, int index)
{
    if (index >= size)
    {
        return;
    }
    cout << arr[index] << " ";
    printArray(arr, size, index + 1);
}

bool linearSearch(int *arr, int size, int index, int target)
{
    if (index >= size)
    {
        return false;
    }
    if (arr[index] == target)
    {
        return true;
    }
    linearSearch(arr, size, index + 1, target);
}

void minimumNumber(int arr[], int size, int index, int &mini)
{
    if (index >= size)
    {
        return;
    }
    mini = min(mini, arr[index]);
    minimumNumber(arr, size, index + 1, mini);
}

void evenInsert(int arr[], int size, int index, vector<int> &v)
{
    if (index >= size)
    {
        return;
    }
    if ((arr[index] % 2) == 0)
    {
        v.push_back(arr[index]);
    }
    evenInsert(arr, size, index + 1, v);
}

void multiplyBy2(int *arr, int size, int index)
{
    if (index >= size)
    {
        return;
    }
    arr[index] = 2 * arr[index];
    multiplyBy2(arr, size, index + 1);
}

void maxNumber(int *arr, int size, int index, int &max1)
{
    if (index >= size)
    {
        return;
    }
    max1 = max(max1, arr[index]);
    maxNumber(arr, size, index + 1, max1);
}

void allOccurences(int arr[], int size, int index, int target, vector<int> &v)
{
    if (index >= size)
    {
        return;
    }
    if (target == arr[index])
    {
        v.push_back(index);
    }
    allOccurences(arr, size, index + 1, target, v);
}

void allDigits(int n, vector<int> &v)
{
    if (n <= 0)
    {
        return;
    }
    allDigits(n / 10, v);
    int remainder = n % 10;
    v.push_back(remainder);
}

void targetCharacterIndex(string s, int index, char target, vector<int> &v)
{
    if (s[index] == '\0')
    {
        return;
    }

    if (s[index] == target)
    {
        v.push_back(index);
    }
    targetCharacterIndex(s, index + 1, target, v);
}
vector<int> targetCharacterIndex1(string s, int index, char target)
{
    vector<int> ans;
    if (s[index] == '\0')
    {
        return ans;
    }
    if (s[index] == target)
    {
        ans.push_back(index);
    }
    vector<int> v = targetCharacterIndex1(s, index + 1, target);
    for (auto i : v)
    {
        ans.push_back(i);
    }
    return ans;
}

int formNumber(int *arr, int index, int size)
{
    if (index >= size)
    {
        return 0;
    }
    int num = formNumber(arr, index + 1, size) * 10 + arr[size - index - 1];
    return num;
}

void printInteger(vector<int> v, int index, int &num)
{
    if (index >= v.size())
    {
        return;
    }
    num = num * 10 + v[index];
    printInteger(v, index + 1, num);
}
int main()
{

    // cout << climbStairs(5) << endl;
    // int a[5] = {9, 1, 2, 5, 4};
    // int size = 5;
    // int index = 0;
    // int target = 6;
    // int mini = INT_MAX;
    // printArray(a, size, index);
    // cout << linearSearch(a, size, index, target);
    // minimumNumber(a, size, index, mini);
    // cout << mini << endl;
    // vector<int> arr;
    // evenInsert(a, size, index, arr);
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // multiplyBy2(a, size, index);
    // printArray(a, size, index);
    // int maxi = INT_MIN;
    // maxNumber(a, size, index, maxi);
    // cout << maxi << endl;

    // vector<int> digit;
    // allDigits(4556087, digit);
    // for (auto i : digit)
    // {
    //     cout << i << " ";
    // }

    // vector<int> indexes;
    // string s = "chahat";
    // char target = 'a';
    // int index = 0;
    // targetCharacterIndex(s, index, target, indexes);
    // for (auto i : indexes)
    // {
    //     cout << i << " " << endl;
    // }
    // cout << endl;
    // vector<int> ans = targetCharacterIndex1(s, index, target);
    // for (auto i : ans)
    // {
    //     cout << i << endl;
    // }

    int arr[] = {4, 0, 6, 2};
    cout << formNumber(arr, 0, 4) << endl;

    vector<int> v = {1, 2, 6, 5};
    int num = 0;
    printInteger(v, 0, num);
    cout << num << endl;

    return 0;
}