
//Quick Sort
#include<bits/stdc++.h>
using namespace std;
int piviotElementPosition(vector<int>&arr , int start , int end){
    int piviotIndex = start;
    int piviotElement = arr[piviotIndex];
		//find total smaller element then the piviot element
    int count = 0;
    for (int i = start+1; i < arr.size(); i++)
    {
        if(arr[i] <= arr[piviotIndex]){
            count++;
        }   
    }
    //place piviot element at right position
    int rightIndex = start+count;
    swap(arr[piviotIndex] , arr[rightIndex]);
    piviotIndex = rightIndex;
		//all small and larger than the piviot arrange using this
    int i = start , j = end;
    while(i < piviotElement && j > piviotElement){
        while(arr[i] <= piviotElement){
            i++;
        }
        while(arr[j] > piviotElement){
            j--;
        }
        if(i < piviotElement && j > piviotElement){
            swap(arr[i++] , arr[j--]);
        }
    }
    return piviotIndex;
}

void quickSort(vector<int> &arr , int start , int end){
    //base case
    if(start >= end) return;
    int p = piviotElementPosition(arr , start , end);
    quickSort(arr,start,p-1);
    quickSort(arr,p+1 , end);
}
int main(){
    vector<int> arr = {8,1,3,4,20,20,30,0,40};
    int start = 0;
    int end = arr.size()-1;
    quickSort(arr,start,end);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}