#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        cout << "Destructor called for  : " << this->data << endl;
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    cout << "Printing Linked List : ";
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node *head)
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

void insertAtHead(Node *&head, Node *&tail, int data) // pass head node by reference
{
    if (head == NULL)
    {
        // empty LL

        // create new Node
        Node *newNode = new Node(data);
        // update head
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Non-empty LL

        // create new Node
        Node *newNode = new Node(data);
        // attach new node to head node
        newNode->next = head;
        // update head
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // empty LL

        // create a new Node
        Node *newNode = new Node(data);
        // update head and tail node
        head = newNode;
        tail = newNode;
    }
    else
    {
        // non-empty LL

        // create a new node
        Node *newNode = new Node(data);
        // attach tail to new Node
        tail->next = newNode;
        // update tail
        tail = newNode;
    }
}

void createTail(Node *&head, Node *&tail)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    int length = getLength(head);
    if (position <= 1)
    {
        insertAtHead(head, tail, data);
    }
    else if (position > length)
    {
        insertAtTail(head, tail, data);
    }
    // else
    // {
    //     // Insert At Middle

    //     // create a New Node
    //     Node *newNode = new Node(data);

    //     // traverse previous/ current to position
    //     Node *prev = NULL;
    //     Node *current = head;

    //     while (position != 1)
    //     {
    //         prev = current;
    //         current = current->next;
    //         position--;
    //     }

    //     // attach previous to new node
    //     prev->next = newNode;

    //     // attach to new node to current
    //     newNode->next = current;
    // }
    else
    {
        // using previous pointer only
        Node *newNode = new Node(data);
        Node *prev = head;

        while (position != 2)
        {
            prev = prev->next;
            position--;
        }

        newNode->next = prev->next;
        prev->next = newNode;
    }
}

void deleteAtPosition(Node *&head, Node *&tail, int position)
{
    // TO DELETE A NODE FIRST COMPLETELY ISOLATE THAT NODE (MAKING ALL NEXT AND PREVIOUS POINTER NULL & NO OTHER NODE IS POINTING TO THAT NODE)

    if (head == NULL) // empty linked list
    {
        cout << "Linked List in empty." << endl;
        return;
    }

    if (head == tail)
    {
        // single element
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    else if (position == 1) // delete from head
    {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
    else if (position == getLength(head)) // delete from tail
    {
        Node *prev = head;
        while (prev->next != tail)
        {
            prev = prev->next;
        }
        prev->next = NULL;
        delete tail;
        tail = prev;
    }
    else // delete from inbetween
    {
        Node *prev = NULL;
        Node *curr = head;
        while (position != 1)
        {
            position--;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    {
        // Creation Of The Node
        // Node a;// static allocation

        Node *first = new Node(10); // dynamic allocation
        Node *second = new Node(20);
        Node *third = new Node(30);
        Node *fourth = new Node(40);
        Node *fifth = new Node(50);

        first->next = second;
        second->next = third;
        third->next = fourth;
        fourth->next = fifth;

        Node *head = first;
        Node *tail = fifth;

        printLL(head);

        cout << "Length of Linked List : " << getLength(head) << endl;

        insertAtHead(head, tail, 0);

        printLL(head);

        insertAtTail(head, tail, 60);

        printLL(head);
    }

    {
        Node *head = NULL;
        Node *tail = NULL;

        insertAtHead(head, tail, 10);
        insertAtTail(head, tail, 20);
        insertAtTail(head, tail, 30);
        insertAtTail(head, tail, 50);

        printLL(head);

        insertAtPosition(head, tail, 40, 4);

        printLL(head);

        deleteAtPosition(head, tail, 1);

        printLL(head);
    }

    return 0;
}