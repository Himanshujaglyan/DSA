#include <iostream>
#include <map>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
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

// LEETCODE 110 (BALANCED BINARY TREE)
int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(TreeNode *root)
{
    if (root == NULL)
        return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int diff = abs(leftHeight - rightHeight);

    bool currAns = (diff <= 1);

    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);

    return (currAns && leftAns && rightAns);
}

// LEETCODE 236 (LOWEST COMMON ANCESTOR OF A BINARY TREE)
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;
    if (root == p)
        return p;
    if (root == q)
        return q;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL && right == NULL)
        return NULL;
    else if (left != NULL && right == NULL)
        return left;
    else if (left == NULL && right != NULL)
        return right;
    else
    {
        return root;
    }
}

// LEETCODE 112 (PATH SUM)
bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == NULL)
        return false;
    else if ((targetSum - root->val) == 0 && root->left == NULL && root->right == NULL)
        return true;
    bool leftAns = hasPathSum(root->left, (targetSum - root->val));
    bool rightAns = hasPathSum(root->right, (targetSum - root->val));

    return (leftAns || rightAns);
}

// BABBAR CODE
bool solve(TreeNode *root, int targetSum, int sum)
{
    if (root == NULL)
        return false;
    sum += root->val;
    if (root->left == NULL && root->right == NULL)
    {
        if (targetSum == sum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool leftAns = solve(root->left, targetSum, sum);
    bool rightAns = solve(root->right, targetSum, sum);

    return (leftAns || rightAns);
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    int sum = 0;
    bool ans = solve(root, targetSum, sum);
    return ans;
}

// LEETCODE 113 (PATH SUM II)
void solve(TreeNode *root, int &targetSum, int &sum, vector<vector<int>> &ans, vector<int> &v)
{
    if (root == NULL)
        return;
    sum += root->val;
    v.push_back(root->val);
    if (root->left == NULL && root->right == NULL)
    {
        if (targetSum == sum)
        {
            ans.push_back(v);
        }
    }
    solve(root->left, targetSum, sum, ans, v);
    solve(root->right, targetSum, sum, ans, v);
    v.pop_back();
    sum -= root->val;
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> ans;
    vector<int> v;
    int sum = 0;
    solve(root, targetSum, sum, ans, v);
    return ans;
}

// GFG (KTH ANCESTOR IN A TREE)
int solve(Node *root, int &k, int &node)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == node)
    {
        k--;
        return root->data;
    }
    int left = solve(root->left, k, node);
    if (k == 0)
    {
        k--;
        return root->data;
    }
    if (left != -1)
    {
        k--;
        return left;
    }
    int right = solve(root->right, k, node);
    if (k == 0)
    {
        k--;
        return root->data;
    }
    if (right != -1)
    {
        k--;
        return right;
    }
    if (left == -1 && right == -1)
    {
        return -1;
    }
}

int kthAncestor(Node *root, int k, int node)
{
    int ans = solve(root, k, node);
    if (k >= 0)
        return -1;
    return ans;
}

// LEETCODE 105 (CONSTRUCT BINARY TREE FROM PREORDER & INORDER TRAVERSAL)
int searchIndex(vector<int> &inorder, int &size, int &target)
{
    for (int i = 0; i < size; i++)
    {
        if (inorder[i] == target)
        {
            return i;
        }
    }
    return -1;
}

TreeNode *constructTree(vector<int> &preorder, vector<int> &inorder, int &preIndex, int inOrderStart, int inOrderEnd, int size)
{
    if (preIndex >= size || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    int element = preorder[preIndex];
    TreeNode *root = new TreeNode(element);
    preIndex++;

    int position = searchIndex(inorder, size, element);

    root->left = constructTree(preorder, inorder, preIndex, inOrderStart, position - 1, size);

    root->right = constructTree(preorder, inorder, preIndex, position + 1, inOrderEnd, size);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int preIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = preorder.size() - 1;
    int size = preorder.size();
    return constructTree(preorder, inorder, preIndex, inOrderStart, inOrderEnd, size);
}

// ANOTHER APPROACH (USING MAP THAT SAVES SEARCHING TIME)
TreeNode *constructTree(vector<int> &preorder, vector<int> &inorder, int &preIndex, int inOrderStart, int inOrderEnd, int size, map<int, int> &valueToIndexMap)
{
    if (preIndex >= size || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    int element = preorder[preIndex];
    TreeNode *root = new TreeNode(element);
    preIndex++;

    int position = valueToIndexMap[element];

    root->left = constructTree(preorder, inorder, preIndex, inOrderStart, position - 1, size, valueToIndexMap);

    root->right = constructTree(preorder, inorder, preIndex, position + 1, inOrderEnd, size, valueToIndexMap);

    return root;
}
void createMapping(vector<int> &inorder, int &size, map<int, int> &valueToIndexMap)
{
    for (int i = 0; i < size; i++)
    {
        int element = inorder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int preIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = preorder.size() - 1;
    int size = preorder.size();
    map<int, int> valueToIndexMap;
    createMapping(inorder, size, valueToIndexMap);
    return constructTree(preorder, inorder, preIndex, inOrderStart, inOrderEnd, size, valueToIndexMap);
}

// LEETCODE 106 (CONSTRUCT BINARY TREE FROM POSTORDER & INORDER TRAVERSAL)
TreeNode *constructTree(vector<int> &postorder, vector<int> &inorder,
                        int &postIndex, int inOrderStart, int inOrderEnd,
                        int size, map<int, int> &valueToIndexMap)
{
    if (postIndex < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    int element = postorder[postIndex];
    TreeNode *root = new TreeNode(element);
    postIndex--;

    int position = valueToIndexMap[element];

    root->right = constructTree(postorder, inorder, postIndex, position + 1, inOrderEnd, size, valueToIndexMap);
    root->left = constructTree(postorder, inorder, postIndex, inOrderStart, position - 1, size, valueToIndexMap);

    return root;
}
void createMapping(vector<int> &inorder, int &size, map<int, int> &valueToIndexMap)
{
    for (int i = 0; i < size; i++)
    {
        int element = inorder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int postIndex = postorder.size() - 1;
    int inOrderStart = 0;
    int inOrderEnd = postorder.size() - 1;
    int size = postorder.size();
    map<int, int> valueToIndexMap;
    createMapping(inorder, size, valueToIndexMap);
    return constructTree(postorder, inorder, postIndex, inOrderStart, inOrderEnd, size, valueToIndexMap);
}
int main()
{

    return 0;
}
