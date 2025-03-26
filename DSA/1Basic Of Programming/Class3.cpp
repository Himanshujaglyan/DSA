#include <iostream>
using namespace std;

int main()
{
    // bool a = true;
    // if(a){
    //     cout << a << "\ttrue" << endl;
    // }

    // a = false;
    // if(a){
    //     cout << a << "\tfalse" << endl;// DOES NOT PRINT
    // }

    // a = 0;
    // if(a){
    //     cout << a << "\t0" << endl;// DOES NOT PRINT
    // }

    // a = 1;
    // if(a){
    //     cout << a << "\t1" << endl;
    // }

    // a = 55;
    // if(a){
    //     cout << a << "\t55" << endl;
    // }

    // a = -55;
    // if(a){
    //     cout << a << "\t-55" << endl;
    // }

    // int number;
    // cout << "Enter a number : ";
    // cin >> number;

    // if (number > 0)
    // {
    //     cout << "Positive " << endl;
    // }
    // else if (number < 0)
    // {
    //     cout << "Negative " << endl;
    // }
    // else
    // {
    //     cout << "Zero" << endl;
    // }

    // if (number % 2 == 0)
    // {
    //     cout << "Even " << endl;
    // }
    // else
    // {
    //     cout << "Odd" << endl;
    // }

    // if (true)
    // {
    //     cout << "True" << endl;
    // }
    // if (false)
    // {
    //     cout << "False" << endl;// DOES NOT PRINT
    // }
    // if (0)
    // {
    //     cout << "Zero" << endl;// DOES NOT PRINT
    // }
    // if (1)
    // {
    //     cout << "One" << endl;
    // }
    // if (55)
    // {
    //     cout << "55" << endl;
    // }
    // if (-55)
    // {
    //     cout << "-55" << endl;
    // }

    // int i = 0;
    // do // WILL EXECUTE ATLEAST ONCE
    // {
    //     cout << i++ << endl;
    // } while (i < 0);
    // i = 0;
    // do
    // {
    //     cout << i++ << endl;
    // } while (i < 1);

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << "Om Jindal" << endl;
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << "outer loop : " << i << endl;
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << "Inner loop : " << j << endl;
    //     }
    //     cout << endl;
    // }

    // int i = 0;
    // for (;;) // WITHOUT ANY CONDITION
    // {
    //     if (i < 5)
    //     {
    //         cout << "Hello : " << i << endl;
    //         // i++;
    //     }
    //     i++;
    // }
    // cout << "Hi" << endl;

    // int j = 5;
    // for (int i = 2, j = 3; i < 5, j < 16, i < 55; i++, j++, i++) // 2nd condition is checked OR LATEST CONDITION IS CHECKED // we cannot initialize two new variables together but can update it
    // {
    //     cout << i << "\t" << j << endl;
    // }

    // for (int i = 0; i = 4; i++)// INFINTE LOOP
    // {
    //     cout << i << endl;
    // }
    // for (int i = 0; 4; i++) // INFINTE LOOP
    // {
    //     cout << i << endl;
    // }
    // for (int i = 0; 0; i++) // DOES NOT EXECUTE
    // {
    //     cout << i << endl;
    // }
    // for (int i = 0; -5; i++) // INFINTE LOOP
    // {
    //     cout << i << endl;
    // }
    // for (int i = 0; true; i++) // INFINTE LOOP
    // {
    //     cout << i << endl;
    // }
    // for (int i = 0; false; i++) // DOES NOT EXECUTE
    // {
    //     cout << i << endl;
    // }

    // int n; // IT WILL RUN IN ALL CASES DOES NOT DEPEND UPON THE VALUE AS CIN AND COUT ALWAYS RETURN TRUE AFTER EXECUTION
    // if (cin >> n)
    // {
    //     cout << "Om Jindal" << endl;
    // }

    // if (cout << n << endl)
    // {
    //     cout << "Om Jindal" << endl;
    // }

    // PATTER PRINTING
    // SQUARE
    // int n;
    // cout << "Enter the side of square : ";
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // RECTANGLE
    // int l, b;
    // cout << "Enter the length and breadth of rectangle : ";
    // cin >> l >> b;

    // for (int i = 0; i < b; i++)
    // {
    //     for (int j = 0; j < l; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // HOLLOW RECTANGLE
    // int l, b;
    // cout << "Enter the length and breadth of rectangle : ";
    // cin >> l >> b;

    // for (int i = 0; i < b; i++)
    // {
    //     for (int j = 0; j < l; j++)
    //     {
    //         if (i == 0 || i == (b - 1) || j == 0 || j == (l - 1))
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

    // HALF PYRAMID
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < row + 1; col++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // INVERTED HALF PYRAMID
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < n - row; col++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // NUMERIC HALF PYRAMID
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;

    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < row + 1; col++)
    //     {
    //         cout << col + 1 << " ";
    //     }
    //     cout << endl;
    // }

    // INVERTED NUMERIC HALF PYRAMID
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;

    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < n - row; col++)
    //     {
    //         cout << col + 1 << " ";
    //     }
    //     cout << endl;
    // }

    // HOLLOW INVERTED HALF PYRAMID
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < n - row; col++)
    //     {
    //         if (row == 0 || row == n - 1 || col == 0 || col == n - row - 1)
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

    // HOLLOW FULL PYRAMID
    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;
    // for (int row = 0; row < n; row++)
    // {
    //     int k = 0;
    //     for (int col = 0; col < 2 * n - 1; col++)
    //     {
    //         if (col < n - row - 1)
    //         {
    //             cout << " ";
    //         }
    //         else if (k < 2 * row + 1)
    //         {
    //             if (k == 0 || k == 2 * row || row == n - 1)
    //                 cout << "*";
    //             else
    //             {
    //                 cout << " ";
    //             }
    //             k++;
    //         }
    //     }
    //     cout << endl;
    // }

    // cout << "Enter the number of rows : ";
    // int n;
    // cin >> n;
    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < n - row - 1; col++)
    //     {
    //         cout << " ";
    //     }
    //     for (int col = 0; col < 2 * row + 1; col++)
    //     {
    //         if (col == 0 || col == 2 * row || row == n - 1)
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
    return 0;
}