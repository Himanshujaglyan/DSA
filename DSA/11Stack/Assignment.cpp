#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// GFG (COUNT THE REVERSALS)
int countRev(string s)
{
    int length = s.length();
    if (length & 1)
    {
        return -1;
    }
    stack<char> st;
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        char ch = s[i];
        if (ch == '{')
        {

            st.push('{');
        }
        else
        {
            if (st.empty())
            {
                count++;
                st.push('{');
            }
            else
            {
                st.pop();
            }
        }
    }
    count += st.size() / 2;
    return count;
}

// LAKSHAY CODE
int countRev1(string s)
{
    if (s.length() & 1)
        return -1;

    stack<char> st;
    int count = 0;
    for (auto ch : s)
    {
        if (ch == '{')
            st.push('{');
        else
        {
            if (st.empty() == 0 && st.top() == '{')

                st.pop();

            else

                st.push(ch);
        }
    }
    while (!st.empty())
    {
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();

        if (a == b)
            count += 1;
        else
            count += 2;
    }

    return count;
}

// LEETCODE 1047 (REMOVE ALL ADJACENT DUPLICATES IN STRING)
string removeDuplicates(string s)
{
    stack<char> st;
    for (char ch : s)
    {
        if (st.empty() || ch != st.top())
        {
            st.push(ch);
        }
        else
        {
            st.pop();
        }
    }
    stack<char> st2;
    while (!st.empty())
    {
        st2.push(st.top());
        st.pop();
    }
    string ans = "";
    while (!st2.empty())
    {
        ans.push_back(st2.top());
        st2.pop();
    }
    return ans;
}

// GFG (THE CELEBRITY PROBLEM)

// WITHOUT STACK
int celebrity(vector<vector<int>> &mat)
{
    for (int i = 0; i < mat[0].size(); i++)
    {
        int j = 0;
        for (j; j < mat.size(); j++)
        {
            if (mat[j][i] == 0 && i != j)
            {
                break;
            }
        }
        if (j == mat.size())
        {
            int k = 0;
            for (k; k < mat[0].size(); k++)
            {
                if (mat[i][k] == 1)
                    break;
            }
            if (k == mat[0].size())
                return i;
        }
    }
    return -1;
}

// LAKSHAY CODE
int celebrity1(vector<vector<int>> &mat)
{
    stack<int> st;

    // push all persons onto the stack
    for (int i = 0; i < mat.size(); i++)
    {
        st.push(i);
    }

    // running discard method, to get mightBeCelebrity
    while (st.size() != 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        // if a knows b
        if (mat[a][b])
        {
            st.push(b); // a is not a celebrity b might be
        }
        else
        {
            st.push(a); // b is not a celebrity a might be
        }
    }

    int mightBeCelebrity = st.top();
    st.pop();

    // celebrity should not know anyone
    for (int i = 0; i < mat.size(); i++)
    {
        if (mat[mightBeCelebrity][i] != 0)
            return -1;
    }

    // everyone should know celebrity
    for (int i = 0; i < mat.size(); i++)
    {
        if (mat[i][mightBeCelebrity] == 0 && i != mightBeCelebrity)
            return -1;
    }

    return mightBeCelebrity;
}

// LEETCODE 1019 (NEXT GREATER NODE IN A LINKED LIST)
void solve(ListNode *head, stack<int> &st, vector<int> &ans)
{
    if (head == 0)
        return;
    solve(head->next, st, ans);
    while (!st.empty() && head->val >= st.top())
        st.pop();
    if (st.empty())
    {
        st.push(0);
    }
    ans.push_back(st.top());
    st.push(head->val);
}

vector<int> nextLargerNodes(ListNode *head)
{
    stack<int> st;
    st.push(0);
    vector<int> ans;
    solve(head, st, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}

// LAKSHAY CODE
vector<int> nextLargerNodes2(ListNode *head)
{
    vector<int> ll;
    ListNode *it = head;
    while (it)
    {
        ll.push_back(it->val);
        it = it->next;
    }
    stack<int> st;
    for (int i = 0; i < ll.size(); i++)
    {
        while (!st.empty() && ll[i] > ll[st.top()])
        {
            int kids = st.top();
            st.pop();
            ll[kids] = ll[i];
        }
        st.push(i);
    }
    while (!st.empty())
    {
        ll[st.top()] = 0;
        st.pop();
    }
    return ll;
}

// ANOTHER APPROACH (USING PAIR)
vector<int> nextLargerNodes1(ListNode *head)
{
    stack<pair<int, int>> st;
    vector<int> ans;
    int i = 0;
    while (head)
    {
        ans.push_back(0);
        while (!st.empty() && st.top().second < head->val)
        {
            int top = st.top().first;
            st.pop();
            ans[top] = head->val;
        }
        st.push({i++, head->val});
        head = head->next;
    }

    return ans;
}

// N-STACKS IN AN ARRAY
class NStack
{
    int *arr, *top, *next;
    int n, size, freeSpot;

public:
    NStack(int _n, int _s) : n(_n), size(_s), freeSpot(0)
    {
        arr = new int[size];
        top = new int[n];
        next = new int[size];

        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;
    }
    bool push(int X, int m)
    {
        if (freeSpot == -1)
            return false;

        // 1. Find Index
        int index = freeSpot;

        // 2. Update FreeSpot
        freeSpot = next[index];

        // 3. Insert the element
        arr[index] = X;

        // 4. Update next Pointer
        next[index] = top[m - 1];

        // 5. Update top pointer
        top[m - 1] = index;

        return true;
    }

    int pop(int m)
    {
        if (top[m - 1] == -1)
            return -1;

        int index = top[m - 1];

        top[m - 1] = next[index];

        next[index] = freeSpot;

        freeSpot = index;

        return arr[index];
    }

    ~NStack()
    {
        delete[] arr;
        delete[] next;
        delete[] top;
    }
};

// LEETCODE-901 -> ONLINE STOCK SPAN (MONOTONIC STACK)
class StockSpanner
{
public:
    stack<pair<int, int>> st; // {price,span}
    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1;
        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};
// LEETCODE-1003 (CHECK IF WORD IS VALID AFTER SUBSTITUTIONS)
bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == 'a' || ch == 'b')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty() && st.top() == 'b')
            {
                st.pop();
            }
            else
            {
                return false;
            }
            if (!st.empty() && st.top() == 'a')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (st.empty())
        return true;
    return false;
}

// LAKSHAY CODE (USING RECURSION WITH FIND FUNCTION)
bool isValid(string s)
{
    if (s.size() == 0)
        return true;
    int index = s.find("abc");
    if (index == string::npos)
    {
        return false;
    }
    else
    {
        string l = s.substr(0, index);
        string r = s.substr(index + 3, s.size());
        return isValid(l + r);
    }
}

// ANOTHER APPROACH
bool isValid(string s)
{
    if (s[0] != 'a')
        return false;

    stack<int> st;

    for (auto ch : s)
    {
        if (ch == 'a')
        {
            st.push(ch);
        }
        else if (ch == 'b')
        {
            if (!st.empty() && st.top() == 'a')
            {
                st.pop();
                st.push(ch);
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (!st.empty() && st.top() == 'b')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return st.empty();
}

// LEETCODE-394 (DECODE STRING)
string decodeString(string s)
{
    stack<string> st;
    for (auto ch : s)
    {
        if (ch == ']')
        {
            string strToRepeat = "";
            while (!st.empty() && st.top() != "[")
            {
                strToRepeat += st.top();
                st.pop();
            }
            st.pop();
            string numericTimes = "";
            while (!st.empty() && isdigit(st.top()[0]))
            {
                numericTimes = st.top() + numericTimes;
                st.pop();
            }
            int n = stoi(numericTimes);

            string decode = "";
            while (n--)
            {
                decode += strToRepeat;
            }
            st.push(decode);
        }
        else
        {
            string temp(1, ch);
            st.push(temp);
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// LEETCODE-71 (Simplify Path)
string simplifyPath(string path)
{
    stack<string> st;
    int i = 0;
    while (i < path.length())
    {
        int start = i;
        int end = i + 1;
        while (end < path.length() && path[end] != '/')
        {
            end++;
        }
        i = end;
        string minPath = path.substr(start, end - start);
        if (minPath == "/." || minPath == "/")
        {
            continue;
        }
        if (minPath == "/..")
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            st.push(minPath);
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }
    if (ans == "")
        return "/";
    return ans;
}

// LEETCODE-85 (MAXIMUM RECTANGLE)
vector<int> minLeft(vector<int> heights)
{
    vector<int> minL(heights.size());
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < heights.size(); i++)
    {
        while (st.top() != -1 && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        minL[i] = st.top();
        st.push(i);
    }
    return minL;
}
vector<int> minRight(vector<int> heights)
{
    vector<int> minR(heights.size());
    stack<int> st;
    st.push(-1);
    for (int i = heights.size() - 1; i >= 0; i--)
    {
        while (st.top() != -1 && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        minR[i] = st.top();
        st.push(i);
    }
    for (int i = 0; i < heights.size(); i++)
    {
        if (minR[i] == -1)
            minR[i] = heights.size();
    }
    return minR;
}

int largestRectangleArea(vector<int> heights)
{
    vector<int> l = minLeft(heights);
    vector<int> r = minRight(heights);
    int ans = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int width = r[i] - l[i] - 1;
        int height = heights[i];
        int area = width * height;
        ans = max(ans, area);
    }
    return ans;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    vector<vector<int>> v;
    for (int i = 0; i < matrix.size(); i++)
    {
        vector<int> t;
        for (int j = 0; j < matrix[i].size(); j++)
        {
            t.push_back(matrix[i][j] - '0');
        }
        v.push_back(t);
    }

    int area = largestRectangleArea(v[0]);
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (v[i][j])
            {
                v[i][j] += v[i - 1][j];
            }
            else
            {
                v[i][j] = 0;
            }
        }
        area = max(area, largestRectangleArea(v[i]));
    }
    return area;
}

// LEETCODE 735 (ASTEROID COLLISION)
vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;
    for (int i = 0; i < asteroids.size(); i++)
    {
        if (!st.empty())
            cout << st.top() << " ";
        int asteroid = asteroids[i];
        if (asteroid >= 0)
        {
            st.push(asteroid);
        }
        else
        {
            if (st.empty() || st.top() < 0)
            {
                st.push(asteroid);
            }
            else
            {
                while (!st.empty() && st.top() > 0 && st.top() + asteroid < 0)
                {
                    st.pop();
                }
                if (!st.empty() && st.top() + asteroid == 0)
                {
                    st.pop();
                }
                else if (st.empty() || st.top() < 0)
                {
                    st.push(asteroid);
                }
            }
        }
        if (!st.empty())
            cout << st.top() << endl;
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// LAKSHAY CODE
vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;
    for (int i = 0; i < asteroids.size(); i++)
    {
        bool des = false;
        int asteroid = asteroids[i];
        if (asteroid >= 0)
        {
            st.push(asteroid);
        }
        else
        {
            if (st.empty() || st.top() < 0)
            {
                st.push(asteroid);
            }
            else
            {
                while (!st.empty() && st.top() > 0)
                {
                    if (abs(asteroid) == st.top())
                    {
                        des = true;
                        st.pop();
                        break;
                    }
                    else if (abs(asteroid) > st.top())
                    {
                        st.pop();
                    }
                    else
                    {
                        des = true;
                        break;
                    }
                }
                if (!des)
                    st.push(asteroid);
            }
        }
    }
    int size = st.size();
    vector<int> ans(size);
    for (int i = size - 1; i >= 0; i--)
    {
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}

// LEETCODE 853 (CAR FLEET)
class Solution
{
    class Car
    {
    public:
        int position;
        int speed;
        Car(int _position, int _speed) : position(_position), speed(_speed) {}
    };
    static bool customComparator(Car &a, Car &b)
    {
        return a.position < b.position;
    }

public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<Car> cars;
        for (int i = 0; i < position.size(); i++)
        {
            Car car(position[i], speed[i]);
            cars.push_back(car);
        }
        sort(cars.begin(), cars.end(), customComparator);

        stack<float> st;
        for (auto car : cars)
        {
            float time = (target - car.position) / (float)car.speed;
            while (!st.empty() && st.top() <= time)
            {
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};

// LEETCODE 1776 (CAR FLEET II)
vector<double> getCollisionTimes(vector<vector<int>> &cars)
{
    stack<int> st;
    vector<double> ans(cars.size(), -1);
    st.push(cars.size() - 1);
    for (int i = cars.size() - 2; i >= 0; i--)
    {
        while (!st.empty() && cars[i][1] <= cars[st.top()][1])
        {
            st.pop();
        }
        while (!st.empty())
        {
            double time = double(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);
            if (ans[st.top()] == -1 || time <= ans[st.top()])
            {
                ans[i] = time;
                break;
            }
            else
            {
                st.pop();
            }
        }
        st.push(i);
    }
    return ans;
}

// LEETCODE 32 (VALID PARETHESIS)
int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                int len = i - st.top();
                ans = max(ans, len);
            }
        }
    }
    return ans;
}

// LEETCODE 739 (DAILY TEMPERATURE)
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> st;
    int size = temperatures.size();
    vector<int> ans(size, 0);
    for (int i = size - 1; i >= 0; i--)
    {
        while (!st.empty() && temperatures[st.top()] <= temperatures[i])
        {
            st.pop();
        }
        if (!st.empty() && temperatures[st.top()] > temperatures[i])
        {
            ans[i] = st.top() - i;
        }
        st.push(i);
    }
    return ans;
}

// LAKSHAY CODE
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> st;
    int size = temperatures.size();
    vector<int> ans;
    for (int i = 0; i < size; i++)
    {
        ans.push_back(0);
        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            ans[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

// LEETCODE 402 (REMOVE K DIGITS)
string removeKdigits(string num, int k)
{
    stack<char> st;
    for (int i = 0; i < num.length(); i++)
    {
        while (!st.empty() && k != 0 && st.top() > num[i])
        {
            k--;
            st.pop();
        }
        st.push(num[i]);
    }
    while (k--)
    {
        st.pop();
    }
    string ans = "";
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    while (ans.size() && ans.back() == '0')
    {
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    if (ans == "")
        return "0";
    return ans;
}

// LEETCODE 921 (MINIMUM ADD TO MAKE VALID PARENTHESIS)
int minAddToMakeValid(string s)
{
    int count = 0;
    stack<int> st;
    for (auto ch : s)
    {
        if (ch == '(')
        {
            count++;
            st.push(ch);
        }
        else
        {
            if (st.empty())
            {
                count++;
            }
            else
            {
                count--;
                st.pop();
            }
        }
    }
    return count;
}

// LEETCODE 1472 (DESIGN BROWSER HISTORY)
class BrowserHistory
{
public:
    vector<string> v;
    int index = 0;
    int steps = 0;
    BrowserHistory(string homepage)
    {
        v.push_back(homepage);
    }

    void visit(string url)
    {
        if (index == steps)
        {
            v.push_back(url);
            index++;
            steps++;
        }
        else
        {
            while (steps != index)
            {
                v.pop_back();
                steps--;
            }
            v.push_back(url);
            steps++;
            index++;
        }
    }

    string back(int step)
    {
        if (step <= index)
        {
            index -= step;
        }
        else
        {
            index = 0;
        }
        return v[index];
    }

    string forward(int step)
    {
        if (index + step <= steps)
        {
            index += step;
        }
        else
        {
            index = steps;
        }
        return v[index];
    }
};

// LAKSHAY CODE
class BrowserHistory
{
public:
    stack<string> browserStack, fwdStack;
    BrowserHistory(string homepage)
    {
        browserStack.push(homepage);
    }

    void visit(string url)
    {
        while (!fwdStack.empty())
        {
            fwdStack.pop();
        }
        browserStack.push(url);
    }

    string back(int steps)
    {
        while (steps != 0 && browserStack.size() > 1)
        {
            fwdStack.push(browserStack.top());
            browserStack.pop();
            steps--;
        }
        return browserStack.top();
    }

    string forward(int steps)
    {
        while (steps != 0 && fwdStack.size() != 0)
        {
            browserStack.push(fwdStack.top());
            fwdStack.pop();
            steps--;
        }
        return browserStack.top();
    }
};
int main()
{
    NStack s(3, 6);
    cout << s.push(10, 1) << endl;
    cout << s.push(20, 1) << endl;
    cout << s.push(30, 1) << endl;
    cout << s.push(15, 2) << endl;
    cout << s.push(14, 3) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(2) << endl;
    return 0;
}