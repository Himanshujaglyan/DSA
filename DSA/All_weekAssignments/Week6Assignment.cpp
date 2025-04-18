//!Pointers

#include<bits/stdc++.h>
using namespace std;


int main(){
    // !Pointer Level 1 Class:-
    //!Normal Pointer Behaviour**************************
    // int  a = 3;
    // cout<<&a<<endl;
    // int* ptr = &a;
    // cout<<&ptr;
    // *ptr = *ptr+2;
    // cout<<a;
    // cout<<sizeof(ptr);
    // ---------------------------------------------------------------------------------
    // ---------------------------------------------------------------------------------
    //!Pointer Level 2 Class:-
    //!Integer Array Pointer Behaviour*************************
        // int arr[4] = {10,20,30,40};
    // int* p = arr;
    // cout<<*(p)++;
    // cout<<*(arr+3);
    // cout<<arr<<endl; // Base Address
    // cout<<&arr<<endl; // Base Address
    // cout<<&arr[0]<<endl; // Base Address
    // ------------------------------
    // cout<<arr[1]<<endl; // 20
    // cout<<*arr<<endl; // first index value
    // cout<<*arr + 1 <<endl;// base address per jo value hai usme 1 add ker dea
    // cout<<*(arr + 2); // yai third index ko denote kerage 
    // ------------------------------
    // int arr[4] = {10,20,30,40};
    // int* ptr = arr;
    // cout<<*ptr<<endl;
    // cout<<*ptr++<<endl;
    // cout<<*++ptr<<endl;
    // cout<<*(ptr+1)<<endl;
    // cout<<*(ptr)+1<<endl;
    // cout<<*(ptr+2)<<endl;
    // cout<<*(ptr)+2<<endl;
    // ------------------------


    // !Char Array Pointer Behaviour*************************
    char ch[] = {'a','b','c','d','\0'};
    char* ptr = ch;
    // cout<<ch<<endl;
    // cout<<&ch<<endl;
    // cout<<&ch[2]<<endl;
    // ------------------------
    // cout<<*ptr<<endl; //a
    // cout<<*ptr++<<endl; //a
    // cout<<*++ptr<<endl; //b
    // cout<<*(ptr+1)<<endl; //b
    // cout<<*(ptr)+1<<endl; //98 (a+1 = 98)
    // cout<<*(ptr+2)<<endl; //c
    // cout<<*(ptr)+2<<endl; //99
    // ---------------------------------

    // !Pointer with Function Behaviour*************************

    // int arr[5] = {1,3,4,5,6};
    // cout<<"Array Size : "<<sizeof(arr)<<endl;
    // int pointersSize = callFun(arr);
    // cout<<"Pointer Size : "<<pointersSize;

    //----------------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------------
    //!Pointers Level 3 Class:-
    
   


    return 0;
}
