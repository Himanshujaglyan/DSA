#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// LEETCODE 2 (ADD TWO NUMBERS)
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode(-1);
    ListNode *it = ans;
    int carry = 0;
    while (l1 || l2 || carry)
    {
        int a = l1 ? l1->val : 0;
        int b = l2 ? l2->val : 0;
        int sum = a + b + carry;
        int digit = sum % 10;
        carry = sum / 10;
        it->next = new ListNode(digit);
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
        it = it->next;
    }
    ListNode *finalAns = ans->next;
    delete ans;
    return finalAns;
}

int main()
{
    return 0;
}