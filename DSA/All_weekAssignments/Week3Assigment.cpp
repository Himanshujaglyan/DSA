//Assigment Week three (Array qus)
#include<bits/stdc++.h>
using namespace std;
int main(){
    // -----------------Spiral Matrix;----------------------    
//    vector<vector<int>> arr = {
//     {1,2,3,4,5},
//     {5,6,7,8,9},
//     {9,10,11,12,13},
//     {14,15,16,17,18}
// };
//   vector<int> ans;
//   int row = arr.size();
//   int col = arr[0].size();
//   int count = 0;
//   int startingrow = 0;
//   int endingcol = col-1;
//   int endingrow = row - 1;
//   int startcol = 0;
//     int total_element = row*col;
//   while(count < total_element){
//     for (int i = startcol; i <= endingcol && count<total_element ;i++)
//     {
//         ans.push_back(arr[startingrow][i]);
//         count++;
//     }
//     startingrow++;
//     for (int i = startingrow; i <= endingrow && count<total_element;i++)
//     {
//         ans.push_back(arr[i][endingcol]);
//         count++;
//     }
//     endingcol--;
//     for (int i = endingcol; i >= startcol && count<total_element ;i--)
//     {
//         ans.push_back(arr[endingrow][i]);
//         count++;
//     }
//     endingrow--;
//     for (int i = endingrow; i >= startingrow && count<total_element;i--)
//     {
//         ans.push_back(arr[i][startcol]);
//         count++;
//     }
//     startcol++;
//   }

//   for (int i = 0; i < ans.size(); i++)
//   {
//     cout<<ans[i]<<" ";
//   }
 
// Qus Add two no represented by two array-------------------------
// vector<int> arr1 = {9,5,4,9};
// vector<int> arr2 = {2,1,4};
// int i = arr1.size() - 1;
// int j = arr2.size() - 1;
// int carry = 0;
// vector<int> ans;    
// while (i>=0 && j>=0)
//     {
//         int x = arr1[i] + arr2[j] + carry;
//         int digit = x % 10;
//         ans.push_back(digit);
//         carry = x / 10;
//         i--,j--;
//     }
// while (i>=0)
//     {
//         int x = arr1[i] + 0 + carry;
//         int digit = x % 10;
//         ans.push_back(digit);
//         carry = x / 10;
//         i--;
//     }
// while (j>=0)
//     {
//         int x = 0 + arr2[j] + carry;
//         int digit = x % 10;
//         ans.push_back(digit);
//         carry = x / 10;
//         j--;
//     }
//     if(carry){
//         ans.push_back(carry);
//     }

//     reverse(ans.begin() , ans.end());
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout<<ans[i];
//     }
    

// Qus Find Factorial of a large number----------------------
// int number = 7;
// vector<int> ans;
// ans.push_back(1);
// int carry = 0;
// for (int i = 2; i <= number; i++)
// {
//     for(int j = 0 ; j < ans.size() ; j++){
//         int x = ans[j] * i + carry;
//         ans[j] = x % 10;
//         carry = x / 10;
//     }
//     while(carry){
//         ans.push_back(carry%10);
//         carry = carry / 10;
//     }
// }
//     reverse(ans.begin(),ans.end());
//     for(auto e : ans){
//         cout<<e;
//     }


// Qus Remove All Duplicates from Sorted array
// vector<int> arr = {0,0,0,1,1,2,2,2,2,3,3,4};
// int i = 0;
// int count = 1;
// for (int j = 0; j < arr.size(); j++)
// {
//     if(arr[i] != arr[j]){
//         i++;
//         arr[i] = arr[j];
//         count++;
//     }
// }   
//  for (int i = 0; i < count; i++)
//  {
//     cout<<arr[i]<<" ";
//  }
 

// Qus Maximum subarray average sum;
// class Solution {
//     public:
//         double findMaxAverage(vector<int>& arr, int k) {
//             int i = 0 , j = 0 , sum = 0 ;
//             double max_sum = INT_MIN;
//             while(j < arr.size()){
//                 sum += arr[j];
//                 if(j-i+1 == k){
//                  max_sum = max(max_sum, (double)sum);
//                     sum -= arr[i];
//                     i++;
//                 }
//                 j++;
//             }
//             return max_sum/k;
            
//         }
//     };
    return 0;
}