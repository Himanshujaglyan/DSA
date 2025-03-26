#include <iostream>
#include <queue>
using namespace std;

// GFG (First non-repeating character in a stream)
string FirstNonRepeating(string str)
{
    queue<char> q;
    int map[26] = {0};
    string ans = "";
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        map[ch - 'a']++;
        q.push(ch);

        while (!q.empty())
        {
            char ch = q.front();
            if (map[ch - 'a'] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(ch);
                break;
            }
        }

        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

// LEETCODE 134 (GAS STATION)
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int balance = 0;
    int deficit = 0;
    int start = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        balance += gas[i] - cost[i];
        if (balance < 0)
        {
            deficit += abs(balance);
            start = i + 1;
            balance = 0;
        }
    }

    if (balance - deficit >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}

// LEETCODE 239 (SLIDING WINDOW MAXIMUM)
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < k - 1; i++)
    {
        int element = nums[i];
        while (!dq.empty() && (nums[dq.back()] < element))
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = k - 1; i < nums.size(); i++)
    {
        if (!dq.empty() && (i - dq.front() >= k))
        {
            dq.pop_front();
        }
        int element = nums[i];
        while (!dq.empty() && (nums[dq.back()] < element))
        {
            dq.pop_back();
        }
        dq.push_back(i);

        ans.push_back(nums[dq.front()]);
    }

    return ans;
}
int main()
{

    return 0;
}