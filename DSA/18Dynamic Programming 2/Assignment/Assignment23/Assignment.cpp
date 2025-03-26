#include <iostream>
#include <map>
using namespace std;

// LEETCODE 494 (TARGET SUM)
int solve(vector<int> &nums, int target, int index)
{
    if (index >= nums.size())
        return target == 0 ? 1 : 0;
    int plus = solve(nums, target + nums[index], index + 1);
    int minus = solve(nums, target - nums[index], index + 1);
    return plus + minus;
}

int findTargetSumWays(vector<int> &nums, int target)
{
    return solve(nums, target, 0);
}

// MEMOIZATION
int solve(vector<int> &nums, int target, int index, map<pair<int, int>, int> &dp)
{
    if (index >= nums.size())
        return target == 0 ? 1 : 0;
    if (dp.find({index, target}) != dp.end())
        return dp[{index, target}];
    int plus = solve(nums, target + nums[index], index + 1, dp);
    int minus = solve(nums, target - nums[index], index + 1, dp);
    return dp[{index, target}] = plus + minus;
}

int findTargetSumWays(vector<int> &nums, int target)
{
    map<pair<int, int>, int> dp;
    return solve(nums, target, 0, dp);
}

// BOTTOM UP
int findTargetSumWays(vector<int> &nums, int goal)
{
    map<pair<int, int>, int> dp;
    dp[{nums.size(), 0}] = 1;
    int total = 0;
    for (int &num : nums)
    {
        total += num;
    }
    for (int index = nums.size() - 1; index >= 0; index--)
    {
        for (int target = -total; target <= total; target++)
        {
            int plus = dp.find({index + 1, target + nums[index]}) != dp.end() ? dp[{index + 1, target + nums[index]}] : 0;
            int minus = dp.find({index + 1, target - nums[index]}) != dp.end() ? dp[{index + 1, target - nums[index]}] : 0;
            dp[{index, target}] = plus + minus;
        }
    }
    return dp[{0, goal}];
}
int main()
{
    return 0;
}