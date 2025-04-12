//!Pointers

#include<bits/stdc++.h>
using namespace std;
int main(){
    int  a = 3;
    // cout<<&a<<endl;
    int* ptr = &a;
    // cout<<&ptr;
    *ptr = *ptr+2;
    // cout<<a;
    cout<<sizeof(ptr);

    return 0;
}