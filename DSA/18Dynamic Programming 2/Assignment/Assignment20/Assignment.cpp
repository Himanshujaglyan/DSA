#include <iostream>
using namespace std;

// LEETCODE 123 (BEST TIME TO BUY AND SELL STOCK III)
int solve(vector<int> &prices, int i, bool buy, int limit, vector<vector<vector<int>>> &dp)
{
    if (i >= prices.size() || limit == 0)
    {
        return 0;
    }
    if (dp[i][buy][limit] != -1)
        return dp[i][buy][limit];
    if (buy)
    {
        int buyProfit = -prices[i] + solve(prices, i + 1, false, limit, dp);
        int skipProfit = solve(prices, i + 1, true, limit, dp);
        return dp[i][buy][limit] = max(buyProfit, skipProfit);
    }
    else
    {
        int sellProfit = prices[i] + solve(prices, i + 1, true, limit - 1, dp);
        int skipProfit = solve(prices, i + 1, false, limit, dp);
        return dp[i][buy][limit] = max(sellProfit, skipProfit);
    }
}
int maxProfit(vector<int> &prices)
{
    vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
    return solve(prices, 0, true, 2, dp);
}

// BOTTOM-UP
int maxProfit(vector<int> &prices)
{
    vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                if (buy)
                {
                    int buyProfit = -prices[i] + dp[i + 1][0][limit];
                    int skipProfit = dp[i + 1][1][limit];
                    dp[i][buy][limit] = max(buyProfit, skipProfit);
                }
                else
                {
                    int sellProfit = prices[i] + dp[i + 1][1][limit - 1];
                    int skipProfit = dp[i + 1][0][limit];
                    dp[i][buy][limit] = max(sellProfit, skipProfit);
                }
            }
        }
    }
    return dp[0][1][2];
}

// SPACE OPTIMIZED
int maxProfit(vector<int> &prices)
{
    vector<vector<int>> prev(2, vector<int>(3, 0));
    vector<vector<int>> next(2, vector<int>(3, 0));
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                if (buy)
                {
                    int buyProfit = -prices[i] + next[0][limit];
                    int skipProfit = next[1][limit];
                    prev[buy][limit] = max(buyProfit, skipProfit);
                }
                else
                {
                    int sellProfit = prices[i] + next[1][limit - 1];
                    int skipProfit = next[0][limit];
                    prev[buy][limit] = max(sellProfit, skipProfit);
                }
            }
            next = prev;
        }
    }
    return prev[1][2];
}
int main()
{
    return 0;
}