#include<bits/stdc++.h>
using namespace std;
//!create Node by creating class
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node(){
//         this->data = 0;
//         this->next = NULL;
//     }
//     Node(int data){
//         this->data = data;
//         this->next = NULL;
//     }
// };
// void PrintLL(Node* head){
//     Node* temp = head;
//     while(temp != NULL){
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
// }

//!Insert on Head and Tail
class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void InsertatHead(Node* &head , int data){
    //In Three steps we can insert a new node on head of linked list
    //Step1 Create a Node
    Node* newNode = new Node(data);
    //Step connect newNode next to head of linked list
    newNode->next = head;
    //Step update head by newNode
    head = newNode;
}

void PrintLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void InsertatTail(Node* &head , int data){
    Node* newNode = new Node(data);
    head->next = newNode;
    newNode = head;
}

int main(){
    //!Manually create and connect Nodes
    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(40);
    // Node* fifth = new Node(50);
    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    // cout<<"Print Linked List:"<<endl;
    // PrintLL(first);    

    //!Insert on Head and Tail
    Node* head = NULL;
    InsertatHead(head,10);
    InsertatHead(head,20);
    InsertatHead(head,30);
    InsertatHead(head,40);
    InsertatHead(head,50);
    cout<<"Print NewNode on Head of Linked list: "<<endl;
    PrintLL(head);
//--------Insert at Tail--------------------------
    Node* head1 = NULL;
    InsertatTail(head1,1);
    InsertatTail(head1,2);
    InsertatTail(head1,3);
    InsertatTail(head1,4);
    InsertatTail(head1,5);
    cout<<"Print NewNode on Tail of Linked List: "<<endl;
    PrintLL(head1);
    
    return 0;
}