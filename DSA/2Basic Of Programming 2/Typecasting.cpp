#include <iostream>
using namespace std;

int main()
{
    // TYPECASTING

    // IMPLICIT TYPE CONVERSION
    // int to float
    int a = 5;
    float b = 3.14;
    cout << a + b << endl;

    // char to int
    char ch = 'A';
    int d = ch + 1;
    cout << d << endl;
    cout << ch + d << endl;

    // int to char
    int c = 5;
    char e = 'a' + c;
    cout << e << endl;

    // EXPLICIT TYPE CONVERSION
    int x = 5;
    float y = 5.4;
    float z = x + (int)y;
    cout << z << endl;

    double pi = 3.14153238;
    int inpi = (int)pi;
    cout << inpi << endl;

    int a1 = 10;
    int b1 = 3.0;
    float c1 = (float)a1 / b1;
    cout << c1 << endl;
    return 0;
}