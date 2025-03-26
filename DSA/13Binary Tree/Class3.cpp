#include <iostream>
#include <map>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// GFG (LEFT VIEW OF BINARY TREE)
void solve(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->left, level + 1, ans);
    solve(root->right, level + 1, ans);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    int level = 0;
    solve(root, level, ans);
    return ans;
}

// LEETCODE 199 (BINARY TREE RIGHT SIDE VIEW)
void solve(TreeNode *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->val);
    }
    solve(root->right, level + 1, ans);
    solve(root->left, level + 1, ans);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    int level = 0;
    solve(root, level, ans);
    return ans;
}

// GFG (TOP VIEW OF A BINARY TREE)
// HERE WE HAVE USE LEVEL ORDER TRAVERSAL
// IT CANNOT BE SOLVED USING PREORDER, INORDER, POSTORDER TRAVERSAL
vector<int> topView(Node *root)
{
    map<int, int> horizontalDistanceToNodeMap;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *front = temp.first;
        int horizontalDistance = temp.second;

        if (horizontalDistanceToNodeMap.find(horizontalDistance) == horizontalDistanceToNodeMap.end())
        {
            horizontalDistanceToNodeMap[horizontalDistance] = front->data;
        }
        if (front->left != NULL)
        {
            q.push(make_pair(front->left, horizontalDistance - 1));
        }

        if (front->right != NULL)
        {
            q.push(make_pair(front->right, horizontalDistance + 1));
        }
    }

    vector<int> ans;
    for (auto i : horizontalDistanceToNodeMap)
    {
        ans.push_back(i.second);
    }

    return ans;
}

// GFG (BOTTOM VIEW OF A BINARY TREE)
// SAME AS TOP VIEW LOGIC BUT WITHOUT IF CONDITION OF MAP
vector<int> bottomView(Node *root)
{
    map<int, int> horizontalDistanceToNodeMap;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *front = temp.first;
        int horizontalDistance = temp.second;

        horizontalDistanceToNodeMap[horizontalDistance] = front->data;

        if (front->left != NULL)
        {
            q.push(make_pair(front->left, horizontalDistance - 1));
        }

        if (front->right != NULL)
        {
            q.push(make_pair(front->right, horizontalDistance + 1));
        }
    }

    vector<int> ans;

    for (auto i : horizontalDistanceToNodeMap)
    {
        ans.push_back(i.second);
    }

    return ans;
}

// GFG (TREE BOUNDARY TRAVERSAL)
void LeftBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left != NULL)
    {
        LeftBoundary(root->left, ans);
    }
    else
    {
        LeftBoundary(root->right, ans);
    }
}

void LeafBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    LeafBoundary(root->left, ans);
    LeafBoundary(root->right, ans);
}

void RightBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    if (root->right != NULL)
    {
        RightBoundary(root->right, ans);
    }
    else
    {
        RightBoundary(root->left, ans);
    }
    ans.push_back(root->data);
}
vector<int> boundary(Node *root)
{
    vector<int> ans;
    ans.push_back(root->data);
    LeftBoundary(root->left, ans);
    LeafBoundary(root->left, ans);
    LeafBoundary(root->right, ans);
    RightBoundary(root->right, ans);

    return ans;
}
int main()
{
    return 0;
}