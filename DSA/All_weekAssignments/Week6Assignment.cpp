//!Pointers

#include<bits/stdc++.h>
using namespace std;
int main(){
    // int  a = 3;
    // cout<<&a<<endl;
    // int* ptr = &a;
    // cout<<&ptr;
    // *ptr = *ptr+2;
    // cout<<a;
    // cout<<sizeof(ptr);
    // -----------------------------------------
    int arr[4] = {10,20,30,40};
    int* p = arr;
    cout<<*(p)++;
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
    

    return 0;
}