//! Recursion***********************************************************************
//! Important Note:
// -->Recursion qus kerne se pahle simple tarike se solve kerne ka socha ker thekk hai
// -->Base case ka socha ker 80% sol mil jayega
// -->Bus Loop ke jagah function use kerna shuru ker diya think like that!!

#include <bits/stdc++.h>
using namespace std;
void counting1(int n)
{
    if (n == 0)
        return;
    counting1(n - 1);
    cout << n << " ";
}
// --------------------------------------------
void counting2(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    counting2(n - 1);
}
// ----------------------------------------------
int factorial(int n)
{
    if (n == 1)
        return 1;
    int ans = n * factorial(n - 1);
    return ans;
}
//------------ -----------------------------------
int powerOf2(int n)
{
    if (n == 0)
        return 1;
    int ans = 2 * powerOf2(n - 1);
    return ans;
}
//-----------------------------------------------
int fib(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    int ans = fib(n - 1) + fib(n - 2);
    return ans;
}
//----------------------------------------------
int climbStaires(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int ans = climbStaires(n - 1) + climbStaires(n - 2);
    return ans;
}
//----------------------------------------------
void printArrayElement(vector<int> arr, int n, int i)
{
    // Base Case (compare it with normal printing of array using for loop)
    if (i >= n)
        return;
    cout << arr[i] << " ";
    // Recusion says ek print tum kero baki me kerdunga
    printArrayElement(arr, n, i + 1);
}
//---------------------------------------------
void FindMaxElement(vector<int> arr, int n, int i, int &maxi)
{
    if (i >= n)
        return;
    if (arr[i] > maxi)
    {
        maxi = arr[i];
    }
    FindMaxElement(arr, n, i + 1, maxi);
}
//--------------------------------------------
bool FindKeyIsPresent(string str, int n, int i, int key)
{
    if (i >= n)
        return false;
    if (str[i] == key)
        return true;
    return FindKeyIsPresent(str, n, i + 1, key);
}
//-------------------------------------------
int IsPresentChar(string str, int n, int i, char key)
{
    // Base Case
    if (i >= n)
        return -1;
    if (str[i] == key)
        return i;
    return IsPresentChar(str, n, i + 1, key);
}
//-------------------------------------------
void GetAllTheIndexOFKey(string str, int n, int i, char key, vector<int> &arr)
{
    if (i >= n)
        return;
    if (str[i] == key)
    {
        arr.push_back(i);
    }
    return GetAllTheIndexOFKey(str, n, i + 1, key, arr);
}
//------------------------------------------
void PrintAllDigit(int num, vector<int> &arr)
{
    if (num == 0)
        return;
    int rem = num % 10;
    arr.push_back(rem);
    num = num / 10;
    return PrintAllDigit(num, arr);
}
//------------------------------------------
bool CheckIsSorted(vector<int> &arr, int n, int i)
{
    if (i >= n)
        return true;
    if (arr[i] < arr[i - 1])
    {
        return false;
    }
    return CheckIsSorted(arr, n, i + 1);
}
//-----------------------------------------
int BSrecursion(vector<int> &arr, int s, int e, int target)
{
    if (s > e)
        return -1;
    int mid = (s + e) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    if (arr[mid] < target)
    {
        return BSrecursion(arr, mid + 1, e, target);
    }
    else
    {
        return BSrecursion(arr, s, mid - 1, target);
    }
}
//-----------------------------------------
void printAllSubsequenceOf_String(string str, string output, int i, vector<string> &ans)
{
    // Base case
    if (i >= str.length())
    { // jub subhi i pointer at last str.length se bade ho jayenge to print each output
        ans.push_back(output);
        return;
    }
    // Exclude
    printAllSubsequenceOf_String(str, output, i + 1, ans);
    // Include
    output = output + str[i];
    printAllSubsequenceOf_String(str, output, i + 1, ans);
}
//-----------------------------------------
void printAllSubsequenceof_Array(vector<int> &arr, vector<int> &output, int i, vector<vector<int>> &ans)
{
    // Base case
    if (i >= arr.size())
    {
        ans.push_back(output); // Store the current subsequence
        return;
    }

    // Exclude current element
    printAllSubsequenceof_Array(arr, output, i + 1, ans);

    // Include current element
    output.push_back(arr[i]);
    printAllSubsequenceof_Array(arr, output, i + 1, ans);

    // Backtrack
    output.pop_back();
}
//-----------------------------------------
int MinCoinRequired(vector<int> &arr, int target)
{
    // Base case
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = MinCoinRequired(arr, target - arr[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    return mini;
}
//----------------------------------------
int FindMaxCutOf_Rod(int n, int x, int y, int z)
{
    // Base case
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }
    int ans1 = FindMaxCutOf_Rod(n - x, x, y, z) + 1; // here each +1 denotes to bachi hui road means ager ek function se ek side ke road ka ans nikal rahe hai to + 1 dusri rod ko represent ker rahi hai;
    int ans2 = FindMaxCutOf_Rod(n - y, x, y, z) + 1;
    int ans3 = FindMaxCutOf_Rod(n - z, x, y, z) + 1;

    int ans = max(ans1, max(ans2, ans3));

    return ans;
}
//-----------------------------------------
void FindMaxSumOfNon_Adjacent(vector<int> &arr, int i, int sum, int &maxi)
{
    // Base case
    if (i >= arr.size())
    {
        maxi = max(sum, maxi);
        return;
    }

    // Include
    FindMaxSumOfNon_Adjacent(arr, i + 2, sum + arr[i], maxi);
    // Exclude
    FindMaxSumOfNon_Adjacent(arr, i + 1, sum, maxi);
}
//-----------------------------------------
int Find_LastOccOFChar(string &str, char &target, int i)
{
    // Base case
    if (i < 0)
        return -1;

    if (str[i] == target)
    {
        return i;
    }
    Find_LastOccOFChar(str, target, i - 1);
}
//-----------------------------------------
void ReverseString(string &str, int start, int end)
{
    if (start > end)
    {
        return;
    }
    swap(str[start], str[end]);
    ReverseString(str, start + 1, end - 1);
}
//-----------------------------------------
void AddingTwoString(string &num1, int p1, string &num2, int p2, int carry, string &ans)
{
    // Base Case
    if (p1 < 0 && p2 < 0)
    {
        if (carry != 0)
            ans.push_back(carry + '0');
        return;
    }

    int n1 = ((p1 >= 0) ? num1[p1] : '0') - '0'; // bus pointer ko handle kiya hai ke kam jada value ke case me garbage value na aayue for example - "12" + "123"
    int n2 = ((p2 >= 0) ? num2[p2] : '0') - '0';
    int sum = n1 + n2 + carry;
    int digit = sum % 10;
    carry = sum / 10;

    ans.push_back(digit + '0');

    AddingTwoString(num1, p1 - 1, num2, p2 - 1, carry, ans);
}
//-----------------------------------------
bool CheckPalindrome(string &str, int i, int j)
{
    // Base case
    if (i >= j)
    {
        return true;
    }

    if (str[i] != str[j])
    {
        return false;
    }
    CheckPalindrome(str, i + 1, j - 1);
}
//-----------------------------------------
void RemoveAllOccurenceOfSubstring(string &str, string &part, int i)
{
    // Base case
    if (i >= str.length() - part.length())
    {
        return;
    }

    int pos = str.find(part);
    if (pos != string::npos)
    {
        // str.erase(pos , part.length());
        // =========OR (you can do without erase method also)============
        string left_str = str.substr(0, pos);
        string right_str = str.substr(pos + part.size(), str.size());
        str = left_str + right_str;
    }
    RemoveAllOccurenceOfSubstring(str, part, i + 1);
}
//-----------------------------------------
void FindAllSubarray_Recursion(vector<int> &arr, int start, int end)
{
    // Base case
    if (end == arr.size())
    {
        return;
    }

    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    FindAllSubarray_Recursion(arr, start, end + 1);
}
void FindAllSubstring(vector<int> &arr)
{
    for (int start = 0; start < arr.size(); start++)
    {
        int end = start;
        FindAllSubarray_Recursion(arr, start, end);
    }
}
//-----------------------------------------
void BuyAndSell(vector<int> &arr, int &BuyPrice, int &profit, int i)
{
    // Base case
    if (i >= arr.size())
    {
        return;
    }
    // ek kaam mene kiya baki recursion karega!
    if (arr[i] < BuyPrice)
    {
        BuyPrice = arr[i];
    }
    else if (arr[i] - BuyPrice > profit)
    {
        profit = arr[i] - BuyPrice;
    }

    BuyAndSell(arr, BuyPrice, profit, i + 1);
}
//-----------------------------------------
void FindMaxAmount_RObbed(vector<int> &arr , int i , int sum , int &maxi){
    //base case
    if(i >= arr.size()){
        maxi = max(sum , maxi);
        return;
    }
    //Include
    FindMaxAmount_RObbed(arr , i+2 , sum+arr[i], maxi);
    //Exclude
    FindMaxAmount_RObbed(arr , i+1 , sum , maxi);
}
//-----------------------------------------







int main()
{
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

    //! Note : String me char find kerne wale qus ke niche maine 3 varity ke qus(9,10,11) kiye hai okk!!!

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

    // 15. Find all Possible Subsequence of a string using Recusion (method - Includign/Excluding)?
    // string str = "abc";
    // string output = "";
    // int i = 0 ;
    // vector<string> ans;
    // printAllSubsequenceOf_String(str,output,i,ans);
    // for(auto it : ans){
    //     cout<<it<<endl;
    // }

    // extra 16. Find all Possible Subsequence of an Array using Recursion (method - Including/Excluding)?
    //  vector<int> arr = {1, 2, 3}; // Example array
    //  vector<int> output;
    //  vector<vector<int>> ans;
    //  int i = 0;
    //  printAllSubsequenceof_Array(arr, output, i, ans);
    //  // Print all subsequences
    //  for (auto seq : ans)
    //  {
    //      for (auto num : seq)
    //      {
    //          cout << num << " ";
    //      }
    //      cout << endl;
    //  }

    //! Recursion Level-4

    // 16. Find Minimum element required of an Array whose sum is equal to Target (Coins Problem)
    // vector<int> arr = {2,3};
    // int target = 5;
    // int ans = MinCoinRequired(arr,target);
    // cout<<ans;

    // 17. Cut Maximum segment of Rod (Metal Rod cutting Problem)?
    // int n = 7;
    // int x = 5, y = 2,z = 2 ;
    // int ans = FindMaxCutOf_Rod(n,x,y,z);
    // if(ans < 0){
    //     ans = 0;
    // }
    // cout<<"Maximum cut of Metal Rod is : "<< ans;

    // 18. Maximum sum of Non-Adjacent Element of array using Recursion (Method:- Including/Excluding)
    // vector<int> arr = {2,1,4,9};
    // int maxi = INT_MIN;
    // int sum = 0 ;
    // int i =  0;
    // FindMaxSumOfNon_Adjacent(arr,i, sum , maxi);
    // cout<<maxi;

    //! Recursion 13 Assignment QUS :-

    // Qus1. Last Occurence of a Character?
    // string str = "abcddedg";
    // char target = 'd';
    // int i = str.length()-1;
    // int ans = Find_LastOccOFChar(str,target,i);
    // cout<<"Last Occurence of "<<target<<" is "<<ans;

    // Qus2. Reverse a String Using Recursion?
    // string str = "himanshu";
    // int start = 0;
    // int end = str.length()-1;
    // ReverseString(str,start,end);
    // cout<<str;

    // Qus3. Adding Two String using Recursion (Leetcode - 415)
    // string num1 = "23";
    // string num2 = "329";
    // string ans = "";
    // int p1 = num1.length()-1;
    // int p2 = num2.length()-1;
    // int carry = 0;
    // AddingTwoString(num1 , p1 , num2 , p2 , carry , ans );
    // reverse(ans.begin(), ans.end());
    // cout<<ans;
    // int i = 10;
    // char s = i + '0';
    // cout<<s;

    // Qus4. Check Palindrome using Recursion?
    // string str = "madam";
    // int i = 0 , j = str.length()-1;
    // if(CheckPalindrome(str,i,j)){
    //     cout<<"Yes Palindrome!";
    // }else{
    //     cout<<"Not Palindrome!";
    // }

    // Qus4. Remove All Occurences of String?
    // string str = "daabcbaabcbc";
    // string part = "abc";
    // int i= 0;
    // RemoveAllOccurenceOfSubstring(str , part , i);
    // cout<<str;

    // Qus5. Print All Subarray using Recursion? (Did you know diff between SubSequence and Subarray see in my DSA third notebook black color first page)
    // vector<int> arr = {1, 2, 3,4,5};
    // FindAllSubstring(arr);

    // Qus6. Buy and Sell Stocks using Recursion?
    // vector<int> arr = {7,1,5,3,6,4};
    // int BuyPrice = INT_MAX;
    // int profit = 0;
    // int i = 0 ;
    // BuyAndSell(arr , BuyPrice , profit , i);
    // cout<<profit;

    // Qus7. House Rober (Leetcode - 198) // same wahi concept or sol hai level 4 je last qus wala Max nikalte hai jisme(Including/excluding)
        // vector<int> arr = {2,1,4,9};
        // int sum = 0 ;
        // int maxi = INT_MIN;
        // int i = 0;
        // FindMaxAmount_RObbed(arr , i , sum , maxi); 
        // cout<<maxi;
        
    // Qus8. 
        return 0;
}