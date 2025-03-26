#include <iostream>
using namespace std;

int a = 25; // BAD PRACTISE (GLOBAL VARIABLE)
int main()
{
    // {
    //     cout << (2 & 3) << endl;
    //     cout << (5 | 10) << endl;
    //     cout << (5 ^ 8) << endl;

    //     int a = 2 ^ 3 ^ 4 ^ 5 ^ 4 ^ 3 ^ 2; // FIND UNIQUE ELEMENT
    //     cout << a << endl;

    //     cout << (5 ^ 0) << endl; // XOR WITH ZERO GIVES SAME NUMBER
    //     cout << (-5 ^ 0) << endl;
    //     cout << (5 ^ 1) << endl; // XOR ONE WITH ODD NUMBER REDUCES THE NUMBER BY ONE
    //     cout << (3 ^ 1) << endl;
    //     cout << (4 ^ 1) << endl; // XOR ONE WITH EVEN NUMBER INCREASES THE NUMBER BY ONE
    //     cout << (6 ^ 1) << endl;
    //     cout << (-6 ^ 1) << endl;
    //     cout << (-7 ^ 1) << endl;
    //     cout << endl;

    //     cout << (5 ^ 4) << endl; // XOR ODD NUMBER BY ITS LESSER NUMBER GIVES THE RESULT ONE
    //     cout << (7 ^ 6) << endl; // XOR EVEN NUMBER BY ITS GREATER NUMBER RESULTS IN ONE
    //     cout << (9 ^ 8) << endl;
    //     cout << (11 ^ 10) << endl;
    //     cout << (5 ^ -1) << endl; // XOR WITH -1 INCREASE THE NUMBER BY ONE WITH NEGATIVE SIGN
    //     cout << (16 ^ -1) << endl;
    //     cout << (7 ^ -1) << endl;
    //     cout << (8 ^ -1) << endl;
    //     cout << (23 ^ -1) << endl;
    //     cout << endl;

    //     cout << (5 ^ -6) << endl; // XOR ANY NUMBER WITH ITS NEGATIVE BIGGER NUMBER RESULTS IN -1
    //     cout << (6 ^ -7) << endl;
    //     cout << (7 ^ -8) << endl;
    //     cout << (8 ^ -9) << endl;
    //     cout << endl;

    //     cout << (5 ^ 5) << endl; // XOR WITH SAME NUMBER RESULTS IN ZERO
    //     cout << endl;

    //     cout << (5 ^ -5) << endl; // XOR ODD NUMBER WITH ITS NEGATIVE RESULTS IN -2
    //     cout << (7 ^ -7) << endl;
    //     cout << (1 ^ -1) << endl;
    //     cout << (3 ^ -3) << endl;
    //     cout << endl;

    //     cout << (5 & 0) << endl; // ANY NUMBER & ZERO GIVES ZERO
    //     cout << (22 & 0) << endl;
    //     cout << (-56 & 0) << endl;
    //     cout << endl;

    //     cout << (5 & 1) << endl; // ODD NUMBER & ONE RESULTS ONE
    //     cout << (-7 & 1) << endl;
    //     cout << (4 & 1) << endl; // EVEN NUMBER & ONE RESULTS ZERO
    //     cout << (-8 & 1) << endl;
    //     cout << endl;

    //     cout << (-5 & 4) << endl; // NEGATIVE NUMBER & WITH ITS LESSER POSITIVE RESULTS ZERO
    //     cout << (-6 & 5) << endl;
    //     cout << (-7 & 6) << endl;
    //     cout << (-8 & 7) << endl;
    //     cout << endl;

    //     cout << (8 & 8) << endl; // & WITH SAME NUMBER RESULTS THE SAME NUMBER
    //     cout << endl;

    //     int num = 1;
    //     bool num1 = 1;
    //     bool num2 = ~1;
    //     int num3 = ~1;
    //     cout << num1 << endl;
    //     cout << ~num1 << endl;
    //     cout << ~(num1) << endl;
    //     cout << (~num1) << endl;
    //     cout << num << endl;
    //     cout << ~num << endl;
    //     cout << ~(num) << endl;
    //     cout << (~num) << endl;
    //     cout << num2 << endl;
    //     cout << num3 << endl;
    //     cout << endl;
    // }

    int y = 66;
    cout << y << endl;               // 66
    cout << (y = 33) << endl;        // 33
    cout << y << endl;               // 33
    cout << (y == (y = 22)) << endl; // false
    cout << y << endl;               // 22
    cout << ~(0) << endl;            // -1
    cout << endl;

    // cout << (5 << 1) << endl;
    // cout << endl;

    // int a = 7;
    // cout << (a << 1) << endl;
    // cout << (a << 3) << endl;
    // cout << endl;

    // int b = -5;
    // cout << (b << 1) << endl;
    // cout << (b << 2) << endl;
    // cout << (b << 3) << endl;
    // cout << endl;

    // cout << (50 >> 1) << endl;   // POSITIVE EVEN EXACTLY DIVIDES BY 2
    // cout << (23 >> 1) << endl;   // POSITIVE ODD DIVIDES BY 2
    // cout << (-5 >> 1) << endl;   // NEGATIVE ODD DIVIDES BY 2 AND ADD ONE IN NEGATVE
    // cout << (-100 >> 1) << endl; // NEGATIVE EVEN EXACTLY DIVIDES BY 2
    // cout << (-23 >> 1) << endl;
    // cout << (-23 >> 0) << endl;
    // cout << (-23 >> -1) << endl; // ERROR// IT MEANS TO DO LEFT SHIFT BY 1
    // cout << (-23 >> -2) << endl; // ERROR
    // cout << endl;

    // unsigned int n = -1;
    // cout << n << endl;
    // cout << (n >> 1) << endl;
    // cout << (n << -1) << endl; // ERROR
    // cout << endl;

    // a = 10;
    // cout << a++ * 10 << endl;
    // cout << a << endl;
    // cout << ++a * 10 << endl;
    // cout << endl;

    a = 10;
    cout << ((++a) * (++a)) << endl; // 11 x 12 = 132
    a = 10;
    cout << ((++a) * (a++)) << endl; // 11 x 11 = 121
    a = 10;
    cout << ((a++) * (++a)) << endl; // 10 x 12 = 120
    a = 10;
    cout << ((a++) * (a++)) << endl; // 10 x 11 = 110
    cout << endl;

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << i << endl;
    //     if (i == 2)
    //     {
    //         break;
    //     }
    //     cout << i << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << i << endl;
    //     if (i == 2)
    //     {
    //         continue;
    //     }
    //     cout << i << endl;
    // }

    // {
    //     int a = 5;
    //     cout << a << endl;
    //     {
    //         int a = 6;
    //         cout << a << endl;
    //         {
    //             int a = 7;
    //             cout << a << endl;
    //         }
    //         cout << a << endl;
    //     }
    //     cout << a << endl;
    // }
    // cout << a << endl;

    // cout << ((2 * 3) + (5 / 6)) + 5 << endl; // OPERATOR PRECEDENCE // ALWAYS USE BRACKETS
    return 0;
}