#include <iostream>
using namespace std;

// LONGEST INCREASING SUBSEQUENCE PATTERN :- WHEN WE TALK ABOUT STACKING, PLACEMENT OR INSERTION BASED ON SOME CONDITION
// FOR EXAMPLE :- PLACING SMALLER CUBOIDS OVER LARGER CUBOIDS REPEATLY

// LEETCODE 300 (LONGEST INCREASING SUBSEQUENCE)
int solve(vector<int> &nums, int currIndex, int prevIndex)
{
    if (currIndex >= nums.size())
    {
        return 0;
    }

    int include = 0;
    int exclude = 0;

    if (prevIndex == -1 || nums[currIndex] > nums[prevIndex])
    {
        include = 1 + solve(nums, currIndex + 1, currIndex);
    }

    exclude = solve(nums, currIndex + 1, prevIndex);

    return max(include, exclude);
}

int lengthOfLIS(vector<int> &nums)
{
    return solve(nums, 0, -1);
}

// MEMOIZATION
int solve(vector<int> &nums, int currIndex, int prevIndex, vector<vector<int>> &dp)
{
    if (currIndex >= nums.size())
    {
        return 0;
    }

    if (dp[currIndex][prevIndex + 1] != -1) // INDEX SHIFTING
        return dp[currIndex][prevIndex + 1];
    int include = 0;
    int exclude = 0;

    if (prevIndex == -1 || nums[currIndex] > nums[prevIndex])
    {
        include = 1 + solve(nums, currIndex + 1, currIndex, dp);
    }

    exclude = solve(nums, currIndex + 1, prevIndex, dp);

    return dp[currIndex][prevIndex + 1] = max(include, exclude);
}

int lengthOfLIS(vector<int> &nums)
{
    vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 2, -1));
    return solve(nums, 0, -1, dp);
}

// TABULATION
int lengthOfLIS(vector<int> &nums)
{
    vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 2, 0));

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        { // prev pointer will go 1 less than curr in worst case
            int include = 0;
            int exclude = 0;
            if (j == -1 || nums[i] > nums[j])
            {
                include = 1 + dp[i + 1][i + 1]; // MAKE SURE TO DO INDEX SHIFTING
            }
            exclude = dp[i + 1][j + 1];

            dp[i][j + 1] = max(include, exclude);
        }
    }
    return dp[0][0];
}

// SPACE OPTIMIZED
int lengthOfLIS(vector<int> &nums)
{
    vector<int> curr(nums.size() + 2, 0);
    vector<int> next(nums.size() + 2, 0);
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int include = 0;
            int exclude = 0;
            if (j == -1 || nums[i] > nums[j])
            {
                include = 1 + next[i + 1];
            }
            exclude = next[j + 1];

            curr[j + 1] = max(include, exclude);
        }
        next = curr;
    }
    return curr[0];
}

// MORE SPACE OPTIMIZED
int lengthOfLIS(vector<int> &nums)
{
    vector<int> next(nums.size() + 2, 0);
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        for (int j = -1; j <= i - 1; j++)
        {
            int include = 0;
            int exclude = 0;
            if (j == -1 || nums[i] > nums[j])
            {
                include = 1 + next[i + 1];
            }
            exclude = next[j + 1];

            next[j + 1] = max(include, exclude);
        }
    }
    return next[0];
}

// USING BINARY SEARCH
int lengthOfLIS(vector<int> &nums)
{
    vector<int> ans;
    ans.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > ans.back())
        {
            ans.push_back(nums[i]);
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[index] = nums[i];
        }
    }

    return ans.size();
}

// LEETCODE 1691 (MAXIMUM HEIGHT BY STACKING CUBOIDS) (USING ABOVE APPROACH)
bool check(vector<int> c1, vector<int> c2)
{
    // c1 -> small cube
    // c2 -> big cube
    if ((c1[0] <= c2[0]) && (c1[1] <= c2[1]) && (c1[2] <= c2[2]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int solve(vector<vector<int>> &cuboids) // We directly used the previous code
{
    vector<int> next(cuboids.size() + 2, 0);
    for (int i = cuboids.size() - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int include = 0;
            int exclude = 0;
            if (j == -1 || check(cuboids[j], cuboids[i]))
            {
                include = cuboids[i][2] + next[i + 1];
            }
            exclude = next[j + 1];

            next[j + 1] = max(include, exclude);
        }
    }
    return next[0];
}
int maxHeight(vector<vector<int>> &cuboids)
{
    for (auto &cuboid : cuboids)
    {
        sort(cuboid.begin(), cuboid.end());
    }
    sort(cuboids.begin(), cuboids.end());
    int ans = solve(cuboids);
    return ans;
}

// LEETCODE 354 (RUSSIAN DOLL ENVELOPES)
bool check1(vector<int> &e1, vector<int> &e2)
{
    if ((e1[0] < e2[0]) && (e1[1] < e2[1]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int solve(vector<vector<int>> &envelopes)
{
    vector<int> next(envelopes.size() + 2, 0);
    for (int i = envelopes.size() - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int include = 0;
            int exclude = 0;
            if (j == -1 || check1(envelopes[j], envelopes[i]))
            {
                include = 1 + next[i + 1];
            }
            exclude = next[j + 1];

            next[j + 1] = max(include, exclude);
        }
    }
    return next[0];
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end());
    return solve(envelopes);
}

// BINARY SEARCH
static bool myComp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end(), myComp);
    vector<int> ans;
    ans.push_back(envelopes[0][1]);
    for (int i = 1; i < envelopes.size(); i++)
    {
        if (ans.back() < envelopes[i][1])
        {
            ans.push_back(envelopes[i][1]);
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
            ans[index] = envelopes[i][1];
        }
    }
    return ans.size();
}

// HERE WE COMPARE ON THE BASIS OF HEIGHT AND IT WILL NOT CAUSE PROBLEM BECAUSE IN CASE OF BIGGER HEIGHT COMING
// IT WILL SURELY BE OF GREATER WIDTH AS WE HAD ALREADY TACKLED IT USING OUR SORTING LOGIC
// WHERE BIGGER HEIGHT COMES FIRST THEN SMALLER OF SAME WIDTH
int main()
{
    return 0;
}