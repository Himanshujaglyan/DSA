#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void PrintLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int FindlenLL(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
Node* InsertATHead(Node* &head , int data){
    //1 create Node
    Node* newNode = new Node(data);
    //2 new node ko link kiya head se
    newNode->next = head;
    //3 head ko update ker dea
    head = newNode;
 return head;
}
void InsertatTail(Node* &head ,Node* &tail, int data){
    //1 Create new Node
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}
void InsertAtMiddleofLL(Node* &head , int data){
    Node* newNode = new Node(data);
    //1 find the lenght of linked list
    int len = FindlenLL(head);
    //2 find the position of linked list
    Node* prev = NULL;
    Node* curr = head;
    if(len%2 != 0){
        int position = len/2 + 1;
        while(position != 0){
            position--;
            prev = curr;
            curr = curr->next;
        }
    }else{
        int position = len/2;
        while(position != 0){
            position--;
            prev = curr;
            curr = curr->next;
        }
    }
    prev->next = newNode;
    newNode->next = curr;
}
void InsertInbetweenInLL(Node* &head ,int data, int position){
    Node* newNode = new Node(data);
    Node* prev = NULL;
    Node* curr = head;
    while(position != 0){
        position--;
        prev = curr;
        curr = curr->next;
    }
    prev->next = newNode;
    newNode->next = curr;

}
Node* DeleteFromHead(Node* &head){
    Node* temp = head;
    head = temp->next;
    temp->next = NULL;
    delete temp;
    return head;
}
void DeleteFromTail(Node* &head , Node* &tail){
    Node* temp = head;
    while(temp->next != tail){
        temp = temp->next;
    }
    temp->next = NULL;
    delete tail;
    tail = temp;
}
void DeleteFromAnyPosition(Node* &head , int position){
    Node* prev = NULL;
    Node* curr = head;
    while(position != 1){
        position--;
        prev= curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}   

int main(){
    Node* head = new Node(10);
    Node* first = new Node(20);
    Node* second = new Node(30);
    Node* third = new Node(40);
    Node* tail = new Node(50);
    //link all
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = tail;


    //!Print the Linked list
    // PrintLL(head);
    //!Find Length of Linked List
    // int len = FindlenLL(head);
    // cout<<len;
    //! Insert New Node at head
    // head = InsertATHead(head , 5);
    // PrintLL(head);
    //! Insert at tail
    // InsertatTail(head ,tail , 60);
    // PrintLL(head);
    //! Insert at middle of linked list
    // InsertAtMiddleofLL(head , 100);
    // PrintLL(head);
    //! Insert at any position in Linked list
    // InsertInbetweenInLL(head ,100, 3);
    PrintLL(head);
    //! Delete head from linked list
    // head = DeleteFromHead(head);
    // PrintLL(head);
    //! Delete tail from Linked list
    // DeleteFromTail(head , tail);
    // PrintLL(head);
    //! Delete from any position
    // DeleteFromAnyPosition(head , 3);
    // PrintLL(head);
    //!-----------------Doubly Linked list  (Note : Doubly linked list ke liye eske niche wali file hai with Name- LL_Revesion_2)
    //Baki niche mene singly linked list ke hi or important solve kiye hai@!!
    
    
    return 0;
}