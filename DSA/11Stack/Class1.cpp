#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        arr = new int[size];
        this->top = -1;
        this->size = size;
    }

    bool isEmpty()
    {
        return top == -1 ? true : false;
    }

    void push(int data)
    {
        if (top >= size - 1)
            cout << "Stack Overflow" << endl;
        else
        {
            top++;
            arr[top] = data;
        }
    }

    void pop()
    {
        if (top == -1)
            cout << "Stack Underflow" << endl;
        else
        {
            top--;
        }
    }

    int getSize()
    {
        return top + 1;
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    void print()
    {
        cout << endl;
        cout << "Top : " << top << endl;
        cout << "Top Element : " << getTop() << endl;
        cout << "Stack : ";
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void getMiddleElementHelper(stack<int> &st, int &pos, int &ans)
{
    if (pos == 1)
    {
        ans = st.top();
        return;
    }

    pos--;
    int temp = st.top();
    st.pop();

    getMiddleElementHelper(st, pos, ans);

    st.push(temp);
}
int getMiddleElement(stack<int> &st) // TIME COMPLEXCITY :- O(N)
{
    if (st.empty())
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    int size = st.size();
    int position = size & 1 ? (size / 2 + 1) : (size / 2);
    int ans = -1;
    getMiddleElementHelper(st, position, ans);
    return ans;
}

void insertAtBottom(stack<int> &st, int &element) // TIME COMPLEXCITY :- O(N)
{
    if (st.empty())
    {
        st.push(element);
        return;
    }

    int temp = st.top();
    st.pop();

    insertAtBottom(st, element);

    st.push(temp);
}

void reverseAStack(stack<int> &st) // TIME COMPLEXCITY :- O(N2)
{
    if (st.empty())
    {
        return;
    }
    int temp = st.top();
    st.pop();
    reverseAStack(st);

    insertAtBottom(st, temp);
}

void insertInSortedStack(stack<int> &st, int &element) // TIME COMPLEXCITY :- O(N)
{
    if (st.empty() || element > st.top())
    {
        st.push(element);
        return;
    }

    int temp = st.top();
    st.pop();

    insertInSortedStack(st, element);

    st.push(temp);
}

void sortStack(stack<int> &st) // TIME COMPLEXCITY :- O(N2)
{
    if (st.empty())
    {
        return;
    }
    int temp = st.top();
    st.pop();

    sortStack(st);

    insertInSortedStack(st, temp);
}
int main()
{

    // {
    //     stack<int> st;
    //     cout << st.size() << endl;
    //     // cout << st.top() << endl;// segmentation fault
    //     cout << st.empty() << endl;

    //     st.push(10);
    //     st.push(20);
    //     st.push(30);

    //     cout << "Size of stack is : " << st.size() << endl;
    //     cout << "Top of stack is : " << st.top() << endl;

    //     st.pop();

    //     cout << "Size of stack is : " << st.size() << endl;
    //     cout << "Top of stack is : " << st.top() << endl;
    //     st.pop();

    //     cout << "Size of stack is : " << st.size() << endl;
    //     cout << "Top of stack is : " << st.top() << endl;
    //     st.pop();

    //     cout << "Size of stack is : " << st.size() << endl;
    //     cout << "Top of stack is : " << st.top() << endl;
    //     st.pop();

    //     cout << "Size of stack is : " << st.size() << endl;
    //     cout << "Top of stack is : " << st.top() << endl;
    // }

    // {
    //     Stack st(8);

    //     st.push(10);
    //     st.print();

    //     st.push(20);
    //     st.print();

    //     st.push(30);
    //     st.print();

    //     st.pop();
    //     st.print();

    //     st.pop();
    //     st.print();

    //     st.pop();
    //     st.print();

    //     st.pop();
    //     st.print();

    //     st.push(10);
    //     st.push(20);
    //     st.push(30);
    //     st.push(40);
    //     st.push(50);
    //     st.push(60);
    //     st.push(70);
    //     st.push(80);
    //     st.push(90);
    //     st.print();

    //     cout << "Top Element is : " << st.getTop() << endl;
    //     cout << "Size of stack is : " << st.getSize() << endl;
    //     if (st.isEmpty())
    //         cout << "Empty." << endl;
    //     else
    //         cout << "Not Empty." << endl;
    // }

    // {
    //     string str = "HelloWorld";
    //     stack<char> s;
    //     for (int i = 0; i < str.length(); i++)
    //     {
    //         s.push(str[i]);
    //     }
    //     while (!s.empty())
    //     {
    //         cout << s.top();
    //         s.pop();
    //     }
    //     cout << endl;

    //     stack<int> st;
    //     st.push(10);
    //     st.push(20);
    //     st.push(30);
    //     st.push(40);
    //     st.push(50);
    //     st.push(60);
    //     cout << "Middle Element is : " << getMiddleElement(st) << endl;
    //     int element = 400;
    //     insertAtBottom(st, element);
    //     reverseAStack(st);
    //     while (!st.empty())
    //     {
    //         cout << st.top() << " ";
    //         st.pop();
    //     }

    //     stack<int> st;
    //     st.push(10);
    //     st.push(20);
    //     st.push(30);
    //     int element = 13;
    //     insertInSortedStack(st, element);

    //     while (!st.empty())
    //     {
    //         cout << st.top() << " ";
    //         st.pop();
    //     }

    //     stack<int> st;
    //     st.push(10);
    //     st.push(5);
    //     st.push(17);
    //     st.push(36);
    //     st.push(88);
    //     st.push(3);
    //     sortStack(st);
    //     while (!st.empty())
    //     {
    //         cout << st.top() << " ";
    //         st.pop();
    //     }
    // }

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl;

    st.top() = 50;

    cout << st.top() << endl;

    stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);

    while (!s1.empty())
    {
        s1.pop();
    }
    return 0;
}