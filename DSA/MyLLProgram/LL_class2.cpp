//! Doubly Linked List********************************************************************
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void printLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
 //! 1) Insert at Head in Doubly LL
void insertAtHead(Node* &head , Node* &tail , int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        // newNode = head;
        head = newNode;
    }
}
 //! 2) Insert at Tail in Doubly LL
void insertAtTail(Node* &head , Node* &tail , int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
 //! 3) Insert at Specific Position
void insertAtPosition(Node* &head , Node* &tail , int position , int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }else{
        Node* newNode = new Node(data);
        Node* prevNode = NULL;
        Node* currNode = head;
        while(position != 1){
            position--;
           prevNode = currNode;
           currNode = currNode->next;
        }
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = currNode;
        currNode->prev = newNode; 
    }
}
 //! 4) Delete from Head
void deleteFromHead(Node* &head , Node* &tail){
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
}
 //! 5) Delete from Tail
 void deleteFromTail(Node* &head , Node* &tail){
    Node* temp = tail->prev;
    temp->next = NULL;
    tail->prev = NULL;
    delete tail;
    tail = temp;
 }
 //! 6) Delete from Position
 void deleteFromPosition(Node* &head , Node* &tail , int position){
    Node* prevNode = NULL;
    Node* currNode = head;
    while(position != 1){
        position--;
        prevNode = currNode;
        currNode = currNode->next;
    }
    Node* nextNode = currNode->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    currNode->next = NULL;
    currNode->prev = NULL;
    delete currNode;
 }
 //! 7) Reverse the Linked List (Note: do tarah se reverse ker sakte hai using Iterative and using Recursion)
 Node* ReveseLL(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
//! 8) Reverse the Linked List (Recursion)
Node* ReverseRecursionLL(Node* &head , Node* &prev , Node* &curr){
    //Base case
    if(curr == NULL){
        return prev;
    }
    Node* nextNode = curr->next;
    curr->next = prev;
    ReverseRecursionLL(head , curr , nextNode);
}

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    
    Node* head = first;
    Node* tail = fourth;
    //! 1) Insert at Head in Doubly LL
    insertAtHead(head , tail , 5);
    insertAtHead(head , tail , 1);
    // printLL(head);
    //! 2) Insert at Tail in Doubly LL
    insertAtTail(head , tail , 50);
    insertAtTail(head , tail , 60);
    //printLL(head);
    //! 3) Insert at Specific Position
    insertAtPosition(head , tail , 4 , 100);
    // printLL(head);
    //! 4) Delete from Head
    deleteFromHead(head , tail);
    // printLL(head);
    //! 5) Delete from Tail
    deleteFromTail(head , tail);
    // printLL(head);
    //! 6) Delete from Position
    deleteFromPosition(head,tail,5);
    printLL(head);
    
    //! 7) Reverse the Linked List (Using Iterative method)
    // head = ReveseLL(head);
    // cout<<endl;
    // cout<<"Reverse Linked List (Loop):"<<endl;
    // printLL(head);

    //! 8) Reverse the Linked List (Using Recursion)
    Node* prev = NULL;
    Node* curr = head;
    head = ReverseRecursionLL(head , prev , curr);
    cout<<endl;
    cout<<"Reverse Linked List (Recursion)"<<endl;
    printLL(head);

    
    return 0;
}

