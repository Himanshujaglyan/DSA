#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    int children_count;
    Node **children;

    Node(int val)
    {
        this->data = val;
        this->children_count = 0;
        this->children = 0;
    }
};

Node *takeInput()
{
    int data, count;
    cout << "Enter the data : ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter the child count for " << data << " node : ";
    cin >> count;
    Node *root = new Node(data);
    root->children_count = count;
    root->children = new Node *[count];

    for (int i = 0; i < count; i++)
    {
        root->children[i] = takeInput();
    }
    return root;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(0);
    while (!q.empty())
    {
        auto front = q.front();
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
            for (int i = 0; i < front->children_count; i++)
            {
                if (front->children[i])
                {
                    q.push(front->children[i]);
                }
            }
        }
    }
}

// struct Node
// {
//     int data;
//     struct Node *left, *right;
// };

// // GFG (KTH ANCESTOR IN A TREE)
// Node *solve(Node *root, int &k, int &node, int &ans)
// {
//     if (!root)
//         return 0;
//     if (root->data == node)
//         return root;

//     auto l = solve(root->left, k, node, ans);
//     auto r = solve(root->right, k, node, ans);

//     if (!l && !r)
//         return 0;

//     k--;
//     if (k == 0)
//     {
//         ans = root->data;
//     }

//     if (l && !r)
//         return l;
//     else if (!l && r)
//         return r;
//     else
//         return root;
// }

// int kthAncestor(Node *root, int k, int node)
// {
//     int ans = -1;
//     solve(root, k, node, ans);
//     return ans;
// }

int main()
{
    Node *root = takeInput();
    levelOrderTraversal(root);
    return 0;
}