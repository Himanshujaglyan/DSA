#include <iostream>
#include <queue>
#include <map>
using namespace std;

// LEETCODE 1962 (REMOVE STONES TO MINIMIZE THE TOTAL)
int minStoneSum(vector<int> &piles, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < piles.size(); i++)
    {
        pq.push(piles[i]);
    }

    while (k--)
    {
        int top = pq.top();
        pq.pop();
        top -= top / 2;
        pq.push(top);
    }

    int ans = 0;
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }

    return ans;
}

// LEETCODE 767 (REORGANIZE STRING)
class Info
{
public:
    char val;
    int count;
};

class compare
{
public:
    bool operator()(Info a, Info b) { return a.count < b.count; }
};
class Solution
{
public:
    string reorganizeString(string s)
    {
        int freq[26] = {0};

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            freq[ch - 'a']++;
        }

        priority_queue<Info, vector<Info>, compare> pq;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                Info temp(i + 'a', freq[i]);
                pq.push(temp);
            }
        }

        string ans = "";
        while (pq.size() > 1)
        {
            Info first = pq.top();
            pq.pop();
            Info second = pq.top();
            pq.pop();
            ans.push_back(first.val);
            ans.push_back(second.val);
            first.count--;
            second.count--;
            if (first.count)
                pq.push(first);
            if (second.count)
                pq.push(second);
        }

        if (pq.size() == 1)
        {
            Info first = pq.top();
            pq.pop();
            ans.push_back(first.val);
            first.count--;

            if (first.count != 0)
                return "";
        }

        return ans;
    }
};

// LAKSHAY CODE
string reorganizeString(string s)
{
    // create freq map
    map<char, int> freqMap;
    for (auto ch : s)
    {
        freqMap[ch]++;
    }

    // make PQ.
    priority_queue<pair<int, char>> pq;
    for (auto it : freqMap)
    {
        pq.push({it.second, it.first});
    }

    // build answer string
    string ans;
    pair<int, char> hidden = {0, 0};
    while (!pq.empty())
    {
        if (ans.size() == 0)
        {
            hidden = pq.top();
            pq.pop();
            ans += hidden.second;
            hidden.first--;
        }
        else
        {
            auto top = pq.top();
            pq.pop();
            ans += top.second;
            top.first--;
            if (hidden.first > 0)
                pq.push(hidden);
            hidden = top;
        }
    }
    if (ans.size() != s.size())
        return "";
    return ans;
}
// LEETCODE 1405 (LONGEST HAPPY STRING)
class Info
{
public:
    char val;
    int count;
    Info(char ch, int num)
    {
        val = ch;
        count = num;
    }
};

class compare
{
public:
    bool operator()(Info a, Info b) { return a.count < b.count; }
};
class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<Info, vector<Info>, compare> pq;

        if (a)
        {
            Info a1('a', a);
            pq.push(a1);
        }
        if (b)
        {
            Info b1('b', b);
            pq.push(b1);
        }
        if (c)
        {
            Info c1('c', c);
            pq.push(c1);
        }

        string ans = "";
        while (pq.size() > 1)
        {
            Info first = pq.top();
            pq.pop();
            Info second = pq.top();
            pq.pop();

            if (first.count >= 2)
            {
                ans.push_back(first.val);
                ans.push_back(first.val);
                first.count -= 2;
            }
            else
            {
                ans.push_back(first.val);
                first.count--;
            }

            if (second.count >= 2 && second.count >= first.count)
            {
                ans.push_back(second.val);
                ans.push_back(second.val);
                second.count -= 2;
            }
            else
            {
                ans.push_back(second.val);
                second.count--;
            }

            if (first.count > 0)
                pq.push(first);
            if (second.count > 0)
                pq.push(second);
        }
        if (pq.size() == 1)
        {
            Info first = pq.top();
            pq.pop();
            if (first.count >= 2)
            {
                ans.push_back(first.val);
                ans.push_back(first.val);
                first.count -= 2;
            }
            else
            {
                ans.push_back(first.val);
                first.count--;
            }
        }
        return ans;
    }
};

// LAKSHAY CODE
string longestDiverseString(int a, int b, int c)
{
    priority_queue<pair<int, int>> pq;

    if (a)
    {
        pq.push({a, 'a'});
    }
    if (b)
    {
        pq.push({b, 'b'});
    }
    if (c)
    {
        pq.push({c, 'c'});
    }

    string ans = "";
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        if (ans.size() == 0 || ans.back() != top.second)
        {
            int times = min(top.first, 2);
            for (int i = 0; i < times; i++)
            {
                ans += top.second;
            }
            top.first -= times;
            if (top.first > 0)
            {
                pq.push(top);
            }
        }
        else if (!pq.empty())
        {
            auto top2 = pq.top();
            pq.pop();
            ans += top2.second;
            top2.first--;
            if (top2.first > 0)
            {
                pq.push(top2);
            }
            pq.push(top);
        }
        else
        {
            break;
        }
    }
    return ans;
}
// LEETCODE 295 (FIND MEDIAN FROM DATA STREAM)
class MedianFinder
{
public:
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double>> minHeap;

    MedianFinder() {}

    void addNum(int num)
    {
        if (maxHeap.empty() && minHeap.empty())
        {
            maxHeap.push(num);
        }
        else
        {
            double median = findMedian();
            if (maxHeap.size() == minHeap.size())
            {
                if (num > median)
                {
                    minHeap.push(num);
                }
                else
                {
                    maxHeap.push(num);
                }
            }
            else if (maxHeap.size() > minHeap.size())
            {
                if (num > median)
                {
                    minHeap.push(num);
                }
                else
                {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(num);
                }
            }
            else
            {
                if (num > median)
                {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(num);
                }
                else
                {
                    maxHeap.push(num);
                }
            }
        }
    }

    double findMedian()
    {
        if (maxHeap.size() == minHeap.size())
        {
            return (maxHeap.top() + minHeap.top()) / double(2);
        }
        else if (maxHeap.size() > minHeap.size())
        {
            return maxHeap.top();
        }
        else
        {
            return minHeap.top();
        }
    }
};

// LAKSHAY CODE
class MedianFinder
{
public:
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double>> minHeap;

    MedianFinder() {}

    void addNum(int num)
    {
        if (maxHeap.empty() || num < maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        if (maxHeap.size() < minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double
    findMedian()
    {
        if (maxHeap.size() == minHeap.size())
        {
            return (maxHeap.top() + minHeap.top()) / double(2);
        }
        return maxHeap.top();
    }
};
int main()
{
    return 0;
}