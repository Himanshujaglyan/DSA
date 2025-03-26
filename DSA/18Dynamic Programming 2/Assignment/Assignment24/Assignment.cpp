#include <iostream>
using namespace std;

// LEETCODE 474 (ONES AND ZEROES)
int solve(vector<pair<int, int>> &count, int m, int n, int i, vector<vector<vector<int>>> &dp)
{
    if (i >= count.size())
    {
        return 0;
    }
    if (dp[i][m][n] != -1)
        return dp[i][m][n];
    int include = 0, exclude = 0;
    if (m - count[i].first >= 0 && n - count[i].second >= 0)
    {
        include = 1 + solve(count, m - count[i].first, n - count[i].second, i + 1, dp);
    }
    exclude = solve(count, m, n, i + 1, dp);
    return dp[i][m][n] = max(include, exclude);
}

int findMaxForm(vector<string> &strs, int m, int n)
{
    vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
    vector<pair<int, int>> count;
    for (auto &str : strs)
    {
        int one = 0, zero = 0;
        for (auto &ch : str)
        {
            if (ch == '1')
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        count.push_back({zero, one});
    }
    return solve(count, m, n, 0, dp);
}

// BOTTOM UP
int findMaxForm(vector<string> &strs, int m, int n)
{
    vector<pair<int, int>> count;
    for (auto &str : strs)
    {
        int one = 0, zero = 0;
        for (auto &ch : str)
        {
            if (ch == '1')
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        count.push_back({zero, one});
    }
    vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    for (int i = strs.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                int include = 0, exclude = 0;
                if (j - count[i].first >= 0 && k - count[i].second >= 0)
                {
                    include = 1 + dp[i + 1][j - count[i].first][k - count[i].second];
                }
                exclude = dp[i + 1][j][k];
                dp[i][j][k] = max(include, exclude);
            }
        }
    }
    return dp[0][m][n];
}

// SPACE OPTIMIZED
int findMaxForm(vector<string> &strs, int m, int n)
{
    vector<pair<int, int>> count;
    for (auto &str : strs)
    {
        int one = 0, zero = 0;
        for (auto &ch : str)
        {
            if (ch == '1')
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        count.push_back({zero, one});
    }
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    for (int i = strs.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                int include = 0, exclude = 0;
                if (j - count[i].first >= 0 && k - count[i].second >= 0)
                {
                    include = 1 + dp[1][j - count[i].first][k - count[i].second];
                }
                exclude = dp[1][j][k];
                dp[0][j][k] = max(include, exclude);
            }
        }
        dp[1] = dp[0];
    }
    return dp[0][m][n];
}
int main()
{
    return 0;
}