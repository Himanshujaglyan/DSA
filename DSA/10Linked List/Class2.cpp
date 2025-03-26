#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *previous;
    Node *next;

    Node()
    {
        this->previous = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->previous = NULL;
        this->next = NULL;
    }
};

void printDLL(Node *&head)
{
    Node *temp = head;
    cout << "Printing Doubly Linked List : ";
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int getLengthDLL(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // empty linked list
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    else
    {
        // non-empty linked list
        Node *newNode = new Node(data);
        newNode->next = head;
        head->previous = newNode;
        head = newNode; // head = head-> prev;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // empty linked list
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        // non-empty linked list
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{

    if (position <= 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    else if (position > getLengthDLL(head))
    {
        insertAtTail(head, tail, data);
        return;
    }
    else
    {
        Node *newNode = new Node(data);
        Node *prev = NULL;
        Node *curr = head;

        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }

        prev->next = newNode;
        newNode->previous = prev;
        newNode->next = curr;
        curr->previous = newNode;
    }
}

void deleteAtPosition(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << "Linked List is empty." << endl;
        return;
    }

    if (head == tail)
    {
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    if (position <= 1)
    {
        Node *temp = head;
        head = temp->next;
        head->previous = NULL;
        temp->next = NULL;
        delete temp;
    }
    else if (position >= getLengthDLL(head))
    {
        Node *prev = tail->previous;
        prev->next = NULL;
        tail->previous = NULL;
        delete tail;
        tail = prev;
    }
    else
    {
        Node *prevNode = NULL;
        Node *currNode = head;

        while (position != 1)
        {
            prevNode = currNode;
            currNode = currNode->next;
            position--;
        }
        Node *nextNode = currNode->next;
        prevNode->next = nextNode;
        nextNode->previous = prevNode;
        currNode->next = NULL;
        currNode->previous = NULL;
        delete currNode;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);

    printDLL(head);

    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);

    printDLL(head);

    insertAtPosition(head, tail, 0, 2);

    printDLL(head);

    deleteAtPosition(head, tail, 1);
    deleteAtPosition(head, tail, 2);
    deleteAtPosition(head, tail, 3);
    deleteAtPosition(head, tail, 2);
    deleteAtPosition(head, tail, 1);
    deleteAtPosition(head, tail, 1);

    printDLL(head);
    return 0;
}