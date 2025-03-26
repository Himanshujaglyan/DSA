#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[][4], int row, int col) // ROW-WISE
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void printArray2(int arr[][4], int row, int col) // COLUMN-WISE
{
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}
bool findTarget(int arr[][4], int row, int col, int target)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}
void rowWiseSum(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << endl;
    }
}
void printReverseDiagonal(int arr[4][4], int row, int col)
{
    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = 0; j < row; j++)
        {
            if ((i + j) == 3)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
}

void transpose(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i > j)
            {
                {
                    swap(arr[i][j], arr[j][i]);
                }
            }
        }
    }
}
void transpose2(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = i + 1; j < col; j++)
        {
            {
                swap(arr[i][j], arr[j][i]);
            }
        }
    }
}
int main()
{
    // int arr[3][4];
    // int brr[3][4] = {{1, 2, 3, 4}, {11, 22, 33, 44}, {111, 222, 333, 4444}};
    // int crr[][4] = {{1, 2, 3, 4}, {11, 22, 33, 44}, {111, 222, 333, 4444}};
    // int drr[][] = {{1, 2, 3, 4}, {11, 22, 33, 44}, {111, 222, 333, 4444}};  // ERROR // WE NEED TO SPECIFY COLUMN IN 2-D MATRIX AS FOR CONVERSION WE HAVE FORMLA (C*I+J)
    // int Err[3][] = {{1, 2, 3, 4}, {11, 22, 33, 44}, {111, 222, 333, 4444}}; // ERROR // WHEN PASSING IN FUNCTION WE ALSO NEED TO SPECIFY COLUMN

    // int arr[3][4] = {{1, 2, 3, 4}, {11, 22, 33, 44}, {111, 222, 333, 4444}};
    // printArray2(arr, 3, 4);

    // int crr[3][3][3] = {{{1, 2, 3}, {1, 2, 3}, {1, 2, 3}}, {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}}, {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}}};
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         for (int k = 0; k < 3; k++)
    //         {
    //             cout << crr[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    // int brr[3][3];
    // int row = 3;
    // int col = 3;
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout << "Enter the input for row index : " << i << " and column index : " << j << " : ";
    //         cin >> brr[i][j];
    //     }
    // }

    // int arr[3][4] = {{1, 2, 3, 4}, {11, 22, 33, 44}, {111, 222, 333, 4444}};
    // if (findTarget(arr, 3, 4, 44444))
    // {
    //     cout << "Target found." << endl;
    // }
    // else
    // {
    //     cout << "Target not found." << endl;
    // }
    // rowWiseSum(arr, 3, 4);

    // int arr[4][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}};
    // printReverseDiagonal(arr,4,4);
    // printArray(arr, 4, 4);
    // transpose2(arr, 4, 4);
    // printArray(arr, 4, 4);

    // vector<int> v(5) = {1, 2, 3, 4, 5}; // ERROR
    // vector<int> v(5, 4);
    // vector<int> v = {1, 2, 3, 4, 5};

    // vector<int> v(5);
    // cout << "Size of vector is : " << v.size() << endl;
    // cout << "Capacity of vector is : " << v.capacity() << endl;
    // v.push_back(10);
    // cout << "Size of vector is : " << v.size() << endl;
    // cout << "Capacity of vector is : " << v.capacity() << endl;

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << endl;

    // vector<int> v1;
    // cout << v1.size() << endl;

    // vector<vector<int>> arr(5, vector<int>(5, 1));
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     for (int j = 0; j < arr[i].size(); j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // vector<vector<int>> arr;
    // vector<int> v1(10, 1);
    // vector<int> v2(7, 2);
    // vector<int> v3(8, 3);
    // vector<int> v4(2, 4);
    // vector<int> v5(4, 5);
    // arr.push_back(v1);
    // arr.push_back(v2);
    // arr.push_back(v3);
    // arr.push_back(v4);
    // arr.push_back(v5);
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     for (int j = 0; j < arr[i].size(); j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}