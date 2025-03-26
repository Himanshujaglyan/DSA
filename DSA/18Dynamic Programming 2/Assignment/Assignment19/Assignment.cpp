#include <iostream>
using namespace std;

// LEETCODE 122 (BEST TIME TO BUY AND SELL STOCK II)
int solve(vector<int> &prices, int start, int end, int index)
{
    if (index >= prices.size())
    {
        return prices[end] - prices[start];
    }
    if (prices[index] < prices[index - 1])
    {
        int profit = prices[end] - prices[start];
        return profit + solve(prices, index, index, index + 1);
    }
    return solve(prices, start, index, index + 1);
}

int maxProfit(vector<int> &prices)
{
    int start = 0;
    int end = 0;
    int index = 1;
    return solve(prices, start, end, index);
}

// LAKSHAY CODE
// MEMOIZATION
int solve(vector<int> &prices, int i, bool buy, vector<vector<int>> &dp)
{
    if (i >= prices.size())
        return 0;
    if (dp[i][buy] != -1)
        return dp[i][buy];
    if (buy)
    {
        int buyProfit = -prices[i] + solve(prices, i + 1, false, dp);
        int skipProfit = solve(prices, i + 1, true, dp);
        return dp[i][buy] = max(buyProfit, skipProfit);
    }
    else
    {
        int sellProfit = prices[i] + solve(prices, i + 1, true, dp);
        int skipProfit = solve(prices, i + 1, false, dp);
        return dp[i][buy] = max(sellProfit, skipProfit);
    }
}

int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    return solve(prices, 0, true, dp);
}

// BOTTOM UP
int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                int buyProfit = -prices[i] + dp[i + 1][0];
                int skipProfit = dp[i + 1][1];
                dp[i][buy] = max(buyProfit, skipProfit);
            }
            else
            {
                int sellProfit = prices[i] + dp[i + 1][1];
                int skipProfit = dp[i + 1][0];
                dp[i][buy] = max(sellProfit, skipProfit);
            }
        }
    }
    return dp[0][1];
}

// SPACE OPTIMIZED
int maxProfit(vector<int> &prices)
{
    vector<int> prev(2, 0);
    vector<int> next(2, 0);
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                int buyProfit = -prices[i] + next[0];
                int skipProfit = next[1];
                prev[buy] = max(buyProfit, skipProfit);
            }
            else
            {
                int sellProfit = prices[i] + next[1];
                int skipProfit = next[0];
                prev[buy] = max(sellProfit, skipProfit);
            }
        }
        next = prev;
    }
    return prev[1];
}

int main()
{
    return 0;
}