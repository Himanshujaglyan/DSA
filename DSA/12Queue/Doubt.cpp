#include <iostream>
using namespace std;

// LEETCODE 641 (DESIGN CIRCULAR DEQUE)
class MyCircularDeque
{
public:
    int size, front, rear, *arr;

    MyCircularDeque(int k)
    {
        size = k;
        front = rear = -1;
        arr = new int[k];
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = value;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        arr[front] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        arr[rear] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
            return true;
        return false;
    }
};

// LEETCODE 622 (DESIGN CIRCULAR QUEUE)
class MyCircularQueue
{
public:
    int front;
    int rear;
    int size;
    int *arr;
    MyCircularQueue(int k)
    {
        size = k;
        front = rear = -1;
        arr = new int[k];
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        arr[front] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        else
            return arr[front];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        else
            return arr[rear];
    }

    bool isEmpty() { return (front == -1 && rear == -1); }

    bool isFull()
    {
        return ((front == 0 && rear == size - 1) || (rear == front - 1));
    }
};
int main()
{

    return 0;
}