#include <iostream>
using namespace std;

int main()
{
    // int a = 10;
    // int c = 20;
    // int b = 20;
    // cout << int(&a) << endl;
    // cout << int(&b) << endl;
    // cout << int(&c) << endl;
    // int *ptr = &a;
    // int *ptr1 = &b;
    // cout << ptr - ptr1 << endl;
    // cout << ptr1 - ptr << endl;
    // cout << ptr - ptr << endl;
    // cout << ptr1 - ptr1 << endl;

    // char a, b;
    // char *ptr, ptr1; // ptr is a pointer and ptr1 is a character
    // cout << sizeof(ptr);
    // cout << sizeof(ptr1);
    // ptr = &a;
    // // ptr1 = &b;// ERROR

    // int a = 15;
    // int b = 6;
    // int &x = a;
    // cout << x << endl;
    // x++;
    // cout << a << endl;
    // cout << x << endl;
    // &x = b; // ERROR // WE CANNOT CHANGE THE REFERNCE VARIABLE IT IS POINTING TOO
    // cout << x << endl;
    // cout << a << endl;
    // cout << b << endl;

    // int arr[] = {0, 1, 2, 3, 4};
    // cout << int(&arr[0]) << endl;
    // cout << int(&arr[1]) << endl;
    // cout << int(&arr[2]) << endl;
    // cout << int(&arr[3]) << endl;
    // cout << int(&arr[4]) << endl;
    // cout << int(*(&arr + 1)) << endl;
    // cout << int(*(&arr)) << endl;
    // cout << (*(&arr + 1) - *(&arr)) << endl;// TO FIND NUMBER OF ELEMENTS IN AN ARRAY
    // cout << int((&arr + 1)) << endl;
    // cout << int((&arr)) << endl;
    // cout << ((&arr + 1) - (&arr)) << endl;// TO FIND NUMBER OF ELEMENTS IN AN ARRAY

    // int a = 5;
    // int *ptr = &a;
    // const int b = 6;
    // const int *ptr1 = &b; // POINTER TO A CONSTANT INT VARIABLE
    // // b++;// ERROR
    // ptr1++;
    // // (*ptr1)++;// ERROR

    // int p = 5;
    // int const *q = &p;// POINTER TO VARIABLE WHICH CANNOT BE MODIFIED BY POINTER
    // // (*q)++;// ERROR
    // q++;
    // p++;
    // cout << p << endl;

    // int p = 5;
    // int *const q = &p; // CONSTANT POINTER
    // (*q)++;
    // // q++; // ERROR
    // p++;

    // // const int c = 7;
    // // const int const *ptr2 = &c;// WRONG DECLARATION
    // const int i = 20;
    // const int* const ptr = &i;
    // // ptr++;// ERROR
    // // i++;// ERROR
    // // (*ptr)++;// ERROR

    // // int a = 10, *pa, &ra; // ERROR &ra requires an initializer
    // int a = 10, *pa, &ra = a;

    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int(*ptr)[10] = &arr; // BRACKETS IS NECESSARY HERE IN THIS CASE
    // cout << (*ptr)[0] << endl;
    // cout << (*ptr)[1] << endl;
    // cout << (*ptr)[2] << endl;
    // cout << (*ptr)[3] << endl;
    // cout << sizeof(ptr) << endl;
    // cout << endl;
    // cout << int(&arr) << endl;
    // cout << int(ptr) << endl;
    // cout << int(*ptr) << endl;
    // cout << int(ptr + 1) << endl;
    // cout << int(*(ptr) + 1) << endl;

    // int *ptr1[10] = {&arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7], &arr[8], &arr[9]}; // BRACKETS ARE NOT NECESSARY
    // cout << *ptr1[0] << endl;
    // cout << *ptr1[1] << endl;
    // cout << *ptr1[2] << endl;
    // cout << *ptr1[3] << endl;
    // cout << sizeof(ptr1) << endl;

    // int a[] = {10, 20, 30, 40, 50};
    // int *p[] = {a, a + 3, a + 4, a + 1, a + 2};
    // int **ptr = p;
    // cout << int(ptr) << endl;
    // cout << int(p) << endl;
    // ptr++;
    // cout << int(ptr) << endl;
    // cout << int(p + 1) << endl;
    // cout << *ptr - *p << endl;
    // cout << ptr - p << " " << **ptr;

    // int arr[5] = {1, 2, 3, 4, 5};
    // int(*ptr)[5] = &arr;
    // int **ptr2 = ptr;// ERROR
    return 0;
}