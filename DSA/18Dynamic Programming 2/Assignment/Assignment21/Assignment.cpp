#include <iostream>
using namespace std;

// LEETCODE 188 (BUY AND SELL STOCK IV)
int maxProfit(int k, vector<int> &prices)
{
    vector<vector<int>> prev(2, vector<int>(k + 1, 0));
    vector<vector<int>> next(2, vector<int>(k + 1, 0));
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= k; limit++)
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
    return prev[1][k];
}
int main()
{
    return 0;
}