#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// GFG (IS BINARY TREE HEAP)
int nodeCount(struct Node *root)
{
    if (!root)
        return 0;
    int l = nodeCount(root->left);
    int r = nodeCount(root->right);
    return 1 + l + r;
}

bool isCBT(struct Node *root, int &n, int i)
{
    if (!root)
        return true;
    if (i > n)
        return false;
    return isCBT(root->left, n, 2 * i) && isCBT(root->right, n, 2 * i + 1);
}

bool isMaxOrder(struct Node *root)
{
    if (!root)
        return true;
    bool left = isMaxOrder(root->left);
    bool right = isMaxOrder(root->right);
    bool ans = false;
    if (root->left == NULL && root->right == NULL)
    {
        ans = true;
    }
    else if (root->left != NULL && root->right == NULL)
    {
        ans = root->data > root->left->data;
    }
    else
    {
        ans = root->data > root->left->data && root->data > root->right->data;
    }
    return left && right && ans;
}
bool isHeap(struct Node *root)
{
    int n = nodeCount(root);
    int i = 1;
    return isCBT(root, n, i) && isMaxOrder(root);
}

// GFG (MERGE TWO BINARY MAX HEAPS)
void heapify(vector<int> &v, int index, int size)
{
    while (true)
    {
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        int swapIndex = index;
        if (leftIndex < size && v[swapIndex] < v[leftIndex])
        {
            swapIndex = leftIndex;
        }
        if (rightIndex < size && v[swapIndex] < v[rightIndex])
        {
            swapIndex = rightIndex;
        }

        if (swapIndex == index)
        {
            break;
        }
        else
        {
            swap(v[index], v[swapIndex]);
            index = swapIndex;
        }
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> c(a.begin(), a.end());
    c.insert(c.end(), b.begin(), b.end());
    for (int i = (c.size() / 2); i >= 0; i--)
    {
        heapify(c, i, c.size());
    }
    return c;
}
// LEETCODE 973 (K CLOSEST POINT TO ORIGIN)
class Info
{
public:
    int x;
    int y;
    int distance;
    Info(int _x, int _y)
    {
        x = _x;
        y = _y;
        distance = (x * x) + (y * y);
    }
};
class compare
{
public:
    bool operator()(Info a, Info b)
    {
        return a.distance > b.distance;
    }
};
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<Info, vector<Info>, compare> pq;
        for (int i = 0; i < points.size(); i++)
        {
            int xCor = points[i][0];
            int yCor = points[i][1];
            Info temp(xCor, yCor);
            pq.push(temp);
        }
        vector<vector<int>> ans;
        while (k--)
        {
            vector<int> temp;
            Info top = pq.top();
            pq.pop();
            temp.push_back(top.x);
            temp.push_back(top.y);
            ans.push_back(temp);
        }
        return ans;
    }
};
// LAKSHAY CODE
class compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        int disA = a.first * a.first + a.second * a.second;
        int disB = b.first * b.first + b.second * b.second;
        return disA > disB;
    }
};

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    vector<vector<int>> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

    for (auto p : points)
    {
        pq.push({p[0], p[1]});
    }

    while (k--)
    {
        auto top = pq.top();
        ans.push_back({top.first, top.second});
        pq.pop();
    }

    return ans;
}

// LEETCODE 1878 (GET BIGGEST THREE RHOMBUS SUMS IN A GRID)
bool checkBounds(vector<vector<int>> &grid, vector<pair<int, int>> &v)
{
    int m = grid.size();
    int n = grid[0].size();
    for (auto p : v)
    {
        if (p.first < 0 || p.first >= m || p.second < 0 || p.second >= n)
        {
            return false;
        }
    }
    return true;
}

bool getAllVertices(vector<vector<int>> &grid, vector<pair<int, int>> &v, int &cx, int &cy, int &delta)
{
    pair<int, int> A{cx - delta, cy};
    pair<int, int> B{cx, cy + delta};
    pair<int, int> C{cx + delta, cy};
    pair<int, int> D{cx, cy - delta};
    v[0] = A;
    v[1] = B;
    v[2] = C;
    v[3] = D;
    return (checkBounds(grid, v));
}
void getAllSum(vector<vector<int>> &grid, int &cx, int &cy, priority_queue<int> &pq)
{
    pq.push(grid[cx][cy]);
    vector<pair<int, int>> v(4);
    int delta = 1;
    while (getAllVertices(grid, v, cx, cy, delta))
    {
        pair<int, int> A = v[0];
        pair<int, int> B = v[1];
        pair<int, int> C = v[2];
        pair<int, int> D = v[3];

        int csum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];
        // AB
        for (int i = 1; i < (B.first - A.first); i++)
        {
            csum += grid[A.first + i][A.second + i];
        }
        // BC
        for (int i = 1; i < (C.first - B.first); i++)
        {
            csum += grid[B.first + i][B.second - i];
        }
        // CD
        for (int i = 1; i < (C.first - D.first); i++)
        {
            csum += grid[C.first - i][C.second - i];
        }
        // DA
        for (int i = 1; i < (D.first - A.first); i++)
        {
            csum += grid[D.first - i][D.second + i];
        }

        pq.push(csum);
        delta++;
    }
}

bool canPush(vector<int> &v, int &sum)
{
    for (auto i : v)
    {
        if (i == sum)
        {
            return false;
        }
    }
    return true;
}
vector<int> getBiggestThree(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    priority_queue<int> pq;
    vector<int> ans;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            getAllSum(grid, i, j, pq);
        }
    }

    while (!pq.empty() && ans.size() < 3)
    {
        int sum = pq.top();
        pq.pop();
        if (canPush(ans, sum))
        {
            ans.push_back(sum);
        }
    }
    return ans;
}

// LEETCODE 2163 (MINIMUM DIFFERENCE IN SUMS AFTER REMOVAL OF ELEMENTS)
class Solution
{
public:
#define ll long long
    long long minimumDifference(vector<int> &nums)
    {
        int n = nums.size() / 3;
        vector<ll> prefix(nums.size(), -1), suffix(nums.size(), -1);

        ll sum = 0;
        priority_queue<ll> maxi;
        for (int i = 0; i < nums.size(); i++)
        {
            maxi.push(nums[i]);
            sum += nums[i];

            if (maxi.size() > n)
            {
                sum -= maxi.top();
                maxi.pop();
            }

            if (maxi.size() == n)
            {
                prefix[i] = sum;
            }
        }

        sum = 0;
        priority_queue<ll, vector<ll>, greater<ll>> mini;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            mini.push(nums[i]);
            sum += nums[i];

            if (mini.size() > n)
            {
                sum -= mini.top();
                mini.pop();
            }

            if (mini.size() == n)
            {
                suffix[i] = sum;
            }
        }

        ll ans = LONG_LONG_MAX;
        for (int i = n - 1; i < 2 * n; i++)
        {
            ans = min(ans, prefix[i] - suffix[i + 1]);
        }
        return ans;
    }
};

// LEETCODE 871 (MINIMUM NUMBER OF REFUELING STOPS)
int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
{

    int stops = 0;
    priority_queue<int> pq;
    int currFuel = startFuel;
    int currPosition = 0;
    for (int i = 0; i < stations.size(); i++)
    {
        int position = stations[i][0];
        int fuel = stations[i][1];
        currFuel -= position - currPosition;
        if (currFuel < 0)
        {
            if (!pq.empty())
            {
                while (currFuel < 0)
                {
                    if (pq.empty())
                        return -1;
                    int top = pq.top();
                    currFuel += top;
                    pq.pop();
                    stops++;
                }
            }
            else
            {
                return -1;
            }
        }
        pq.push(fuel);
        currPosition = position;
    }

    currFuel -= target - currPosition;
    if (currFuel < 0)
    {
        if (!pq.empty())
        {
            while (currFuel < 0)
            {
                if (pq.empty())
                    return -1;
                int top = pq.top();
                currFuel += top;
                pq.pop();
                stops++;
            }
        }
        else
        {
            return -1;
        }
    }
    return stops;
}

// LAKSHAY CODE
int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
{
    int stops = 0;
    int dis = 0;
    int fuel = startFuel;
    int i = 0;
    priority_queue<pair<int, int>> pq;
    while (true)
    {
        while (i < stations.size() && stations[i][0] <= dis + fuel)
        {
            if (i < stations.size())
            {
                pq.push({stations[i][1], stations[i][0]});
            }
            else
            {
                break;
            }
            i++;
        }

        dis += fuel;
        fuel = 0;

        cout << dis << endl;
        if (dis >= target)
            break;

        if (pq.empty())
            return -1;

        auto &top = pq.top();
        fuel = (dis - top.second) + top.first;
        dis = top.second;
        pq.pop();
        stops++;
    }

    return stops;
}

// LEETCODE 239 (SLIDING WINDOW MAXIMUM)// TIME COMPLEXCITY :- O(NlogN) // SPACE COMPLEXCITY :- O(N)
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k - 1; i++)
    {
        pq.push({nums[i], i});
    }
    vector<int> ans;
    for (int i = k - 1; i < nums.size(); i++)
    {
        cout << i << endl;
        pq.push({nums[i], i});
        while (pq.top().second <= i - k)
        {
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    return ans;
}
int main()
{

    return 0;
}