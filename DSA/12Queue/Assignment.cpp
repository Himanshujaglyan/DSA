#include <bits/stdc++.h>
using namespace std;

// LEETCODE 232 (IMPLEMENT QUEUE USING STACK)
// POP OPERATION IS HEAVY
class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int pop = -1;
        if (!s2.empty())
        {
            pop = s2.top();
            s2.pop();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            pop = s2.top();
            s2.pop();
        }
        return pop;
    }

    // FRONT ELEMENT
    int peek()
    {
        int peek = -1;
        if (!s2.empty())
        {
            peek = s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            peek = s2.top();
        }
        return peek;
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

// PUSH OPERATION IS HEAVY
class MyQueue1
{
public:
    stack<int> s1, s2;
    MyQueue1()
    {
    }

    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int pop = -1;
        if (!s1.empty())
        {
            pop = s1.top();
            s1.pop();
        }
        return pop;
    }

    int peek()
    {
        int peek = -1;
        if (!s1.empty())
        {
            peek = s1.top();
        }
        return peek;
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

// LEETCODE 225 (IMPLEMENT STACK USING QUEUE)
class MyStack
{
public:
    queue<int> q1, q2;
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        if (empty())
            return -1;
        int count = 0;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
            count++;
        }

        while (count != 1)
        {
            q1.push(q2.front());
            q2.pop();
            count--;
        }
        int ans = q2.front();
        q2.pop();
        return ans;
    }

    int top()
    {
        return q1.back();
    }

    bool empty()
    {
        return q1.empty();
    }
};

// LAKSHAY CODE (USING 2 QUEUE)
class MyStack1
{
public:
    queue<int> q1, q2;
    MyStack1()
    {
    }

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        int pop = -1;
        if (!q1.empty())
        {
            pop = q1.front();
            q1.pop();
        }
        return pop;
    }

    int top()
    {
        int top = -1;
        if (!q1.empty())
        {
            top = q1.front();
        }
        return top;
    }

    bool empty()
    {
        return q1.empty();
    }
};

// USING SINGLE QUEUE
class MyStack2
{
public:
    queue<int> q1;
    MyStack2()
    {
    }

    void push(int x)
    {
        q1.push(x);
        int size = q1.size();
        for (int i = 0; i < size - 1; i++)
        {
            int temp = q1.front();
            q1.pop();
            q1.push(temp);
        }
    }

    int pop()
    {
        int pop = -1;
        if (!q1.empty())
        {
            pop = q1.front();
            q1.pop();
        }
        return pop;
    }

    int top()
    {
        int top = -1;
        if (!q1.empty())
        {
            top = q1.front();
        }
        return top;
    }

    bool empty()
    {
        return q1.empty();
    }
};

// K QUEUES IN AN ARRAY
class KQueue
{
public:
    int n, k, freeSpot;
    int *arr, *next, *front, *rear;

    KQueue(int _n, int _k) : n(_n), k(_k), freeSpot(0)
    {
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        for (int i = 0; i < k; i++)
        {
            front[i] = rear[i] = -1;
        }

        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }

    bool push(int x, int qi)
    {
        if (freeSpot == -1)
            return false;

        int index = freeSpot;
        freeSpot = next[index];

        if (front[qi] == -1)
        {
            front[qi] = index;
        }
        else
        {
            next[rear[qi]] = index;
        }

        next[index] = -1;
        rear[qi] = index;
        arr[index] = x;

        return true;
    }

    int pop(int qi)
    {
        if (front[qi] == -1)
        {
            return -1;
        }

        int index = front[qi];
        front[qi] = next[index];

        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    ~KQueue()
    {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};

// GFG (Sum of minimum and maximum elements of all subarrays of size k)
int sumOfMaxMinOfWindowOfSizeK(vector<int> &nums, int k)
{
    int ans = 0;
    deque<int> max, min;

    for (int i = 0; i < k - 1; i++)
    {
        while (!max.empty() && nums[i] > nums[max.back()])
        {
            max.pop_back();
        }
        while (!min.empty() && nums[i] < nums[min.back()])
        {
            min.pop_back();
        }
        max.push_back(i);
        min.push_back(i);
    }

    for (int i = k - 1; i < nums.size(); i++)
    {
        while (!max.empty() && nums[i] > nums[max.back()])
        {
            max.pop_back();
        }
        while (!min.empty() && nums[i] < nums[min.back()])
        {
            min.pop_back();
        }
        max.push_back(i);
        min.push_back(i);
        if (i - max.front() >= k)
        {
            max.pop_front();
        }
        if (i - min.front() >= k)
        {
            min.pop_front();
        }
        ans += abs(nums[max.front()] + nums[min.front()]);
    }

    return ans;
}

// LEETCODE 933 (NUMBER OF RECENT CALLS)
class RecentCounter
{
public:
    queue<int> q;

    RecentCounter() {}

    int ping(int t)
    {
        q.push(t);
        int temp = t - 3000;
        while (!q.empty() && q.front() < temp)
        {
            q.pop();
        }
        return q.size();
    }
};

// LEETCODE 1823 (FIND WINNER OF CIRCULAR GAME)
int findTheWinner(int n, int k)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (q.size() != 1)
    {
        for (int i = 1; i < k; i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        q.pop();
    }

    return q.front();
}

// LEETCODE 950 (REVEAL CARDS IN INCREASING ORDER)
vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    sort(deck.begin(), deck.end());
    queue<int> q;
    vector<int> ans(deck.size());
    // putting indices of ans into q
    for (int i = 0; i < deck.size(); i++)
    {
        q.push(i);
    }
    // reverse simulation + filling using sorted deck
    for (int i = 0; i < deck.size(); i++)
    {
        int index = q.front();
        q.pop();

        ans[index] = deck[i];

        q.push(q.front());
        q.pop();
    }
    return ans;
}

// LEETCODE 2327 (NUMBER OF PEOPLE AWARE OF SECRET)
int peopleAwareOfSecret(int n, int delay, int forget)
{
    const int M = 1e9 + 7;
    queue<pair<int, int>> forgetQ; // start_date, num_of_person
    queue<pair<int, int>> delayQ;
    forgetQ.push({1, 1});
    delayQ.push({1, 1});
    int ans = 1;
    int curr_active_spreader = 0;
    for (int day = 1; day <= n; day++)
    {
        if (!forgetQ.empty() && forgetQ.front().first + forget <= day)
        {
            auto front = forgetQ.front();
            forgetQ.pop();
            curr_active_spreader = (curr_active_spreader - front.second + M) % M;
            ans = (ans - front.second + M) % M;
        }
        if (!delayQ.empty() && delayQ.front().first + delay <= day)
        {
            auto front = delayQ.front();
            delayQ.pop();
            curr_active_spreader = (curr_active_spreader + front.second) % M;
        }
        if (curr_active_spreader > 0)
        {
            ans = (ans + curr_active_spreader) % M;
            forgetQ.push({day, curr_active_spreader});
            delayQ.push({day, curr_active_spreader});
        }
    }
    return ans;
}
int main()
{
    // KQueue kq(8, 3);
    // cout << kq.push(1, 0) << endl;
    // cout << kq.push(2, 0) << endl;
    // cout << kq.push(5, 1) << endl;
    // cout << kq.push(3, 0) << endl;
    // cout << kq.pop(1) << endl;
    // cout << kq.pop(1) << endl;
    // cout << kq.pop(0) << endl;
    // cout << kq.pop(0) << endl;
    // cout << kq.pop(0) << endl;
    // cout << kq.pop(0) << endl;

    vector<int> v = {2, 5, -1, 7, -3, -1, -2};
    int k = 3;
    cout << sumOfMaxMinOfWindowOfSizeK(v, k) << endl;
    return 0;
}