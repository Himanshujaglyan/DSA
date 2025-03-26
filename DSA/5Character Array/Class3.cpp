#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

string decodeMessage(string key, string message)
{
    char start = 'a';
    char mapping[300] = {0};
    for (auto ch : key)
    {
        if (mapping[ch] == 0 && ch != ' ')
        {
            mapping[ch] = start;
            start++;
        }
    }
    string answer;
    for (auto i : message)
    {
        if (i == ' ')
        {
            answer.push_back(' ');
        }
        else
        {
            answer.push_back(mapping[i]);
        }
    }
    return answer;
}
int gargbageCollection(vector<string> garbage, vector<int> travel)
{ // leetcode 2391
    int pickP = 0;
    int pickG = 0;
    int pickM = 0;

    int travelP = 0;
    int travelG = 0;
    int travelM = 0;

    int lastP = 0;
    int lastG = 0;
    int lastM = 0;

    for (int i = 0; i < garbage.size(); i++)
    {
        string current = garbage[i];
        for (int j = 0; j < current.length(); j++)
        {
            char ch = current[j];
            if (ch == 'P')
            {
                pickP++;
                lastP = i;
            }
            else if (ch == 'M')
            {
                pickM++;
                lastM = i;
            }
            else if (ch == 'G')
            {
                pickG++;
                lastG = i;
            }
        }
    }
    for (int i = 0; i < lastP; i++)
    {
        travelP += travel[i];
    }
    for (int i = 0; i < lastM; i++)
    {
        travelM += travel[i];
    }
    for (int i = 0; i < lastG; i++)
    {
        travelG += travel[i];
    }

    int totalTime = (pickP + travelP) + (pickM + travelM) + (pickG + travelG);
    return totalTime;
}
// LEETCODE 791 (CUSTOM SORT STRING)
class Solution
{
public:
    static string o;

    static bool myComp(char &a, char &b)
    {
        return o.find(a) < o.find(b);
    }

    string customSortString(string order, string s)
    {
        o = order;
        sort(s.begin(), s.end(), myComp);
        return s;
    }
};
string Solution ::o;

void createMapping(string &s)
{
    char start = 'a';
    char mapping[300] = {0};
    for (auto ch : s)
    {
        if (mapping[ch] == 0)
        {
            mapping[ch] = start;
            start++;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        s[i] = mapping[ch];
    }
}

vector<string> findAndReplacePattern(vector<string> str, string pattern)
{
    vector<string> ans;
    createMapping(pattern);
    for (string s : str)
    {
        string temp = s;
        createMapping(temp);
        if (temp == pattern)
        {
            ans.push_back(s);
        }
    }
    return ans;
}
int main()
{

    // string str = "Om Jindal";
    // for (auto ch : str)
    // {
    //     cout << ch << " ";
    // }
    // cout << endl;
    // vector<int> v{1, 2, 3};
    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // string str = "the quick brown fox jumps over the lazy dog";
    // string str1 = "vkbs bs t suepuv";
    // cout << decodeMessage(str, str1) << endl;

    // vector<string> garbage;
    // string str = "G";
    // string str1 = "P";
    // string str2 = "PG";
    // string str3 = "GG";
    // garbage.push_back(str);
    // garbage.push_back(str1);
    // garbage.push_back(str2);
    // garbage.push_back(str3);

    // vector<int> travel{2, 4, 3};
    // cout << gargbageCollection(garbage, travel) << endl;

    // string data = "abcd";
    // string order = "cba";
    // data = customSortString(data, order);
    // cout << data << endl;

    // vector<string> str{"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    // string pattern = "abb";
    // str = findAndReplacePattern(str, pattern);
    // for (int i = 0; i < str.size(); i++)
    // {
    //     cout << str[i] << " ";
    // }
    return 0;
}