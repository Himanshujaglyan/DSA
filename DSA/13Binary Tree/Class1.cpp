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
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createNode()
{
    cout << "Enter the data : ";
    int data;
    cin >> data;
    if (data == -1)
        return NULL;
    // STEP 1 :- Create root Node
    Node *root = new Node(data);
    // cout << "Left Node of : " << root->data << endl;
    // STEP 2 :- Create Left Subtree
    root->left = createNode();
    // cout << "Right Node of : " << root->data << endl;
    // STEP 3 :- Create right subtree
    root->right = createNode();

    return root;
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

void levelOrderTraversal(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) // q.size() > 1
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            if (front->left != NULL)
                q.push(front->left);

            if (front->right != NULL)
                q.push(front->right);
        }
    }
}

// LEETCODE 104 (MAXIMUM DEPTH OF BINARY TREE)
int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// LEVEL APPROACH
int maxDepth1(TreeNode *root)
{
    if (root == 0)
        return 0;
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    int count = 0;
    while (!q.empty()) // q.size() > 1
    {
        TreeNode *front = q.front();
        q.pop();
        if (front == NULL)
        {
            count++;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
    }
    return count;
}

// LEETCODE 543 (DIAMETER OF BINARY TREE)
int diameterOfBinaryTree(TreeNode *root)
{
    if (root == 0)
        return 0;
    int leftAns = diameterOfBinaryTree(root->left);
    int rightAns = diameterOfBinaryTree(root->right);
    int option3 = maxDepth(root->left) + maxDepth(root->right);
    return max(leftAns, max(rightAns, option3));
}
int main()
{
    Node *root = createNode();
    cout << endl;
    cout << "Printing Preoder : ";
    preOrderTraversal(root);
    cout << endl;
    cout << "Printing InOrder : ";
    inOrderTraversal(root);
    cout << endl;
    cout << "Printing PostOrder : ";
    postOrderTraversal(root);
    cout << endl;
    cout << "Printing LevelOrder : " << endl;
    levelOrderTraversal(root);
    return 0;
}

// A FULL BINARY TREE IS A TREE WITH EITHER 0 OR 2 CHILD NODES