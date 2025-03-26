#include <iostream>
using namespace std;

// GFG (KNAPSACK WITH DUPLICATE ITEMS)
int solve(vector<int> &val, vector<int> &wt, int index, int capacity, vector<vector<int>> &dp)
{
    if (index >= val.size())
    {
        return 0;
    }
    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    int case1 = 0, case2 = 0;
    if (capacity - wt[index] >= 0)
    {
        case1 = val[index] + solve(val, wt, index, capacity - wt[index], dp);
    }
    case2 = solve(val, wt, index + 1, capacity, dp);
    return dp[index][capacity] = max(case1, case2);
}

int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    vector<vector<int>> dp(val.size() + 1, vector<int>(capacity + 1, -1));
    return solve(val, wt, 0, capacity, dp);
}
int main()
{
    return 0;
}