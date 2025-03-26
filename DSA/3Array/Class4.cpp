#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
void sort(vector<int> &v) // DUTCH NATIONAL FLAG ALGORITHM
{
    int i = 0;
    int start = 0;
    int end = v.size() - 1;
    while (i <= end)
    {
        if (v[i] == 0)
        {
            swap(v[i], v[start]);
            start++;
            i++;
        }
        else if (v[i] == 2)
        {
            swap(v[i], v[end]);
            end--;
        }
        else
        {
            i++;
        }
    }
}
void sort2(vector<int> &v)
{
    int start = 0;
    int end = v.size() - 1;
    while (start <= end)
    {
        if (v[start] == 2)
        {
            if (v[end] != 2)
            {
                swap(v[start], v[end--]);
            }
            else
            {
                end--;
            }
        }
        else if (v[start] == 0)
        {
            start++;
        }
        else if (v[start] == 1)
        {
            int pointer = start + 1;
            while (v[pointer] != 0 && (pointer < v.size()))
            {
                pointer++;
            }
            if (v[pointer] == 0)
            {
                swap(v[start++], v[pointer]);
            }
            else
            {
                start++;
            }
        }
    }
}
int missingNumber(vector<int> v)
{
    int num;
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    int totalSum = ((v.size() + 1) * (v.size())) / 2;
    num = totalSum - sum;
    return num;
}

int missingNumber2(vector<int> &nums)
{
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        result ^= nums[i];
    }
    for (int i = 0; i <= nums.size(); i++)
    {
        result ^= i;
    }
    return result;
}
void rotateBy90(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i; j < v[i].size(); j++)
        {
            swap(v[i][j], v[j][i]);
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        int start = 0;
        int end = v[i].size() - 1;
        while (start <= end)
        {
            swap(v[i][start++], v[i][end--]);
        }
    }
}
int rowWithMaximumOne(vector<vector<int>> v)
{
    int row = -1;
    int count = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        int oneCount = 0;
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == 1)
            {
                oneCount++;
            }
        }
        if (oneCount > count)
        {
            count = oneCount;
            row = i;
        }
    }
    return row + 1;
}
void alternativePrint(vector<int> &v)
{

    for (int i = 0; i < v.size(); i++)
    {
        int j = i;

        if (i % 2 == 0)
        {
            while ((v[j] < 0))
            {
                j++;
            }
            swap(v[i], v[j]);
        }
        else
        {
            while ((v[j] > 0))
            {
                j++;
            }
            swap(v[i], v[j]);
        }
    }
}
void alternativePrint2(vector<int> &v)
{
    vector<int> arrange;
    int len = v.size() - 1;
    int p = 0;
    int n = 0;
    while (p <= len && n <= len)
    {

        while (p <= len && v[p] < 0)
        {
            p++;
        }
        while (n <= len && v[n] >= 0)
        {
            n++;
        }
        arrange.push_back(v[p]);
        arrange.push_back(v[n]);
        p++;
        n++;
    }
    v = arrange;
}
int main()
{

    // int arr[] = {-13, -3, 0, 56, -67, -44, 88, 92, -23, 34};
    // int size = sizeof(arr) / 4;
    // int j = 0;
    // for (int i = 0; i < size; i++)
    // {
    //     if (arr[i] < 0)
    //     {
    //         swap(arr[i], arr[j++]);
    //     }
    // }
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // vector<int> v = {1, 0, 2, 2, 1, 0, 1, 0, 1, 2, 0, 0, 2, 1, 2, 1};
    // sort(v);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << endl;

    // vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 9, 10};
    // cout << "Missing number is : " << missingNumber(v) << endl;

    // vector<vector<int>> v;
    // vector<int> v1{1, 2, 3};
    // vector<int> v2{4, 5, 6};
    // vector<int> v3{7, 8, 9};
    // v.push_back(v1);
    // v.push_back(v2);
    // v.push_back(v3);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // rotateBy90(v);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // vector<vector<int>> v;
    // vector<int> v1{1, 0, 0};
    // vector<int> v2{1, 1, 0};
    // vector<int> v3{0, 1, 0, 0};
    // vector<int> v4{0, 1, 0, 0};
    // v.push_back(v1);
    // v.push_back(v2);
    // v.push_back(v3);
    // v.push_back(v4);
    // cout << "Row with maximum number of one is : " << rowWithMaximumOne(v) << endl;

    vector<int> v{-1, 2, 3, -4, -5, 6, 7, -8, -9, 10};
    alternativePrint2(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}