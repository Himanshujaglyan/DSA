#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;//.just for doubly linked list
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void PrintLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int FindLLlen(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
Node* InsertatHead(Node* head , int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}
void InsertatTail(Node* head , Node* tail , int data){
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
void InsertAtanyPosition(Node* head , int data , int position){
    Node* newNode = new Node(data);
    Node* left = NULL;
    Node* curr = head;
    while(position != 1){
        position--;
        left = curr;
        curr = curr->next;
    }

    left->next = newNode;
    newNode->prev = left;
    newNode->next = curr;
    curr->prev = newNode;
    
}
Node* DeleteFromHead(Node* &head){
    Node* temp = head;
    head = temp->next;
    temp->next = NULL;
    delete temp;
    return head;
}
void DeleteFromNode(Node* &head , Node* &tail){
    Node* temp = head;
    while(temp->next != tail){
        temp = temp->next;
    }
    temp->next = NULL;
    delete tail;
    tail = temp;
}
void DeleteFromAnyPosition(Node* &head , int position){
    Node* prevNode = NULL;
    Node* currNode = head;
    while(position != 1){
        position--;
        prevNode = currNode;
        currNode = currNode->next;
    }
    prevNode->next = currNode->next;
    currNode->next->prev = prevNode;
}

int main(){
    //Create Nodes for doubly linked list
    Node* head = new Node(10);
    Node* first = new Node(20);
    Node* second = new Node(30);
    Node* third = new Node(40);
    Node* tail = new Node(50);

    head->next = first;
    head->prev = NULL;
    first->next = second;
    first->prev = head;
    second->next=third;
    second->prev = first;
    third->next = tail;
    third->prev = second;
    
    //! Print Doubly Linked list
    PrintLL(head);
    //! Insert at Head in Doubly Linked list
    // head = InsertatHead(head,5);
    // PrintLL(head);
    //! Insert at Tail in Doubly Linked list
    //InsertatTail(head,tail,100);
    //PrintLL(head);
    //! Insert at any position in Doubly linked list
    // InsertAtanyPosition(head,100,3);
    // PrintLL(head);
    //! Delete at Head of doubly linked list
    // head = DeleteFromHead(head);
    // PrintLL(head);
    //! Delete from tail of Doubly linked list
    // DeleteFromNode(head , tail);
    // PrintLL(head);
    //! Delete from any Position in Doubly linked list
    // DeleteFromAnyPosition(head , 3);
    // PrintLL(head);
   
    return 0;
} 




























