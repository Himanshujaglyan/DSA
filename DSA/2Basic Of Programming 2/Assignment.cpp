#include <iostream>
#include <limits.h>
using namespace std;

// float circleArea(float radius)
// {
//     float area = 3.14 * radius * radius;
//     return area;
// }

// int reverseInteger(int x) // LEETCODE 7
// {
//     int reverse = 0;
//     bool isNegative = 0;
//     if (x <= INT_MIN)
//     {
//         return 0;
//     }
//     if (x < 0)
//     {
//         isNegative = true;
//         x = -x;
//     }
//     while (x > 0)
//     {
//         if (reverse > INT_MAX / 10)
//         {
//             return 0;
//         }
//         int remainder = x % 10;
//         reverse = reverse * 10 + remainder;
//         x /= 10;
//     }
//     if (isNegative)
//     {
//         return (-reverse);
//     }
//     else
//     {
//         return reverse;
//     }
// }

// int factorial(int n)
// {
//     int fact = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         fact *= i;
//     }
//     return fact;
// }

// void PrintMaximum(int num1, int num2, int num3)
// {
//     if (num1 >= num2 && num1 >= num3)
//     {
//         cout << "Maximum number is : " << num1 << endl;
//     }
//     else if (num2 >= num1 && num2 >= num3)
//     {
//         cout << "Maximum number is : " << num2 << endl;
//     }
//     else
//     {
//         cout << "Maximun number is : " << num3 << endl;
//     }
// }

// int Maximum(int num1, int num2, int num3)
// {
//     int ans = max(num1, num2);
//     int finalAns = max(ans, num3);
//     return finalAns;
// }

// void PrintCounting(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         cout << i << "\n";
//     }
// }

// void CheckEvenOdd(int num)
// {
//     if (num % 2 == 0)
//     {
//         cout << "Even Number." << endl;
//     }
//     else
//     {
//         cout << "Odd Number." << endl;
//     }
// }
// void CheckEvenOddUsingBitwise(int num) // CHECK LSB(LEAST SIGNIFICANT BIT)
// {
//     if ((num & 1) == 0)
//     {
//         cout << "Even Number." << endl;
//     }
//     else
//     {
//         cout << "Odd Number." << endl;
//     }
// }
// void SumUptoN(int n)
// {
//     int sum = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         sum += i;
//     }
//     cout << "Sum is : " << sum << endl;
// }
// void SumEvenUptoN(int n)
// {
//     int sum = 0;
//     for (int i = 2; i <= n; i += 2)
//     {
//         sum += i;
//     }
//     cout << "Sum is : " << sum << endl;
// }
// void CheckPrimeOrNot(int num)
// {
//     int flag = 0;
//     for (int i = 2; i <= num / 2; i++)
//     {
//         if (num % i == 0)
//         {
//             flag = 1;
//             break;
//         }
//     }
//     if (flag == 0)
//     {
//         cout << "Number is a prime number." << endl;
//     }
//     else
//     {
//         cout << "The number is not a prime number." << endl;
//     }
// }
// int numberOfSetBits(int n)
// {
//     int count = 0;
//     while (n > 0)
//     {
//         if ((n & 1) == 1)
//         {
//             count++;
//         }
//         n = n >> 1;
//     }
//     return count;
// }
int numberOfSetBits2(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1); // UNSETS THE RIGHTMOST BIT
        count++;
    }
    return count;
}

// int createNumber(int n)
// {
//     int digit;
//     int number = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         cout << "Enter digit " << i << " : ";
//         cin >> digit;
//         number = number * 10 + digit;
//     }
//     return number;
// }

// void printDigits(int n)
// {
//     while (n > 0)
//     {
//         int digit = n % 10;
//         cout << "Digit : " << digit << endl;
//         n /= 10;
//     }
// }

// void convertKmToMiles(int n)
// {
//     cout << n << " km = : " << n * 0.621371 << " Miles";
// }
// void convertTemperature(double celcius)
// {
//     double kelvin = celcius + 273.15;
//     double fahrenheit = celcius * 1.80 + 32.00;
//     cout << "Kelvin : " << kelvin << endl;
//     cout << "Fahrenheit : " << fahrenheit << endl;
// }
// void setThekthBit(int num, int bit)// 0 BASED INDEXING FROM RIGHT
// {
//     int k = 1;
//     k = k << bit;
//     num = (num | k);
//     cout << num;
// }
int main()
{
    // PrintMaximum(1, 2, 3);
    // cout << Maximum(100, 20, 3) << endl;
    // PrintCounting(99);
    // CheckEvenOdd(83);
    // CheckEvenOddUsingBitwise(83);
    // SumUptoN(10);
    // SumEvenUptoN(10);
    // CheckPrimeOrNot(-121);
    // cout << numberOfSetBits2(31) << endl;
    // cout << circleArea(10) << endl;
    // cout << factorial(5) << endl;
    // cout << reverseInteger(853455) << endl;
    // int n;
    // cout << "Enter the number of digits : ";
    // cin >> n;
    // cout << createNumber(n);
    // printDigits(125489);
    // convertKmToMiles(1456);
    // convertTemperature(36.50);
    // setThekthBit(10, 2);

    return 0;
}