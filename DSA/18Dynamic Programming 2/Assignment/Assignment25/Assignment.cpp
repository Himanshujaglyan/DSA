#include <iostream>
using namespace std;

// LEETCODE 801 (MINIMUM SWAPS TO MKAE SEQUENCES INCREASING)
int solve(vector<int> &v1, vector<int> &v2, int i, int p1, int p2)
{
    if (i >= v1.size())
        return 0;

    int swap = INT_MAX, noSwap = INT_MAX;
    if (p1 < v1[i] && p2 < v2[i])
    {
        noSwap = solve(v1, v2, i + 1, v1[i], v2[i]);
    }

    if (p1 < v2[i] && p2 < v1[i])
    {
        swap = 1 + solve(v1, v2, i + 1, v2[i], v1[i]);
    }

    return min(swap, noSwap);
}

int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    return solve(nums1, nums2, 0, -1, -1);
}

// MEMOIZATION
int solve(vector<int> &v1, vector<int> &v2, int i, int p1, int p2, vector<vector<int>> &dp, int isSwap)
{
    if (i >= v1.size())
        return 0;
    if (dp[i][isSwap] != -1)
        return dp[i][isSwap];
    int swap = INT_MAX, noSwap = INT_MAX;
    if (p1 < v1[i] && p2 < v2[i])
    {
        noSwap = solve(v1, v2, i + 1, v1[i], v2[i], dp, 0);
    }

    if (p1 < v2[i] && p2 < v1[i])
    {
        swap = 1 + solve(v1, v2, i + 1, v2[i], v1[i], dp, 1);
    }

    return dp[i][isSwap] = min(swap, noSwap);
}

int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
    return solve(nums1, nums2, 0, -1, -1, dp, 0);
}

// BOTTOM UP
int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));
    for (int i = nums1.size() - 1; i >= 1; i--)
    {
        for (int j = 1; j >= 0; j--)
        {
            int p1 = nums1[i - 1];
            int p2 = nums2[i - 1];
            if (j)
            {
                swap(p1, p2);
            }
            int swap = INT_MAX, noSwap = INT_MAX;
            if (p1 < nums1[i] && p2 < nums2[i])
            {
                noSwap = dp[i + 1][0];
            }
            if (p1 < nums2[i] && p2 < nums1[i])
            {
                swap = 1 + dp[i + 1][1];
            }
            dp[i][j] = min(swap, noSwap);
        }
    }
    return dp[1][0];
}
int main()
{
    return 0;
}