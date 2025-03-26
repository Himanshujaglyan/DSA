#include <iostream>
#include <map>
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

// LEETCODE 206 (REVERSE LINKED LIST) // TIME COMPLEXCITY :- O(N)
ListNode *reverseList1(ListNode *head)
{
    ListNode *prevNode = NULL;
    ListNode *currNode = head;

    while (currNode != NULL)
    {
        ListNode *nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    return prevNode;
}

ListNode *solve(ListNode *prev, ListNode *curr) // METHOD-2
{
    // base case
    if (curr == NULL)
    {
        return prev;
    }

    ListNode *nextNode = curr->next;
    curr->next = prev;

    return solve(curr, nextNode);
}

ListNode *reverseList2(ListNode *head)
{
    ListNode *prevNode = NULL;
    ListNode *currNode = head;
    return solve(prevNode, currNode);
}

// LEETCODE 876 (MIDDLE OF THE LINKED LIST)
int getLength(ListNode *&head)
{
    int count = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
ListNode *middleNode1(ListNode *head)
{
    ListNode *result = head;
    int currPosition = 1;
    int n = getLength(head);
    int position = n / 2 + 1;
    while (currPosition != position)
    {
        result = result->next;
        currPosition++;
    }
    return result;
}

ListNode *middleNode2(ListNode *head) // METHOD-2 (TORTOISE ALGORITHM)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL) // in case we need N/2th element as mid element then condition :- fast-> next != NULL
    {
        fast = fast->next;
        if (fast != NULL) // in case we need N/2th element as mid element then condition :- fast-> next != NULL
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

// LEETCODE 234 (PALINDROME LINKED LIST)
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL) // HERE WE ARE USING THE N/2th ELEMENT
    {
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}
ListNode *reverseList(ListNode *&head)
{
    ListNode *prevNode = NULL;
    ListNode *currNode = head;

    while (currNode != NULL)
    {
        ListNode *nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    return prevNode;
}
bool compareList(ListNode *head1, ListNode *head2)
{
    while (head2 != NULL)
    {
        if (head1->val != head2->val)
        {
            return false;
        }
        else
        {
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return true;
}
bool isPalindrome(ListNode *head) // TIME COMPLEXCITY :- O(N)
{
    // break in two halves
    ListNode *middle = middleNode(head);
    // reverse second half
    ListNode *head2 = middle->next;
    middle->next = NULL;
    head2 = reverseList(head2); // HERE WE ARE MAKING CHANGES IN THE ORIGINAL DATA STRUCTURE WHICH IS A BAD PRACTISE
    // compare both linked list
    bool ans = compareList(head, head2);
    return ans;
}

// LEETCODE 141 (LINKED LIST CYCLE)
bool hasCycle(ListNode *head) // METHOD-1 (USING MAP)
{
    map<ListNode *, bool> table; // HERE WE ARE USING MAP BUT IT IS IMPORTANT THAT WE KNOW ANOTHER SOLUTION WITHOUT USING MAP
    ListNode *temp = head;

    while (temp != NULL)
    {
        if (table[temp] == false)
        {
            table[temp] = true;
        }
        else
        {
            // cycle present
            return true;
        }
        temp = temp->next;
    }
    // cycle not present
    return false;
}

bool hasCycle2(ListNode *head) // METHOD-2 (FAST-SLOW)
{
    ListNode *slow = head;
    ListNode *fast = head; // EVEN CASE NEXT ELEMENT AS MIDDLE
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
            return true;
        }
    }
    return false;
}
bool hasCycle3(ListNode *head) // METHOD-2 (FAST-SLOW)
{
    ListNode *slow = head;
    ListNode *fast = head->next; // EVEN CASE PREVIOUS ELEMENT AS MIDDLE
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
            return true;
        }
    }
    return false;
}
int main()
{
}
