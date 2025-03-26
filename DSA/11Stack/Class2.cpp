#include <iostream>
#include <stack>
using namespace std;

// IMPLEMENT TWO STACK USING SINGLE ARRAY
class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
    }

    void push1(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top1++;
        arr[top1] = data;
    }
    void push2(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top2--;
        arr[top2] = data;
    }
    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack Underflow." << endl;
            return;
        }
        arr[top1] = 0;
        top1--;
    }
    void pop2()
    {
        if (top2 == size)
        {
            cout << "Stack Underflow." << endl;
            return;
        }
        arr[top2] = 0;
        top2++;
    }
    void print()
    {
        cout << endl;
        cout << "Top1 : " << top1 << endl;
        cout << "Top2 : " << top2 << endl;
        cout << "Stack : ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// LEETCODE 20 (VALID PARENTHESES)
bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            else
            {
                if (ch == ')' && st.top() == '(')
                {
                    st.pop();
                }
                else if (ch == ']' && st.top() == '[')
                {
                    st.pop();
                }
                else if (ch == '}' && st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    return false;
}

// REDUNDANT BRACKETS
bool checkRedundant(string &str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            int operatorCount = 0;
            while (st.top() != '(')
            {
                operatorCount++;
                st.pop();
            }
            if (operatorCount == 0)
            {
                return true;
            }
            st.pop();
        }
    }
    return false;
}
int main()
{

    {
        string str = "((a + b) * (c + d))";
        bool ans = checkRedundant(str);
        if (ans)
        {
            cout << "Redundant Brackets present." << endl;
        }
        else
        {
            cout << "Redundant brackets not present." << endl;
        }
    }

    // {
    //     Stack st(6);
    //     st.print();

    //     st.push1(10);
    //     st.print();

    //     st.push1(20);
    //     st.print();

    //     st.push2(100);
    //     st.print();

    //     st.push2(200);
    //     st.print();

    //     st.push2(300);
    //     st.print();

    //     st.push2(400);
    //     st.print();

    //     st.push2(400);
    //     st.print();

    //     st.pop1();
    //     st.print();

    //     st.pop1();
    //     st.print();

    //     st.pop1();
    //     st.print();

    //     st.pop2();
    //     st.print();
    // }
    return 0;
}