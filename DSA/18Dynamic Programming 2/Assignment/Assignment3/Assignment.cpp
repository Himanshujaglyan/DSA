#include<iostream>
#include<vector>
using namespace std;

// BRUTE FORCE APPROACH
// STORE ALL SUBSEQUENCE OF S1 && S2 AND THEN PERFORM LOOPING TO MATCH THE SUBSEQUENCE AND WHENEVER THEY MATCH CALCULATE THE COST


// LEETCODE 712 (MINIMUM ASCII DELETE SUM FOR 2 STRINGS)
int minimumDeleteSum_helper(string &s1, string &s2, int index1, int index2)
{
    if (index1 == s1.length())
    {
        int total = 0;
        while (index2 < s2.length())
        {
            total += int(s2[index2++]);
        }
        return total;
    }

    if (index2 == s2.length())
    {
        int total = 0;
        while (index1 < s1.length())
        {
            total += int(s1[index1++]);
        }
        return total;
    }

    if (s1[index1] == s2[index2])
    {
        return minimumDeleteSum_helper(s1, s2, index1 + 1, index2 + 1);
    }

    int case1 = int(s1[index1]) + minimumDeleteSum_helper(s1, s2, index1 + 1, index2);
    int case2 = int(s2[index2]) + minimumDeleteSum_helper(s1, s2, index1, index2 + 1);

    return min(case1, case2);
}

int minimumDeleteSum(string s1, string s2)
{
    return minimumDeleteSum_helper(s1, s2, 0, 0);
}

// MEMOIZATION
int minimumDeleteSum_helper(string &s1, string &s2, int index1, int index2, vector<vector<int>> &dp)
{
    if (dp[index1][index2] != -1)
        return dp[index1][index2];
    
    if (index1 == s1.length())
    {
        int total = 0;
        while (index2 < s2.length())
        {
            total += int(s2[index2++]);
        }
        return total;
    }

    if (index2 == s2.length())
    {
        int total = 0;
        while (index1 < s1.length())
        {
            total += int(s1[index1++]);
        }
        return total;
    }

    if (s1[index1] == s2[index2])
    {
        return dp[index1][index2] = minimumDeleteSum_helper(s1, s2, index1 + 1, index2 + 1, dp);
    }

    int case1 = int(s1[index1]) + minimumDeleteSum_helper(s1, s2, index1 + 1, index2, dp);
    int case2 = int(s2[index2]) + minimumDeleteSum_helper(s1, s2, index1, index2 + 1, dp);

    return dp[index1][index2] = min(case1, case2);
}

int minimumDeleteSum(string s1, string s2)
{
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    return minimumDeleteSum_helper(s1, s2, 0, 0, dp);
}

// TABULATION
int minimumDeleteSum_helper(string &s1, string &s2, int index1, int index2, vector<vector<int>> &dp)
{
    int l1 = s1.length();
    int l2 = s2.length();
    for (int i = l2 - 1; i >= 0; i--)
    {
        dp[l1][i] = dp[l1][i + 1] + int(s2[i]);
    }
    for (int i = l1 - 1; i >= 0; i--)
    {
        dp[i][l2] = dp[i + 1][l2] + int(s1[i]);
    }

    for (int index1 = l1 - 1; index1 >= 0; index1--)
    {
        for (int index2 = l2 - 1; index2 >= 0; index2--)
        {
            if (s1[index1] == s2[index2])
            {
                dp[index1][index2] = dp[index1 + 1][index2 + 1];
            }
            else
            {
                int case1 = int(s1[index1]) + dp[index1 + 1][index2];
                int case2 = int(s2[index2]) + dp[index1][index2 + 1];

                dp[index1][index2] = min(case1, case2);
            }
        }
    }
    return dp[0][0];
}

int minimumDeleteSum(string s1, string s2)
{
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    return minimumDeleteSum_helper(s1, s2, 0, 0, dp);
}

// SPACE OPTIMIZED
int minimumDeleteSum_helper(string &s1, string &s2, int index1, int index2)
{
    vector<int> next(s2.length() + 1, 0);
    vector<int> curr(s2.length() + 1, 0);
    int l1 = s1.length();
    int l2 = s2.length();
    for (int i = l2 - 1; i >= 0; i--)
    {
        next[i] = next[i + 1] + int(s2[i]);
    }
    for (int index1 = l1 - 1; index1 >= 0; index1--)
    {
        curr[l2] = next[l2] + int(s1[index1]);
        for (int index2 = l2 - 1; index2 >= 0; index2--)
        {
            if (s1[index1] == s2[index2])
            {
                curr[index2] = next[index2 + 1];
            }
            else
            {
                int case1 = int(s1[index1]) + next[index2];
                int case2 = int(s2[index2]) + curr[index2 + 1];

                curr[index2] = min(case1, case2);
            }
        }
        next = curr;
    }
    return next[0];
}

int minimumDeleteSum(string s1, string s2)
{
    return minimumDeleteSum_helper(s1, s2, 0, 0);
}
int main(){
    return 0;
}