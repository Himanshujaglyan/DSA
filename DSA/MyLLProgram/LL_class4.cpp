//! Linked List class - 4
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
void PrintLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node* reversLL(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = curr->next;
    while(curr != NULL){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev; //kuki ab head yai ban chuka hoga!
}
//! 1) Check Palindrome or Not
bool IsPalindrome(Node* &head){
    if(head == NULL){
        cout<<"LL is empty"<<endl;
        return true;
    }
    if(head->next == NULL){
        return true;//because only single node to palindrome hi hoga na!
    }
    // Step1: Find Middle Node
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;//yai last me middle node ko point karega
        }
    }
    //Step2: Reverse the LL after Middle Node
    Node* reverseLLkaHead = reversLL(slow->next);
    slow->next = reverseLLkaHead;
    //Step3: Compare using two pointer
    Node* temp1 = head;
    Node* temp2 = reverseLLkaHead;
    while(temp2 != NULL){   
        if(temp1->data != temp2->data){
            return false;
        }else{
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
}

//! 2) Remove duplicate from the sorted Linked list
 void RemoveDuplicate(Node* &head){
    if(head == NULL){
        cout<<"LL is empty"<<endl;
        return;
    }
    Node* curr = head;
    while(curr != NULL){
        if((curr->next != NULL) && (curr->data == curr->next->data)){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            temp->next = NULL;
            delete temp;
        }else{
            curr = curr->next;
        }
    }
 }
//! 3) Remove duplicate from the Unsorted Linked list (Use Array to sort the Element first and use the same approch jo 2nd Qus me use hui hai!!)
 Node* sortLL(Node* &head){
    vector<int> arr; //take an array to copy the value of Linked list
    Node* temp = head;
    while(temp != NULL){//LL se Array me saari value puch ker de
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin() , arr.end());//array ko sort ker de

    //Again vector se linked list me value daal de sorted wali
    int i = 0;
    temp = head; // again update the temp
    while(temp != NULL){
        temp->data = arr[i++];
        temp = temp->next;
    }
    return head;
    //baki yaha se sorted linked list ka head return ker dea hai kuki uske baad ka code remove duplicate to hamne likh hi rakha hai upper wahi use ker lenge okk!!
 }
//! 4) Sort 0s 1s and 2s (Using First Approach) 
void sortZerosOnesTwos_1(Node* head){
    int zerosCount = 0;
    int OnesCount = 0;
    int twosCount = 0;
    Node* temp = head;
    //Count all 0,1,2  and arrage in sequence
    while(temp != NULL){
        if(temp->data == 0){
            zerosCount++;
        }
        else if(temp->data == 1){
            OnesCount++;
        }
        else if(temp->data == 2){
            twosCount++;
        }
        temp = temp->next;
    }
    //Replace the data

    temp = head;
    while(zerosCount--){
        temp->data = 0;
        temp = temp->next;        
    }
    while(OnesCount--){
        temp->data = 1;
        temp = temp->next;
    }
    while(twosCount--){
        temp->data = 2;
        temp = temp->next;
    }
}  
//! 5) 

int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* fourth = new Node(0);
    Node* fifth = new Node(0);
    Node* tail = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = tail;

    //! 1) Check Linked List is Palindrome of Not (Note yai qus kerne se pahle apni linked list ko khud se palindrom bana lio kuki mene uper linked list ke element change ker dea tha)
    // if(IsPalindrome(head)){
    //     cout<<"Yes It is Palindrome!"<<endl;
    // }else{
    //     cout<<"No It is Not Palindrome!"<<endl;
    // }
    //! 2) Remove duplicate from the sorted linked list (Note : LL ko modify ker lio sorted way me khud se mene kuki change ker dea tha upper)
    // PrintLL(head);
    // RemoveDuplicate(head);
    // cout<<"After Removing Duplicate from the sorted array :"<<endl;
    // PrintLL(head);
    //! Note :3) Now ab hum duplicate remove karenge of unsorted linked list (Approach:- use Array to sort the element first)
    //head = sortLL(head); 
    // PrintLL(head);//it show sorted linked list 
    //RemoveDuplicate(head);//or yaha se ab hum duplicates remove ker denge 
    // cout<<"Sorted and Remove Duplicated LL :"<<endl;
    // PrintLL(head);
    //! 4) Sort 0s 1s and 2s     
    sortZerosOnesTwos_1(head);
    // PrintLL(head);    
    //! 5) Add 2 Number Represented the Linked List (Remaining) esko Om ke notes se samaj lenge baad me
    return 0;
}
