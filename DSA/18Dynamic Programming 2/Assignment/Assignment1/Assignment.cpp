#include<iostream>
#include<vector>
using namespace std;

// LEETCODE 279 (PERFECT SQUARE)
int solve(int n, int num)
{
    if (num == 0)
    {
        return INT_MAX;
    }
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MAX;
    }
    int r1 = solve(n - (num * num), num);
    int r2 = solve(n, num - 1);

    return r1 < r2 ? 1 + r1 : r2;
}

int numSquares(int n)
{
    int num = sqrt(n);
    return solve(n, num);
}

// MEMOIZATION
int solve(int n, int num, vector<vector<int>> &dp)
{
    if (num == 0)
    {
        return INT_MAX;
    }
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MAX;
    }

    if (dp[n][num] != -1)
    {
        return dp[n][num];
    }
    int r1 = solve(n - (num * num), num, dp);
    int r2 = solve(n, num - 1, dp);

    return dp[n][num] = r1 < r2 ? 1 + r1 : r2;
}

int numSquares(int n)
{
    int num = sqrt(n);
    vector<vector<int>> dp(n + 1, vector<int>(num + 1, -1));
    return solve(n, num, dp);
}

// TABULATION
int numSquares(int n)
{
    int num = sqrt(n);
    vector<vector<int>> dp(n + 1, vector<int>(num + 1, 0));
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i][0] = INT_MAX;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            int r1 = INT_MAX;
            if (i - (j * j) >= 0)
                r1 = dp[i - (j * j)][j];
            int r2 = dp[i][j - 1];
            dp[i][j] = r1 < r2 ? 1 + r1 : r2;
        }
    }
    return dp[n][num];
}

// SPACE OPTIMIZED
int numSquares(int n)
{
    int num = sqrt(n);
    vector<int> prev(n + 1, INT_MAX);
    vector<int> curr(n + 1, 0);
    for (int j = 1; j <= num; j++)// LOOP SWAPPED
    {
        for (int i = 1; i <= n; i++)
        {
            int r1 = INT_MAX;
            if (i - (j * j) >= 0)
                r1 = curr[i - (j * j)];
            int r2 = prev[i];
            curr[i] = r1 < r2 ? 1 + r1 : r2;
        }
        prev = curr;
    }
    return curr[n];
}

// LAKSHAY CODE
// TIME COMPLEXCITY :- O(ROOT(N) POWER N) || WORST CASE :- O(N POWER N)
// SPACE COMPLEXCITY :- O(N)
int solve(int n)
{
    if (n == 0)
        return 0;
    int ans = INT_MAX;
    int start = 1;
    int end = sqrt(n);
    while (start <= end)
    {
        int noOfPerfectSquare = 1 + solve(n - (start * start));
        start++;
        ans = min(ans, noOfPerfectSquare);
    }
    return ans;
}

int numSquares(int n)
{
    return solve(n);
}

// TOP DOWN
int solve(int n, vector<int> &dp)// TIME COMPLEXCITY :- CHECK IMAGE
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int ans = INT_MAX;
    int start = 1;
    int end = sqrt(n);
    while (start <= end)
    {
        int noOfPerfectSquare = 1 + solve(n - (start * start), dp);
        start++;
        ans = min(ans, noOfPerfectSquare);
    }
    return dp[n] = ans;
}

int numSquares(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

// TABULATION
int solve(int n, vector<int> &dp)
{
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int ans = INT_MAX;
        int start = 1;
        int end = sqrt(i);
        while (start <= end)
        {
            int noOfPerfectSquare = 1 + dp[i - (start * start)];
            start++;
            ans = min(ans, noOfPerfectSquare);
        }
        dp[i] = ans;
    }

    return dp[n];
}

int numSquares(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}
int main(){
    return 0;
}