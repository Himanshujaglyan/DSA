#include <iostream>
#include <math.h>
// #include <conio.h>
using namespace std;

int DecimalToBinaryMethod1(int n) // DIVISION METHOD
{
    int i = 0;
    int binary = 0;
    while (n > 0)
    {
        int bit = n % 2;
        binary = binary + bit * float(pow(10, i++));
        n = n / 2;
    }
    return binary;
}
int DecimalToBinaryMethod2(int n) // BITWISE METHOD
{
    int i = 0;
    int binary = 0;
    while (n > 0)
    {
        int bit = n & 1;
        binary = binary + bit * float(pow(10, i++));
        n = n >> 1;
    }
    return binary;
}
int BinaryToDecimal(int n)
{
    int decimal = 0;
    int i = 0;
    while (n > 0)
    {

        int bit = n % 10;
        decimal = decimal + bit * float(pow(2, i++));
        n = n / 10;
    }
    return decimal;
}
int main()
{
    int number;
    cout << "Enter a number : ";
    cin >> number;
    // int binary = DecimalToBinaryMethod1(number);
    // cout << binary;
    int decimal = BinaryToDecimal(number);
    cout << decimal;
    return 0;
}