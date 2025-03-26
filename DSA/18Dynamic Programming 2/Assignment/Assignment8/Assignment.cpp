#include <iostream>
using namespace std;

// LEETCODE 95 (UNIQUE BST II)
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode *> solve(int start, int end)
{
    if (start > end)
        return {NULL};
    if (start == end)
        return {new TreeNode(start)};
    vector<TreeNode *> ans;
    for (int i = start; i <= end; i++)
    {
        vector<TreeNode *> left = solve(start, i - 1);
        vector<TreeNode *> right = solve(i + 1, end);
        for (int j = 0; j < left.size(); j++)
        {
            for (int k = 0; k < right.size(); k++)
            {
                TreeNode *root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                ans.push_back(root);
            }
        }
    }
    return ans;
}

vector<TreeNode *> generateTrees(int n)
{
    return solve(1, n);
}

// MEMOIZATION (3-D DP ARRAY)
vector<TreeNode *> solve(int start, int end, vector<vector<vector<TreeNode *>>> &dp)
{
    if (start > end)
        return {NULL};
    if (start == end)
        return {new TreeNode(start)};
    if (dp[start][end].size() > 0)
        return dp[start][end];
    vector<TreeNode *> ans;
    for (int i = start; i <= end; i++)
    {
        vector<TreeNode *> left = solve(start, i - 1, dp);
        vector<TreeNode *> right = solve(i + 1, end, dp);
        for (int j = 0; j < left.size(); j++)
        {
            for (int k = 0; k < right.size(); k++)
            {
                TreeNode *root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                ans.push_back(root);
            }
        }
    }
    return dp[start][end] = ans;
}

vector<TreeNode *> generateTrees(int n)
{
    vector<vector<vector<TreeNode *>>> dp(n + 1, vector<vector<TreeNode *>>(n + 1, vector<TreeNode *>(0)));
    return solve(1, n, dp);
}

int main()
{
    return 0;
}