#include <iostream>
using namespace std;

// VARIABLE SIZE WINDOW KAE CASE MEIN AGR INVALID ANSWER HO TOH WINDOW KAE SIZE KO INCREASE KRTE HEI BY DOING END++ && VALID ANSWER KAE CASE MEIN WINDOW KA SIZE DECREASE KRTE HEI BY DOING START++;

// LEETCODE 209 (MINIMUM SIZE SUBARRAY SUM)
int minSubArrayLen(int target, vector<int> &nums)
{
    int s = 0;
    int e = 0;
    int len = INT_MAX;
    int sum = 0;
    while (e < nums.size())
    {
        sum += nums[e];
        while (sum >= target)
        {
            len = min(len, e - s + 1);
            sum -= nums[s];
            s++;
        }
        e++;
    }
    return len == INT_MAX ? 0 : len;
}
// LEETCODE 1 (TWO SUM)
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < nums.size(); i++)
    {
        v.push_back({nums[i], i});
    }
    sort(v.begin(), v.end());
    int s = 0;
    int e = v.size() - 1;
    while (s < e)
    {
        int sum = v[s].first + v[e].first;
        if (sum == target)
        {
            return {v[s].second, v[e].second};
        }
        else if (sum > target)
        {
            e--;
        }
        else
        {
            s++;
        }
    }
    return {};
}

// LEETCODE 930 (BINARY SUBARRAYS WITH SUM)
int numSubarraysWithSum(vector<int> &nums, int target)
{
    int s = 0;
    int e = 0;
    int count = 0;
    int sum = 0;
    int prefixZero = 0;
    while (e < nums.size())
    {
        sum += nums[e];
        while (s < e && (sum > target || nums[s] == 0))
        {
            if (nums[s] == 1)
            {
                prefixZero = 0;
            }
            else
            {
                prefixZero += 1;
            }
            sum -= nums[s++];
        }
        if (sum == target)
        {
            count += 1 + prefixZero;
        }
        e++;
    }
    return count;
}

// LEETCODE 76 (MINIMUM WINDOW SUBSTRING)
string minWindow(string s, string t)
{
    int count = 0;
    int tMap[256] = {0};
    for (char &ch : t)
    {
        tMap[ch]++;
        count++;
    }
    int st = 0;
    int e = 0;
    pair<int, int> p = {-1, -1};
    string ans = "";
    int sMap[256] = {0};
    while (e < s.length())
    {
        char ch = s[e++];
        if (sMap[ch] < tMap[ch])
        {
            count--;
        }
        sMap[ch]++;
        while (count == 0)
        {
            if (p.first == -1 || (e - st) < p.second - p.first + 1)
            {
                p = {st, e};
            }
            sMap[s[st]]--;
            if (sMap[s[st]] < tMap[s[st]])
            {
                count++;
            }
            st++;
        }
    }
    if (p.first != -1)
        ans = s.substr(p.first, p.second - p.first);
    return ans;
}

// BABBAR CODE
string minWindow(string s, string t)
{
    if (s.length() < t.length())
        return "";

    unordered_map<char, int> sMap;
    unordered_map<char, int> tMap;

    for (char &ch : t)
    {
        tMap[ch]++;
    }

    int ansIndex = -1;
    int ansLength = INT_MAX;
    int start = 0;

    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        sMap[ch]++;
        if (sMap[ch] <= tMap[ch])
        {
            count++;
        }
        if (count == t.length())
        {
            while (sMap[s[start]] > tMap[s[start]])
            {
                sMap[s[start]]--;
                start++;
            }
            int windowLength = i - start + 1;
            if (windowLength < ansLength)
            {
                ansLength = windowLength;
                ansIndex = start;
            }
        }
    }
    if (ansIndex == -1)
        return "";
    return s.substr(ansIndex, ansLength);
}
int main()
{
    return 0;
}