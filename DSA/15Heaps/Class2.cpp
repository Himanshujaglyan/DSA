#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

// GFG (KTH SMALLEST ELEMENT IN AN ARRAY)
int kthSmallest(vector<int> &arr, int k)
{
    // code here
    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < arr.size(); i++)
    {
        if (pq.top() > arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

// LEETCODE 215 (KTH LARGEST ELEMENT IN AN ARRAY)
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]);
    }

    for (int i = k; i < nums.size(); i++)
    {
        if (pq.top() < nums[i])
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }

    return pq.top();
}

// LEETCODE 958 (CHECK COMPLETENESS OF A BINARY TREE)
void countNodes(TreeNode *root, int &count)
{
    if (!root)
        return;
    count++;
    countNodes(root->left, count);
    countNodes(root->right, count);
}

void levelOrderTraversal(TreeNode *root, int &count)
{
    if (!root)
        return;
    count++;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();
        if (front->left)
        {
            count++;
            q.push(front->left);
        }
        else
            break;
        if (front->right)
        {
            count++;
            q.push(front->right);
        }
        else
            break;
    }
}
bool isCompleteTree(TreeNode *root)
{
    int TotalNodes = 0;
    countNodes(root, TotalNodes);
    int lastNode = 0;
    levelOrderTraversal(root, lastNode);
    return lastNode == TotalNodes;
}

// ANOTHER APPROACH
bool levelOrderTraversal(TreeNode *root, bool &flag)
{
    if (!root)
        return true;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();
        if (front->left)
        {
            if (flag)
                return false;
            q.push(front->left);
        }
        else
            flag = true;
        if (front->right)
        {
            if (flag)
                return false;
            q.push(front->right);
        }
        else
            flag = true;
    }
    return true;
}
bool isCompleteTree(TreeNode *root)
{
    bool flag = false;
    return levelOrderTraversal(root, flag);
}

// GFG (IS BINARY TREE HEAP)
bool levelOrderTraversal(Node *root)
{
    if (!root)
        return true;
    queue<Node *> q;
    q.push(root);
    bool flag = false;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front->left)
        {
            if (flag)
                return false;
            q.push(front->left);
        }
        else
            flag = true;
        if (front->right)
        {
            if (flag)
                return false;
            q.push(front->right);
        }
        else
            flag = true;
    }
    return true;
}

pair<bool, int> solve(Node *root)
{
    if (!root)
    {
        return {true, INT_MIN};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {true, root->data};
    }

    auto leftAns = solve(root->left);
    auto rightAns = solve(root->right);

    if (leftAns.first && rightAns.first && root->data > leftAns.second && root->data > rightAns.second)
    {
        return {true, root->data};
    }
    else
    {
        return {false, max(root->data, max(leftAns.second, rightAns.second))};
    }
}

bool isHeap(struct Node *tree)
{
    return solve(tree).first && levelOrderTraversal(tree);
}

// GFG (BST TO MAX HEAP)
void inorderTraversal(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    inorderTraversal(root->left, ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
}

void postOrderTraversal(Node *root, vector<int> &ans, int &index)
{
    if (!root)
        return;

    postOrderTraversal(root->left, ans, index);
    postOrderTraversal(root->right, ans, index);
    root->data = ans[index++];
}
void convertToMaxHeapUtil(Node *root)
{
    vector<int> ans;
    inorderTraversal(root, ans);
    int index = 0;
    postOrderTraversal(root, ans, index);
}
int main()
{
    { // create max heap
        priority_queue<int> pq;

        pq.push(10);
        pq.push(20);
        pq.push(30);
        pq.push(40);
        pq.push(50);

        cout << "Top element of heap is : " << pq.top() << endl;

        pq.pop();
        cout << "Top element of heap is : " << pq.top() << endl;
        cout << "Size of max Heap is : " << pq.size() << endl;

        if (pq.empty())
        {
            cout << "Empty." << endl;
        }
        else
        {
            cout << "Not Empty." << endl;
        }
    }

    {
        // min heap creation
        priority_queue<int, vector<int>, greater<int>> pq;

        pq.push(100);
        pq.push(90);
        pq.push(70);
        pq.push(80);

        cout << "Top element of heap is : " << pq.top() << endl;

        pq.pop();
        cout << "Top element of heap is : " << pq.top() << endl;
        cout << "Size of min Heap is : " << pq.size() << endl;

        if (pq.empty())
        {
            cout << "Empty." << endl;
        }
        else
        {
            cout << "Not Empty." << endl;
        }
    }

    return 0;
}