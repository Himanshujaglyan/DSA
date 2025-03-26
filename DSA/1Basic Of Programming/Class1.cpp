#include <iostream>
// #include <math.h>
// #include <conio.h>
#include<cmath>
using namespace std;

int main()
{
    // COMPOUND INTEREST
    cout << "Enter the principle amount : ";
    int principle;
    cin >> principle;
    cout << "Enter the rate amount : ";
    int rate;
    cin >> rate;
    cout << "Enter the time amount : ";
    int time;
    cin >> time;
    float compound_interest = principle * pow((1 + (float(rate) / 100)), time);
    cout << "The compound interest is : " << compound_interest << endl;

    // PRINT PRIME NUMBERS UPTO N
    cout << "Enter a Number : ";
    int number;
    cin >> number;
    for (int i = 2; i <= number; i++)
    {
        for (int j = 2; j <= i; j++)
        {
            if (i % j == 0)
            {
                if (i == j)
                {
                    cout << i << "\t";
                }
                else
                {
                    break;
                }
            }
        }
    }

    // PRIME NUMBER
    cout << "Enter a Number : ";
    int number;
    cin >> number;
    bool flag = 1;
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            cout << "The number is not a prime number.";
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "The number is a prime number.";
    }

    // MAXIMUM OF THREE NUMBERS
    cout << "Enter any three numbers : ";
    int a, b, c;
    cin >> a >> b >> c;
    cout << "The greatest of three numbers is : ";
    if (a > b)
    {
        if (a > c)
        {
            cout << a;
        }
        else
        {
            cout << c;
        }
    }
    else
    {
        if (b > c)
        {
            cout << b;
        }
        else
        {
            cout << c;
        }
    }
    return 0;
}