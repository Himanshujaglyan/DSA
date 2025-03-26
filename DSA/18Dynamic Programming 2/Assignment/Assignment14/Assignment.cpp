#include <iostream>
using namespace std;

// LEETCODE 97 (INTERLEAVING STRING)
bool solve(string &s1, string &s2, string &s3, int i1, int i2, int i3, vector<vector<vector<int>>> &dp)
{
    if (i1 == s1.size() && i2 == s2.size() && i3 == s3.size())
        return true;

    if (dp[i1][i2][i3] != -1)
        return dp[i1][i2][i3];
    bool flag = false;

    if (i1 < s1.length() && s1[i1] == s3[i3])
    {
        flag = flag || solve(s1, s2, s3, i1 + 1, i2, i3 + 1, dp);
    }

    if (i2 < s2.length() && s2[i2] == s3[i3])
    {
        flag = flag || solve(s1, s2, s3, i1, i2 + 1, i3 + 1, dp);
    }

    return dp[i1][i2][i3] = flag;
}

bool isInterleave(string s1, string s2, string s3)
{
    int i1 = 0;
    int i2 = 0;
    int i3 = 0;
    vector<vector<vector<int>>> dp(s1.length() + 1, vector<vector<int>>(s2.length() + 1, vector<int>(s3.length() + 1, -1)));
    return solve(s1, s2, s3, i1, i2, i3, dp);
}

// TABULATION
bool isInterleave(string s1, string s2, string s3)
{
    vector<vector<vector<bool>>> dp(s1.length() + 1, vector<vector<bool>>(s2.length() + 1, vector<bool>(s3.length() + 1, false)));
    dp[s1.length()][s2.length()][s3.length()] = true;
    for (int i1 = s1.length(); i1 >= 0; i1--)
    {
        for (int i2 = s2.length(); i2 >= 0; i2--)
        {
            for (int i3 = s3.length(); i3 >= 0; i3--)
            {
                if (i1 == s1.size() && i2 == s2.size() && i3 == s3.size())
                    continue;

                bool flag = false;
                if (i1 < s1.length() && s1[i1] == s3[i3])
                {
                    flag = flag || dp[i1 + 1][i2][i3 + 1];
                }

                if (i2 < s2.length() && s2[i2] == s3[i3])
                {
                    flag = flag || dp[i1][i2 + 1][i3 + 1];
                }

                dp[i1][i2][i3] = flag;
            }
        }
    }
    return dp[0][0][0];
}

// SPACE OPTIMIZED
bool isInterleave(string s1, string s2, string s3)
{
    vector<vector<bool>> next(s2.length() + 1, vector<bool>(s3.length() + 1, false));
    vector<vector<bool>> curr(s2.length() + 1, vector<bool>(s3.length() + 1, false));
    next[s2.length()][s3.length()] = true;
    curr[s2.length()][s3.length()] = true;
    for (int i1 = s1.length(); i1 >= 0; i1--)
    {
        for (int i2 = s2.length(); i2 >= 0; i2--)
        {
            for (int i3 = s3.length(); i3 >= 0; i3--)
            {
                if (i1 == s1.size() && i2 == s2.size() && i3 == s3.size())
                    continue;

                bool flag = false;
                if (i1 < s1.length() && s1[i1] == s3[i3])
                {
                    flag = flag || next[i2][i3 + 1];
                }

                if (i2 < s2.length() && s2[i2] == s3[i3])
                {
                    flag = flag || curr[i2 + 1][i3 + 1];
                }
                curr[i2][i3] = flag;
            }
            next = curr;
        }
    }
    return next[0][0];
}
int main()
{
    return 0;
}