#include <iostream>
#include <queue>
#include <deque>
using namespace std;

class Queue
{
public:
    int *arr = 0;
    int size;
    int front;
    int rear;

    Queue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int val)
    {
        // overflow
        if (rear == size - 1)
        {
            cout << "Queue Overflow." << endl;
            return;
        }
        // empty
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        // normal case
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    void pop()
    {
        // underflow
        if (front == -1 && rear == -1)
        {
            cout << "Queue underflow." << endl;
            return;
        }
        // Single element
        if (front == rear)
        {
            arr[front] = -1;
            front = rear = -1;
        }
        // normal case
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    int getSize()
    {
        if (front == -1 && rear == -1)
        {
            return 0;
        }
        else
        {
            return rear - front + 1;
        }
    }

    int getFront()
    {
        if (front == -1)
        {
            cout << "Queue is Empty." << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    int getRear()
    {
        if (rear == -1)
        {
            cout << "Queue is Empty." << endl;
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }

    void print()
    {
        cout << "Printing Queue : ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Queue()
    {
        cout << "Destructor Called" << endl;
        delete[] arr;
    }
};

class Cqueue
{
public:
    int *arr = 0;
    int size;
    int front;
    int rear;

    Cqueue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = rear = -1;
    }

    void push(int val)
    {
        // overflow
        if (front == (rear + 1) % size) // MODULO IS A HEAVY OPERATION SO TRY TO AVOID IT
        {
            cout << "Queue overflow." << endl;
            return;
        }
        // single element
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else
        {
            rear = (rear + 1) % size; // WHENEVER WE MODULO A NUMBER BY N THEN ANSWER WILL COME INBETWEEN (0 TO N-1)
            arr[rear] = val;
        }
    }

    void pop()
    {
        // underflow
        if (front == -1 && rear == -1)
        {
            cout << "Queue underflow." << endl;
            return;
        }
        // single element
        if (front == rear)
        {
            arr[front] = -1;
            front = rear = -1;
        }
        else
        {
            arr[front] = -1;
            front = (front + 1) % size;
        }
    }
    void print()
    {
        cout << "Front:" << front << " Rear:" << rear << endl;
        cout << "Printing Queue : ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void pushBack(int val)
    {
        if (rear == size - 1)
        {
            cout << "Queue Overflow." << endl;
            return;
        }
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    void pushFront(int val)
    {
        if (front == 0)
        {
            cout << "Overflow." << endl;
            return;
        }
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[front] = val;
        }
        else
        {
            front--;
            arr[front] = val;
        }
    }

    void popFront()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue Underflow." << endl;
            return;
        }
        if (front == rear)
        {
            arr[front] = -1;
            front = rear = -1;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    void popBack()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Underflow." << endl;
            return;
        }
        if (front == rear)
        {
            arr[rear] = -1;
            front = rear = -1;
        }
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }
};

class Cdeque
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Cdeque(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void pushBack(int val)
    {
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            cout << "Queue Overflow." << endl;
            return;
        }
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    void pushFront(int val)
    {
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            cout << "Overflow." << endl;
            return;
        }
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[front] = val;
        }
        else
        {
            front--;
            arr[front] = val;
        }
    }

    void popFront()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue Underflow." << endl;
            return;
        }
        if (front == rear)
        {
            arr[front] = -1;
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    void popBack()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Underflow." << endl;
            return;
        }
        if (front == rear)
        {
            arr[front] = -1;
            front = rear = -1;
        }
        else if (rear == 0)
        {
            arr[rear] = -1;
            rear = size - 1;
        }
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }
};
int main()
{
    {
        queue<int> q;

        // insertion
        q.push(5);

        // size
        cout << "Size of Queue: " << q.size() << endl;

        // empty
        if (q.empty() == true)
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            cout << "Queue is not empty." << endl;
        }

        // deletion
        q.pop();

        cout << "Size of Queue: " << q.size() << endl;

        if (q.empty() == true)
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            cout << "Queue is not empty." << endl;
        }

        q.push(10);
        q.push(20);
        q.push(30);

        cout << "First element of queue is : " << q.front() << endl;// front element
        cout << "Last element of queue is : " << q.back() << endl;// rear element
    }

    {
        Queue q(5);
        q.print();

        q.push(10);
        q.print();

        q.push(20);
        q.print();

        q.push(30);
        q.print();

        q.push(40);
        q.print();

        q.push(50);
        q.print();

        cout << "Size of Queue is : " << q.getSize() << endl;

        q.pop();
        q.print();

        cout << "Size of Queue is : " << q.getSize() << endl;
        cout << "Queue is empty or not : " << q.isEmpty() << endl;

        q.push(100);
        q.print();

        q.pop();
        q.pop();
        q.pop();
        q.print();

        cout << "Front element is : " << q.getFront() << endl;

        q.pop();
        q.print();

        cout << "Size of Queue is : " << q.getSize() << endl;
    }

    {
        Cqueue q(5);
        q.print();

        q.push(10);
        q.print();

        q.push(20);
        q.print();

        q.push(30);
        q.print();

        q.push(40);
        q.print();

        q.push(50);
        q.print();

        q.push(60);
        q.print();

        q.pop();
        q.pop();
        q.print();

        q.push(60);
        q.print();

        q.push(70);
        q.print();

        q.push(80);
        q.print();

        q.pop();
        q.print();
        q.pop();
        q.print();
        q.pop();
        q.print();
        q.pop();
        q.print();
        q.pop();
        q.print();
        q.pop();
        q.print();
    }

    {
        deque<int> dq;

        dq.push_back(10);
        cout << dq.front() << endl;
        cout << dq.back() << endl;
        cout << "Size : " << dq.size() << endl;

        dq.push_front(20);
        cout << dq.front() << endl;
        cout << dq.back() << endl;
        cout << "Size : " << dq.size() << endl;

        dq.pop_front();
        cout << dq.front() << endl;
        cout << dq.back() << endl;
        cout << "Size : " << dq.size() << endl;

        dq.pop_back();
        cout << dq.front() << endl;
        cout << dq.back() << endl;
        cout << "Size : " << dq.size() << endl;
    }

    return 0;
}