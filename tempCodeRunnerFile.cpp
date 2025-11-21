#include<bits/stdc++.h>
using namespace std;
void findPossibleSubstr(string str, string output , int i , vector<string>&ans){
    if(i >= str.size()){
        ans.push_back(output);
        return;    
    }
    //exlude
    findPossibleSubstr(str, output , i+1 , ans);
    //include
    output = output + str[i];
    findPossibleSubstr(str , output , i+1 , ans);
}
int main(){
    string str = "abc";
    string output = "";
    int i = 0;
    vector<string> ans;
    findPossibleSubstr(str,output,i,ans);
    for(auto it : ans){
        cout<<it<<endl;
    }
    return 0;
}