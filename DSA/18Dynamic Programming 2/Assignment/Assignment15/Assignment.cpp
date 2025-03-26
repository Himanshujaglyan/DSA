#include <iostream>
using namespace std;

// LEETCODE 1312 (MINIMUM INSERTION STEPS TO MAKE A STRING PALINDROME)
int solve(string &s, int start, int end, vector<vector<int>> &dp)
{
    if (start >= end)
    {
        return 0;
    }
    if (dp[start][end] != -1)
        return dp[start][end];
    int ans;
    if (s[start] == s[end])
    {
        ans = solve(s, start + 1, end - 1, dp);
    }
    else
    {
        int case1 = solve(s, start + 1, end, dp);
        int case2 = solve(s, start, end - 1, dp);
        ans = 1 + min(case1, case2);
    }

    return dp[start][end] = ans;
}

int minInsertions(string s)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, -1));
    return solve(s, 0, s.length() - 1, dp);
}

// TABULATION
int minInsertions(string s)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, 0));
    for (int start = s.length() - 1; start >= 0; start--)
    {
        for (int end = start + 1; end < s.length(); end++)
        {
            int ans;
            if (s[start] == s[end])
            {
                ans = dp[start + 1][end - 1];
            }
            else
            {
                int case1 = dp[start + 1][end];
                int case2 = dp[start][end - 1];
                ans = 1 + min(case1, case2);
            }

            dp[start][end] = ans;
        }
    }
    return dp[0][s.length() - 1];
}

// LAKSHAY CODE
int longestCommonSubsequence(string text1, string text2)
{
    vector<int> prev(text2.length() + 1, 0);
    vector<int> next(text2.length() + 1, 0);
    for (int i = text1.length() - 1; i >= 0; i--)
    {
        for (int j = text2.length() - 1; j >= 0; j--)
        {
            if (text1[i] == text2[j])
            {
                prev[j] = 1 + next[j + 1];
            }
            else
            {
                int case1 = next[j];
                int case2 = prev[j + 1];

                prev[j] = max(case1, case2);
            }
        }
        next = prev;
    }

    return next[0];
}

int longestPalindromeSubseq(string s)
{
    string a = s;
    reverse(a.begin(), a.end());
    return longestCommonSubsequence(s, a);
}

int minInsertions(string s)
{
    int LPSLength = longestPalindromeSubseq(s);
    int remainingChar = s.length() - LPSLength;
    return remainingChar;
}
int main()
{
    return 0;
}