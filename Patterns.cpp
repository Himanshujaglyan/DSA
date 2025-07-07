#include<bits/stdc++.h>
using namespace std;
int main(){
    //! 1) Basic 9 Qus:- 
    // for(int i = 0 ; i < 5 ; i++){
    //     for(int j = 0 ; j < 5 ; j++){
    //         cout<<"*"<<" ";
    //     }
    //     cout<<endl;}

    // for (int i = 1; i <= 5; i++)
    // {
    //     for (int j = 1 ; j <= i ; j++)
    //     {
    //         cout<<"*"<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // for(int i = 0 ; i < 5 ; i++){
    //     for(int j = 0 ; j < 5-i ; j++){
    //         cout<<"*"<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // for(int i = 0 ; i < 5 ; i++){
    //     //Print spaces
    //     for(int j = 0 ; j < i ; j++){
    //         cout<<" "<<" ";
    //     }
    //     //Print stars
    //     for(int j = 0 ; j < 5-i ; j++){
    //         cout<<"*"<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // for(int i = 1 ; i <= 5 ; i++){
    //     //Print space
    //     for(int j = 0 ; j < 5-i ; j++){
    //         cout<<" "<<" ";
    //     }
    //     //Print star
    //     for(int j = 0 ; j < i ; j++){
    //         cout<<"*"<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // for(int i = 1 ; i <= 5 ; i++){
    //     for(int j = 1 ; j <= i ; j++){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }   

    // for(int i = 1 ; i <= 5 ; i++){
    //     for(int j = 1 ; j <= i ; j++){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }   

    // for(int i = 0 ; i < 5 ; i++){
    //     //Print spaces
    //     for(int j = 0 ; j < i ; j++){
    //         cout<<" "<<" ";
    //     }
    //     //Print row digits
    //     for(int j = 0 ; j < 5-i ; j++){
    //         cout<<i+1<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i = 1 ; i <= 5 ; i++){
    //     //Print spaces
    //     for(int j = 0 ; j < 5-i ; j++ ){
    //         cout<<" "<<" ";
    //     }
    //     //Print stars
    //     for(int j = 0 ; j < i ; j++){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }

    //! 2) Medium 6 Qus:- Note : Striver ke Note book me jo circle wale qus hai unko medium consider kiya hai!
       
    // int start;
        // for(int i = 0 ; i < 5 ; i++){
        //     start = i%2 == 0 ? 1 : 0;
        //     for(int j = 0 ; j <= i ; j++){
        //         cout<<start<<" ";
        //         start = 1 - start;            
        //     }
        //     cout<<endl;
        // }

    // int count = 1;
    // for(int i = 0 ; i < 5 ; i++){
    //     for(int j = 0 ; j <= i ; j++){
    //         cout<<count++<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i = 0 ; i < 5 ; i++){
    //     for(char ch = 'A' ; ch <= 'A'+ i ; ch++){
    //         cout<<ch<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i = 0 ; i < 5 ; i++){
    //     for(char ch = 'A' ; ch <= 'A'+(5-i-1) ; ch++){
    //         cout<<ch<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // for(int i = 0 ; i < 5 ; i++ ){
    //     for(int j = 0 ; j <= i ; j++){
    //        char ans = 'A' + i;
    //        cout<<ans<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i = 0 ; i < 5 ; i++){
    //     for(char ch = 'E'-i ; ch <= 'E' ; ch++){
    //         cout<<ch<<" ";
    //     }
    //     cout<<endl;
    // }


    //! 3) Hard 9 Qus:-
    
    // for(int i = 0 ; i < 5 ; i++){
    //     //spaces
    //     for(int j = 0 ; j < 5-i-1 ; j++){
    //         cout<<" "<<" ";
    //     }
    //     //stars
    //     for(int j = 0 ; j < 2*i+1 ; j++){
    //         cout<<"*"<<" ";
    //     }
    //     //spaces
    //     for(int j = 0 ; j < 5-i-1 ; j++){
    //         cout<<" "<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i = 0 ; i < 5 ; i++){
    //     //spaces
    //     for(int j = 0 ; j < i ; j++ ){
    //         cout<<" "<<" ";
    //     }
    //     //stars
    //     for(int j = 0 ; j < 2*5-(2*i+1) ; j++){
    //         cout<<"*"<<" ";
    //     }
    //     //spaces
    //     for(int j = 0 ; j < i ; j++ ){
    //         cout<<" "<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i = 0 ; i < 2*5-1 ; i++){
    //     int start;
    //     start = i>5? 2*5-i : i;
    //     for(int j = 0 ; j < start ; j++){
    //         cout<<"*"<<" ";
    //     } 
    //     cout<<endl;
    // }

    // for (int i = 1; i <= 5; i++)
    // {
    //     for (int j = 1 ; j <= i ; j++)
    //     {
    //         cout<<"*"<<" ";
    //     }
    //     cout<<endl;
    // }
    // for (int i = 1; i <= 5; i++)
    // {
    //     for(int j = 0 ; j <= 5-i-1 ; j++){
    //         cout<<"*"<<" ";
    //     }
    //     cout<<endl;
    // }

    //int space = 2*(4-1);
//    for(int i = 1 ; i <= 4 ; i++){
//     //stars
//     for(int j = 1 ; j <= i ; j++){
//         cout<<j<<" ";
//     }
//     //spaces
//     for(int j = 0 ; j < space ; j++ ){
//         cout<<" "<<" ";
//     }
//     //stars
//     for(int j = i ; j >= 1 ; j--){
//         cout<<j<<" ";
//     }
//     space = space - 2;
//     cout<<endl;
//    }    
    
    // for(int i = 0 ; i < 5 ; i++){
    //     //spaces
    //     for(int j = 0 ; j < 5-i-1 ; j++ ){
    //         cout<<" "<<" ";
    //     }
    //     //stars
    //     char ch = 'A';
    //     int breakPoint = (2*i+1)/2;
    //     for(int j = 0 ; j < 2*i+1 ; j++){
    //         cout<<ch<<" ";
    //         if(j < breakPoint){
    //             ch++;
    //         }else{
    //             ch--;
    //         }
    //     }
    //     //spaces
    //     for(int j = 0 ; j < 5-i-1 ; j++ ){
    //         cout<<" "<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i = 0 ; i < 5 ; i++){
    //     //stars
    //     for(int j = 0 ; j < 5-i-1 ; j++){
    //         cout<<"*"<<" ";
    //     }
    //     //spaces
    //     for(int j = 0 ; j < 2*i ; j++){
    //         cout<<" "<<" ";
    //     }
    //     //stars
    //     for(int j = 0 ; j < 5-i-1 ; j++){
    //         cout<<"*"<<" ";
    //     }
    //     cout<<endl;
    // }
    // int space = 2*(4-1);
    // for(int i = 1 ; i <= 4 ; i++){
    //     //stars
    //     for(int j = 0 ; j < i ; j++){
    //         cout<<"*"<<" ";
    //     }
    //     //spaces
    //     for(int j = 0 ; j < space ; j++){
    //         cout<<" "<<" ";
    //     }
    //     //stars
    //     for(int j = 0 ; j < i ; j++){
    //         cout<<"*"<<" ";
    //     }
    //     space = space-2;
    //     cout<<endl;
    // }

    

    return 0;
}