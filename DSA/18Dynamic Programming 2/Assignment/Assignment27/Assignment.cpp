#include <iostream>
#include <numeric>
using namespace std;

// LEETCODE 486 (PREDICT THE WINNER)
int solve(vector<int> &nums, int s, int e, bool turn)
{
    if (s == e)
    {
        return turn == 1 ? nums[s] : 0;
    }
    if (turn)
    {
        int case1 = nums[s] + solve(nums, s + 1, e, !turn);
        int case2 = nums[e] + solve(nums, s, e - 1, !turn);
        return max(case1, case2);
    }
    else
    {
        int case1 = solve(nums, s + 1, e, !turn);
        int case2 = solve(nums, s, e - 1, !turn);
        return min(case1, case2);
    }
}

bool predictTheWinner(vector<int> &nums)
{
    int p1 = solve(nums, 0, nums.size() - 1, 1);
    int p2 = accumulate(nums.begin(), nums.end(), 0) - p1;
    return p1 >= p2;
}

// LAKSHAY CODE
int solve(vector<int> &nums, int start, int end)
{
    if (start == end)
        return nums[start];

    int diffByStart = nums[start] - solve(nums, start + 1, end);
    int diffByEnd = nums[end] - solve(nums, start, end - 1);

    return max(diffByStart, diffByEnd);
}

bool predictTheWinner(vector<int> &nums)
{
    return solve(nums, 0, nums.size() - 1) >= 0;
}

// MEMOIZATION
int solve(vector<int> &nums, int start, int end, vector<vector<int>> &dp)
{
    if (start == end)
        return nums[start];
    if (dp[start][end] != -1)
        return dp[start][end];

    int diffByStart = nums[start] - solve(nums, start + 1, end, dp);
    int diffByEnd = nums[end] - solve(nums, start, end - 1, dp);

    return dp[start][end] = max(diffByStart, diffByEnd);
}

bool predictTheWinner(vector<int> &nums)
{
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
    return solve(nums, 0, nums.size() - 1, dp) >= 0;
}

// BOTTOM UP
bool predictTheWinner(vector<int> &nums)
{
    vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
    for (int i = 0; i < nums.size(); i++)
    {
        dp[i][i] = nums[i];
    }
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int diffByStart = nums[i] - dp[i + 1][j];
            int diffByEnd = nums[j] - dp[i][j - 1];
            dp[i][j] = max(diffByStart, diffByEnd);
        }
    }
    return dp[0][nums.size() - 1] >= 0;
}
int main()
{
    return 0;
}