//! Divide & Conquer (Backtracking)

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
    int piviotIndex = start;
    int piviotElement = arr[start];

    // Find Right Position where we have to place our piviot Element
    int count = 0;
    for (int i = start + 1; i < arr.size(); i++)
    {
        if (arr[i] <= piviotElement) // equal ho tub bhi chalega
            count++;
    }
    // Right Possition where piviot will come
    int rightIndex = start + count;
    swap(arr[rightIndex], arr[piviotIndex]);
    piviotIndex = rightIndex;

    int i = start;
    int j = end;
    // Now piviot ek possition per set ho gaya hai ab left me saare piviot se smaller rakhenge and right me piviot se bade rakhenge
    while (i < piviotIndex && j > piviotIndex)
    {
        // ab hum check ker rahe hai ke left side me saare small element hai na to I++
        while (arr[i] <= piviotElement)
        {
            i++;
        }
        while (arr[j] > piviotElement)
        {
            j--;
        }

        if (i < piviotIndex && j > piviotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return piviotIndex;
}
//----------------------------------------------------
void quickSort(vector<int> &arr, int start, int end)
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

//! Backtracking
void Permutation(string &str, int i)
{
    // Base case
    if (i >= str.length())
    {
        cout << str << endl;
        return;
    }

    for (int j = i; j < str.length(); j++)
    {
        swap(str[i], str[j]);

        // Recursion (for loop ke ander hi kuki j her ek i ke liye swap hoga na)
        Permutation(str, i + 1);

        // Backtracking
        swap(str[i], str[j]); // ager hum by reference str ko pass ker rahe hai to usse orignal string update ho rahi hai sirf esi liye hamne backtracking ka use kerke orignal string ko dubara bana dea hai lekin ager hum ager reference pass na kare to backtracking ke bhi need nahi hai!!
    }
}
//----------------------------------------------------
bool isSafe(vector<vector<int>> &arr, int row, int col, int i, int j, vector<vector<bool>> &visited)
{
    if ((i >= 0 && i < row) && (j >= 0 && j < col) && (arr[i][j] == 1) && (visited[i][j] == false))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void FindPathInMaze(vector<vector<int>> &arr, int row, int col, int i, int j, vector<vector<bool>> &visited, vector<string> &path, string output)
{
    // Base case
    if (i == row - 1 && j == col - 1)
    {
        path.push_back(output);
        return;
    }

    // Down -->(i+1 , j)
    if (isSafe(arr, row, col, i + 1, j, visited))
    {
        visited[i + 1][j] = true;
        FindPathInMaze(arr, row, col, i + 1, j, visited, path, output + 'D');
        // Backtrack
        visited[i + 1][j] = false;
    }
    // Left -->(i , j-1)
    if (isSafe(arr, row, col, i, j - 1, visited))
    {
        visited[i][j - 1] = true;
        FindPathInMaze(arr, row, col, i, j - 1, visited, path, output + 'L');
        // Backtrack
        visited[i][j - 1] = false;
    }

    // Right -->(i,j+1)
    if (isSafe(arr, row, col, i, j + 1, visited))
    {
        visited[i][j + 1] = true;
        FindPathInMaze(arr, row, col, i, j + 1, visited, path, output + 'R');
        // Backtrack
        visited[i][j + 1] = false;
    }

    // Up -->(i-1 , j)
    if (isSafe(arr, row, col, i - 1, j, visited))
    {
        visited[i - 1][j] = true;
        FindPathInMaze(arr, row, col, i - 1, j, visited, path, output + 'U');
        // Backtrack
        visited[i - 1][j] = false;
    }
}
//----------------------------------------------------
void PrintAllArrayWithPossibleQueenPossition(vector<vector<char>> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}
bool isSafe(vector<vector<char>> &arr, int n, int row, int col)
{
    // Bhai baat esi hai muje apne piche wale se hi to check kerna hai ke piche wale col me queen attack na ker de!!

    // Left Row
    int i = row;
    int j = col - 1;
    while (j >= 0)
    {
        if (arr[i][j] == 'Q')
        {
            return false; // left row me merko queen mil gayi to ma kah dunga merko khatra hai yaha
        }
        j--;
    }
    // upper Left Diagonal
    i = row - 1;
    j = col - 1;
    while (i >= 0 && j >= 0)
    {
        if (arr[i][j] == 'Q')
        {
            return false;
        }
        i--, j--;
    }
    // Lower lef Diagonal
    i = row + 1;
    j = col - 1;
    while (i < n && j >= 0)
    {
        if (arr[i][j] == 'Q')
        {
            return false;
        }
        i++, j--;
    }

    return true;
}
void PlaceAllQueens(vector<vector<char>> &arr, int n, int col)
{
    // Base case (jub col hi kahtam ho jayenge yani or queen ko place ne kerna)
    if (col >= n)
    {
        PrintAllArrayWithPossibleQueenPossition(arr, n);
        return;
    }
    // Place queen at correct possition where previous queens not attack
    for (int row = 0; row < n; row++)
    {
        if (isSafe(arr, n, row, col))
        {
            arr[row][col] = 'Q';
            PlaceAllQueens(arr, n, col + 1);
            // Backtracking
            arr[row][col] = '-'; // taki next possible way nikal sake queens ko palce kerne ka!
        }
    }
}

//-----------------------------------------------------
void GenerateAllPossibleParenthesis(vector<string> &ans, int open, int close, string output)
{
    // Base case
    if (open == 0 && close == 0)
    {
        ans.push_back(output);
        return;
    }

    // Include open bracket
    if (open > 0)
    {
        output.push_back('(');
        GenerateAllPossibleParenthesis(ans, open - 1, close, output);
        // Backtracking
        output.pop_back();
    }
    // Include close bracket
    if (close > open)
    {
        output.push_back(')');
        GenerateAllPossibleParenthesis(ans, open, close - 1, output);
        // Backracking
        output.pop_back();
    }
}
//----------------------------------------------------
void FindPossibleCombination(vector<string> &mapping, string digits, vector<string> &ans, string output, int index)
{
    // Base case
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }

    int key = digits[index] - '0'; // given string me se character ko integer me convert ker de
    string value = mapping[key];   // key ke value jo mapped hai mapping array me usko store ker liya
    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        FindPossibleCombination(mapping, digits, ans, output, index + 1);
        // Backtracking
        output.pop_back(); // jub because initially string empty the to hame empty hi bana ke rakhna hai  okk!!
    }
}
//---------------------------------------------------
//!Assignment Qus:
long long Inversion_Merge(vector<int> &arr, int start, int end, int mid)
{
    int len1 = mid - start + 1;
    int len2 = end - mid;

    vector<int> leftArray(len1);
    vector<int> rightArray(len2);

    int k = start;
    for (int i = 0; i < len1; i++)
        leftArray[i] = arr[k++];

    k = mid + 1;
    for (int i = 0; i < len2; i++)
        rightArray[i] = arr[k++];

    int i = 0, j = 0, x = start;
    long long invCount = 0;

    while (i < len1 && j < len2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[x++] = leftArray[i++];
        }
        else
        {
            arr[x++] = rightArray[j++];
            invCount += (len1 - i); // 👈 Inversion Count Increase bus ke left ke phir baki saare bhi right wale element se bade honge
        }
    }

    while (i < len1)
        arr[x++] = leftArray[i++];

    while (j < len2)
        arr[x++] = rightArray[j++];

    return invCount;
}
//----------------------------------------------------------
long long Inversion_MergeSort(vector<int> &arr, int start, int end)
{
    long long invCount = 0;
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        invCount += Inversion_MergeSort(arr, start, mid);
        invCount += Inversion_MergeSort(arr, mid + 1, end);

        invCount += Inversion_Merge(arr, start, end, mid);
    }
    return invCount;
}
//---------------------------------------------------------
 void NewQuickSort(vector<int> &arr , int start , int end){
    if(start >= end){
        return;
    }

    int pivot = end;
    int i = start - 1;
    int j = start;
    
    while(j < pivot){
        if(arr[j] < arr[pivot]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;//always increase j
    }
    //Now ab last me pivot ko uski sahi jaga per rakh denge 
    i++;
    swap(arr[i],arr[pivot]);
    //And ab half half part per recursion chla denge
    NewQuickSort(arr,start , i-1);//kuki i es time pivot ke possition hai 
    NewQuickSort(arr , i+1 , end);//kuki i es time pivot ke possition hai

 }
//---------------------------------------------------------




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
    // vector<int> arr = {8, 1, 3, 4, 20,20, 30,0, 40};
    // int start = 0;
    // int end = arr.size()-1;
    // quickSort(arr, start, end);
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    //! Backtracking

    // Qus1 : Print All Possible Permutation of String?
    // string str = "abc";
    // int i = 0;
    // Permutation(str , i);

    // Qus2 : Rat in a Maze?
    // vector<vector<int>> arr = {{1,0,0},{1,1,0},{1,1,1}};
    // int row = 3;
    // int col = 3;
    // vector<vector<bool>> visited(row,vector<bool>(col,false));
    // visited[0][0] = true;
    // vector<string> path;
    // string output = "";
    // FindPathInMaze(arr , row , col ,0 , 0 , visited ,path , output);
    // for(auto it : path){
    //     cout<<it<<endl;
    // }

    // Qus3 : N-Queens (leetcode 51)
    // int n = 4;
    // vector<vector<char>> arr(n , vector<char>(n,'-'));//initialy sabhi position ko 0 ker dea hai means abhi koi queen palce nahi hai
    // int col = 0;
    // PlaceAllQueens(arr , n , col);

    // Qus4 : Generate Parenthesis (Leetcode - 22) Note: es qus bus ek cheeze ajib hai jub close>end kerte hai
    // int n = 2;
    // vector<string> ans;
    // string output = "";
    // int open = n;
    // int close = n;
    // GenerateAllPossibleParenthesis(ans,open,close,output);
    // for(auto it : ans){
    //         cout<<it<<endl;
    // }

    // Qus5 : Letter combination of a Phone Number (Leetcode - 17)
    // string digits = "23";
    // vector<string> mapping(10);
    // mapping[2] = "abc";
    // mapping[3] = "def";
    // mapping[4] = "ghi";
    // mapping[5] = "jkl";
    // mapping[6] = "mno";
    // mapping[7] = "pqrs";
    // mapping[8] = "tuv";
    // mapping[9] = "wxyz";
    // vector<string> ans;
    // string output = "";
    // int index = 0;
    // FindPossibleCombination(mapping , digits , ans , output , index);
    // for(auto it : ans){
    //     cout<<it<<endl;
    // }

    //! Assignment Qus
    
    // Qus1 :Count Inversion (Pura Merge sort hi hai bus bus el line change hai merge algo ke ander you just need to remaimber)
    // vector<int> arr = {8, 4, 2, 1};
    // int start = 0;
    // int end = arr.size() - 1;
    // long long inversionCount = Inversion_MergeSort(arr, start, end);
    // cout << "Sorted Array: ";
    // for (int i = 0; i < arr.size(); i++)
    //     cout << arr[i] << " ";
    // cout << "\nTotal Inversion Count: " << inversionCount << endl;
    
    // Qus2 : In-Place Merge sort (Complex to implement and also TC increased in worst case)
    
    // Qus3 : Maximum subarray Sum (Best ans using Kadane's Algorithm)

    // Qus4 : Quick Sort (Taking end element as Pivot Element)
        //     vector<int> arr = {7,2,1,8,6,3,5,4};
        //     int start = 0;
        //     int end = arr.size()-1;
        //    NewQuickSort(arr,start,end);  
        //     for (int i = 0; i < arr.size(); i++)
        //     {
        //         cout<<arr[i]<<" ";
        //     }
            
    return 0;
}
