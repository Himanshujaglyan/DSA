//! Divide & Conquer

#include <bits/stdc++.h>
using namespace std;
void Merge(vector<int> &arr, int start, int end, int mid)
{
    int len1 = mid - start + 1; // left array length
    int len2 = end - mid;       // right array length (or yaha end - mid + 1 esliye nahi likha kuki end - (mid + 1)+1 hota 1 se 1 cut ho jata then last me end - mid hi aata esliye direct likh dea )

    // create left and right array
    vector<int> leftArray(len1);
    vector<int> rightArray(len2);

    // Now jo bhi array bana hai unko alag alag left and right array me daal dete hai
    int k = start;
    for (int i = 0; i < len1; i++)
    {
        leftArray[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        rightArray[i] = arr[k++];
    }

    // Now ab final array me update kerange sorted way me yai hai final merging process
    int i = 0;     // leftArray ke 0 index per rakh dea ek pointer
    int j = 0;     // rightArray ke  0 index per rakh dea ek pointer
    int x = start; // Orignal array jo hai usi me change kerange to waha ek pointer 0 index per rakhe dea

    // now sort ke liye left and right array ke her elemenet ko compare kerange jo chota hoga use pahle rakte jayenge okk
    while (i < len1 && j < len2)
    {
        if (leftArray[i] < rightArray[j])
        {
            arr[x++] = leftArray[i++];
        }
        else
        {
            arr[x++] = rightArray[j++];
        }
    }

    // Note left and right array ke length kam jada ho sakti hai to use case me jiske element bacenge at last vo direct orignalArray me dall denge
    while (i < len1)
    {
        arr[x++] = leftArray[i++];
    }
    while (j < len2)
    {
        arr[x++] = rightArray[j++];
    }
}
//----------------------------------------------------
void MergeSort(vector<int> &arr, int start, int end)
{
    // Base case
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    // divide into left part using Recursion
    MergeSort(arr, start, mid);
    // divide into right part using Recursion
    MergeSort(arr, mid + 1, end);
    // Merge divided parts in sorted way
    Merge(arr, start, end, mid);
}
//----------------------------------------------------
int PiviotPosition(vector<int> &arr, int start, int end)
{
    // Consider Pivot Element
    int piviotIndex = 0;
    int piviotElement = arr[0];

    // Find Right Position where we have to place our piviot Element
    int count = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i] < piviotElement;
        count++;
    }
    // Right Possition where piviot will come
    int rightIndex = start+count;
    swap(arr[rightIndex] , arr[piviotElement]);

    //Now piviot ek possition per set ho gaya hai ab left me saare piviot se smaller rakhenge and right me piviot se bade rakhenge
    while(){
        //Note : ek baar revise kerke dubara solve kerio khud se kal
    }

}


    void quickSort(vector<int> & arr, int start, int end)
    {
        // Base case
        if (start >= end)
        {
            return;
        }

        // Place Piviot element at that position where all element on left of Pivot is smaller than the Pivot and on right side all or larger than the Pivot
        int p = PiviotPosition(arr, start, end);

        // Now sort the left part of array before Pivot element
        quickSort(arr, start, p - 1);

        // Now sort the right part of array after the Pivot Element
        quickSort(arr, p + 1, end);
    }

    int main()
    {

        // 1. Merge Sort
        //  vector<int> arr = {38,27,43,3,9,20}; //output: 3,9,20,27,38,43
        //  int start = 0;
        //  int end = arr.size()-1;
        //  MergeSort(arr , start , end);
        //  cout<<"Sorted Array :"<<endl;
        //  for (int i = 0; i < arr.size(); i++)
        //  {
        //      cout<<arr[i]<<" ";
        //  }

        
        // 2. Qucik Sort
        vector<int> arr = {8, 1, 3, 4, 20, 30, 40};
        int start = 0;
        int end = arr.size();
        quickSort(arr, start, end);

        return 0;
    }

    // Note es qus me problem hai kal khud se aake debud kerio without any help!!