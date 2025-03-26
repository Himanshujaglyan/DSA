#include <iostream>
using namespace std;

// LEETCODE 337 (HOUSE ROBBER 3)
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int solve(TreeNode *root)
{
    if (!root)
        return 0;

    int exclude = solve(root->left) + solve(root->right);
    int include = root->val;
    if (root->left)
        include += solve(root->left->left) + solve(root->left->right);
    if (root->right)
        include += solve(root->right->left) + solve(root->right->right);

    return max(include, exclude);
}

int rob(TreeNode *root)
{
    return solve(root);
}

// MEMOIZATION
int solve(TreeNode *root, unordered_map<TreeNode *, int> &dp)
{
    if (!root)
        return 0;
    if (dp.find(root) != dp.end())
        return dp[root];
    int exclude = solve(root->left, dp) + solve(root->right, dp);
    int include = root->val;
    if (root->left)
        include += solve(root->left->left, dp) + solve(root->left->right, dp);
    if (root->right)
        include += solve(root->right->left, dp) + solve(root->right->right, dp);

    return dp[root] = max(include, exclude);
}

int rob(TreeNode *root)
{
    unordered_map<TreeNode *, int> dp;
    return solve(root, dp);
}

// TABULATION
// IT DOES NOT MAKE ANY SENSE AS WE GENERALLY TRAVELS FROM TOP TO BOTTOM IN TREE AND THROUGH BOTTOM-UP COMPLEXCITY ALSO INCREASES
int main()
{
    return 0;
}