#include <iostream>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

void convertBSTtoDLL(Node *root, Node *&head)
{
    // R N L
    if (!root)
        return;
    convertBSTtoDLL(root->right, head);
    root->right = head;
    if (head != NULL)
        head->left = root;
    head = root;
    convertBSTtoDLL(root->left, head);
}

void printLinkedList(Node *&head)
{
    cout << endl;
    cout << "Printing Linked List : ";
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->right;
    }
}

void convertBSTtoDLLUsingInorder(Node *root, Node *&temp, Node *&head)
{
    if (!root)
        return;
    convertBSTtoDLLUsingInorder(root->left, temp, head);
    if (temp)
        temp->right = root;
    root->left = temp;
    temp = root;
    if (head == NULL)
        head = temp;
    convertBSTtoDLLUsingInorder(root->right, temp, head);
}

Node *convertDLLtoBST(Node *&head, int n)
{
    if (head == NULL || n <= 0)
        return NULL;
    // L N R
    Node *leftSubtree = convertDLLtoBST(head, n / 2);
    Node *root = head;
    root->left = leftSubtree;
    head = head->right;
    Node *rightSubtree = convertDLLtoBST(head, (n - n / 2 - 1));
    root->right = rightSubtree;
    return root;
}

// LEETCODE-109 (CONVERT SORTED LIST TO BST)
TreeNode *convertDLLtoBST(ListNode *&head, int n)
{
    if (head == NULL || n <= 0)
        return NULL;
    // L N R
    TreeNode *leftSubtree = convertDLLtoBST(head, n / 2);
    TreeNode *root = new TreeNode(head->val);
    root->left = leftSubtree;
    head = head->next;
    TreeNode *rightSubtree = convertDLLtoBST(head, (n - n / 2 - 1));
    root->right = rightSubtree;
    return root;
}
int length(ListNode *&head)
{
    ListNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

TreeNode *sortedListToBST(ListNode *head)
{
    int n = length(head);
    return convertDLLtoBST(head, n);
}
int main()
{
    {
        // int inorder[] = {10, 20, 30, 40, 50, 60, 70};
        // int size = 7;
        // int start = 0;
        // int end = size - 1;
        // Node *root = BSTFromInorder(inorder, start, end);
        // cout << "Level Order Traversal : " << endl;
        // levelOrderTraversal(root);
        // Node *temp = NULL;
        // // convertBSTtoDLL(root, head);
        // // printLinkedList(head);
        // Node *head = NULL;
        // convertBSTtoDLLUsingInorder(root, temp, head);
        // printLinkedList(head);
    }
    {
        Node *first = new Node(10);
        Node *second = new Node(20);
        Node *third = new Node(30);

        first->right = second;
        second->left = first;
        second->right = third;
        third->left = second;

        Node *root = convertDLLtoBST(first, 3);
        levelOrderTraversal(root);
    }
    return 0;
}