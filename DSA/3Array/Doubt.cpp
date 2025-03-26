#include <iostream>
using namespace std; // GLOBAL EXAMINATION
int a = 9;
int fun(int a)
{
    cout << a << endl;
    a++;
    cout << a << endl;
    return a + 1;
}
void print()
{
    cout << a << endl;
    a++;
    cout << a << endl;
}
int main()
{
    // int arr[5] = {1, 2, 3, 4, 5};
    // int arr2[5] = arr;      // ERROR cannot copy array directly
    // char ch[5] = char(arr); // ERROR cannot typecast array

    cout << a << endl;
    int a = fun(5);
    cout << a << endl;
    print();
    cout << a << endl;
    print();
    return 0;
}