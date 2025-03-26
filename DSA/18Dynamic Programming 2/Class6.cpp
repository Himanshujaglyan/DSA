#include <iostream>
#include <map>
using namespace std;

// PARTIONING || MERGE INTERVAL PATTERN

// LEETCODE 375 (GUESS NUMBER HIGHER OR LOWER II)
int solve(int start, int end)
{
    if (start >= end)
    {
        return 0;
    }

    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solve(start, i - 1), solve(i + 1, end)));
    }

    return ans;
}

int getMoneyAmount(int n)
{
    return solve(1, n);
}

// MEMOIZATION
int solve(int start, int end, vector<vector<int>> &dp)
{
    if (start >= end)
    {
        return 0;
    }

    if (dp[start][end] != -1)
        return dp[start][end];
    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solve(start, i - 1, dp), solve(i + 1, end, dp)));
    }

    return dp[start][end] = ans;
}

int getMoneyAmount(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(1, n, dp);
}

// TABULATION
int getMoneyAmount(int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));

    for (int start_index = n; start_index >= 1; start_index--)
    {
        for (int end_index = start_index + 1; end_index <= n; end_index++) // check starting value
        {
            int ans = INT_MAX;
            for (int i = start_index; i <= end_index; i++)
            {
                ans = min(ans, i + max(dp[start_index][i - 1], dp[i + 1][end_index]));
            }

            dp[start_index][end_index] = ans;
        }
    }

    return dp[1][n];
}

// LEETCODE 1130 (MINIMUM COST TREE FROM LEAF VALUES) (PRECOMPUTATION)
int solve(vector<int> &arr, map<pair<int, int>, int> &maxi, int start, int end)
{
    if (start >= end)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = start; i < end; i++)
    {
        ans = min(ans, maxi[{start, i}] * maxi[{i + 1, end}] +
                           solve(arr, maxi, start, i) +
                           solve(arr, maxi, i + 1, end));
    }
    return ans;
}

int mctFromLeafValues(vector<int> &arr)
{
    int size = arr.size();
    map<pair<int, int>, int> maxi;
    for (int i = 0; i < size; i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < size; j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }
    return solve(arr, maxi, 0, size - 1);
}

// MEMOIZATION
int solve(vector<int> &arr, map<pair<int, int>, int> &maxi, int start, int end, vector<vector<int>> &dp)
{
    if (start >= end)
    {
        return 0;
    }
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }
    int ans = INT_MAX;
    for (int i = start; i < end; i++)
    {
        ans = min(ans, maxi[{start, i}] * maxi[{i + 1, end}] +
                           solve(arr, maxi, start, i, dp) +
                           solve(arr, maxi, i + 1, end, dp));
    }
    return dp[start][end] = ans;
}

int mctFromLeafValues(vector<int> &arr)
{
    int size = arr.size();
    map<pair<int, int>, int> maxi;
    for (int i = 0; i < size; i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < size; j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }
    vector<vector<int>> dp(size + 1, vector<int>(size + 1, -1));
    return solve(arr, maxi, 0, size - 1, dp);
}

// TABULATION
int mctFromLeafValues(vector<int> &arr)
{
    int size = arr.size();
    map<pair<int, int>, int> maxi;
    for (int i = 0; i < size; i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < size; j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }

    vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));
    for (int start_index = size - 1; start_index >= 0; start_index--)
    {
        for (int end_index = start_index + 1; end_index < size; end_index++)
        {
            int ans = INT_MAX;
            for (int i = start_index; i < end_index; i++)
            {
                ans = min(
                    ans, (maxi[{start_index, i}] * maxi[{i + 1, end_index}]) + dp[start_index][i] + dp[i + 1][end_index]);
            }
            dp[start_index][end_index] = ans;
        }
    }

    return dp[0][size - 1];
}
int main()
{

    return 0;
}