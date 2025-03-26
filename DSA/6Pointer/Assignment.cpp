#include <iostream>
using namespace std;

int main()
{
    // ERROR AS WE ARE DEREFERNCING NULL POINTER
    // int *ptr = 0;
    // int a = 10;
    // *ptr = a;
    // cout << *ptr << endl;

    // // RANDOM VALUE
    // int a = 4;
    // int *c = &a;
    // c = c + 1;
    // cout << a << " " << *c << endl;

    // // ERROR AS CONSTANT POINTER CANNOT BE INCREMENTED
    // int a[] = {1, 2, 3, 4, 5};
    // int *p = a++;
    // cout << *p << endl;

    // // SUBTRACTING TWO POINTERS
    // int arr[] = {1,2,3,4,5,6};
    // int *ptr1 = &arr[0];
    // int *ptr2 = ptr1 + 3;
    // cout << *ptr2 << " " << ptr2 - ptr1 << endl;

    // // DOUBLE POINTER
    // int a = 10;
    // int *p = &a;
    // int **q = &p;
    // int b = 20;
    // *q = &b;
    // (*p)++;
    // cout << a << " " << b << endl;
}