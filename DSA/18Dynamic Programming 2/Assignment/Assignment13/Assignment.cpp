#include <iostream>
using namespace std;

// LEETCODE 312 (BURST BALLOONS)
// BRUTE FORCE APPROACH :- BURST EACH BALLOON ONE BY ONE AND GOES FROM TOP TO BOTTOM
int solve(vector<int> &nums, vector<bool> &isBursted, int count)
{
    if (count == nums.size())
        return 0;

    int size = nums.size();
    int ans = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (isBursted[i])
            continue;
        int leftIndex = i - 1;
        while (leftIndex >= 0 && isBursted[leftIndex])
        {
            leftIndex--;
        }
        int left = leftIndex < 0 ? 1 : nums[leftIndex];
        int rightIndex = i + 1;
        while (rightIndex < size && isBursted[rightIndex])
        {
            rightIndex++;
        }
        int right = rightIndex >= size ? 1 : nums[rightIndex];
        int coins = left * nums[i] * right;
        isBursted[i] = true;
        count++;
        ans = max(ans, coins + solve(nums, isBursted, count));
        isBursted[i] = false;
        count--;
    }
    return ans;
}

int maxCoins(vector<int> &nums)
{
    vector<bool> isBursted(nums.size(), false);
    return solve(nums, isBursted, 0);
}

// LAKSHAY APPROACH
// IN PREVIOUS APPROACH WE ARE REMOVING BALLOONS WHILE IN THIS APPROACH WE WILL ADD BALLOON WHILE GOING FROM BOTTOM-UP(TO SELECT WHICH BALLOON IS LAST BURSTED)
// ALSO THERE IN NO OPTIMAL SUBSTRUCTURE THAT IS FORMING
int solve(vector<int> &nums, int start, int end)
{
    if (start > end)
        return 0;

    int coins = INT_MIN;
    for (int i = start; i <= end; i++)
    {
        coins = max(coins, nums[start - 1] * nums[i] * nums[end + 1] + solve(nums, start, i - 1) + solve(nums, i + 1, end));
    }

    return coins;
}

int maxCoins(vector<int> &nums)
{
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    return solve(nums, 1, nums.size() - 2);
}

// MEMOIZATION
int solve(vector<int> &nums, int start, int end, vector<vector<int>> &dp)
{
    if (start > end)
        return 0;
    if (dp[start][end] != -1)
        return dp[start][end];
    int coins = INT_MIN;
    for (int i = start; i <= end; i++)
    {
        coins = max(coins, nums[start - 1] * nums[i] * nums[end + 1] + solve(nums, start, i - 1, dp) + solve(nums, i + 1, end, dp));
    }

    return dp[start][end] = coins;
}

int maxCoins(vector<int> &nums)
{
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
    return solve(nums, 1, nums.size() - 2, dp);
}

// TABULATION
int maxCoins(vector<int> &nums)
{
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
    for (int start = nums.size() - 2; start >= 1; start--)
    {
        for (int end = start; end <= nums.size() - 2; end++)
        {
            int coins = INT_MIN;
            for (int i = start; i <= end; i++)
            {
                coins = max(coins, nums[start - 1] * nums[i] * nums[end + 1] + dp[start][i - 1] + dp[i + 1][end]);
            }

            dp[start][end] = coins;
        }
    }
    return dp[1][nums.size() - 2];
}
int main()
{
    return 0;
}