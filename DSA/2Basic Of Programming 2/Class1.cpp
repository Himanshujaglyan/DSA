#include <iostream>
#include "assert.h"
using namespace std;

int main()
{
    // FULL PYRAMID
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < n - row - 1; col++)
    //     {
    //         cout << " ";
    //     }
    //     for (int col = 0; col < row + 1; col++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // INVERTED FULL PYRAMID
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;

    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < row; col++)
    //     {
    //         cout << " ";
    //     }
    //     for (int col = 0; col < n - row; col++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // DIAMOND
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;
    // n/=2;
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < n - row - 1; col++)
    //     {
    //         cout << " ";
    //     }
    //     for (int col = 0; col < row + 1; col++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < row; col++)
    //     {
    //         cout << " ";
    //     }
    //     for (int col = 0; col < n - row; col++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // HOLLOW INVERTED FULL PYRAMID
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;

    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < row; col++)
    //     {
    //         cout << " ";
    //     }
    //     for (int col = 0; col < n - row; col++)
    //     {
    //         if (col == 0 || col == n - row - 1 || row == 0)
    //         {
    //             cout << "* ";
    //         }
    //         else
    //         {
    //             cout << "  ";
    //         }
    //     }
    //     cout << endl;
    // }

    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;

    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < row; col++)
    //     {
    //         cout << " ";
    //     }
    //     for (int col = 0; col < 2 * (n - row) - 1; col++)
    //     {
    //         if (col == 0 || col == (2 * (n - row - 1)) || row == 0)
    //         {
    //             cout << "*";
    //         }
    //         else
    //         {
    //             cout << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    // HOLLOW DIAMOND
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;
    // n /= 2;
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < n - row - 1; col++)
    //     {
    //         cout << " ";
    //     }
    //     for (int col = 0; col < 2 * row + 1; col++)
    //     {
    //         if (col == 0 || col == 2 * row)
    //         {
    //             cout << "*";
    //         }
    //         else
    //         {
    //             cout << " ";
    //         }
    //     }

    //     cout << endl;
    // }
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < row; col++)
    //     {
    //         cout << " ";
    //     }
    //     for (int col = 0; col < 2 * (n - row) - 1; col++)
    //     {
    //         if (col == 0 || col == (2 * (n - row - 1)))
    //         {
    //             cout << "*";
    //         }
    //         else
    //         {
    //             cout << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    // FLIPPED SOLID DIAMOND
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;
    // n /= 2;
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < n - row; col++)
    //     {
    //         cout << "*";
    //     }
    //     for (int col = 0; col < 2 * row + 1; col++)
    //     {
    //         cout << " ";
    //     }
    //     for (int col = 0; col < n - row; col++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < row + 1; col++)
    //     {
    //         cout << "*";
    //     }
    //     for (int col = 0; col < 2 * (n-row) - 1; col++)
    //     {
    //         cout << " ";
    //     }
    //     for (int col = 0; col < row + 1; col++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    // FANCY PATTERN
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < 2 * row + 1; col++)
    //     {
    //         if (col % 2 == 0)
    //         {
    //             cout << row + 1;
    //         }
    //         else
    //         {
    //             cout << "*";
    //         }
    //     }
    //     cout << endl;
    // }
    // n--;
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < 2 * (n -row) - 1; col++)
    //     {
    //         if (col % 2 == 0)
    //         {
    //             cout << n - row;
    //         }
    //         else
    //         {
    //             cout << "*";
    //         }
    //     }
    //     cout << endl;
    // }

    // FANCY PATTERN
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;
    // for (int row = 0; row < n; row++)
    // {
    //     int col = 0;
    //     for (col; col < row + 1; col++)
    //     {
    //         cout << char('A' + col);
    //     }
    //     col -= 2;
    //     for (col; col >= 0; col--)
    //     {
    //         cout << char('A' + col);
    //     }
    //     cout << endl;
    // }

    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;
    // for (int row = 0; row < n; row++)
    // {
    //     int k = 0;
    //     int flag = 1;
    //     for (int col = 0; col < 2 * row + 1; col++)
    //     {
    //         if (col < row + 1)
    //         {
    //             cout << char('A' + k);
    //             k++;
    //         }
    //         else
    //         {
    //             if (flag == 1)
    //             {
    //                 k -= 2;
    //                 flag = 0;
    //             }
    //             cout << char('A' + k);
    //             k--;
    //         }
    //     }
    //     cout << endl;
    // }

    // NUMERIC PALINDROME EQUILATERAL PYRAMID
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < n - row - 1; col++)
    //     {
    //         cout << " ";
    //     }
    //     int col = 0;
    //     for (col; col < row + 1; col++)
    //     {
    //         cout << col + 1;
    //     }
    //     col -= 2;
    //     for (col; col >= 0; col--)
    //     {
    //         cout << col + 1;
    //     }
    //     cout << endl;
    // }

    // for (int row = 0; row < n; row++)
    // {
    //     int c = 1;
    //     for (int col = 0; col < n + row; col++)
    //     {
    //         if (col < n - row - 1)
    //         {
    //             cout << " ";
    //         }
    //         else if (col < n)
    //         {
    //             cout << c++;
    //         }
    //         else if(col == n)
    //         {
    //             c -= 2;
    //             cout << c--;
    //         }
    //         else{
    //             cout << c--;
    //         }
    //     }
    //     cout << endl;
    // }

    // FANCY PATTERN // ONLY FOR N UPTO 9
    // ********1********
    // *******2*2*******
    // ******3*3*3******
    // *****4*4*4*4*****
    // ****5*5*5*5*5****

    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < 2 * (n - 1) - row; col++)
    //     {
    //         cout << "*";
    //     }
    //     for (int col = 0; col < row + 1; col++)
    //     {
    //         if (col == row)
    //         {
    //             cout << row + 1;
    //         }
    //         else
    //         {
    //             cout << row + 1 << "*";
    //         }
    //     }
    //     for (int col = 0; col < 2 * (n - 1) - row; col++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < (4 * n - 3); col++)
    //     {
    //         if (col < (2 * (n - 1) - row))
    //         {
    //             cout << "*";
    //         }
    //         else if (col < 2 * (n - 1) + row)
    //         {
    //             cout << row + 1 << "*";
    //             col++;
    //         }
    //         else if (col == 2 * (n - 1) + row)
    //         {
    //             cout << row + 1;
    //         }
    //         else
    //         {
    //             cout << "*";
    //         }
    //     }
    //     cout << endl;
    // }

    // cout << "Enter the number of rows : ";
    int n;
    cin >> n;
    assert(n <= 9);
    // for (int i = 0; i < n; i++) // LAKSHAY CODE
    // {
    //     int start_num_index = 8 - i;
    //     int num = i + 1;
    //     int count_num = num;
    //     for (int j = 0; j < 17; j++)
    //     {
    //         if (j == start_num_index && count_num > 0)
    //         {
    //             cout << num;
    //             count_num--;
    //             start_num_index += 2;
    //         }
    //         else
    //         {
    //             cout << "*";
    //         }
    //     }
    //     cout << endl;
    // }

    // FANCY PATTERN #2
    // 1
    // 2*3
    // 4*5*6
    // 7*8*9*10
    // 7*8*9*10
    // 4*5*6
    // 2*3
    // 1
    // cout << "Enter a number : ";
    // int n;
    // cin >> n;
    // int counter = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i + 1; j++)
    //     {
    //         if (j == i)
    //         {
    //             cout << counter++;
    //         }
    //         else
    //         {
    //             cout << counter++ << "*";
    //         }
    //     }
    //     cout << endl;
    // }
    // counter -= n;
    // for (int i = 0; i < n; i++)
    // {
    //     int k = counter;
    //     for (int j = 0; j < n - i; j++)
    //     {
    //         if (j == n - i - 1)
    //         {
    //             cout << k++;
    //         }
    //         else
    //         {
    //             cout << k++ << "*";
    //         }
    //     }
    //     counter = counter - (n - i - 1);
    //     cout << endl;
    // }

    // FANCY PATTER #3
    // cout << "Enter a number : ";
    // int n;
    // cin >> n;
    // cout << "*" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "*";
    //     int cond = i <= n / 2 ? 2 * i : 2 * (n - i - 1);
    //     for (int j = 0; j <= cond; j++)
    //     {
    //         if (j <= cond / 2)
    //         {
    //             cout << j + 1;
    //         }
    //         else
    //         {
    //             cout << cond + 1 - j;
    //         }
    //     }
    //     cout << "*";
    //     cout << endl;
    // }
    // cout << "*";

    // PASCAL TRIANGLE (BASED ON BINOMIAL COEFFICIENT)
    // TO FIND ANY ELEMENT JUST DO NCR FOR WHERE N = R - 1 AND R = C - 1 IN 1 - BASED INDEXING
    cout << "Enter the number of rows : ";
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int c = 1;
        for (int j = 1; j <= i; j++)
        {
            cout << c << " ";
            c = c * (i - j) / j;
        }
        cout << endl;
    }
    // 0-BASED INDEXING

    for (int i = 0; i < n; i++)
    {
        int c = 1;
        for (int j = 0; j < i + 1; j++)
        {
            cout << c << " ";
            c = c * (i - j) / (j + 1);
        }
        cout << endl;
    }

    // SOLID HALF DIAMOND
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < row + 1; col++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // n--;
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < n - row; col++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    // for (int row = 0; row < 2 * n - 1; row++)
    // {
    //     // int cond = 0;
    //     // if (row < n)
    //     // {
    //     //     cond = row + 1;
    //     // }
    //     // else
    //     // {
    //     //     // cond = 2 * n - row - 1;
    //     //     cond = n - (row%n) - 1;
    //     // }
    //     int cond = row < n ? row+1 : n - (row%n) - 1;
    //     for (int col = 0; col < cond; col++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    // FLYOD'S TRIANGLE
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;
    // int counter = 1;
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < row + 1; col++)
    //     {
    //         cout << counter++ << " ";
    //     }
    //     cout << endl;
    // }

    // BUTTERFLY PATTERN
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < row + 1; col++)
    //     {
    //         cout << "*";
    //     }
    //     for (int col = 0; col < 2 * (n - row - 1); col++)
    //     {
    //         cout << " ";
    //     }
    //     for (int col = 0; col < row + 1; col++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < n - row; col++)
    //     {
    //         cout << "*";
    //     }
    //     for (int col = 0; col < 2 * row; col++)
    //     {
    //         cout << " ";
    //     }
    //     for (int col = 0; col < n - row; col++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    // BUTTERFLY PATTERN (LAKSHAY)
    // int n;
    // cout << "Enter a number : ";
    // cin >> n;

    // for (int i = 0; i < 2 * n; i++)
    // {
    //     int cond = i < n ? i : 2 * n - i - 1;
    //     int space_count = 2 * (n - cond - 1);
    //     for (int j = 0; j < 2 * n; j++)
    //     {
    //         if (j <= cond)
    //         {
    //             cout << "*";
    //         }
    //         else if (space_count > 0)
    //         {
    //             cout << " ";
    //             space_count--;
    //         }
    //         else
    //         {
    //             cout << "*";
    //         }
    //     }
    //     cout << endl;
    // }

    // SWASTIK
    // cout << "Enter the side of swastik : ";
    // int n;
    // cin >> n;
    // for (int row = 0; row < 2 * n + 1; row++)
    // {
    //     for (int col = 0; col < 2 * n + 1; col++)
    //     {

    //         if (row < n)
    //         {
    //             if (col == 0 || col == n || (row == 0 && col > n))
    //             {
    //                 cout << "* ";
    //             }
    //             else
    //             {
    //                 cout << "  ";
    //             }
    //         }
    //         else if (row == n)
    //         {

    //             cout << "* ";
    //         }
    //         else
    //         {

    //             if (col == n || col == 2 * n || ((row == (2 * n)) && (col < n)))
    //             {
    //                 cout << "* ";
    //             }
    //             else
    //             {
    //                 cout << "  ";
    //             }
    //         }
    //     }

    //     cout << endl;
    // }

    // NUMERIC HOLLOW HALF PYRAMID

    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;

    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < row + 1; col++)
    //     {
    //         if (col == 0 || col == row || row == n-1)
    //         {
    //             cout << col + 1;
    //         }
    //         else
    //         {
    //             cout << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    // NUMERIC HOLLOW INVERTED HALF PYRAMID
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;

    // for (int row = 0; row < n; row++)
    // {
    //     int count = row + 1;
    //     for (int col = 0; col < n - row; col++)
    //     {
    //         if (col == 0 || col == n - row - 1 || row == 0)
    //         {
    //             cout << count++;
    //         }
    //         else
    //         {
    //             cout << " ";
    //             count++;
    //         }
    //     }
    //     cout << endl;
    // }

    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = row; col < n; col++)
    //     {
    //         if (col == row || col == n - 1 || row == 0)
    //         {
    //             cout << col + 1;
    //         }
    //         else
    //         {
    //             cout << " ";
    //         }
    //     }
    //     cout << endl;
    // }
    return 0;
}