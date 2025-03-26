#include <iostream>
using namespace std;

// LEETCODE 1402 (REDUCING DISHES)
int solve(vector<int> &satisfaction, int i, int time, vector<vector<int>> &dp)
{
    if (i >= satisfaction.size())
        return 0;
    if (dp[i][time] != -1)
        return dp[i][time];
    // include
    int include = (time * satisfaction[i]) + solve(satisfaction, i + 1, time + 1, dp);
    // exclude
    int exclude = solve(satisfaction, i + 1, time, dp);
    return dp[i][time] = max(include, exclude);
}

int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction, 0, 1, dp);
}

// BOTTOM-UP
int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
    sort(satisfaction.begin(), satisfaction.end());
    for (int i = n - 1; i >= 0; i--)
    {
        for (int time = n; time >= 1; time--)
        {
            int include = (time * satisfaction[i]) + dp[i + 1][time + 1];
            int exclude = dp[i + 1][time];
            dp[i][time] = max(include, exclude);
        }
    }
    return dp[0][1];
}

// SPACE OPTIMIZED
int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    vector<vector<int>> dp(2, vector<int>(n + 2, 0));
    sort(satisfaction.begin(), satisfaction.end());
    for (int i = n - 1; i >= 0; i--)
    {
        for (int time = n; time >= 1; time--)
        {
            int include = (time * satisfaction[i]) + dp[1][time + 1];
            int exclude = dp[1][time];
            dp[0][time] = max(include, exclude);
        }
        dp[1] = dp[0];
    }
    return dp[0][1];
}
int main()
{
    return 0;
}