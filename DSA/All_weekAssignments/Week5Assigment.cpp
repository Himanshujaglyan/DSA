#include<bits/stdc++.h>
using namespace std;
int getLength(char ch[]){
    int length = 0;
    int i = 0;
    while(ch[i] != '\0'){
        length++;
        i++;
    }
    return length;
}
//--------------------------------------------------
void Reverse_CharArray(char ch[]){
    int i = 0;
    int n = getLength(ch);
    int j = n - 1;
    while(i <= j){
        swap(ch[i],ch[j]);
        i++,j--;
    }
}
//-------------------------------------------------


int main(){
// Qus1 Length of char Array?
    // char ch[10] = {'a','s','f','g','h','t','e','g','d'};
    // int length = getLength(ch);
    // cout<<length;
   
// Qus2 Reverse Char Array?
    // char ch[10];
    // cin>>ch;
    // Reverse_CharArray(ch);
    // cout<<ch;
    
// Qus3    
    return 0;
}