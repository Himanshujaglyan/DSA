#include <iostream>
using namespace std;

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

// GFG (DELETE A NODE FROM BST) // LAKSHAY CODE
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
            Node *min = root->right;
            while (min->left != NULL)
            {
                min = min->left;
            }
            min->left = root->left;
            root = root->right;
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
Node *deleteNode(Node *root, int X)
{
    return deleteFromBST(root, X);
}

// ANOTHER APPROACH
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
            Node *max = root->left;
            while (max->right != NULL)
            {
                max = max->right;
            }
            max->right = root->right;
            root = root->left;
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
Node *deleteNode(Node *root, int X)
{
    return deleteFromBST(root, X);
}
int main()
{

    return 0;
}