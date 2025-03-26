#include <iostream>
using namespace std;

// LEETCODE 416 (PARTITION EQUAL SUBSET SUM)
// MY APPROACH
bool solve1(vector<int> &nums, int index, int leftArray, int rightArray)
{
    if (index >= nums.size())
    {
        if (leftArray == rightArray)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool case1 = solve1(nums, index + 1, leftArray + nums[index], rightArray);
    bool case2 = solve1(nums, index + 1, leftArray, rightArray + nums[index]);

    return case1 || case2;
}

bool canPartition(vector<int> &nums)
{
    return solve1(nums, 0, 0, 0);
}

// BABBAR APPROACH
bool solve(vector<int> &nums, int index, int sum, int &requiredSum)
{
    if (sum == requiredSum)
        return true;
    else if (sum > requiredSum)
        return false;
    else if (index >= nums.size())
        return false;

    bool include = solve(nums, index + 1, sum + nums[index], requiredSum);
    bool exclude = solve(nums, index + 1, sum, requiredSum);

    return include || exclude;
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum & 1)
        return false;
    int requiredSum = sum / 2;
    return solve(nums, 0, 0, requiredSum);
}

// MEMOIZATION
bool solve(vector<int> &nums, int index, int sum, int &requiredSum, vector<vector<int>> &dp)
{
    if (sum == requiredSum)
        return true;
    else if (sum > requiredSum)
        return false;
    else if (index >= nums.size())
        return false;
    if (dp[index][sum] != -1)
        return dp[index][sum];
    bool include = solve(nums, index + 1, sum + nums[index], requiredSum, dp);
    bool exclude = solve(nums, index + 1, sum, requiredSum, dp);
    return dp[index][sum] = include || exclude;
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum & 1)
        return false;
    int requiredSum = sum / 2;
    vector<vector<int>> dp(nums.size() + 1, vector<int>(requiredSum + 1, -1));
    return solve(nums, 0, 0, requiredSum, dp);
}

// TABULATION
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum & 1)
        return false;
    int requiredSum = sum / 2;
    vector<vector<bool>> dp(nums.size() + 1, vector<bool>(requiredSum + 1, false));
    for (int index = nums.size() - 1; index >= 0; index--)
    {
        dp[index][requiredSum] = true;// UPDATION
        for (int sum = requiredSum - 1; sum >= 0; sum--)
        {
            bool include = false;
            if (sum + nums[index] <= requiredSum)// EXTRA CONDITION REQUIRED
                include = dp[index + 1][sum + nums[index]];
            bool exclude = dp[index + 1][sum];
            dp[index][sum] = include || exclude;
        }
    }
    return dp[0][0];
}

// SPACE OPTIMIZED
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum & 1)
        return false;
    int requiredSum = sum / 2;
    vector<bool> next(requiredSum + 1, false);
    vector<bool> curr(requiredSum + 1, false);
    next[requiredSum] = true;
    curr[requiredSum] = true;
    for (int index = nums.size() - 1; index >= 0; index--)
    {
        for (int sum = requiredSum - 1; sum >= 0; sum--)
        {
            bool include = false;
            if (sum + nums[index] <= requiredSum)
                include = next[sum + nums[index]];
            bool exclude = next[sum];
            curr[sum] = include || exclude;
        }
        next = curr;
    }
    return next[0];
}

// MORE SPACE OPTIMIZED
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum & 1)
        return false;
    int requiredSum = sum / 2;
    vector<bool> next(requiredSum + 1, false);
    next[requiredSum] = true;
    for (int index = nums.size() - 1; index >= 0; index--)
    {
        for (int sum = 0; sum <= requiredSum - 1; sum++)
        {
            bool include = false;
            if (sum + nums[index] <= requiredSum)
                include = next[sum + nums[index]];
            bool exclude = next[sum];
            next[sum] = include || exclude;
        }
    }
    return next[0];
}

// LEETCODE 1155 (NUMBER OF DICE ROLLS WITH TARGET SUM)
int mod = 1e9 + 7;

int solve(int &k, int target, int n)
{
    if (n == 0)
    {
        if (target == 0)
            return 1;
        else
            return 0;
    }
    if (target <= 0)
        return 0;
    int totalWays = 0;
    for (int i = 1; i <= k; i++)
    {
        totalWays += (solve(k, target - i, n - 1) % mod);
    }

    return totalWays;
}

int numRollsToTarget(int n, int k, int target)
{
    return solve(k, target, n);
}

// MEMOIZATION
int solve(int &k, int target, int n, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (target == 0)
            return 1;
        else
            return 0;
    }
    if (target <= 0)
        return 0;
    if (dp[n][target] != -1)
        return dp[n][target];
    int totalWays = 0;
    for (int i = 1; i <= k; i++)
    {
        int ways = solve(k, target - i, n - 1, dp);
        totalWays = (totalWays + (ways % mod)) % mod;
    }

    return dp[n][target] = totalWays;
}

int numRollsToTarget(int n, int k, int target)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    return solve(k, target, n, dp);
}

// TABULATION
int numRollsToTarget(int n, int k, int target)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            int totalWays = 0;
            for (int z = 1; z <= k; z++)
            {
                int ways = 0;
                if (j - z >= 0)
                    ways = dp[i - 1][j - z];
                totalWays = (totalWays + (ways % mod)) % mod;
            }
            dp[i][j] = totalWays;
        }
    }
    return dp[n][target];
}

// SPACE OPTIMIZED
int numRollsToTarget(int n, int k, int target)
{
    vector<int> prev(target + 1, 0);
    vector<int> curr(target + 1, 0);
    prev[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            int totalWays = 0;
            for (int z = 1; z <= k; z++)
            {
                int ways = 0;
                if (j - z >= 0)
                    ways = prev[j - z];
                totalWays = (totalWays + (ways % mod)) % mod;
            }
            curr[j] = totalWays;
        }
        prev = curr;
    }
    return curr[target];
}
int main()
{
    return 0;
}