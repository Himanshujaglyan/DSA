#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// LEETCODE 142 (LINKED LIST CYCLE 2)
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
        {
            break;
        }
    }
    if (fast == slow)
    {
        slow = head;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // return fast;
    }

    return NULL;
}

// GFG (REMOVE LOOP IN A LINKED LIST)
struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void removeLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
        {
            break;
        }
    }
    if (fast == slow)
    {
        slow = head;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        Node *startPoint = slow;
        Node *temp = slow;
        while (temp->next != startPoint)
            temp = temp->next;
        temp->next = NULL;
    }
}

// GFG (ADD 1 TO A LINKED LIST NUMBER)

// APPROACH :- 1 USE THE LINKED LIST TO FORM A NUMBER THEN ADD ONE TO THAT NUMBER AND FORM ANOTHER LINKED LIST

// APPROACH :- 2 REVERSE, ADD, REVERSE

Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node *addOne(Node *head)
{
    head = reverseList(head);

    Node *temp = head;
    int carry = 1;
    while (temp != NULL)
    {
        temp->data += carry;
        carry = (temp->data) / 10;
        temp->data %= 10;
        if (carry == 0)
            break;
        if ((temp->next == NULL) && carry == 1)
        {
            Node *newNode = new Node(carry);
            temp->next = newNode;
            temp = temp->next;
        }
        temp = temp->next;
    }

    head = reverseList(head);

    return head;
}

// LEETCODE 25 (REVERSE NODES IN K GROUPS)
int getLength(ListNode *head)
{
    ListNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    int length = getLength(head);
    if (length < k)
    {
        return head;
    }
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *nextNode = curr->next;
    int position = 1;
    while (position <= k)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        position++;
    }
    // nextNode and currNode points at the same position at this location of code
    ListNode *recAns = reverseKGroup(nextNode, k); // so we can send currNode also here in recursive call
    head->next = recAns;

    return prev;
}

// LEETCODE 83 (REMOVE DUPLICATES FROM A SORTED LIST)
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        ListNode *nextNode = temp->next;
        if (nextNode->val == temp->val)
        {
            temp->next = nextNode->next;
            nextNode->next = NULL;
            delete nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
    return 0;
}