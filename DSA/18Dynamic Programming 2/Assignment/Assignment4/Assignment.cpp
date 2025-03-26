#include<iostream>
using namespace std;

// LEETCODE 5 (LONGEST PALINDROMIC SUBSTRING)
int startIndex = 0;
int maxLength = 1;

bool solve(string &s, int i, int j)
{
    if (i >= j)
        return true;
    bool flag = false;
    if (s[i] == s[j])
    {
        flag = solve(s, i + 1, j - 1);
    }
    if (flag)
    {
        int currLen = j - i + 1;
        if (maxLength < currLen)
        {
            maxLength = currLen;
            startIndex = i;
        }
    }
    return flag;
}
string longestPalindrome(string s)
{
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            bool check = solve(s, i, j);
        }
    }
    return s.substr(startIndex, maxLength);
}

// MEMOIZATION
bool solve(string &s, int i, int j, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i >= j)
        return true;
    bool flag = false;
    if (s[i] == s[j])
    {
        flag = solve(s, i + 1, j - 1, dp);
    }
    if (flag)
    {
        int currLen = j - i + 1;
        if (maxLength < currLen)
        {
            maxLength = currLen;
            startIndex = i;
        }
    }
    return dp[i][j] = flag;
}
string longestPalindrome(string s)
{
    int len = s.length();
    vector<vector<int>> dp(len + 1, vector<int>(len + 1, -1));
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            bool check = solve(s, i, j, dp);
        }
    }
    return s.substr(startIndex, maxLength);
}
int main(){
    return 0;
}