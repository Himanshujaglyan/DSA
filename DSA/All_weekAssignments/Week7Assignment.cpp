//! Recursion***********************************************************************
#include<bits/stdc++.h>
using namespace std;
void counting1(int n ){
    if(n == 0) return;
    counting1(n-1);
    cout<<n<<" ";
}
// --------------------------------------------
void counting2(int n){
    if(n == 0) return;
    cout<<n<<" ";
    counting2(n-1);
}
// ----------------------------------------------
int factorial(int n ){
    if(n == 1) return 1;
    int ans = n * factorial(n-1);
    return ans;
}
//------------ -----------------------------------
int powerOf2(int n){
    if(n == 0) return 1;
    int ans = 2 * powerOf2(n-1);
    return ans;
}
//-----------------------------------------------
int fib(int n ){
    if(n == 1) return 0;
    if(n == 2) return 1;
    int ans = fib(n-1) + fib(n-2);
    return ans;
}
//----------------------------------------------


int main(){
    //! Recursion Level-1 
    // Note : Yai jo niche 4 qus hai yai bhi ho sakte hai recursion Baki jo lecture me hua hai vo niche solve hai
// you have a number given you have to print the all digits of that number 
// find min and max number in the array using recursion
// find an element present in the array or not using recusion / or find on which index it was / 
// or find how many times the number is appear in the array using recursion
// ----------------------------------------------

// 1. Counting (Normal => 1-5) HEAD Recursion  using recursion?
    // int n = 5;
    // counting1(n);    

// 2. Counting (Reverse => 5-1) TAIL Recursion  using recursion?
    // int n = 5;
    // counting2(n);

// 3. Find Factorial of number using Recursion?
    // int n = 5; //5!
    // int ans = factorial(n);
    // cout<<"Factorial of "<<n<<" is "<<ans;

// 4. Any power of 2 calculation using Recusion? Ex:- 2^4 = 16
    // int n = 4; // this the power of 2
    // int ans = powerOf2(n);
    // cout<<ans;

// 5. Fibonacchi (Means konsi term ke hum fibonacchi number dekhna cahite hai ) means Ex:- (0 1 1 2 3 5 8 13) jesa yaha first term per zero hai seocnd per 1 hai or so on !
    // int n = 5;
    // int ans = fib(n);
    // cout<<ans;
    
    //! Recursion Level-2

  
    return 0;
} 