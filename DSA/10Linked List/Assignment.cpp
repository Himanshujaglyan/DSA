#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    int data;
    Node *next;
    Node *random;
    Node *bottom;

    Node(int _val)
    {
        val = _val;
        data = _val;
        next = NULL;
        random = NULL;
        bottom = NULL;
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode *next;
};

// GFG (DELETE N NODES AFTER M NODES OF A LINKED LIST)
void solve(Node *prev, Node *curr, int &n, int &m)
{
    if (curr == NULL)
    {
        return;
    }
    int position = 0;
    while (curr != NULL && position != m)
    {
        prev = curr;
        curr = curr->next;
        position++;
    }

    int count = 0;
    while (curr != NULL && count < n)
    {
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        curr = prev->next;
        count++;
    }
    solve(prev, curr, n, m);
}
void linkdelete(struct Node **head, int n, int m)
{
    Node *prevNode = NULL;
    Node *currNode = *head;
    solve(prevNode, currNode, n, m);
}

// LAKSHAY CODE
void deleteNode(struct Node *head, int n, int m)
{
    if (!head)
        return;
    Node *it = head;
    for (int i = 0; i < m - 1; i++)
    {
        if (!it)
            return;
        it = it->next;
    }

    if (!it)
        return;

    Node *MthNode = it;
    it = it->next;

    for (int i = 0; i < n; i++)
    {
        if (!it)
            break;
        Node *temp = it->next;
        it->next = nullptr;
        delete it;
        it = temp;
    }
    MthNode->next = it;
    deleteNode(it, n, m);
}

void linkdelete2(struct Node **head, int n, int m)
{
    deleteNode(*head, n, m);
}

// LEETCODE 21 (MERGE TWO SORTED LIST)
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) // HERE WE ARE ADDING LIST1 TO LIST 2
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    ListNode *ans = list2;
    ListNode *temp1 = list1;
    ListNode *prev1 = NULL;
    ListNode *temp2 = list2;
    ListNode *prev2 = NULL;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->val >= temp2->val) // IT WILL INCREASE THE POINTER POSITION UNTIL RIGHT POSITION IS FOUND IN LIST2
        {
            prev2 = temp2;
            temp2 = temp2->next;
        }
        else
        {
            ListNode *nextNode = temp1->next;
            temp1->next = temp2;
            if (prev2 != NULL)
                prev2->next = temp1;
            if (prev2 == NULL)
                ans = temp1;
            prev2 = temp1;
            temp1 = nextNode;
        }
    }
    if (temp2 == NULL)
    {
        prev2->next = temp1;
    }
    return ans;
}

// LAKSHAY CODE
ListNode *mergeTwoLists2(ListNode *left, ListNode *right)
{
    if (left == 0)
        return right;
    if (right == 0)
        return left;

    ListNode *ans = new ListNode(-1);
    ListNode *mptr = ans;

    while (left && right)
    {
        if (left->val <= right->val)
        {
            mptr->next = left;
            mptr = left;
            left = left->next;
        }
        else
        {
            mptr->next = right;
            mptr = right;
            right = right->next;
        }
    }

    if (left)
        mptr->next = left;
    if (right)
        mptr->next = right;

    return ans->next;
}

// HACKER RANK (GET NODE VALUE)
int getLength(SinglyLinkedListNode *&llist)
{
    SinglyLinkedListNode *temp = llist;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int getNode(SinglyLinkedListNode *llist, int positionFromTail)
{
    int length = getLength(llist);
    int position = 1;
    SinglyLinkedListNode *it = llist;
    while (position != (length - positionFromTail))
    {
        it = it->next;
        position++;
    }

    return it->data;
}

// LAKSHAY CODE
void fun(SinglyLinkedListNode *&llist, int &positionFromTail, int &ans)
{
    if (!llist)
        return;
    fun(llist->next, positionFromTail, ans);
    if (positionFromTail == 0)
    {
        ans = llist->data;
    }
    positionFromTail--;
}
int getNode2(SinglyLinkedListNode *llist, int positionFromTail)
{
    int ans = -1;
    fun(llist, positionFromTail, ans);
    return ans;
}

// LEETCODE 160 (INTERSECTION OF TWO LINKED LIST)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *a = headA;
    ListNode *b = headB;

    while (a->next && b->next)
    {
        if (a == b)
        {
            return a;
        }
        a = a->next;
        b = b->next;
    }

    if (a->next)
    {
        // list A is bigger
        int lenA = 0;
        while (a->next)
        {
            a = a->next;
            lenA++;
        }

        while (lenA--)
        {
            headA = headA->next;
        }
    }
    else
    {
        // list B is bigger
        int lenB = 0;
        while (b->next)
        {
            b = b->next;
            lenB++;
        }

        while (lenB--)
        {
            headB = headB->next;
        }
    }

    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
}

// LEETCODE 148 (SORT LIST)

ListNode *findMid(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode *mergeLL(ListNode *&left, ListNode *&right)
{
    if (left == 0)
        return right;
    if (right == 0)
        return left;

    ListNode *ans = new ListNode(-1);
    ListNode *mptr = ans;

    while (left && right)
    {
        if (left->val <= right->val)
        {
            mptr->next = left;
            mptr = left;
            left = left->next;
        }
        else
        {
            mptr->next = right;
            mptr = right;
            right = right->next;
        }
    }

    if (left)
        mptr->next = left;
    if (right)
        mptr->next = right;

    return ans->next;
}

ListNode *sortList(ListNode *head)
{
    if (head == nullptr || head->next == NULL)
    {
        return head;
    }

    ListNode *mid = findMid(head);
    ListNode *left = head;
    ListNode *right = mid->next;
    mid->next = NULL;

    left = sortList(left);
    right = sortList(right);

    return mergeLL(left, right);
}

// GFG (FLATTENING LINKED LIST)
Node *merge(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    Node *ans = 0;

    if (a->data < b->data)
    {
        ans = a;
        a->bottom = merge(a->bottom, b);
    }
    else
    {
        ans = b;
        b->bottom = merge(a, b->bottom);
    }
    return ans;
}

Node *flatten(Node *root)
{
    if (!root)
        return 0;
    return merge(root, flatten(root->next));
}

// LEETCODE 138 (COPY LIST WITH RANDOM POINTERS)
Node *helper(Node *head, unordered_map<Node *, Node *> &mp)
{
    if (head == 0)
        return 0;

    Node *newHead = new Node(head->val);
    mp[head] = newHead;
    newHead->next = helper(head->next, mp);
    if (head->random)
    {
        newHead->random = mp[head->random];
    }
    return newHead;
}

Node *copyRandomList(Node *head) // TIME COMPLEXCITY :- O(N) || SPACE COMPLEXCITY :- O(N) + O(N)
{
    unordered_map<Node *, Node *> mp;
    return helper(head, mp);
}

// ANOTHER APPROACH WITHOUT MAP BY CLONING
Node *copyRandomList(Node *head)
{
    if (!head)
        return 0;

    // CLONING THE NODES
    Node *it = head;
    while (it)
    {
        Node *cloneNode = new Node(it->val);
        cloneNode->next = it->next;
        it->next = cloneNode;
        it = it->next->next;
    }

    // ASSIGNING THE RANDOM LINKS
    it = head;
    while (it)
    {
        Node *cloneNode = it->next;
        cloneNode->random = it->random ? it->random->next : NULL;
        it = it->next->next;
    }

    // DEATTACH THE CLONED LL

    it = head;
    Node *cloneLL = it->next;

    while (it)
    {
        Node *cloneNode = it->next;
        it->next = it->next->next;
        if (cloneNode->next)
            cloneNode->next = cloneNode->next->next;
        it = it->next;
    }

    return cloneLL;
}

// LEETCODE 61 (ROTATE LIST)
int getLength(ListNode *&head)
{
    ListNode *temp = head;
    int count = 0;
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == 0 || k == 0)
        return head;
    int length = getLength(head);
    k %= length;
    if (k == 0)
        return head;
    ListNode *it = head;
    int position = 1;
    while (position < (length - k))
    {
        it = it->next;
        position++;
    }
    ListNode *nextNode = it->next;
    it->next = NULL;
    ListNode *ans = nextNode;
    while (nextNode->next != NULL)
    {
        nextNode = nextNode->next;
    }
    nextNode->next = head;
    return ans;
}

// LEETCODE 2058 (FIND THE MINIMUM & MAXIMUM NUMBER OF NODES BETWEEN CRITICAL POINTS)
vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL ||
        head->next->next->next == NULL)
    {
        return vector<int>(2, -1);
    }
    ListNode *it = head->next;
    int previous = head->val;
    int next = it->next->val;
    int count = 0;
    while (it->next != NULL)
    {
        next = it->next->val;
        if (it->val > previous && it->val > next)
        {
            previous = it->val;
            it->val = 0;
            count++;
        }
        else if (it->val < previous && it->val < next)
        {
            previous = it->val;
            it->val = 0;
            count++;
        }
        else
        {
            previous = it->val;
        }
        it = it->next;
    }
    if (count < 2)
        return vector<int>(2, -1);

    int maximum = 0;
    int minimum = 0;
    int ans1 = INT_MAX;
    int ans2 = INT_MIN;
    bool flag = 0;
    it = head->next;
    while (it->next != NULL)
    {
        if (it->val == 0 && flag == 1)
        {
            ans1 = min(ans1, minimum);
            ans2 = max(ans2, maximum);
            minimum = 0;
        }
        if (it->val == 0 && flag == 0)
        {
            flag = 1;
        }
        if (flag == 1)
        {
            maximum++;
            minimum++;
        }
        it = it->next;
    }
    vector<int> ans = {ans1, ans2};
    return ans;
}

// LAKSHAY CODE
vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    vector<int> ans = {-1, -1}; // minDis maxDis
    ListNode *prev = head;
    if (!prev)
        return ans;
    ListNode *curr = head->next;
    if (!curr)
        return ans;
    ListNode *nxt = head->next->next;
    if (!nxt)
        return ans;

    int i = 1;
    int minDis = INT_MAX;
    int maxDis = INT_MIN;
    int firstCP = -1;
    int lastCP = -1;

    while (nxt)
    {
        bool isCP =
            ((curr->val > prev->val) && (curr->val > nxt->val)) ||
                    ((curr->val < prev->val) && (curr->val < nxt->val))
                ? true
                : false;

        if (isCP && firstCP == -1)
        {
            firstCP = i;
            lastCP = i;
        }
        else if (isCP)
        {
            minDis = min(minDis, i - lastCP);
            lastCP = i;
        }
        ++i;
        prev = prev->next;
        curr = curr->next;
        nxt = nxt->next;
    }

    if (firstCP == lastCP)
        return ans;

    ans[0] = minDis;
    ans[1] = lastCP - firstCP;

    return ans;
}

// LEETCODE 2181 (MERGE NODES IN BETWEEN ZEROS)
ListNode *mergeNodes(ListNode *head)
{
    ListNode *curr = head->next;
    while (curr)
    {
        ListNode *nxt = curr->next;
        if (nxt->val == 0)
        {
            curr->next = nxt->next;
            nxt->next = NULL;
            delete nxt;
            curr = curr->next;
        }
        else
        {
            curr->val += nxt->val;
            curr->next = nxt->next;
            nxt->next = NULL;
            delete nxt;
        }
    }
    return head->next;
}

// LAKSHAY CODE
ListNode *mergeNodes(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;
    ListNode *lastNode = NULL;
    int sum = 0;
    while (fast)
    {
        if (fast->val != 0)
        {
            sum += fast->val;
        }
        else
        {
            slow->val = sum;
            lastNode = slow;
            slow = slow->next;
            sum = 0;
        }
        fast = fast->next;
    }
    lastNode->next = NULL;
    while (slow)
    {
        ListNode *nxt = slow->next;
        delete slow;
        slow = nxt;
    }
    return head;
}

// LEETCODE 328 (ODD EVEN LINKED LIST)
ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = even;
    ListNode *prevOdd = NULL;
    while (odd != NULL && even != NULL)
    {
        odd->next = even->next;
        prevOdd = odd;
        odd = odd->next;
        if (odd)
        {
            even->next = odd->next;
            even = even->next;
        }
    }
    if (odd)
        odd->next = evenHead;
    else
        prevOdd->next = evenHead;
    return head;
}
// LAKSHAY CODE
ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = even;
    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

// LEETCODE 2816 (DOUBLE A NUMBER REPRESENTED AS A LINKED LIST)
ListNode *doubleIt(ListNode *head)
{
    int carry = twice(head);
    if (carry > 0)
    {
        head = new ListNode(carry, head);
    }
    return head;
}

int twice(ListNode *head)
{
    if (head == nullptr)
    {
        return 0;
    }
    int doubleValue = head->val * 2 + twice(head->next);
    head->val = doubleValue % 10;
    return doubleValue / 10;
}

// LAKSHAY CODE
void solve(ListNode *head, int &carry)
{
    if (!head)
        return;
    solve(head->next, carry);
    int prod = head->val * 2 + carry;
    head->val = prod % 10;
    carry = prod / 10;
}

ListNode *doubleIt(ListNode *head)
{
    int carry = 0;
    solve(head, carry);
    if (carry)
    {
        ListNode *newNode = new ListNode(carry);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// LEETCODE 1721 (SWAPPING NODES IN A LINKED LIST)
void solve(ListNode *head, int &k, ListNode *&last)
{
    if (!head)
        return;
    solve(head->next, k, last);
    if (k == 0)
    {
        last = head;
    }
    k--;
}

ListNode *swapNodes(ListNode *head, int k)
{
    ListNode *h1 = head;
    ListNode *h2 = head;
    int count = k - 1;
    solve(head, count, h2);

    while (k != 1)
    {
        k--;
        h1 = h1->next;
    }
    swap(h1->val, h2->val);
    return head;
}

// LAKSHAY CODE
int getLength1(ListNode *head)
{
    if (!head)
        return 0;
    return 1 + getLength1(head->next);
}

ListNode *swapNodes(ListNode *head, int k)
{
    // case-1
    if (!head || !head->next)
        return head;

    int len = getLength1(head);
    // case-2
    if (len == 2)
    {
        ListNode *nextNode = head->next;
        nextNode->next = head;
        head->next = NULL;
        head = nextNode;
        return head;
    }

    int lpos = k;
    int rpos = len - k + 1;
    if (lpos > rpos)
        swap(lpos, rpos);

    // case-3
    if (lpos == rpos)
        return head;

    // case-4
    if (lpos == 1)
    {
        ListNode *lp = 0;
        ListNode *ln = head;
        ListNode *rp = head;
        for (int i = 0; i < rpos - 2; i++)
        {
            rp = rp->next;
        }
        ListNode *rn = rp->next;
        ListNode *rsave = rn->next;

        rn->next = ln->next;
        rp->next = ln;
        ln->next = rsave;

        head = rn;
        return head;
    }

    // case-5
    int noOfNodesBetweenSwapNodes = rpos - lpos - 1;

    if (noOfNodesBetweenSwapNodes == 0)
    {
        ListNode *lp = head;
        for (int i = 0; i < lpos - 2; i++)
        {
            lp = lp->next;
        }
        ListNode *ln = lp->next;
        ListNode *rp = head;
        for (int i = 0; i < rpos - 2; i++)
        {
            rp = rp->next;
        }
        ListNode *rn = rp->next;
        ListNode *rsave = rn->next;

        lp->next = rn;
        rn->next = ln;
        ln->next = rsave;

        return head;
    }
    else
    {
        // case-6
        ListNode *lp = head;
        for (int i = 0; i < lpos - 2; i++)
        {
            lp = lp->next;
        }
        ListNode *ln = lp->next;
        ListNode *rp = head;
        for (int i = 0; i < rpos - 2; i++)
        {
            rp = rp->next;
        }
        ListNode *rn = rp->next;
        ListNode *rsave = rn->next;

        lp->next = rn;
        rn->next = ln->next;
        rp->next = ln;
        ln->next = rsave;

        return head;
    }
}

// LEETCODE 1171 (REMOVE ZERO SUM CONSECUTIVE NODES FROM LINKED LIST)
ListNode *removeZeroSumSublists(ListNode *head)
{
    if (!head)
        return 0;
    head->next = removeZeroSumSublists(head->next);
    ListNode *slow = head;
    ListNode *fast = head;
    int sum = 0;
    while (fast)
    {
        sum += fast->val;
        if (sum == 0)
        {
            ListNode *nextNode = fast->next;
            fast->next = NULL;
            head = nextNode;
            fast = nextNode;
        }
        else
        {
            fast = fast->next;
        }
    }
    return head;
}

// LAKSHAY CODE
void sanitize(ListNode *head, unordered_map<int, ListNode *> &mp, int csum)
{
    int temp = csum;
    while (true)
    {
        temp += head->val;
        if (temp == csum)
            break;
        mp.erase(temp);
        head = head->next;
    }
}

ListNode *removeZeroSumSublists(ListNode *head)
{
    if (!head || (!head->next && head->val == 0))
        return 0;
    unordered_map<int, ListNode *> mp;
    ListNode *it = head;
    int csum = 0;
    while (it)
    {
        csum += it->val;
        if (csum == 0)
        {
            head = it->next;
            mp.clear();
        }
        else if (mp.find(csum) != mp.end())
        {
            sanitize(mp[csum]->next, mp, csum);
            mp[csum]->next = it->next;
        }
        else
        {
            mp[csum] = it;
        }
        it = it->next;
    }
    return head;
}
int main()
{

    return 0;
}
