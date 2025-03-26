#include <iostream>
using namespace std;

int factorial(int n)
{
    // if (n == 0 || n == 1) // BASE CASE
    // {
    //     return 1;
    // }
    cout << n << endl;

    int recursiveAns = factorial(n - 1); // RECURSIVE RELATION
    int finalAns = n * recursiveAns;     // PROCESSING

    return finalAns;
}

// int factorial(int n){
//     if(n == 0 || n == 1){
//         return 1;
//     }

//     return n * factorial(n-1);
// }

void printCounting(int n) // ASCENDING COUNTING
{
    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    printCounting(n - 1); // HEAD RECURSION (IF PROCESSING HAPPENS AFTER RECURIVE CALL)
    cout << n << endl;
}

void printCounting1(int n) // DESCENDING COUNTING
{
    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    cout << n << endl;
    printCounting(n - 1); // TAIL RECURSION (THE FUNCTION THAT END WITH RECURSIVE CALL)
}

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int fibb = fib(n - 1) + fib(n - 2);
    return fibb;
}

int powerOf2(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return 2 * powerOf2(n - 1);
}

int sumUptoN(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sumUptoN(n - 1);
}
int main()
{
    // cout << factorial(43258) << endl; // IT RUNS 43258 TIMES
    // printCounting(11);
    // cout << fib(12) << endl;
    cout << powerOf2(10) << endl;
    cout << sumUptoN(10) << endl;

    // cout << "Enter the element you want to find : ";
    // int n;
    // cin >> n;
    // int first = 0;
    // int second = 1;
    // int next;
    // for (int i = 1; i < n; i++)
    // {
    //     next = first + second;
    //     first = second;
    //     second = next;
    // }
    // cout << "The element is : " << next;

    // int t1 = 0, t2 = 1;
    // int next = t1 + t2;
    // int i, n;
    // cin >> n;
    // if(n == 0){
    //     cout << t1 << " ";
    // }
    // if(n >= 1){
    //     cout << t1 << " " << t2 << " ";
    // }
    // for (int i = 2; i <= n; i++)
    // {
    //     cout << next << " ";
    //     t1 = t2;
    //     t2 = next;
    //     next = t1 + t2;
    // }

    return 0;
}