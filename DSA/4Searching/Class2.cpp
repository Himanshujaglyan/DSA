#include <iostream>
#include <math.h>
// #include <conio.h>
#include <vector>
using namespace std;

int findPivotElement(vector<int> v)
{
    int n = v.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (s == e)
        {
            return s;
        }
        else if (v[mid] > v[mid + 1] && (mid + 1) <= (n - 1))
        {
            return mid;
        }
        else if (v[mid] < v[mid - 1] && (mid - 1) >= 0)
        {
            return mid - 1;
        }
        else if (v[s] > v[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int findPivotElement2(vector<int> nums)
{
    int s = 0;
    int e = nums.size() - 1;
    int result = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] < nums.front())
        {
            e = mid - 1;
        }
        else if (nums[mid] < nums[mid + 1] && (mid + 1) < nums.size())
        {
            result = mid;
            s = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return result;
}
int binarySearch(vector<int> v, int s, int e, int target)
{
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (v[mid] == target)
        {
            return mid;
        }
        else if (target > v[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}
int squareRoot(int num)
{
    int s = 0;
    int e = num;
    long long int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if ((mid * mid) == num)
        {
            return mid;
        }
        else if ((mid * mid) > num)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
            ans = mid;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
double squareRoot2(int num, int k)
{
    double s = 0;
    double e = num;
    double mid = s + (e - s) / 2;
    double ans = -1;
    while (s <= e)
    {
        if ((mid * mid) == num)
        {
            return mid;
        }
        else if ((mid * mid) > num)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
            ans = mid;
        }
        mid = s + (e - s) / 2;
    }
    for (int j = 0; j < k; j++)
    {
        s = ans;
        e = ans + (9 / pow(10, j + 1));
        for (double i = s; i <= e; i += (1 / pow(10, j + 1)))
        {
            if ((i * i) > num)
            {
                break;
            }
            else
            {
                ans = i;
            }
        }
    }
    return ans;
}
bool searchMatrix(vector<vector<int>> v, int target)
{
    int row = v.size();
    int col = v[0].size();
    int n = row * col;
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        int i = mid / col;
        int j = mid % col;
        int element = v[i][j];

        if (element == target)
        {
            return true;
        }
        else if (target > element)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return false;
}
int main()
{
    // vector<int> v{12, 14, 16, 2, 4, 6, 8, 10};
    // int pivotIndex = findPivotElement(v);
    // cout << "Pivot Element is : " << v[pivotIndex] << endl;
    // int target = 10;
    // cout << "Element found at index : ";
    // if (target >= v[0] && target <= v[pivotIndex])
    // {
    //     cout << "A : ";
    //     cout << binarySearch(v, 0, pivotIndex, target) << endl;
    // }
    // else
    // {
    //     cout << "B : ";
    //     cout << binarySearch(v, pivotIndex + 1, v.size() - 1, target) << endl;
    // }

    // cout << "Square root of number is : " << squareRoot2(68, 4) << endl;

    // vector<vector<int>> v;
    // vector<int> v1{1, 2, 3};
    // vector<int> v2{5, 6, 7};
    // vector<int> v3{8, 9, 10};
    // vector<int> v4{11, 12, 13};
    // v.push_back(v1);
    // v.push_back(v2);
    // v.push_back(v3);
    // v.push_back(v4);

    // int search = searchMatrix(v, 110);// time complexcity : log(m*n)
    // if(search){
    //     cout << "Found." << endl;
    // }
    // else{
    //     cout << "Not found." << endl;
    // }
    return 0;
}