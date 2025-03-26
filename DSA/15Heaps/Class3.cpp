#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// GFG (MERGE K SORTED ARRAYS)
class Info
{
public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int val, int row, int col)
    {
        this->data = val;
        this->rowIndex = row;
        this->colIndex = col;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Info *, vector<Info *>, compare> pq;
        for (int i = 0; i < K; i++)
        {
            int element = arr[i][0];
            Info *temp = new Info(element, i, 0);
            pq.push(temp);
        }

        vector<int> ans;
        while (!pq.empty())
        {
            Info *temp = pq.top();
            pq.pop();
            int data = temp->data;
            int row = temp->rowIndex;
            int col = temp->colIndex;
            ans.push_back(data);
            if (col + 1 < arr[0].size())
            {
                Info *element = new Info(arr[row][col + 1], row, col + 1);
                pq.push(element);
            }
        }

        return ans;
    }
};

// LEETCODE-23 (MERGE K SORTED LIST)
class compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = 0;
        ListNode *temp = 0;
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
                pq.push(lists[i]);
        }
        while (!pq.empty())
        {
            ListNode *top = pq.top();
            pq.pop();
            if (!head)
                head = top;
            if (!temp)
                temp = top;
            else
            {
                temp->next = top;
                temp = top;
            }
            if (top->next != NULL)
            {
                pq.push(top->next);
            }
        }
        return head;
    }
};

// LEETCODE-632 (SMALLEST RANGE COVERING ELEMENT FROM K-LISTS)
class Info
{
public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int val, int row, int col)
    {
        this->data = val;
        this->rowIndex = row;
        this->colIndex = col;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b) { return a->data > b->data; }
};

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &arr)
    {
        priority_queue<Info *, vector<Info *>, compare> pq;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < arr.size(); i++)
        {
            int element = arr[i][0];
            maxi = max(maxi, element);
            mini = min(mini, element);
            Info *temp = new Info(element, i, 0);
            pq.push(temp);
        }

        int startRange = mini;
        int endRange = maxi;
        int range = endRange - startRange;
        while (!pq.empty())
        {
            Info *temp = pq.top();
            pq.pop();

            int row = temp->rowIndex;
            int col = temp->colIndex;

            if (col + 1 < arr[row].size())
            {
                Info *element = new Info(arr[row][col + 1], row, col + 1);
                pq.push(element);
            }
            else
            {
                break;
            }

            mini = pq.top()->data;
            maxi = max(arr[row][col + 1], maxi);
            int newRange = maxi - mini;

            if (newRange < range)
            {
                startRange = mini;
                endRange = maxi;
                range = newRange;
            }
        }

        vector<int> ans = {startRange, endRange};
        return ans;
    }
};
int main()
{

    return 0;
}