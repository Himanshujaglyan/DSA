#include <iostream>
using namespace std;

// LEETCODE 1140 (STONE GAME II)
int solve(vector<int> &piles, int start, int M, bool alice)
{
    if (start >= piles.size())
        return 0;

    int ans = alice ? INT_MIN : INT_MAX;
    int total = 0;
    for (int X = 1; X <= 2 * M; X++)
    {
        if (X + start - 1 >= piles.size())
            break;
        total += piles[X + start - 1];
        if (alice)
        {
            ans = max(ans, total + solve(piles, X + start, max(X, M), !alice));
        }
        else
        {
            // now bob has taken maximum profit so alice will be left with minimum profit
            ans = min(ans, solve(piles, X + start, max(X, M), !alice));
        }
    }
    return ans;
}

int stoneGameII(vector<int> &piles)
{
    return solve(piles, 0, 1, true);
}

// MEMOIZATION
int solve(vector<int> &piles, int start, int M, bool alice, vector<vector<vector<int>>> &dp)
{
    if (start >= piles.size())
        return 0;
    if (dp[start][M][alice] != -1)
        return dp[start][M][alice];
    int ans = alice ? INT_MIN : INT_MAX;
    int total = 0;
    for (int X = 1; X <= 2 * M; X++)
    {
        if (X + start - 1 >= piles.size())
            break;
        total += piles[X + start - 1];
        if (alice)
        {
            ans = max(ans, total + solve(piles, X + start, max(X, M), !alice, dp));
        }
        else
        {
            // now bob has taken maximum profit so alice will be left with minimum profit
            ans = min(ans, solve(piles, X + start, max(X, M), !alice, dp));
        }
    }
    return dp[start][M][alice] = ans;
}

int stoneGameII(vector<int> &piles)
{
    vector<vector<vector<int>>> dp(piles.size() + 1, vector<vector<int>>(piles.size() + 1, vector<int>(2, -1)));
    return solve(piles, 0, 1, true, dp);
}

// TABULATION
int stoneGameII(vector<int> &piles)
{
    vector<vector<vector<int>>> dp(piles.size() + 1, vector<vector<int>>(piles.size() + 2, vector<int>(2, 0)));
    for (int start = piles.size() - 1; start >= 0; start--)
    {
        for (int M = piles.size(); M >= 1; M--)// AS M CAN BE EQUAL TO PILES.SIZE()
        {
            for (int alice = 0; alice < 2; alice++)
            {
                int ans = alice ? INT_MIN : INT_MAX;
                int total = 0;
                for (int X = 1; X <= 2 * M; X++)
                {
                    if (X + start - 1 >= piles.size())
                        break;
                    total += piles[X + start - 1];
                    if (alice)
                    {

                        ans = max(ans, total + dp[X + start][max(X, M)][!alice]);
                    }
                    else
                    {
                        // now bob has taken maximum profit so alice will be left with minimum profit
                        ans = min(ans, dp[X + start][max(X, M)][!alice]);
                    }
                }
                dp[start][M][alice] = ans;
            }
        }
    }
    return dp[0][1][1];
}
int main()
{
    return 0;
}