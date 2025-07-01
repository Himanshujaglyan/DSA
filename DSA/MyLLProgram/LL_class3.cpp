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
void PrintLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
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
//! 3) Reverse Linked List in Group of K?
Node* ReverseLLInK(Node* &head , int k){
    int LLlen = FindLen(head); 
    if(k > LLlen){
        cout<<"Enter valid value of k"<<endl;
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = curr->next;    
    int count = 0;
    //pahle group ke according hamne khud reverse ker dea  
    while(count < k){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        count++;
    }
    //baki ka kaam recursion sambhalega
    if(nextNode != NULL){
        head->next = ReverseLLInK(nextNode , k);
    }
return prev;
}    
//! 4) Check Linked list is circular or not (1)
bool IscircularLL(Node* &head){
    if(head == NULL) return false;
    Node* temp = head->next;
    while(temp!= NULL && temp != head){
        temp = temp->next;    
    }
    return (temp == head);
}
//! 5) Check Linked list is circular or not (2)
bool IsCircularLL2(Node* &head){
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow){
            return true;
        }
    }
    return false;
}

int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* tail = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = tail;
    //just for to make circular linked list
    tail->next = head;

    //! 1) Find Middle Node in Linked List (using Length Approach)
    // Node* middleNode = FindMiddleNode1(head);
    // cout<<"Middle Node is : "<<middleNode->data<<endl;
    //! 2) Find Middle Node in Linked List (Using Fast and Slow Approach)
    // Node* middleNode = FindMiddleNode2(head);
    // cout<<"Middle Node is : "<<middleNode->data<<endl;
    //! 3) Reverse Linked List in Group of K?
        //head = ReverseLLInK(head , 3);//means her third node se reverse karenge or jo baki ka kaam hoga vo recursion se karenge
        // PrintLL(head);
    //! 4) Is Linked List is circular or Not (First Approach)
    // if(IscircularLL(head)){
    //     cout<<"Yes it is circular LL"<<endl;
    // }else{
        //     cout<<"No it is not circular LL"<<endl;
        // }
    //! 5) Is Linked list is circular or Not (using Fast and Slow Approach)
        // if(IsCircularLL2(head)){
        //     cout<<"Yes it is circular LL"<<endl;
        // }else{
        //     cout<<"No it is not circular LL"<<endl;
        // }
    //! 6) 
    return 0;
}