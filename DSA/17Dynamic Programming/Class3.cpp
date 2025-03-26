#include <iostream>
#include <vector>
using namespace std;

// GFG (PAINTING THE FENCE)
long long solve(int n, int &k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    return (k - 1) * (solve(n - 1, k) + solve(n - 2, k));
}

long long solveUsingMem(int n, int &k, vector<long long> &dp)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = (k - 1) * (solveUsingMem(n - 1, k, dp) + solveUsingMem(n - 2, k, dp));
}

long long solveUsingTabulation(int n, int &k)
{
    vector<long long> dp(n + 1, 0);
    dp[1] = k;
    if (n == 1)
        return k;
    dp[2] = k * k;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
    }
    return dp[n];
}

long long solveUsingTabulationSpaceOptimized(int n, long long &k)
{
    int mod = 1e9 + 7;
    long long prev = k % mod;
    long long curr = (k * k) % mod;
    if (n == 1)
        return prev;
    if (n == 2)
        return curr;
    long long ans = 0;
    for (int i = 3; i <= n; i++)
    {
        long long sum = (prev + curr) % mod;
        ans = (sum * ((k - 1) % mod)) % mod;
        prev = curr;
        curr = ans;
    }
    return ans;
}

long long countWays(int n, long long k)
{
    // vector<long long> dp(n + 1, -1);
    return solveUsingTabulationSpaceOptimized(n, k);
}

// GFG (0-1 KNAPSACK PROBLEM) // 2-D DP
int solve(vector<int> &val, vector<int> &wt, int capacity, int index)
{

    if (index >= val.size() || capacity == 0)
        return 0;

    int include = 0;
    int exclude = 0;
    if (wt[index] <= capacity)
        include = val[index] + solve(val, wt, capacity - wt[index], index + 1);
    exclude = 0 + solve(val, wt, capacity, index + 1);

    return max(include, exclude);
}

int solveUsingMem(vector<int> &val, vector<int> &wt, int capacity, int index, vector<vector<int>> &dp)
{

    if (index >= val.size() || capacity == 0)
        return 0;
    if (dp[capacity][index] != -1)
        return dp[capacity][index];

    int include = 0;
    int exclude = 0;
    if (wt[index] <= capacity)
        include = val[index] + solveUsingMem(val, wt, capacity - wt[index], index + 1, dp);
    exclude = 0 + solveUsingMem(val, wt, capacity, index + 1, dp);

    return dp[capacity][index] = max(include, exclude);
}

int solveUsingTabulation(vector<int> &val, vector<int> &wt, int capacity)
{

    vector<vector<int>> dp((capacity + 1), vector<int>(val.size() + 1, 0));

    for (int i = 0; i <= capacity; i++)
    {
        for (int j = val.size() - 1; j >= 0; j--)
        {
            int include = 0;
            int exclude = 0;
            if (wt[j] <= i)
                include = val[j] + dp[i - wt[j]][j + 1];
            exclude = 0 + dp[i][j + 1];
            dp[i][j] = max(include, exclude);
        }
    }

    return dp[capacity][0];
}

int solveUsingTabulationSO(vector<int> &val, vector<int> &wt, int capacity)
{

    vector<int> current(capacity + 1, 0);
    vector<int> prev(capacity + 1, 0);

    for (int i = val.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j <= capacity; j++)
        {
            int include = 0;
            int exclude = 0;
            if (j >= wt[i])
                include = val[i] + current[j - wt[i]];
            exclude = 0 + current[j];
            prev[j] = max(include, exclude);
        }
        current = prev;
    }

    // for (int j = val.size() - 1; j >= 0; j--)// CHANGING PREV && CURRENT && SWAPPING THE LOOPS
    // {
    //     for (int i = 0; i <= capacity; i++)
    //     {
    //         int include = 0;
    //         int exclude = 0;
    //         if (wt[j] <= i)
    //             include = val[j] + current[i - wt[j]];
    //         exclude = 0 + current[i];
    //         prev[i] = max(include, exclude);
    //     }
    //     current = prev;
    // }

    return prev[capacity];
}

int solveUsingTabulationSO2(vector<int> &val, vector<int> &wt, int capacity) // SINGLE VECTOR
{
    vector<int> prev(capacity + 1, 0);

    for (int j = val.size() - 1; j >= 0; j--)
    {
        for (int i = capacity; i >= 0; i--)
        {
            int include = 0;
            int exclude = 0;
            if (wt[j] <= i)
                include = val[j] + prev[i - wt[j]];
            exclude = 0 + prev[i];
            prev[i] = max(include, exclude);
        }
    }

    return prev[capacity];
}

int knapSack(int capacity, vector<int> &val, vector<int> &wt)
{
    // vector<vector<int>> dp((capacity + 1), vector<int> (val.size(), -1));
    return solveUsingTabulationSO2(val, wt, capacity);
}
int main()
{
    return 0;
}