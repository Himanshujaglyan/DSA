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

Node *insertIntoBST(Node *root, int &data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void createBST(Node *&root)
{
    cout << "Enter the data : ";
    int data;
    cin >> data;
    while (data != -1)
    {
        // COMPLEXCITY IN CASE OF BALANCED BST IS O(log(N))
        root = insertIntoBST(root, data); // WORST CASE COMPLEXCITY :- O(N) WHEN TREE IS SKEWED TO ONE SIDE
        cout << "Enter the data : ";
        cin >> data;
    }
}

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

void preOrderTraversal(Node *root)
{
    // NLR
    if (root == NULL)
        return;
    // N
    cout << root->data << " ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root)
{

    // LNR
    if (root == NULL)
        return;
    // L
    inOrderTraversal(root->left);
    // N
    cout << root->data << " ";
    // R
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{

    // LRN
    if (root == NULL)
        return;
    // L
    postOrderTraversal(root->left);
    // R
    postOrderTraversal(root->right);
    // N
    cout << root->data << " ";
}

int minimumValue(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}

int maximumValue(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

bool searchInBST(Node *root, int &target)
{
    if (root == NULL)
        return false;
    if (root->data == target)
        return true;

    if (target > root->data)
    {
        return searchInBST(root->right, target);
    }
    else
    {
        return searchInBST(root->left, target);
    }
}

// LEETCODE-700 (SEARCH IN A BST)
TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == NULL)
        return NULL;
    if (root->val == val)
        return root;

    if (val > root->val)
    {
        return searchBST(root->right, val);
    }
    else
    {
        return searchBST(root->left, val);
    }
}

// GFG (DELETE A NODE FROM BST)
Node *deleteFromBST(Node *root, int &target)
{
    if (root == NULL)
        return root;

    if (root->data == target)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *childSubtree = root->left;
            delete root;
            return childSubtree;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *childSubtree = root->right;
            delete root;
            return childSubtree;
        }
        else
        {
            int maxi = maximumValue(root->left);
            root->data = maxi;
            root->left = deleteFromBST(root->left, maxi);
            return root;
        }
    }
    else if (target > root->data)
    {
        root->right = deleteFromBST(root->right, target);
    }
    else
    {
        root->left = deleteFromBST(root->left, target);
    }
    return root;
}
int main()
{
    // 50 30 60 25 40 70 80 55 -1
    Node *root = NULL;
    createBST(root);

    cout << "Level Order : " << endl;
    levelOrderTraversal(root);

    cout << endl;
    cout << "PreOrder : " << endl;
    preOrderTraversal(root);

    cout << endl;
    cout << "InOrder : " << endl;
    inOrderTraversal(root);
    cout << endl;

    cout << "PostOrder : " << endl;
    postOrderTraversal(root);
    cout << endl;

    // cout << "Minimum Value : " << minimumValue(root) << endl;
    // cout << "Maximum Value : " << maximumValue(root) << endl;

    // int target;
    // cout << "Enter the target : ";
    // cin >> target;

    // while (target != -1)
    // {
    //     bool ans = searchInBST(root, target);
    //     if (ans)
    //     {
    //         cout << "Target Found." << endl;
    //     }
    //     else
    //     {
    //         cout << "Target not Found." << endl;
    //     }

    //     cout << "Enter the target : ";
    //     cin >> target;
    // }

    int target;
    cout << "Enter the target : ";
    cin >> target;

    while (target != -1)
    {
        root = deleteFromBST(root, target);
        cout << endl
             << "Level Order Traversal : " << endl;
        levelOrderTraversal(root);
        cout << "Enter the target : ";
        cin >> target;
    }
    return 0;
}