//! Recursion***********************************************************************
//! Important Note:
    // -->Recursion qus kerne se pahle simple tarike se solve kerne ka socha ker thekk hai 
    // -->Base case ka socha ker 80% sol mil jayega
    // -->Bus Loop ke jagah function use kerna shuru ker diya think like that!!

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
int climbStaires(int n ){
  if(n == 0 || n == 1) return 1;
  int ans = climbStaires(n-1) + climbStaires(n-2);
  return ans;
}
//----------------------------------------------
void printArrayElement(vector<int> arr , int n , int i){
    //Base Case (compare it with normal printing of array using for loop)
    if(i >= n) return;
    cout<<arr[i]<<" ";
    //Recusion says ek print tum kero baki me kerdunga
    printArrayElement(arr,n,i+1);
}
//---------------------------------------------
void FindMaxElement(vector<int> arr , int n , int i,int& maxi){
    if(i >= n) return;
    if(arr[i] > maxi){
        maxi = arr[i];
    }
    FindMaxElement(arr,n,i+1,maxi);
}
//--------------------------------------------
bool FindKeyIsPresent(string str , int n , int i , int key){
    if(i >= n) return false;
    if(str[i] == key) return true;
    return FindKeyIsPresent(str,n,i+1,key);
}
//-------------------------------------------
int IsPresentChar(string str , int n , int i , char key){
    //Base Case
    if(i >= n) return -1;
    if(str[i] == key) return i;
    return IsPresentChar(str , n , i+1 , key);
}
//-------------------------------------------
void GetAllTheIndexOFKey(string str , int n , int i , char key , vector<int>& arr){
    if(i >= n) return ;
    if(str[i] == key){
        arr.push_back(i);
    }
    return GetAllTheIndexOFKey(str,n,i+1,key,arr);
}
//------------------------------------------
void PrintAllDigit(int num , vector<int>& arr){
    if(num == 0) return ;
    int rem = num % 10;
    arr.push_back(rem);
    num = num / 10;
    return PrintAllDigit(num , arr);
}
//------------------------------------------
bool CheckIsSorted(vector<int> &arr , int n , int i){ 
    if(i >= n) return true;
    if(arr[i] < arr[i-1]){
        return false;
    }
    return CheckIsSorted(arr,n,i+1);
}
//-----------------------------------------
int BSrecursion(vector<int> &arr , int s , int e, int target){
    if(s > e) return -1;
    int mid = (s+e)/2;
    if(arr[mid] == target){
        return mid;
    }
    if(arr[mid] < target){
       return BSrecursion(arr,mid+1,e,target);
    }else{
        return BSrecursion(arr,s,mid-1,target);
    }
}
//-----------------------------------------
void printAllSubstring(string str , string output, int i, vector<string>& ans ){
    //Base case
    if(i >= str.length()){//jub subhi i pointer at last str.length se bade ho jayenge to print each output
        ans.push_back(output);
        return;
    }
    // Exclude
    printAllSubstring(str , output , i+1,ans);
    //Include
    output = output + str[i];
    printAllSubstring(str,output , i+1,ans);
}
//-----------------------------------------
int FindMiniElementCount(vector<int>& arr , int target ){
    //Base case
    if(target == 0){
        return 0;
    }
    if(target < 0){
        return INT_MAX;
    }
    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = FindMiniElementCount(arr, target-arr[i]);
        if(ans != INT_MAX){
        mini = min(mini , ans + 1);
        }
    }

return mini;
}
//----------------------------------------


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

// 6. Climb Staires (This is qus is very similar or we can say same as fibonacci series okk)
    // int n = 3;
    // int ans = climbStaires(n);
    // cout<<ans;

// 7. Print all elements of Array using Recursion?
        // vector<int> arr = {10,20,30,40,50};
        // int n = arr.size();
        // int i = 0;
        // printArrayElement(arr, n , i);
 
// 8. Find Max Element in Array using Recusion?
    // vector<int> arr = {10,21,11,42,22,12};
    // int n = arr.size();
    // int i = 0;
    // int maxi = INT_MIN;
    // FindMaxElement(arr,n,i,maxi);   
    // cout<<maxi;
    
    //!Note : String me char find kerne wale qus ke niche maine 3 varity ke qus(9,10,11) kiye hai okk!!!

    // 9. Find char in String using Recursion?
    //    string str = "himanshu";
    //    char key = 'h';
    //    int i = 0;
    //    int n = str.length();
    //     if(FindKeyIsPresent(str,n,i,key)){
    //         cout<<"Key is Present";
    //     }else{
    //         cout<<"Key is Not Present";
    //     }
       
// 10. Check whether the Char present In String or Not and -->return Index?
    // string str = "himanshu";
    // int n = str.length();
    // int i = 0;
    // char key = 'x';
    // int ans = IsPresentChar(str,n,i,key);
    // cout<<ans;

// 11. Check wheter the Char present in string and How many times -->print all Indexes Return in Array?
        // string str = "abcbdbebfb";
        // int n = str.length();
        // int i = 0;
        // char key = 'b';
        // vector<int> arr;
        // GetAllTheIndexOFKey(str,n,i,key,arr);
        // for(auto ele : arr){
        //     cout<<ele<<" ";
        // }

// 12. Print All Digit of Number?
        // int num = 435;
        // vector<int> arr;
        // PrintAllDigit(num,arr);
        // reverse(arr.begin(), arr.end());
        // for(auto it : arr){
        //     cout<<it<<" ";
        // }
 
        //! Recursion Level-3

// 13. Check Give Array is Sorted or Not?
        // vector<int> arr = {1,2,3,4,5,6,7};
        // int i = 1;
        // int n = arr.size();
        // if(CheckIsSorted(arr,n,i)){
        //     cout<<"Sorted";
        // }else{
        //     cout<<"UnSorted";
        // }

// 14. Search Element in Array using Binary Search (Recursion)? 
        // vector<int> arr = {2,4,6,8,10,12,14,16};
        // int target = 12;
        // int s = 0;
        // int e = arr.size()-1;
        // int ans = BSrecursion(arr,s,e,target);
        // cout<<ans;

// 15. Find all Possible Substring of a string using Recusion (method - Includign/Excluding)?
    // string str = "abc";
    // string output = "";
    // int i = 0 ;
    // vector<string> ans;
    // printAllSubstring(str,output,i,ans);
    // for(auto it : ans){
    //     cout<<it<<endl;
    // }

        //! Recursion Level-4 (Note : yai 16 qus muje etna acche se clear nahi hua hai )

// 16. Find Minimum element required of an Array whose sum is equal to Target
    // vector<int> arr = {1,2};
    // int target = 5;
    // int ans = FindMiniElementCount(arr,target);
    // cout<<ans;
 
// 17. 
    return 0;

} 