#include <iostream>
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

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}

Node *BSTFromInorder(int inorder[], int s, int e)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = s + (e - s) / 2;
    int element = inorder[mid];
    Node *root = new Node(element);

    root->left = BSTFromInorder(inorder, s, mid - 1);
    root->right = BSTFromInorder(inorder, mid + 1, e);

    return root;
}

// LEETCODE-98 (VALIDATE BINARY SEARCH TREE)
int minimum(TreeNode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    TreeNode *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->val;
}

int maximum(TreeNode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    TreeNode *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->val;
}

bool isValidBST(TreeNode *root)
{
    if (!root)
        return true;
    bool left = isValidBST(root->left);
    bool right = isValidBST(root->right);
    if (left)
    {
        if (root->left)
        {
            left = root->val > maximum(root->left);
        }
    }
    if (right)
    {
        if (root->right)
        {
            right = root->val < minimum(root->right);
        }
    }
    return left && right;
}

// ANOTHER APPROACH (USING INORDER TRAVERSAL)
void inOrderTraversal(TreeNode *root, vector<int> &inOrder)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left, inOrder);
    inOrder.push_back(root->val);
    inOrderTraversal(root->right, inOrder);
}

bool isValidBST(TreeNode *root)
{
    vector<int> inOrder;
    inOrderTraversal(root, inOrder);
    int size = inOrder.size();
    cout << size << endl;
    for (int i = 0; i < size - 1; i++)
    {
        if (inOrder[i] >= inOrder[i + 1])
        {
            return false;
        }
    }
    return true;
}

// BABBAR CODE (USING RANGE)
bool solve(TreeNode *root, long long int lowerBound, long long int upperBound)
{
    if (root == NULL)
        return true;

    bool cond1 = (root->val > lowerBound);
    bool cond2 = (root->val < upperBound);
    bool left = solve(root->left, lowerBound, root->val);
    bool right = solve(root->right, root->val, upperBound);

    return cond1 && cond2 && left && right;
}

bool isValidBST(TreeNode *root)
{

    long long int lowerBound = -2147483658;
    long long int upperBound = 2147483658;
    return solve(root, lowerBound, upperBound);
}

// LEETCODE-235 (LOWEST COMMON ANCESTOR OF A BINARY SEARCH TREE)
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;
    if (p->val < root->val && q->val < root->val)
    {
        // p & q are at left
        return lowestCommonAncestor(root->left, p, q);
    }
    else if (p->val > root->val && q->val > root->val)
    {
        // p & q are at right
        return lowestCommonAncestor(root->right, p, q);
    }
    {
        return root;
    }
}

// LEETCODE-230 (KTH SMALLEST ELEMENT IN A BST)
void inOrderTraversal(TreeNode *root, vector<int> &inOrder)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left, inOrder);
    inOrder.push_back(root->val);
    inOrderTraversal(root->right, inOrder);
}

int kthSmallest1(TreeNode *root, int k)
{
    vector<int> inOrder;
    inOrderTraversal(root, inOrder);
    return inOrder[k - 1];
}

// BABBAR CODE
int kthSmallest(TreeNode *root, int &k)
{
    if (root == NULL)
        return -1;

    // L
    int left = kthSmallest(root->left, k);
    if (left != -1)
    {
        return left;
    }

    // N
    k--;
    if (k == 0)
    {
        return root->val;
    }

    // R
    int right = kthSmallest(root->right, k);
    return right;
}

// LEETCODE-653 (TWO SUM IV - INPUT IS A BST)
void inOrderTraversal(TreeNode *root, vector<int> &inOrder)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left, inOrder);
    inOrder.push_back(root->val);
    inOrderTraversal(root->right, inOrder);
}

bool findTarget(TreeNode *root, int k)
{
    vector<int> inOrder;
    inOrderTraversal(root, inOrder);
    int start = 0;
    int end = inOrder.size() - 1;
    while (start < end)
    {
        if (inOrder[start] + inOrder[end] == k)
            return true;
        else if (inOrder[start] + inOrder[end] < k)
            start++;
        else
            end--;
    }
    return false;
}
int main()
{
    int inorder[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;
    int start = 0;
    int end = size - 1;
    Node *root = BSTFromInorder(inorder, start, end);
    cout << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);
    return 0;
}