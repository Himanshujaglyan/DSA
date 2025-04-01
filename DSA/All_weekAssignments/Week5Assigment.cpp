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
void Fillthespace(char ch[]){
    for (int i = 0; i < strlen(ch); i++) 
    {
        if(ch[i] == ' '){
            ch[i] = '@';
        }
    }
}
//------------------------------------------------
bool checkPalindrom(char ch[]){
    int i = 0 , j = getLength(ch) - 1 ; 
    while(i <= j){
     if(ch[i] != ch[j]){
        return false;
     }else{
        i++,j--;
     }
    }
    return true;
}
bool checkPalindrom1(string str,int start , int end){
    int i = start , j = end ; 
    while(i <= j){
     if(str[i] != str[j]){
        return false;
     }else{
        i++,j--;
     }
    }
    return true;
}
//------------------------------------------------
void ConvertIntoUpperCase(char ch[]){
    for (int i = 0; i < getLength(ch); i++)
    {
        ch[i] = ch[i]-'a'+'A';
    }

}
//-----------------------------------------------
string removeDuplicates(string str){
    string ans;
    int i = 0 ;
    while(i < str.length()){
        if(str.length() > 0){
            if(str[i] == ans[ans.length() - 1]){
                ans.pop_back();
            }else{
                ans.push_back(str[i]);
            }
        }else{
            ans.push_back(str[i]);
        }
        i++;
    }
    return ans;
}
//-----------------------------------------------
string removeAllOccurrences(string str , string part){
    int n = str.length();
    int m = part.length();

    for (int i = 0; i < n - m; i++)
    {
        int pos = str.find(part);
        if(pos != string::npos){
            str.erase(pos,m);
            pos = str.find(part);
        }
    }
    return str;
}
//-----------------------------------------------
int FindInstring(string str , string part){
    int n = str.length();
    int m = part.length();
    for (int i = 0; i <= n - m; i++)
    {
        bool flag = true;
        for (int j = 0; j < m; j++)
        {
            if(str[i+j] != part[j]){
                flag = false;
                break;
            }
        }
        if(flag) return i;
    }
    return -1;
}
//--------------------------------------------
bool Valid_Palindrome(string str){
    int i = 0 , j = str.length() - 1;
    while(i <= j){
        if(str[i] != str[j]){
            return checkPalindrom1(str,i+1 , j) || checkPalindrom1(str,i , j-1);
        }else{
            i++,j--;
        }
    }
    return true;
}
//-------------------------------------------
int MinimumTimeDifference(vector<string> str){
    vector<int> minutes;

    for (int i = 0; i < str.size(); i++)
    {
        string curr = str[i];
        int hour = stoi(curr.substr(0,2));
        int min = stoi(curr.substr(3,2));
        int totalmin = hour * 60 + min;
        minutes.push_back(totalmin);
    }
    sort(minutes.begin(),minutes.end());
    int mini = INT_MAX;
    int n = minutes.size();
    for (int i = 0; i < minutes.size(); i++)
    {
        int temp = minutes[i + 1] - minutes[i];
        mini= min(mini,temp);
    }
    int diff = (minutes[0] + 1440) - minutes[n-1];
    mini = min(mini, diff);

    return mini;
}
//-------------------------------------------
int possiblePalindromicSubstring(string str , int i , int j ){
    int count = 0;
    while(i >= 0 && j < str.length() && str[i] == str[j]){
        count++;
        i--,j++;
    }
    return count;
}
//-------------------------------------------



int main(){
    // 1st Class of Char Array and String!!****************************************
// Qus1 Length of char Array?
    // char ch[10] = {'a','s','f','g','h','t','e','g','d'};
    // int length = getLength(ch);
    // cout<<length;
   
// Qus2 Reverse Char Array?
    // char ch[10];
    // cin>>ch;
    // Reverse_CharArray(ch);
    // cout<<ch;
    
// Qus3 Fill spaces with @ symbol?
    // char ch[100];
    // cout<<"Enter your String = ";
    // cin.getline(ch,100);
    // Fillthespace(ch);
    // cout<<ch;
    
// Qus4 Check Palindrom or not?
    // char ch[10];
    // cout<<"Enter input = ";
    // cin>>ch;
    // if(checkPalindrom(ch)){
    //     cout<<"Yes it is palindrom!!";
    // }else{
    //     cout<<"It is not Palindrom!!";
    // }

// Qus5 Convert lowercase character to upper case?
    // char ch[10];
    // cout<<"Enter the String = ";
    // cin>>ch;
    // ConvertIntoUpperCase(ch);
    // cout<<ch;

    //2nd Class of Char Array and String!!*************************************

// Qus6 Remove all adjacent Duplicate in the String?
    // string str = "abbaca";//Output: "ca"
    // string ans = removeDuplicates(str);
    // cout<<ans;
    
// Qus7 Remove all occurrences of a substring?
    // string str = "daabcbaabcbc";
    // string part = "abc";
    // string rem = removeAllOccurrences(str,part);
    // cout<<rem;  
   
// Qus8 Find part of string in big string and return the first find index
    // yai qus ager interviewerr bol de ke find() function mat use kero manually find ka code likho
    // string str = "Himanshu";
    // string part = "man";
    // int findIndex = FindInstring(str, part);
    // cout<<findIndex;
   
// Qus9 Valid Palindrome (||) leetcode - 680    
    // string str = "leverl";
    // if(Valid_Palindrome(str)){
    //     cout<<"This is valid Palindrome!";
    // }else{
    //     cout<<"Not a valid Palindrome!";
    // }

// Qus10 Minimum Time Difference leetcode-539
        // vector<string> str = {"12:10","10:15","13:15","17:20","18:00","19:47","23:59"}; 
        // int minimum = MinimumTimeDifference(str);
        // cout<<minimum;

// Qus11 Possible palindromic substring leetcode - 647
        // string str = "anant";
        // int count = 0;
        // for (int i = 0; i < str.length(); i++)
        // {
        //     int oddkaCount = possiblePalindromicSubstring(str , i , i);
        //     count = count + oddkaCount;
        //     int evenkaCount = possiblePalindromicSubstring(str , i , i+1);
        //     count = count + evenkaCount;
        // }
        // cout<<count;

        //2nd WEEK 5 CONNECTION !!*************************************

    string str = "Himanshu";
    string get = str.substr(3,2);
    cout<<get;
    return 0;
}