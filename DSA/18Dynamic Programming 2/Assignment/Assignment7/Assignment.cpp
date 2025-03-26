#include <iostream>
using namespace std;

// LEETCODE 140 (WORD BREAK II)
bool wordFinder(string &word, vector<string> &wordDict)
{
    for (auto &s : wordDict)
    {
        if (word == s)
            return true;
    }
    return false;
}

bool wordBreak_helper(string &s, vector<string> &wordDict, int &size, int start, vector<string> &ans, string sentence)
{
    if (start >= size)
    {
        sentence.pop_back();
        ans.push_back(sentence);
        return true;
    }
    int index = start;
    string word = "";
    bool flag = false;
    while (index < size)
    {
        word.push_back(s[index++]);
        if (wordFinder(word, wordDict))
        {
            string temp = sentence + word;
            temp.push_back(' ');
            bool check = wordBreak_helper(s, wordDict, size, index, ans, temp);
            flag = flag || check;
        }
    }
    return flag;
}
vector<string> wordBreak(string s, vector<string> &wordDict)
{
    vector<string> ans;
    int size = s.length();
    wordBreak_helper(s, wordDict, size, 0, ans, "");
    return ans;
}

// LAKSHAY CODE (RECURSION + MEMOIZATION)
vector<string> wordBreak_helper(string &s, unordered_map<string, bool> &dict, int start, unordered_map<int, vector<string>> &dp)
{
    if (start >= s.length())
        return {""};
    if (dp.find(start) != dp.end())
        return dp[start];
    vector<string> ans;
    string word = "";
    for (int i = start; i < s.length(); i++)
    {
        word.push_back(s[i]);
        if (dict.find(word) == dict.end())
            continue;
        auto right = wordBreak_helper(s, dict, i + 1, dp);
        for (auto &rightSentence : right)
        {
            if (rightSentence != "")
            {
                ans.push_back(word + " " + rightSentence);
            }
            else
            {
                ans.push_back(word);
            }
        }
    }
    return dp[start] = ans;
}
vector<string> wordBreak(string s, vector<string> &wordDict)
{
    unordered_map<string, bool> dict;
    for (auto &word : wordDict)
    {
        dict[word] = 1;
    }
    unordered_map<int, vector<string>> dp;
    return wordBreak_helper(s, dict, 0, dp);
}
int main()
{
    return 0;
}