#include <iostream>
using namespace std;

// LEETCODE 139 (WORD BREAK)
// MY APPROACH
bool wordFinder(string &word, vector<string> &wordDict)
{
    for (auto &s : wordDict)
    {
        if (word == s)
            return true;
    }
    return false;
}

bool wordBreak_helper(string &s, vector<string> &wordDict, int &size, int index, string word)
{
    if (index >= size)
        return true;
    while (index < size)
    {
        word.push_back(s[index++]);
        bool flag = wordFinder(word, wordDict);
        if (flag)
        {
            bool case1 = wordBreak_helper(s, wordDict, size, index, "");
            bool case2 = wordBreak_helper(s, wordDict, size, index, word);
            return case1 || case2;
        }
    }
    return false;
}
bool wordBreak(string s, vector<string> &wordDict)
{
    int size = s.length();
    string word = "";
    return wordBreak_helper(s, wordDict, size, 0, word);
}

// LAKSHAY APPROACH
bool wordFinder(string &word, vector<string> &wordDict)
{
    for (auto &s : wordDict)
    {
        if (word == s)
            return true;
    }
    return false;
}

bool wordBreak_helper(string &s, vector<string> &wordDict, int &size, int index)
{
    if (index >= size)
        return true;
    string word = "";
    bool flag = false;
    while (index < size)
    {
        word.push_back(s[index++]);
        if (wordFinder(word, wordDict))
        {
            flag = flag || wordBreak_helper(s, wordDict, size, index);
        }
    }
    return flag;
}
bool wordBreak(string &s, vector<string> &wordDict)
{
    int size = s.length();
    return wordBreak_helper(s, wordDict, size, 0);
}

// MEMOIZATION
bool wordFinder(string &word, vector<string> &wordDict)
{
    for (auto &s : wordDict)
    {
        if (word == s)
            return true;
    }
    return false;
}

bool wordBreak_helper(string &s, vector<string> &wordDict, int &size, int start, vector<int> &dp)
{
    if (start >= size)
        return true;
    if (dp[start] != -1)
        return dp[start];
    int index = start;
    string word = "";
    bool flag = false;
    while (index < size)
    {
        word.push_back(s[index++]);
        if (wordFinder(word, wordDict))
        {
            flag = flag || wordBreak_helper(s, wordDict, size, index, dp);
        }
    }
    return dp[start] = flag;
}
bool wordBreak(string &s, vector<string> &wordDict)
{
    int size = s.length();
    vector<int> dp(s.size() + 1, -1);
    return wordBreak_helper(s, wordDict, size, 0, dp);
}

// TABULATION
bool wordFinder(string &word, vector<string> &wordDict)
{
    for (auto &s : wordDict)
    {
        if (word == s)
            return true;
    }
    return false;
}
bool wordBreak(string &s, vector<string> &wordDict)
{
    int size = s.length();
    vector<bool> dp(s.size() + 1, true);
    for (int start = size - 1; start >= 0; start--)
    {
        int index = start;
        string word = "";
        bool flag = false;
        while (index < size)
        {
            word.push_back(s[index++]);
            if (wordFinder(word, wordDict))
            {
                flag = flag || dp[index];
            }
            if (flag)
                break;
        }
        dp[start] = flag;
    }
    return dp[0];
}
int main()
{
    return 0;
}