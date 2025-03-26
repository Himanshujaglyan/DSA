#include <iostream>
#include<map>
#include<vector>
using namespace std;

// LEETCODE 115 (DISTINCT SUBSEQUENCE)
int solve(string &s, string &t, int index, string &word)
{
    if (word == t)
        return 1;
    if (index >= s.length())
    {
        return 0;
    }
    int exclude = solve(s, t, index + 1, word);
    word.push_back(s[index]);
    int include = solve(s, t, index + 1, word);
    word.pop_back();

    return include + exclude;
}

int numDistinct(string s, string t)
{
    string word = "";
    return solve(s, t, 0, word);
}

// MEMOIZATION
int solve(string &s, string &t, int index, string &word, map<pair<int, string>, int> &dp)
{
    if (word == t)
        return 1;
    if (index >= s.length())
    {
        return 0;
    }
    if (dp.find({index, word}) != dp.end())
        return dp[{index, word}];
    int exclude = solve(s, t, index + 1, word, dp);
    word.push_back(s[index]);
    int include = solve(s, t, index + 1, word, dp);
    word.pop_back();

    return dp[{index, word}] = include + exclude;
}

int numDistinct(string s, string t)
{
    map<pair<int, string>, int> dp;
    string word = "";
    return solve(s, t, 0, word, dp);
}

// LAKSHAY CODE
int solve(string &s, string &t, int i1, int i2)
{
    if (i2 >= t.length())
        return 1;
    if (i1 >= s.length())
        return 0;

    int ans = 0;
    if (s[i1] == t[i2])
    {
        ans += solve(s, t, i1 + 1, i2 + 1);
    }
    ans += solve(s, t, i1 + 1, i2);
    return ans;
}

int numDistinct(string s, string t)
{
    return solve(s, t, 0, 0);
}

// MEMOIZATION
int solve(string &s, string &t, int i1, int i2, vector<vector<int>> &dp)
{
    if (i2 >= t.length())
        return 1;
    if (i1 >= s.length())
        return 0;
    if (dp[i1][i2] != -1)
        return dp[i1][i2];
    int ans = 0;
    if (s[i1] == t[i2])
    {
        ans += solve(s, t, i1 + 1, i2 + 1, dp);
    }
    ans += solve(s, t, i1 + 1, i2, dp);
    return dp[i1][i2] = ans;
}

int numDistinct(string s, string t)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
    return solve(s, t, 0, 0, dp);
}

// TABULATION
int numDistinct(string s, string t)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for (int i = 0; i <= s.length(); i++)
    {
        dp[i][t.length()] = 1;
    }
    for (int i1 = s.length() - 1; i1 >= 0; i1--)
    {
        for (int i2 = t.length() - 1; i2 >= 0; i2--)
        {
            long long ans = 0;
            if (s[i1] == t[i2])
            {
                ans += dp[i1 + 1][i2 + 1];
            }
            ans += dp[i1 + 1][i2];
            dp[i1][i2] = ans;
        }
    }
    return dp[0][0];
}
int main()
{
    return 0;
}