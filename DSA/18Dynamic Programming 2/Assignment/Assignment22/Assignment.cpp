#include <iostream>
using namespace std;

// LEETCODE 714 (BEST TIME TO BUY AND SELL STOCK WITH TRANSACTION FEE)
int maxProfit(vector<int> &prices, int fee)
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
                int sellProfit = prices[i] + next[1] - fee; // change
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