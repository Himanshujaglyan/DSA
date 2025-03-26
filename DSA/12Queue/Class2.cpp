#include <iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> st;

    while (!q.empty())
    {
        int frontElement = q.front();
        q.pop();
        st.push(frontElement);
    }

    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        q.push(top);
    }
}

void recReverseQueue(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int element = q.front();
    q.pop();
    recReverseQueue(q);
    q.push(element);
}

// GFG (REVERSE FIRST K ELEMENTS OF QUEUE)
queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> st;
    for (int i = 0; i < k; i++)
    {
        int temp = q.front();
        q.pop();
        st.push(temp);
    }

    while (!st.empty())
    {
        int temp = st.top();
        st.pop();
        q.push(temp);
    }
    int size = q.size();
    for (int i = 0; i < (size - k); i++)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
    return q;
}
// GFG (Interleave the First Half of the Queue with Second Half)
vector<int> rearrangeQueue(queue<int> &first)
{
    queue<int> second;

    int size = first.size();
    for (int i = 0; i < size / 2; i++)
    {
        int temp = first.front();
        first.pop();
        second.push(temp);
    }

    vector<int> ans;
    for (int i = 0; i < size / 2; i++)
    {
        int temp = second.front();
        second.pop();
        ans.push_back(temp);

        temp = first.front();
        first.pop();
        ans.push_back(temp);
    }

    return ans;
}

// GFG (FIRST NEGATIVE IN EVERY WINDOW OF SIZE K)
vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k)
{
    deque<long long> dq;

    for (int index = 0; index < k - 1; index++)
    {
        if (arr[index] < 0)
        {
            dq.push_back(index);
        }
    }
    vector<long long> ans;
    for (int i = k - 1; i < n; i++)
    {
        if (!dq.empty() && (i - dq.front() >= k))
        {
            dq.pop_front();
        }
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
        if (dq.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans;
}

int main()
{
    {
        queue<int> q;

        q.push(10);
        q.push(20);
        q.push(30);
        q.push(40);
        q.push(50);
        q.push(60);

        // reverseQueue(q);
        // recReverseQueue(q);

        cout << "Printing Queue: ";
        while (!q.empty())
        {
            int element = q.front();
            q.pop();
            cout << element << " ";
        }
    }
    return 0;
}