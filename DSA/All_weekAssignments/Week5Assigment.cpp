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

//------------------------------Assignment Qus-----------------------------------------------------

bool validAnagram(string str1 , string str2){
    int hashTable[256] = {0};
    if(str1.length() != str2.length()){
        return false;
    }
    for (int i = 0; i < str1.length(); i++)
    {
        hashTable[str1[i]]++;
    }
    for (int i = 0; i < str2.length(); i++)
    {
        hashTable[str2[i]]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if(hashTable[i] != 0){
            return false;
        }
    }
    return true;
}
//-------------------------------------------
string ReverseOnlyLetters(string str){
    int l = 0 , r = str.length() - 1;
    while(l < r){
        if(isalpha(str[l]) && isalpha(str[r])){
            swap(str[l],str[r]);
            l++,r--;
        }else if(!isalpha(str[l])){
            l++;
        }else{
            r--;
        }
    }
    return str;
}
//------------------------------------------
string LongestCommanPrefix(vector<string> str){
    if(str.empty()) return "";
    string prefix = str[0];
    for (int i = 1; i < str.size(); i++)
    {
        while(str[i].find(prefix) !=  0){
            prefix = prefix.substr(0,prefix.length() - 1);
            if(prefix.empty()) return "";
        }
    }
    return prefix;
}
//------------------------------------------
bool isvowel(char ch){
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
string ReverseOnlyVowel(string s){
    int l = 0 , h = s.length()-1;
    while(l < h){
        if(isvowel(s[l]) && isvowel(s[h])){
            swap(s[l],s[h]);
            l++,h--;
        }else if(!isvowel(s[l])){
            l++;
        }else{
            h--;
        }
    }
    return s; 
}
//------------------------------------------
bool CheckIsomorphicString(string s , string t){
    int hash[256] = {0};
    bool ischarMapping[256] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        if(hash[s[i]] == 0 && ischarMapping[t[i]] == 0){
            hash[s[i]] = t[i];
            ischarMapping[t[i]] = true;
        }
    }

    for (int i = 0; i < s.length(); i++)
    {
        if(char(hash[s[i]]) != t[i]){
            return false;
        }
    }
    return true;
}
//------------------------------------------
string ReorganizeString(string s){
    int hash[26] = {0};
    //yaha mene hash ke ander jitne bhi character hai unka count store kiya hai 
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;
    }
    //ab me yaha vo character find kerunga jo jada baar aaya hai or konsa character hai vo
    int max_freq = INT_MIN;
    char max_freq_char;
    for (int i = 0; i < 26; i++)
    {
        if(hash[i] > max_freq){
            max_freq = hash[i];
            max_freq_char = i + 'a';
        }
    }
    // ab me ek single round me max frequency character dekhunga ke ek gap me saare max character aara hai kya
    int index = 0 ;
    for (int i = 0; i < 26; i++)
    {
        if(max_freq > 0 && index < s.size()){
            s[index] = max_freq_char;
            max_freq--;
            index += 2;
        }
    }

    // ab me yaha check ker raha hu ke ager max_freq zero ke equal nahi hua matlb ek flow me saare max character adjust nahi hua
    if(max_freq != 0){
        return "";
    }    

    // jub vo kaam ache se hua to phir baki ke character bhi adjust kerte hai 
    for (int i = 0; i < 26; i++)
    {
        while(hash[i] > 0){
            index = index >= s.size()? 1 : index;
            s[index] = i + 'a';
            hash[i]--;
            index += 2;
        }
    }
    
    return s;
}
//--------------------------------------------
vector<vector<string>> GroupAllSimilar_Anagram(vector<string> strs){
    map<string , vector<string>> mpp;
    for(auto str : strs){
        string s = str;
        sort(s.begin(),s.end());
        mpp[s].push_back(str);
    }
    vector<vector<string>> ans;
    for(auto it = mpp.begin() ; it != mpp.end() ; it++){
        ans.push_back(it->second);
    }   
    return ans;
}
//--------------------------------------------
int findFirstIndex(string str , string part){
    int n = str.length();
    int m = part.length();
    for(int i = 0 ; i < n - m ; i++){
        for(int j = 0 ; j < m ; j++){
            if(str[i+j] != part[j]){
                break;
            }
            if(j == m-1){
                return i;
            }
        }
    }
    return -1;
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
// ------------------------------------------------------------------------------------------------------
        // Assignment Qus week 5 Strings @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// Qus 1 Valid Anagram (Leetcode - 242)
        // string str1 = "anagram";
        // string str2 = "nagaram";
        // if(validAnagram(str1,str2)){
        //     cout<<"valid Anagram";
        // }
        // else{
        //     cout<<"Not Anagram";
        // }

// Qus 2 Reverse Only Letters?
    // string str = "a-bC-dEf-ghIj!"; // Output - j-Ih-gfE-dCba!
    // string ans = ReverseOnlyLetters(str);
    // cout<<ans;
    
// Qus 3 Longest Comman Prefix? 
        // vector<string> str = {"flower","flow","flight"};
        // string ans = LongestCommanPrefix(str);
        // cout<<ans;
    
// Qus 4 Reverse Only Vowels?
    // string str = "leetcode"; // output - leotcede;
    // string ans = ReverseOnlyVowel(str);
    // cout<<ans;
       
// Qus 5 Isomorphic String (Boys/Girls) example
    // string S = "egg";
    // string T = "add";
    // if(CheckIsomorphicString(S,T)){
    //     cout<<"It is Isomorphic String";
    // }else{
    //     cout<<"Not Isomorphic String";
    // }
    
// Qus 6 Reorgnaize String  (leetcode - 767)
    // string str = "aaabef";
    // string ans = ReorganizeString(str);
    // cout<<ans;
    
// Qus 7 Group Anagrams ? (leetcode - 49)
    // vector<string> str = {"eat","tea","tan","ate","nat","bat"}; // output:[["bat"],["nat","tan"],["ate","eat","tea"]]
    // vector<vector<string>> ans = GroupAllSimilar_Anagram(str);
    //  for (auto group : ans) {
    //     cout << "[ ";
    //     for (auto word : group) {
    //         cout << word << " ";
    //     }
    //     cout << "]\n";
    // }

// Qus 8 Longest Palindromic Substring (leetcode - 5)
    //  ! ESKA SOLUTION jub me Dynamic programing kerunga tub milega merko 

//Qus 9 Find the index of first Occurence (leetcode - 28)
    // string str = "Himanshu";
    // string part = "man";
    // int findIndex = findFirstIndex(str, part);
    // cout<<findIndex;



    return 0;
}