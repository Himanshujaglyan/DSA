#include<bits/stdc++.h> ///Binary Search Qus
using namespace std;
int  FirstOccurencebinarySearch(vector<int> arr ,int target){
    int start = 0 , end = arr.size() - 1;
    int mid = start + (end - start) /2;
    int ans  = -1;
    while(start <= end){
        if(arr[mid] == target){
            ans = mid;
            end = mid - 1;
        }else if(target < arr[mid]){
            end = mid - 1; 
        }else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}
//---------------------------------
int findMissing(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int start = arr[0]; // starting element

    while (low <= high) {
        int mid = (low + high) / 2;

        // Check if current element follows the expected pattern
        if (arr[mid] == start + mid) {
            // Left part is fine, go right
            low = mid + 1;
        } else {
            // Pattern broke, go left
            high = mid - 1;
        }
    }

    // At the end, 'low' will point to the missing index
    return start + low;
}
//  ----------------------------------
int findSquareRoot(vector<int> arr , int target){
    int start = 0, end = arr.size() - 1;
    int ans = -1;
    int mid = start + (end - start)/2;
    while(start <= end){    
        if(mid * mid == target){
        return mid;
        }
        else if(mid * mid < target){
        ans = mid;
        start = mid + 1;
        }else {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    } 
    return ans;
}
// ---------------------------------------
double floatValueSquareRoot(int get , int target){
    double step = 0.1;
    for (int i = 0; i < 3; i++)
    {
        for(int j = get ; j * j <= target ; j = j + step ){
            get = j;
        }
        step = step / 10;
    }
    return get;
}
// -----------------------------------------
int findElementInNearlySortedArray(vector<int> arr , int target){
    int start = 0 , end = arr.size() - 1;
    int mid = start + (end - start)/2;
    int ans = -1;
    while(start <= end){
        if(arr[mid] == target){
            return mid;
        }
        
        else if(arr[mid-1] == target){
            return mid-1;
        }
        
        else if(arr[mid+1] == target){
            return mid+1;
        }

        else if(target > arr[mid]){
            start = mid + 2;
        }
        else{
            end = mid - 2;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}
//-----------------------------------------
int findQuotientofGivenNumber(vector<int> arr , int divident , int divisor){
    int start = 0 , end = arr.size() - 1;
    int mid = start + (end - start) /2;
    int ans = -1;
    while(start <= end){
        if(arr[mid] * divisor == divident){
            return mid;
        }else if(arr[mid] * divisor < divident){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }   
    return ans;
}
//-----------------------------------------
int FindOddOccuringElement(vector<int> arr){
    int start = 0 , end = arr.size() -1;
    int mid = start + (end - start)/2;
    int ans = -1;
    while(start <= end){
        if(start == end){
            return arr[mid];
        }else if(mid % 2 == 0){
            if(arr[mid] == arr[mid+1]){
                start = mid + 2;
            }else{
                end = mid;
            }
        }else {
        if(arr[mid] == arr[mid-1]){
                start = mid +1;
        }else{
            end = mid -1;
        }
    }
    mid = start + (end - start)/2;
    }
    return ans;
}
//-----------------------------------------
int getLargestPivotElementInRotatedArray(vector<int>& arr){
    int start = 0 , end = arr.size()-1;
    int mid = start + (end - start)/2;
    while(start <= end){
        if(start == end){
            return start;
        }else if(mid < end && arr[mid] > arr[mid + 1]){
            return mid;
        }else if(mid > start && arr[mid] < arr[mid - 1]){
            return mid-1;
        }else if(arr[mid] < arr[start]){
            end = mid - 1;
        }else {
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}
//----------------------------------------
int FindTargetInRotatedArray(vector<int> arr, int target , int start , int end){
    int mid = start + (end - start)/2;
    while(start <= end){
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] > target){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }   
    return -1;
}
//----------------------------------------
int binarySearch(vector<int>& arr , int start , int target){
    int end = arr.size()-1;
    int mid = start + (end - start)/2;
    while(start <= end){
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] > target){
            end = mid -1 ;
        }else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}
//---------------------------------------
void FintClosestSubbary(vector<int>& arr , int k , int x){
    int l = 0 , h = arr.size() -1;
    while(h - l >= k){
        if(x - arr[l] > arr[h] - x){
            l++;
        }else{
            h--;
        }
    }
    for(int i = l ; i <= h ; i++){
        cout<<arr[i]<<" ";
    }
}
//--------------------------------------
bool isPossible(vector<int> arr , int k , int mid ){
    int studCount = 1;
    int PagesCount = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > mid) return false;  // Book too big
            if (PagesCount + arr[i] <= mid) {
                PagesCount += arr[i];
            } else {
                studCount++;
                PagesCount = arr[i];
                if (studCount > k) return false;
            }
        }
        return true;
}
//-------------------------------------
bool isPossibleFor_PainterProble(vector<int>& arr , int k , int mid){
    int PainterCount = 1;
    int TotalTiming = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > mid) return false;
        if(TotalTiming + arr[i] <= mid){
            TotalTiming += arr[i];
        }else{
            PainterCount++;
            TotalTiming = arr[i];
        }
        if(PainterCount > k) return false;
    }
    return true;
}
//------------------------------------
bool isPossible_AggressiveCow(vector<int>& arr , int k , int mid){
    int CowCount = 1;
    int lastStall = arr[0]; // mene first cow ko pahle stall pe rakh dea ab me second cow ke possition ke liye 
                            // dekhunga ke jo mid aaaya hai ager utne distance pe cow hai to fight nahi hogi

    for (int i = 1; i < arr.size(); i++)
    {
        if(arr[i] - lastStall >= mid){ // distance  ager sahi beth gaya to fir agali cow ke baare me soch
            CowCount++;
            if(CowCount == k){
                return true;
            }
            lastStall = arr[i];
        }
    }
    return false;
}
//------------------------------------
bool isPossible_EKO_SPOJ(vector<int> trees , int mid , int m){
    int woodCollection = 0;
    for(int height : trees){
        if(height > mid){
            woodCollection += (height-mid);
        }
    }
    return woodCollection >= m;
}
//------------------------------------


int main(){

// Qus Fist Occurence of element in array****
    // vector<int> arr = {1,3,4,4,4,4,5,6,7};
    // int target = 5;
    // int firstOccurence = FirstOccurencebinarySearch(arr , target);
    // cout<<"firstOccurence of "<<target <<" is "<<firstOccurence;

//! Qus Find Missing Element jaha range given na ho
    // Ex: sum wala or XOR wala logic tub lag sakta hai ager missing element 1 to N ke bich find ker
    // ho lekin jaha range kisi number se given ho waha Binary search hi use hoga okk!!
    // int main(){
    //     vector<int> arr = {10,11,12,14,15};
    //     int find = findMissing(arr);
    //    cout<<find;

// Qus Find square root of given number****
    // vector<int> arr = {0,1,2,3,4,5,6,7,8,9,10};
    // int target = 10;
    // int get = findSquareRoot(arr,target);
    // double finalans = floatValueSquareRoot(get,target);
    // cout<<get;

// Qus Find element in nearly sorted array:****
    // vector<int> arr = {10,3,40,20,50,80,70};
    // int target = 50;
    // int findElement= findElementInNearlySortedArray(arr,target);
    // cout<<"Element found at index = "<<findElement;

// Qus Divident and divisor is given find Quotient?
    // vector<int> arr = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
    // int divident = 22;
    // int divisor = 7;
    // int Quotient = findQuotientofGivenNumber(arr, divident , divisor);
    // // cout<< divident <<"/"<<divisor<<" Quotient is = "<<Quotient;
    // double step = 0.1;
    // double finalans = Quotient;
    // for (int i = 0; i < 3; i++)
    // {
    //     for(double j = Quotient ; j * divisor <= divident ; j = j+step){
    //         finalans= j; 
    //     }
    //     step = step / 10;
    // }
    // cout<<finalans;

// Qus Find the odd occuring Element in an Array?
    // vector<int> arr = {1,1,2,2,3,3,4,4,3,5,5};
    // int ans = FindOddOccuringElement(arr);
    // cout<<ans;
    
// Qus Largest Pivot element in sorted rotated array?
    // vector<int> arr = {7,8,9,10,11,1,2};
    // int ans = getLargestPivotElementInRotatedArray(arr);
    // cout<<arr[ans];

// Qus Search In rotated sorted array? (Pivot concept is also follow here)
    // vector<int> arr = {4,5,6,7,0,1,2};
    // int target = 0;
    // int getPivotElementIndex = getLargestPivotElementInRotatedArray(arr);
    // // cout<<getPivotElementIndex;
    // int ans = 0;
    // if(target >= arr[0] && target <= arr[getPivotElementIndex]){
    //     ans = FindTargetInRotatedArray(arr,target , 0 , getPivotElementIndex);
    // }else{
    //    ans = FindTargetInRotatedArray(arr,target , getPivotElementIndex + 1 , arr.size() -1 );
    // }
    // cout<<"Target Found at Index = "<<ans;

    // ----------------------------------------------------------------------
    // --------------------- Assignment week 3 qus Bellow ------------------
    // ---------------------------------------------------------------------
   
//Qus1 K-Diff Pair In an Array?
    //Note : Two solve this qus (2 Pointer / Binary Search) But we provide BS solution over here 
    //and 2 pointer solution is written in NoteBook
    // vector<int> arr = {1,3,1,5,4}; //given unsorted array
    // int k = 2; // this is difference given (This qus is similar to Two sum qus)
    // sort(arr.begin(),arr.end());
    // set<pair<int,int>> ans;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     if(binarySearch(arr,i+1, arr.size()-1) != -1){
    //         ans.insert({arr[i],arr[i]+k});
    //     }
    // }
    // cout<<"Total difference pair count is "<<ans.size();

//Qus2 Find k-Closest Element?
    //Note: es qus ke (2 Pointer /Binary Search) dono approch hai per 2 pointer ka to chlo koi 
    // sense hai solution ka lekin BS wale ka nahi hai sirf lower bound lagane ke liye BS bol dea
    // To es solution ko hum 2 Pointer approch se kerange okk
    // vector<int> arr = {12,16,22,30,35,39,42,45,48,50,53,55,56};
    // int k = 4 , x = 35;
    // FintClosestSubbary(arr, k , x);

//Qus3 Exponential search & Unbounded Binary Search?  !!!Pending its sol on notion<DSA last slide

//Qus4 Book Allocation Problem?
    // vector<int> arr = {10,20,30,40};
    // int m = 2;
    // int start = 0 , end = accumulate(arr.begin(),arr.end(),0);
    // int mid = start + (end - start)/2;
    // int ans = 0;
    // while(start <= end){
    //     if(isPossible(arr,m,mid)){
    //         ans = mid;
    //         end = mid - 1;   
    //     }else{
    //         start = mid + 1;
    //     }
    //     mid = start + (end - start)/2;
    // }
    // cout<<ans;

//Qus5 Painter Partision Problem (Similar to Book allocation problem);
    // vector<int> arr = {10,20,30,40};
    // int k = 2;
    // int start = 0 , end = accumulate(arr.begin(),arr.end(),0);
    // int ans = -1;
    // while(start <= end){
    //     int mid = start + (end - start)/2;
    //     if(isPossibleFor_PainterProble(arr,k,mid)){
    //         ans = mid;
    //         end = mid - 1; // because we need minimum timing
    //     }else{
    //         start = mid + 1; // jab posible hi nahi hai to search in right
    //     }
    // }
    // cout<<ans;

//Qus6 Aggresive Cows Problem
    // vector<int> arr = {1,2,4,8,9};
    // sort(arr.begin(),arr.end()); // sorting is mendaitary
    // int k = 3;
    // int ans = 0;
    // int start = 1 , end = arr.back() - arr[0]; 
    // while(start <= end){
    //     int mid = start + (end - start)/2;
    //     if(isPossible_AggressiveCow(arr, k , mid)){//matlb mene theeno cow ko ese place me rakh dea hai jaha vo lade na 
    //       ans = mid;
    //       start = mid + 1; //because hame max cahiye na    
    //     }else{
    //         end = mid - 1; // eska matlb hai kisi cow ko stall nahi mil raha hai to distance kam kerna padega
    //     }
    // }
    // cout<<"Maximum distance of Minimum = " <<ans;

//Qus7 EKO-SPOJ Problem?
    // vector<int> arr = {20,15,10,17};
    // int m = 7;
    // int maxElement = *max_element(arr.begin(), arr.end());
    // int start = 0 , end = maxElement;
    // int ans = -1;
    // while(start <= end){
    //     int mid = start + (end - start)/2;
    //     if(isPossible_EKO_SPOJ(arr, mid , m)){
    //         ans = mid;
    //         start = mid + 1; // ab yaha merko jo machine size aaya hai usko badana hai taki wook kam mile
    //     }else{
    //         end = mid - 1; // ab jo hai machine size kam karaenge jisse wood jada mmilegi
    //     }
    // }
    // cout<<ans;

    return 0;
}