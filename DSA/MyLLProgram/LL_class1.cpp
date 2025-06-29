#include<bits/stdc++.h>
using namespace std;
//! 1)create Node by creating class
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

//! 2)Insert on Head and Tail
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
    ~Node(){
        cout<<"Node is Deleted"<<endl;
    }
};

void InsertatHead(Node* &head , Node* &tail ,int data){
    //if LL is empty so there are four steps
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    } 
    else{
    //In Three steps we can insert a new node on head of linked list
    //Step1 Create a Node
    Node* newNode = new Node(data);
    //Step connect newNode next to head of linked list
    newNode->next = head;
    //Step update head by newNode
    head = newNode;
    }
}

void PrintLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void InsertatTail(Node* &head , Node* &tail ,int data){
    //if LL is empty so there are four steps
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
    }
}

//! 3)Insert Node in specific position of LL
void insertatPosition(Node* &head , Node* &tail , int data , int position){
   if(head == NULL){//ager linked list empty hai to bus create ker do 
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
   }else if(position == 1){//ager position first per insert kerna hai to head wale code ko call ker do
    InsertatHead(head , tail , data);
   }else{ // nahi to simple at any position kahi bhi insert ker do 
       Node* newNode = new Node(data);
       Node* prev = NULL;
       Node* curr = head;
       while(position != 1){
           position--;
           prev = curr;
           curr = curr->next;
        }
        newNode->next = curr;
        prev->next = newNode;
    }
}

//! 4)Delete Node from specific position in Linked list
int lenofLL(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void deleteNodeFromPosition(Node* &head , Node* &tail , int position){
    if(position == 1){//Means delete first Node
        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;        
        return;
    }
    int len = lenofLL(head);
    if(position == len){
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
}
int main(){//----------------------------------------------------------------------------------

    //! 1)Manually create and connect Nodes
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

    //! 2)Insert on Head and Tail
    Node* head = NULL;
    Node* tail = NULL;

    InsertatHead(head,tail,10);
    InsertatHead(head,tail,20);
    InsertatHead(head,tail,30);
    InsertatHead(head,tail,40);
    InsertatHead(head,tail,50);
//--------Insert at Tail--------------------------
    InsertatTail(head,tail,4);
    InsertatTail(head,tail,5);
    
    PrintLL(head);
    
    //! 3) Insert Node in specific position of Linked list
    // Note: upper wale code se linkedlist yai mil rahi hai => 50 40 30 20 10 4  to hame bilkul middle  insert kerna hai ya kisi bhi possition per 
    insertatPosition(head , tail , 101 ,8 );
    cout<<"New Node insert at any position :"<<endl;
    PrintLL(head);
    
    //! 4) Delete Node from specific position in Linked list
    deleteNodeFromPosition(head , tail , 1);
    cout<<endl;
    PrintLL(head);
    return 0;
}

