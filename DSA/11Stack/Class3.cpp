#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>
using namespace std;

// LEETCODE 155 (MIN STACK)
class MinStack // MY CODE
{
public:
    stack<pair<int, int>> st;
    MinStack() {}

    void push(int val)
    {
        pair<int, int> p;
        if (st.empty())
        {
            p.first = p.second = val;
        }
        else
        {
            p.first = val;
            p.second = min(val, st.top().second);
        }
        st.push(p);
    }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

// class MinStack // BABBAR CODE
// {
// public:
//     vector<pair<int, int>> st;
//     MinStack() {}

//     void push(int val)
//     {

//         if (st.empty())
//         {
//             pair<int, int> p = make_pair(val, val);
//             st.push_back(p);
//         }
//         else
//         {
//             pair<int, int> p = make_pair(val, min(val, st.back().second));
//             st.push_back(p);
//         }
//     }

//     void pop()
//     {
//         st.pop_back();
//     }

//     int top()
//     {
//         return st.back().first;
//     }

//     int getMin()
//     {
//         return st.back().second;
//     }
// };

// GFG (HELP CLASSMATES)
vector<int> help_classmate(vector<int> arr, int n) // TIME COMPLEXCITY :- O(N)
{
    vector<int> ans(arr.size(), 0);
    stack<int> st;
    st.push(-1);

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (curr <= st.top()) // here it will perform n push and n pop operations in worst case so complexcity is O(2N) i.e O(N)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}

// GFG (SMALLEST NUMBER ON LEFT)
vector<int> leftSmaller(int n, int a[])
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = a[i];
        while (curr <= st.top())
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}

// LEETCODE 84 (LARGEST RECTANGLE IN HISTOGRAM)
vector<int> nextSmallerElement(vector<int> arr)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(arr.size(), 0);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (st.top() != -1 && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.top() == -1)
            ans[i] = arr.size();

        else
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> arr)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(arr.size(), 0);
    for (int i = 0; i < arr.size(); i++)
    {
        while (st.top() != -1 && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    vector<int> next = nextSmallerElement(heights);
    vector<int> prev = prevSmallerElement(heights);
    int ans = INT_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
        int length = heights[i];
        int width = next[i] - prev[i] - 1;
        int area = length * width;
        ans = max(ans, area);
    }
    return ans;
}

// ANOTHER APPROACH
int largestRectangleArea2(vector<int> &heights)
{
    int ans = INT_MIN;

    for (int i = 0; i < heights.size(); i++)
    {
        int j = i - 1;
        int k = i + 1;
        int a = 1; // Reset 'a' for each histogram bar

        // Move left while the bar is higher
        while (j >= 0 && heights[j] >= heights[i])
        {
            a++;
            j--;
        }

        // Move right while the bar is higher
        while (k < heights.size() && heights[k] >= heights[i])
        {
            a++;
            k++;
        }

        int area = heights[i] * a;
        cout << a << " " << area << endl;
        ans = max(area, ans);
    }

    return ans;
}
int main()
{
    vector<int> arr = {6,2,5,4,5,1,6};
    cout << largestRectangleArea(arr);
    return 0;
}