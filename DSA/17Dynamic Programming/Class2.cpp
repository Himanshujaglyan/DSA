#include <iostream>
#include <vector>
using namespace std;

// LEETCODE-198 (HOUSE ROBBER)

// TOP-DOWN APPROACH
int solve(vector<int> &nums, int index, vector<int> &dp)
{
    if (index >= nums.size())
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int opt1 = solve(nums, index + 1, dp);
    int opt2 = nums[index] + solve(nums, index + 2, dp);

    dp[index] = max(opt1, opt2);
    return dp[index];
}

int rob(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    int index = 0;
    return solve(nums, index, dp);
}

// TABULATION METHOD
int rob(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1, 0);
    dp[nums.size() - 1] = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; i--) // DIRECTION REVERSE OF RECURSION ANS
    {
        int include = nums[i] + dp[i + 2]; // COPY THE RECURSION ANS LOGIC AS IT IS
        int exclude = dp[i + 1];
        dp[i] = max(include, exclude);
    }

    return dp[0]; // IN MOST OF CASES RETURN INDEX FROM WHICH RECURSION ANS STARTS
}

// SPACE OPTIMISED
int rob(vector<int> &nums)
{
    int num1 = nums[nums.size() - 1];
    int num2 = 0;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        int include = nums[i] + num2;
        int exclude = num1;
        int ans = max(include, exclude);
        num2 = num1;
        num1 = ans;
    }
    return num1;
}

// LEETCODE 322 (COIN CHANGE)
int solveUsingMemoization(vector<int> &coins, int amount, vector<int> &dp)
{
    if (amount == 0)
        return 0;
    if (dp[amount] != -1)
        return dp[amount];
    int ans = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        if (amount - coins[i] >= 0)
        {
            int noOfCoins = solveUsingMemoization(coins, amount - coins[i], dp);
            if (noOfCoins != INT_MAX)
            {
                ans = min(ans, (1 + noOfCoins));
            }
        }
    }
    dp[amount] = ans;
    return ans;
}

int solveUsingTabulation(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        int ans = INT_MAX;
        for (int j = 0; j < coins.size(); j++)
        {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) // SPACE OPTIMIZATION NOT POSSIBLE
            {
                ans = min(ans, 1 + dp[i - coins[j]]);
            }
        }
        dp[i] = ans;
    }

    return dp[amount];
}
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, -1);
    int ans = solveUsingTabulation(coins, amount);
    return ans == INT_MAX ? -1 : ans;
}
int main()
{

    return 0;
}