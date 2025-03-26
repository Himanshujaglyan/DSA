#include <iostream>
#include<map>
using namespace std;

// LEETCODE 1187 (MAKE ARRAY STRICTLY INCREASING)
int solve(vector<int> &arr1, vector<int> &arr2, int prev, int i)
{
    if (i == arr1.size())
        return 0;

    int op1 = INT_MAX;
    if (prev < arr1[i])
    {
        // no operation
        op1 = solve(arr1, arr2, arr1[i], i + 1);
    }

    int op2 = INT_MAX;
    auto it = upper_bound(arr2.begin(), arr2.end(), prev);
    if (it != arr2.end())
    {
        int index = it - arr2.begin();
        op2 = solve(arr1, arr2, arr2[index], i + 1);
        if (op2 != INT_MAX)
            op2++;
    }

    return min(op1, op2);
}

int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
{
    sort(arr2.begin(), arr2.end());
    int ans = solve(arr1, arr2, -1, 0);
    return ans == INT_MAX ? -1 : ans;
}

// MEMOIZATION
int solve(vector<int> &arr1, vector<int> &arr2, int prev, int i, map<pair<int, int>, int> &dp)
{
    if (i == arr1.size())
        return 0;
    if (dp.find({prev, i}) != dp.end())
        return dp[{prev, i}];
    int op1 = INT_MAX;
    if (prev < arr1[i])
    {
        // no operation
        op1 = solve(arr1, arr2, arr1[i], i + 1, dp);
    }

    int op2 = INT_MAX;
    auto it = upper_bound(arr2.begin(), arr2.end(), prev);
    if (it != arr2.end())
    {
        int index = it - arr2.begin();
        op2 = solve(arr1, arr2, arr2[index], i + 1, dp);
        if (op2 != INT_MAX)
            op2++;
    }

    return dp[{prev, i}] = min(op1, op2);
}

int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
{
    map<pair<int, int>, int> dp;
    sort(arr2.begin(), arr2.end());
    int ans = solve(arr1, arr2, -1, 0, dp);
    return ans == INT_MAX ? -1 : ans;
}
int main()
{
    return 0;
}