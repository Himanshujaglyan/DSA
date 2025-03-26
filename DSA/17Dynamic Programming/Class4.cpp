#include <iostream>
using namespace std;

// LEETCODE 1143 (LONGEST COMMON SUBSEQQUENCE)
int solve(string &s1, string &s2, int i, int j)
{
    if (i >= s1.length() || j >= s2.length())
    {
        return 0;
    }

    if (s1[i] == s2[j])
    {
        return 1 + solve(s1, s2, i + 1, j + 1);
    }
    else
    {
        int case1 = solve(s1, s2, i, j + 1);
        int case2 = solve(s1, s2, i + 1, j);

        return max(case1, case2);
    }
}

int longestCommonSubsequence(string text1, string text2)
{
    return solve(text1, text2, 0, 0);
}

// MEMOIZATION
int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    if (i >= s1.length() || j >= s2.length())
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1, dp);
    }
    else
    {
        int case1 = solve(s1, s2, i, j + 1, dp);
        int case2 = solve(s1, s2, i + 1, j, dp);

        return dp[i][j] = max(case1, case2);
    }
}

int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
    return solve(text1, text2, 0, 0, dp);
}

// TABULATION
int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));

    for (int i = text1.length() - 1; i >= 0; i--)
    {
        for (int j = text2.length() - 1; j >= 0; j--)
        {
            if (text1[i] == text2[j])
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else
            {
                int case1 = dp[i + 1][j];
                int case2 = dp[i][j + 1];

                dp[i][j] = max(case1, case2);
            }
        }
    }

    return dp[0][0];
}

// SPACE OPTIMIZED
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

// LEETCODE 516 (LONGEST PALINDROMIC SUBSEQUENCE)
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

// LEETCODE 72 (EDIT DISTANCE)
int solve(string &s1, string &s2, int i, int j)
{
    if (i >= s1.length())
    {
        return s2.length() - j;
    }

    if (j >= s2.length())
    {
        return s1.length() - i;
    }

    if (s1[i] == s2[j])
    {
        return solve(s1, s2, i + 1, j + 1);
    }

    // replace
    int op1 = 1 + solve(s1, s2, i + 1, j + 1);
    // delete
    int op2 = 1 + solve(s1, s2, i + 1, j);
    // insert
    int op3 = 1 + solve(s1, s2, i, j + 1);

    return min(op1, min(op2, op3));
}

int minDistance(string word1, string word2)
{
    return solve(word1, word2, 0, 0);
}

// MEMOIZATION
int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    if (i >= s1.length())
    {
        return s2.length() - j;
    }

    if (j >= s2.length())
    {
        return s1.length() - i;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
    {
        return dp[i][j] = solve(s1, s2, i + 1, j + 1, dp);
    }

    // replace
    int op1 = 1 + solve(s1, s2, i + 1, j + 1, dp);
    // delete
    int op2 = 1 + solve(s1, s2, i + 1, j, dp);
    // insert
    int op3 = 1 + solve(s1, s2, i, j + 1, dp);

    return dp[i][j] = min(op1, min(op2, op3));
}

int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));
    return solve(word1, word2, 0, 0, dp);
}

// TABULATION
int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));

    for (int i = 0; i <= word2.length(); i++)
    {
        dp[word1.length()][i] = word2.length() - i;
    }

    for (int i = 0; i <= word1.length(); i++)
    {
        dp[i][word2.length()] = word1.length() - i;
    }

    for (int i = word1.length() - 1; i >= 0; i--)
    {
        for (int j = word2.length() - 1; j >= 0; j--)
        {
            if (word1[i] == word2[j])
            {
                dp[i][j] = dp[i + 1][j + 1];
            }
            else
            {
                // replace
                int op1 = 1 + dp[i + 1][j + 1];
                // delete
                int op2 = 1 + dp[i + 1][j];
                // insert
                int op3 = 1 + dp[i][j + 1];

                dp[i][j] = min(op1, min(op2, op3));
            }
        }
    }

    return dp[0][0];
}

// SPACE OPTIMIZED
int minDistance(string word1, string word2)
{
    vector<int> curr(word1.length() + 1, 0);
    vector<int> next(word1.length() + 1, 0);

    for (int i = 0; i <= word1.length(); i++)
    {
        next[i] = word1.length() - i;
    }

    for (int j = word2.length() - 1; j >= 0; j--)
    {
        curr[word1.length()] = word2.length() - j;// updating value at each iteration
        for (int i = word1.length() - 1; i >= 0; i--)
        {
            if (word1[i] == word2[j])
            {
                curr[i] = next[i + 1];
            }
            else
            {
                // replace
                int op1 = 1 + next[i + 1];
                // delete
                int op2 = 1 + curr[i + 1];
                // insert
                int op3 = 1 + next[i];

                curr[i] = min(op1, min(op2, op3));
            }
        }
        next = curr;
    }

    return next[0];
}
int main()
{
    return 0;
}