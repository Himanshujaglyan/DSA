#include <bits/stdc++.h>
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
    int val;
    int data;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// LEETCODE 543 (DIAMETER OF BINARY TREE)
int height(TreeNode *root, int &diameter)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    int currDiameter = lh + rh;
    diameter = max(currDiameter, diameter);
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

// LEETCODE-110 (BALANCED BINARY TREE)
int height(TreeNode *root, bool &flag)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left, flag);
    int rh = height(root->right, flag);
    int diff = abs(lh - rh);
    if (flag == true)
        flag = (diff <= 1);
    return 1 + max(lh, rh);
}

bool isBalanced(TreeNode *root)
{
    bool flag = true;
    height(root, flag);
    return flag;
}

// LEETCODE-100 (SAME TREE)
void solve(TreeNode *p, TreeNode *q, bool &isIdentical)
{
    if (p == NULL && q == NULL)
    {
        return;
    }
    else if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
    {
        isIdentical = false;
        return;
    }
    else
    {
        if (p->val != q->val)
        {
            isIdentical = false;
            return;
        }
    }
    solve(p->left, q->left, isIdentical);
    solve(p->right, q->right, isIdentical);
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
    bool isIdentical = true;
    solve(p, q, isIdentical);
    return isIdentical;
}

// LAKSHAY CODE
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;
    if (p && q)
    {
        return (p->val == q->val) && (isSameTree(p->left, q->left)) &&
               (isSameTree(p->right, q->right));
    }
    return false;
}

// LEETCODE-101 (SYMMETRIC TREE)
void solve(TreeNode *p, TreeNode *q, bool &isIdentical)
{
    if (p == NULL && q == NULL)
    {
        return;
    }
    else if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
    {
        isIdentical = false;
        return;
    }
    else
    {
        if (p->val != q->val)
        {
            isIdentical = false;
            return;
        }
    }
    solve(p->left, q->right, isIdentical);
    solve(p->right, q->left, isIdentical);
}

bool isSymmetric(TreeNode *root)
{
    bool isIdentical = true;
    solve(root->left, root->right, isIdentical);
    return isIdentical;
}

// LAKSHAY CODE
bool isMirror(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;
    if (p && q)
    {
        return (p->val == q->val) && (isMirror(p->left, q->right)) &&
               (isMirror(p->right, q->left));
    }
    return false;
}

bool isSymmetric(TreeNode *root)
{
    return isMirror(root->left, root->right);
}

// LEETCODE-116 (POPULATING NEXT RIGHT POINTERS IN EACH NODE)
Node *connect(Node *root)
{
    if (root == NULL)
        return root;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {

            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            front->next = q.front();
            if (front->left != NULL)
                q.push(front->left);

            if (front->right != NULL)
                q.push(front->right);
        }
    }
    return root;
}

// GFG (DIAGONAL TREE TRAVERSAL)
void solve(Node *root, vector<int> &ans, queue<Node *> &q)
{
    if (root == NULL)
        return;
    ans.push_back(root->data);
    if (root->left != NULL)
    {
        q.push(root->left);
    }
    solve(root->right, ans, q);
}

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    queue<Node *> q;
    solve(root, ans, q);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        solve(front, ans, q);
    }
    return ans;
}

// LAKSHAY CODE (USING MAP)
void solve(Node *root, int d, map<int, vector<int>> &mp)
{
    if (root == NULL)
        return;
    mp[d].push_back(root->data);
    // when we move left increment diagonal level by 1
    solve(root->left, d + 1, mp);
    // when we move right diagonal level remain same
    solve(root->right, d, mp);
}
vector<int> diagonal(Node *root)
{
    map<int, vector<int>> mp;
    int d = 0;
    solve(root, d, mp);
    vector<int> ans;
    for (auto i : mp)
    {
        vector<int> temp = i.second;
        for (auto j : temp)
        {
            ans.push_back(j);
        }
    }
    return ans;
}

// ANOTHER APPROACH (USING QUEUE)
vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        while (temp)
        {
            ans.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            temp = temp->right;
        }
    }
    return ans;
}

// LEETCODE 987 (VERTICAL ORDER TRAVERSAL OF A BINARY TREE)
void solve(TreeNode *root, int collevel, int rowLevel, map<int, map<int, multiset<int>>> &mp)
{
    if (root == NULL)
        return;
    mp[collevel][rowLevel].insert(root->val);
    solve(root->left, collevel - 1, rowLevel + 1, mp);
    solve(root->right, collevel + 1, rowLevel + 1, mp);
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> mp; // {col , {row, [1,2,3,4]}}
    solve(root, 0, 0, mp);
    vector<vector<int>> ans;
    for (auto it : mp)
    {
        vector<int> vLine;
        auto &colMap = it.second;
        for (auto colMapIt : colMap)
        {
            auto &mset = colMapIt.second;
            vLine.insert(vLine.end(), mset.begin(), mset.end());
        }
        ans.push_back(vLine);
    }
    return ans;
}

// LAKSHAY CODE (THROUGH LEVEL ORDER TRAVERSAL)
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> mp;
    queue<pair<TreeNode *, pair<int, int>>> q; // {Node, {row, col}}
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        TreeNode *&node = front.first;
        auto &coordinate = front.second;
        auto &row = coordinate.first;
        auto &col = coordinate.second;
        mp[col][row].insert(node->val);
        if (node->left != NULL)
        {
            q.push({node->left, {row + 1, col - 1}});
        }
        if (node->right != NULL)
        {
            q.push({node->right, {row + 1, col + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto it : mp)
    {
        vector<int> vLine;
        auto &colMap = it.second;
        for (auto colMapIt : colMap)
        {
            auto &mset = colMapIt.second;
            vLine.insert(vLine.end(), mset.begin(), mset.end());
        }
        ans.push_back(vLine);
    }
    return ans;
}

// LEETCODE-103 (BINARY TREE ZIGZAG LEVEL ORDER TRAVERSAL)
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    bool LtoRDir = true;
    while (!q.empty())
    {
        int width = q.size();
        vector<int> oneLevel(width);
        for (int i = 0; i < width; i++)
        {
            TreeNode *front = q.front();
            q.pop();
            int index = LtoRDir ? i : width - i - 1;
            oneLevel[index] = front->val;
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
        ans.push_back(oneLevel);
        LtoRDir = !LtoRDir;
    }

    return ans;
}

// GFG (TRANSFORM TO SUM TREE)
int solve(Node *root)
{
    if (root == NULL)
        return 0;

    int lAns = solve(root->left);
    int rAns = solve(root->right);

    int curr = root->data;
    root->data = lAns + rAns;
    return root->data + curr;
}

void toSumTree(Node *node)
{
    solve(node);
}

// LEETCODE-437 (PATH SUM III)
void solve(TreeNode *root, long targetSum, int &ans, bool flag)
{
    if (root == NULL)
        return;

    if ((targetSum - root->val) == 0)
    {
        ans++;
    }
    if (!flag)
    {
        solve(root->left, targetSum, ans, false);
        solve(root->right, targetSum, ans, false);
    }
    // Sending true with included node so that they will not neglect any node in-between
    solve(root->left, targetSum - root->val, ans, true);
    solve(root->right, targetSum - root->val, ans, true);
}
int pathSum(TreeNode *root, int targetSum)
{
    int ans = 0;
    solve(root, targetSum, ans, false);
    return ans;
}

// LAKSHAY CODE
int ans = 0;
void solve(TreeNode *root, long targetSum, int &ans)
{
    if (root == NULL)
        return;
    if (targetSum == root->val)
        ans++;
    solve(root->left, targetSum - root->val, ans);
    solve(root->right, targetSum - root->val, ans);
}
int pathSum(TreeNode *root, int targetSum)
{
    if (root)
    {
        solve(root, targetSum, ans);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
    }
    return ans;
}

// LEETCODE-94 (BINARY TREE INORDER TRAVERSAL)
// MORRIS TRAVERSAL
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;
    while (curr)
    {
        // left Node is NULL the visit Current Node and go right
        if (curr->left == NULL)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        // left Node is not NULL
        else
        {
            // Find Inorder Predecessor
            TreeNode *pred = curr->left;
            while (pred->right != curr && pred->right)
            {
                pred = pred->right;
            }
            // if Predecessor right Node is NULL go Left after establish link from pred to curr
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            // left is already visited, go right after visiting curr node while removing the link
            else
            {
                pred->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return ans;
}

// GFG (SUM OF NODES ON THE LONGEST PATH FROM ROOT TO LEAF NODE)
void solve(Node *root, int level, int sum, int &depth, int &ans)
{
    if (root == NULL)
        return;
    sum = sum + root->data;
    if (root->left == NULL && root->right == NULL)
    {
        if (level == depth)
        {
            ans = max(ans, sum);
        }
        else if (level > depth)
        {
            depth = level;
            ans = sum;
        }
        return;
    }
    solve(root->left, level + 1, sum, depth, ans);
    solve(root->right, level + 1, sum, depth, ans);
}
int sumOfLongRootToLeafPath(Node *root)
{
    int depth = 0;
    int ans = 0;
    solve(root, 0, 0, depth, ans);
    return ans;
}

// LAKSHAY CODE
pair<int, int> solve1(Node *root)
{
    if (!root)
        return {0, 0};

    pair<int, int> lh = solve1(root->left);
    pair<int, int> rh = solve1(root->right);

    if (lh.first == rh.first)
    {
        return {lh.first + 1, max(lh.second, rh.second) + root->data};
    }
    else if (lh.first > rh.first)
    {
        return {lh.first + 1, lh.second + root->data};
    }
    else
    {
        return {rh.first + 1, rh.second + root->data};
    }
}

int sumOfLongRootToLeafPath(Node *root)
{
    pair<int, int> ans = solve1(root);// {depth, sum}
    return ans.second;
}

// GFG (MAXIMUM SUM OF NON-ADJACENT NODES) // INCLUDE-EXCLUDE PATTERN
pair<int, int> getMaxSumHelper(Node *root)
{
    if (!root)
        return {0, 0};

    pair<int, int> left = getMaxSumHelper(root->left);
    pair<int, int> right = getMaxSumHelper(root->right);

    // include current node
    int a = root->data + left.second + right.second;
    // exclude current node
    int b = max(left.first, left.second) + max(right.first, right.second);

    return {a, b};
}

int getMaxSum(Node *root)
{
    pair<int, int> ans = getMaxSumHelper(root);
    return max(ans.first, ans.second);
}

// GFG (BURNING TREE)
int height(Node *root)
{
    if (!root)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

void solve(Node *root, int &target, stack<Node *> &st, bool &flag)
{
    // it will push the element from root to the target node
    if (!root)
        return;
    st.push(root);
    if (target == root->data)
    {
        flag = true;
        return;
    }
    if (flag == false)
        solve(root->left, target, st, flag);
    if (flag == false)
        solve(root->right, target, st, flag);
    if (flag == false)
        st.pop();
}
int minTime(Node *root, int target)
{
    stack<Node *> st;
    bool flag = false;
    solve(root, target, st, flag);

    int ans = st.size() - 1;
    int temp = ans;
    Node *tempNode = NULL;
    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();
        int lh = 0;
        if (curr->left != tempNode)
        {
            lh = height(curr->left);
        }
        int rh = 0;
        if (curr->right != tempNode)
        {
            rh = height(curr->right);
        }
        int maxi = max(lh, rh);
        if (maxi - temp > 0)
        {
            ans += maxi - temp;
            temp += maxi - temp;
        }
        tempNode = curr;
        temp--;
    }
    return ans;
}

// LAKSHAY CODE
Node *makeNodeToParentMappingAndFindTargetNode(Node *root, int &target, unordered_map<Node *, Node *> &ParentMap)
{
    queue<Node *> q;
    Node *targetNode = NULL;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front->data == target)
        {
            targetNode = front;
        }
        if (front->left != NULL)
        {
            q.push(front->left);
            ParentMap[front->left] = front;
        }
        if (front->right != NULL)
        {
            q.push(front->right);
            ParentMap[front->right] = front;
        }
    }
    return targetNode;
}

int burnTheTree(Node *&targetNode, unordered_map<Node *, Node *> &ParentMap)
{
    unordered_map<Node *, bool> isBurnt;
    // here to spread fire it take 1 second so at t = 0, target node is burnt
    // take example of test case with only two nodes then output will be 1
    isBurnt[targetNode] = 1;
    queue<Node *> q;
    q.push(targetNode);
    int time = 0;
    while (!q.empty())
    {
        bool isFireSpreaded = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();
            if (front->left != NULL && !isBurnt[front->left])
            {
                q.push(front->left);
                isBurnt[front->left] = 1;
                isFireSpreaded = 1;
            }
            if (front->right != NULL && !isBurnt[front->right])
            {
                q.push(front->right);
                isBurnt[front->right] = 1;
                isFireSpreaded = 1;
            }
            if (ParentMap[front] != NULL && !isBurnt[ParentMap[front]])
            {
                q.push(ParentMap[front]);
                isBurnt[ParentMap[front]] = 1;
                isFireSpreaded = 1;
            }
        }
        if (isFireSpreaded == 1)
        {
            time++;
        }
    }
    return time;
}

int minTime(Node *root, int target)
{
    unordered_map<Node *, Node *> ParentMap; // Node -> Parent Node
    Node *targetNode = makeNodeToParentMappingAndFindTargetNode(root, target, ParentMap);
    return burnTheTree(targetNode, ParentMap);
}

// LEETCODE-652 (FIND DUPLICATE SUBTREES)
string preOrder(TreeNode *root, vector<TreeNode *> &ans, unordered_map<string, int> &mp)
{
    if (!root)
        return "N";

    string curr = to_string(root->val);
    string l = preOrder(root->left, ans, mp);
    string r = preOrder(root->right, ans, mp);
    string s = curr + "," + l + "," + r;

    if (mp.find(s) == mp.end())
    {
        mp[s] = 1;
    }
    else
    {
        if (mp[s] == 1)
        {
            ans.push_back(root);
            mp[s]++;
        }
    }
    return s;
}

vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    vector<TreeNode *> ans;
    unordered_map<string, int> mp;
    preOrder(root, ans, mp);
    return ans;
}
int main()
{
    return 0;
}