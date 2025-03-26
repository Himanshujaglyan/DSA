#include <iostream>
using namespace std;

int increment(int n)
{
    n++;
    cout << &n << endl;
    return n;
}
void incrementBy1(int &k)
{
    k++;
    cout << &k << endl;
}
int main()
{
    // int x = 5;
    // int &y = x;
    // int &z = y;

    // cout << "x is : " << x << endl;
    // cout << "y is : " << y << endl;
    // cout << "z is : " << z << endl;

    // z = 23;
    // cout << "x is : " << x << endl;
    // cout << "y is : " << y << endl;
    // cout << "z is : " << z << endl;

    // y = 3;
    // cout << "x is : " << x << endl;
    // cout << "y is : " << y << endl;
    // cout << "z is : " << z << endl;

    // int &t = 9; // ERROR

    int n = 10;
    cout << &n << endl;
    increment(n);
    cout << n << endl;
    n = increment(n);
    cout << n << endl;
    incrementBy1(n);
    cout << n << endl;


    return 0;
}