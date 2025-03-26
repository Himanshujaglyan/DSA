#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
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

// GFG (Predecessor and Successor)
void inOrderSuccessor(Node *&root, int &key, Node *&succ)
{
    Node *curr = root;
    while (curr)
    {
        if (curr->key > key)
        {
            succ = curr;
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}
void inOrderPredecessor(Node *&root, int &key, Node *&pred)
{
    Node *curr = root;
    while (curr)
    {
        if (curr->key < key)
        {
            pred = curr;
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    inOrderPredecessor(root, key, pre);
    inOrderSuccessor(root, key, suc);
}

// LEETCODE-1008 (CONSTRUCT BINARY SEARCH TREE FROM PREORDER TRAVERAL)
TreeNode *formBST(TreeNode *root, int element)
{
    if (root == NULL)
    {
        TreeNode *curr = new TreeNode(element);
        return curr;
    }
    if (element > root->val)
    {
        root->right = formBST(root->right, element);
    }
    else
    {
        root->left = formBST(root->left, element);
    }
    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    TreeNode *root = NULL;
    for (int i = 0; i < preorder.size(); i++)
    {
        int element = preorder[i];
        root = formBST(root, element);
    }
    return root;
}

// LAKSHAY CODE
TreeNode *buildTree(vector<int> &preorder, int &i, int min, int max)
{
    if (i >= preorder.size())
        return NULL;
    TreeNode *root = NULL;
    if (preorder[i] > min && preorder[i] < max)
    {
        root = new TreeNode(preorder[i++]);
        root->left = buildTree(preorder, i, min, root->val);
        root->right = buildTree(preorder, i, root->val, max);
    }
    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    return buildTree(preorder, i, min, max);
}

// GFG (BROTHERS FROM DIFFERENT ROOTS)
// Approach 1 : Traverse every Node of BST1 and search for the required Node is BST2
// Approach 2 : Find inorder of both the BST and use two pointer to find ans
// Approach 3 : Use stack to traverse the BST and find the required ans

// Approach-2
void inOrderTraversal(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left, v);
    v.push_back(root->data);
    inOrderTraversal(root->right, v);
}
void reverseInOrderTraversal(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    reverseInOrderTraversal(root->right, v);
    v.push_back(root->data);
    reverseInOrderTraversal(root->left, v);
}

int countPairs(Node *root1, Node *root2, int x)
{
    vector<int> v1;
    vector<int> v2;
    inOrderTraversal(root1, v1);
    reverseInOrderTraversal(root2, v2);

    int p1 = 0;
    int p2 = 0;

    int count = 0;

    while (p1 < v1.size() && p2 < v2.size())
    {
        int element1 = v1[p1];
        int element2 = v2[p2];

        if (element1 + element2 == x)
        {
            count++;
            p1++;
            p2++;
        }
        else if (element1 + element2 < x)
        {
            p1++;
        }
        else
        {
            p2++;
        }
    }
    return count;
}

// Approach-3
int countPairs(Node *root1, Node *root2, int x)
{
    stack<Node *> s1, s2;
    Node *a = root1;
    Node *b = root2;
    int ans = 0;
    while (1)
    {

        while (a)
        {
            s1.push(a);
            a = a->left;
        }

        while (b)
        {
            s2.push(b);
            b = b->right;
        }

        if (s1.empty() || s2.empty())
        {
            break;
        }

        Node *atop = s1.top();
        Node *btop = s2.top();

        int sum = atop->data + btop->data;

        if (sum == x)
        {
            ans++;
            s1.pop();
            s2.pop();
            a = atop->right;
            b = btop->left;
        }
        else if (sum < x)
        {
            s1.pop();
            a = atop->right;
        }
        else
        {
            s2.pop();
            b = btop->left;
        }
    }
    return ans;
}

// LEETCODE-1382 (BALANCE A BINARY SEARCH TREE)
void inOrderTraversal(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    inOrderTraversal(root->left, ans);
    ans.push_back(root->val);
    inOrderTraversal(root->right, ans);
}

TreeNode *formBST(vector<int> &inorder, int s, int e)
{
    if (s > e)
        return NULL;
    int mid = s + (e - s) / 2;
    int element = inorder[mid];
    TreeNode *root = new TreeNode(element);
    root->left = formBST(inorder, s, mid - 1);
    root->right = formBST(inorder, mid + 1, e);
    return root;
}

TreeNode *balanceBST(TreeNode *root)
{
    vector<int> inorder;
    inOrderTraversal(root, inorder);
    int start = 0;
    int end = inorder.size() - 1;
    return formBST(inorder, start, end);
}

// GFG (MEDIAN OF BST)
int findNodeCount(Node *root)
{
    Node *curr = root;
    int count = 0;
    while (curr)
    {
        if (curr->left == NULL)
        {
            curr = curr->right;
            count++;
        }
        else
        {
            Node *pred = curr->left;

            while (pred->right != NULL && pred->right != curr)
            {
                pred = pred->right;
            }

            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}

float findActualMedian(Node *root, int &n)
{
    int odd = (n + 1) / 2;
    int even1 = n / 2;
    int even2 = n / 2 + 1;
    int oddVal = -1;
    int even1Val = -1;
    int even2Val = -1;
    Node *curr = root;
    int count = 0;
    while (curr)
    {
        if (curr->left == NULL)
        {
            count++;
            if (count == odd)
            {
                oddVal = curr->data;
            }
            if (count == even1)
            {
                even1Val = curr->data;
            }
            if (count == even2)
            {
                even2Val = curr->data;
            }
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;

            while (pred->right != NULL && pred->right != curr)
            {
                pred = pred->right;
            }

            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                count++;
                if (count == odd)
                {
                    oddVal = curr->data;
                }
                if (count == even1)
                {
                    even1Val = curr->data;
                }
                if (count == even2)
                {
                    even2Val = curr->data;
                }
                curr = curr->right;
            }
        }
    }
    if (n & 1)
    {
        return oddVal;
    }
    else
    {
        return (even1Val + even2Val) / 2.0;
    }
}
float findMedian(struct Node *root)
{
    int count = findNodeCount(root);
    return findActualMedian(root, count);
}

// GFG (CHECK WHETHER BST CONTAIN DEAD END)
void fun(Node *root, unordered_map<int, bool> &visited, bool &ans)
{
    if (!root)
        return;
    visited[root->data] = 1;
    if (root->left == NULL && root->right == NULL)
    {
        int next = root->data + 1;
        int prev = root->data - 1 == 0 ? root->data : root->data - 1;
        if (visited.find(next) != visited.end() && visited.find(prev) != visited.end())
        {
            ans = true;
            return;
        }
    }
    fun(root->left, visited, ans);
    fun(root->right, visited, ans);
}

bool isDeadEnd(Node *root)
{
    unordered_map<int, bool> visited;
    bool ans = false;
    fun(root, visited, ans);
    return ans;
}

// LEETCODE 938 (RANGE SUM OF BST)
void inorderTraversal(TreeNode *root, int &low, int &high, int &ans)
{
    if (root == NULL)
        return;
    if (root->val >= low && root->val <= high)
    {
        ans += root->val;
        inorderTraversal(root->left, low, high, ans);
        inorderTraversal(root->right, low, high, ans);
    }
    else if (root->val < low)
    {
        inorderTraversal(root->right, low, high, ans);
    }
    else if (root->val > high)
    {
        inorderTraversal(root->left, low, high, ans);
    }
}

int rangeSumBST(TreeNode *root, int low, int high)
{
    int ans = 0;
    inorderTraversal(root, low, high, ans);
    return ans;
}

// GFG (FLATTEN BST TO SORTED LIST)
void solve(Node *root, Node *&head, Node *&temp)
{
    if (!root)
        return;
    solve(root->left, head, temp);
    if (temp)
        temp->right = root;
    root->left = NULL;
    temp = root;
    if (!head)
        head = temp;
    solve(root->right, head, temp);
}

Node *flattenBST(Node *root)
{
    Node *head = NULL;
    Node *temp = NULL;
    solve(root, head, temp);
    return head;
}

// GFG (REPLACE EVERY ELEMENT WITH THE LEAST GREATER ELEMENT ON ITS RIGHT)
Node *insertBST(Node *root, int &element, int &succ)
{
    if (!root)
        return new Node(element);
    if (element >= root->data)
    {
        root->right = insertBST(root->right, element, succ);
    }
    else
    {
        succ = root->data;
        root->left = insertBST(root->left, element, succ);
    }
    return root;
}
vector<int> findLeastGreater(vector<int> &arr, int n)
{
    vector<int> ans(arr.size(), -1);
    Node *root = 0;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int succ = -1;
        root = insertBST(root, arr[i], succ);
        ans[i] = succ;
    }
    return ans;
}

// VALID BST FROM PREORDER
void buildBST(vector<int> &A, int &i, int min, int max)
{
    if (i >= A.size())
    {
        return;
    }

    if (A[i] > min && A[i] < max)
    {
        int data = A[i];
        i++;
        buildBST(A, i, min, data);
        buildBST(A, i, data, max);
    }
}

int solve(vector<int> &A)
{
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    buildBST(A, i, min, max);

    if (i == A.size())
        return 1;
    return 0;
}

// GFG (MERGE TWO BST)
vector<int> merge(Node *root1, Node *root2)
{
    vector<int> ans;
    stack<Node *> s1, s2;
    Node *a = root1;
    Node *b = root2;
    while (a || b || !s1.empty() || !s2.empty())
    {

        while (a)
        {
            s1.push(a);
            a = a->left;
        }

        while (b)
        {
            s2.push(b);
            b = b->left;
        }

        if (s2.empty() || (!s1.empty() && s1.top()->data <= s2.top()->data))
        {
            ans.push_back(s1.top()->data);
            a = s1.top()->right;
            s1.pop();
        }
        else
        {
            ans.push_back(s2.top()->data);
            b = s2.top()->right;
            s2.pop();
        }
    }
    return ans;
}
int main()
{
    return 0;
}