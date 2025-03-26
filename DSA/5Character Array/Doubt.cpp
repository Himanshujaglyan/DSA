#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
using namespace std;

int majorityElement(vector<int> v)
{
    sort(v.begin(), v.end());
    return v[(0 + v.size() - 1) / 2];
}

int majorityElement1(vector<int> v)
{
    map<int, int> mp;
    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second > (v.size() / 2))
        {
            return it.first;
        }
    }
    return -1;
}
int majorityElement2(vector<int> &nums)
{
    int count = 0;
    int element = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            element = nums[i];
            count++;
        }
        else if (element == nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return element;
}

string removeOccurence(string s, string part)
{
    while (s.find(part) != string::npos)
    {
        int index = s.find(part);
        string LP = s.substr(0, index);
        string RP = s.substr(index + part.length(), s.length());
        s = LP + RP;
    }
    return s;
}

int main()
{
    // vector<int> v{2, 2, 1, 1, 1, 2, 2};
    // cout << majorityElement(v) << endl;

    vector<int> v{1, 1, 1, 1, 2, 2, 3, 4, 5};
    auto l = lower_bound(v.begin(), v.end(), 1);
    auto u = upper_bound(v.begin(), v.end(), 1); // it return the next address to the last occurence
    cout << *l << endl;
    cout << *u << endl;
    cout << l - v.begin() << endl;
    cout << u - v.begin() << endl;

    string s = "daabcbaabcbc";
    string part = "abc";
    cout << removeOccurence(s, part) << endl;
    return 0;
}