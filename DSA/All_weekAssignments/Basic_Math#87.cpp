#include<bits/stdc++.h>
using namespace std;
bool IsPrime(int n){
    if(n <= 1) return false; // ynni 1 prime number nnhi hni kuki uskn fnctor sirf  1 hi hotn hni 
    for (int i = 2; i < n; i++)
    {
        if(n % i == 0 ) return false;
    }

    return true; // yani last tak koi or factor nahi mila;
}

int main(){
    //! Three Basic Qus About Prime number!!
    // 1. Check Given number is Prime or Not?
    // int n = 11;
    // if(IsPrime(n)){
    //     cout<<"It is Prime number";
    // }else{
    //     cout<<"Not Prime number";
    // }
    
    // 2. Print all Prime number form 1 to 20 or any number as you wish
    // int n = 20;
    // for(int i = 1 ; i <= n ; i++){
    //     if(IsPrime(i)){
    //         cout<<i<<" ";
    //     }
    // }
   
    // 3. Count Total Prime number from 1 to 20 or any number you wish to 
    // int n = 20;
    // int count = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     if(IsPrime(i)){
    //         count++;
    //     }
    // }
    // cout<<count;

    //! Sqrt Approach (Just for optimizing it)
    // Note 3rd qus ko hi optimize kiya ke if prime n tak find na kerke root n tak honge jisse 
    // sirf thodi se time complexity improve hogi per this is not also a best solution 
    // (Proper Notes in Om pdf)
    // so we have another Approach for better Time complexity that is:-Sieve of Eratosthenes
    //! Sieve of Erathosthenes 
    // int n = 21;
    // int ans = 0;
    // vector<bool> prime(n,true);
    // prime[0]=prime[1]=false; // 0 and 1 ko khud se false ker dea

    // for (int i = 2; i < n; i++)
    // {
    //     if(IsPrime(i)){
    //         ans++;
    //         int j = 2*i;
    //         while(j < n){
    //             prime[j] = false;
    //             j += i;
    //         }
    //     }
    // }
    // cout<<ans;
    
    // ------------------------------------------------------------------
    //!Find GCF or HCF of A and B
    int A = 56;
    int B = 74;
    if(A == 0) cout<< B;
    if(B == 0) cout<< A;
    while(A > 0 && B > 0){
        if(A > B){
            A = A - B;
        }else{
            B = B - A;
        }
    }

    if(A == 0){
        cout<<B;
    }else{
        cout<<A;
    }
    return 0;
}