//! Class 3 Linked list
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
int FindLen(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
//! 1) Find Middle Node in Linked List (using Length Approach)
Node* FindMiddleNode1(Node* &head){
    int len = FindLen(head);
    if(len%2 == 0){// If Linked list of Even Length
        Node* temp = head;
        int position = len/2;
        while(position != 1){
            position--;
            temp = temp->next;
        }
        return temp;
    }else{// If Linked list of Odd Length
        Node* temp = head;
        int position = len/2+1;
        while(position != 1){
            position--;
            temp = temp->next;
        }
        return temp;
    }
}
//! 2) Find Middle Node in Linked List (using slow and fast Approach)
Node* FindMiddleNode2(Node* &head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;}

int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* tail = new Node(0);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = tail;

    //! 1) Find Middle Node in Linked List (using Length Approach)
    // Node* middleNode = FindMiddleNode1(head);
    // cout<<"Middle Node is : "<<middleNode->data<<endl;
    //! 2) Find Middle Node in Linked List (Using Fast and Slow Approach)
    // Node* middleNode = FindMiddleNode2(head);
    // cout<<"Middle Node is : "<<middleNode->data<<endl;
    //! 3) Reverse Linked List in Group of K?
    
    return 0;
}