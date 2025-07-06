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
    
    for(int i = 0 ; i < 5 ; i++){
        //spaces
        for(int j = 0 ; j < 5-i-1 ;j++){
            cout<<" "<<" ";
        }
        //stars
        for(int j = 0 ; j < 2*i+1; j++){
            cout<<"*"<<" ";
        }
        //spaces
        for(int j = 0 ; j < 5-i-1 ;j++){
            cout<<" "<<" ";
        }
        cout<<endl;
    }
    


    return 0;
}