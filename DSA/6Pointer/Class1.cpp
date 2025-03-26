#include <iostream>
using namespace std;

int main()
{
    // POINTER
    // int a = 5;
    // cout << a << endl;
    // cout << "Address of a is : " << &a << endl;
    // // cout << *a << endl; // ERROR
    // cout << *(&a) << endl;

    // int *ptr = &a;
    // cout << "Accessing the value of pointer : " << *ptr << endl;
    // cout << ptr << endl;
    // cout << &ptr << endl;

    // REFERENCE VARIABLE
    // int a = 5;
    // int &b = a;
    // cout << a << endl;
    // cout << &a << endl;
    // cout << b << endl;
    // cout << &b << endl;

    // POINTER SYNTAX CHECKING
    // int a = 5;
    // int *ptr = a;// ERROR
    // int ptr = &a;// ERROR

    // POINTER ALWAYS STORE ADDRESS INSPITE OF TYPE OF POINTER -> WHETHER IT IS CHAR, INT, LONG
    // int a = 5;
    // int *ptr = &a;
    // char ch = 'k';
    // char *ptr1 = &ch;
    // long ll = 122433;
    // long* ptr2 = &ll;
    // cout << sizeof(ptr) << endl;
    // cout << sizeof(ptr1) << endl;
    // cout << sizeof(ptr2) << endl;

    // BAD PRACTISE AS IT MAY ACCESS A RANDOM MEMORY THAT IS ILLEGAL MEMORY THAT IS NOT ALLOWED TO ME TO ACCESS SO IT WILL SHOW RUN TIME OR SEGMENTATION FAULT
    // int *ptr;
    // cout << *ptr << endl;

    // SO TO AVOID THIS WE BEGAN OR CREATE A NULL POINTER
    // int *ptr = 0;
    // cout << ptr << endl;
    // int *ptr1 = nullptr;
    // cout << ptr1 << endl;
    // int *ptr2 = NULL;
    // cout << ptr2 << endl;
    // cout << *ptr2 << endl; // WHEN WE DEREFERNCE NULL POINTER IS SHOWS ERROR AS WE ARE DEREFERENCING NULL POINTER

    // BASIC MATHEMATICS WITH POINTER
    // int a = 100;
    // int *ptr = &a;

    // cout << a << endl;
    // cout << &a << endl;
    // // cout << *a << endl;//ERROR
    // cout << ptr << endl;
    // cout << *ptr << endl;
    // cout << &ptr << endl;

    // (*ptr)++;
    // cout << *ptr << endl;
    // ++(*ptr);
    // cout << *ptr << endl;
    // (*ptr) /= 2;
    // cout << *ptr << endl;
    // (*ptr) -= 2;
    // cout << *ptr << endl;

    // cout << ptr << endl;
    // *ptr++;
    // cout << ptr << endl;
    // *ptr--;
    // cout << ptr << endl;

    // int *qtr = ptr;
    // cout << "Q : " << endl;
    // cout << qtr << endl;
    // cout << *qtr << endl;
    // cout << &qtr << endl;

    // int *rtr = *ptr;// ERROR

    // POINTER TO ARRAY
    // int arr[5] = {10, 20, 30, 40, 50};
    // cout << arr << endl;
    // cout << &arr << endl;
    // cout << &arr[0] << endl;
    // cout << arr[0] << endl;
    // cout << *arr << endl;
    // cout << arr + 1 << endl;
    // cout << *arr + 1 << endl;
    // cout << *(arr) + 1 << endl;
    // cout << *(arr + 1) << endl;
    // cout << *(arr + 2) << endl;
    // cout << *(arr + 3) << endl;

    // cout << 0[arr] << endl;
    // cout << 1[arr] << endl;
    // cout << 2[arr] << endl;
    // cout << 3[arr] << endl;

    // // arr = arr + 1;// ERROR INT* TO INT[] INCOMPATIBLE TYPES

    // int *ptr = arr;// int *ptr = &arr[0];
    // cout << arr << endl;
    // cout << ptr << endl;
    // cout << sizeof(arr) << endl;
    // cout << sizeof(ptr) << endl;

    // CORRECT WAYS OF POINTER CREATION
    // int arr[50] = {1, 2, 3, 4, 5};
    // // int *ptr = arr;
    // // int *ptr = &arr; // ERROR // IT TAKES ADDRESS OF ENITRE ARRAY
    // int *ptr = &arr[0];

    // cout << arr << endl;
    // cout << arr[0] << endl;
    // cout << *arr << endl;
    // cout << ptr << endl;
    // cout << *ptr << endl;

    // CHARACTER ARRAY POINTER
    // char ch[50] = "Om Jindal";
    // // char *cptr = ch;// IT TAKES ADDRESS OF ONLY FIRST ELEMENT
    // // char *cptr = &ch; // ERROR // IT TAKES ADDRESS OF ENITRE ARRAY
    // char *cptr = &ch[0];// IT TAKES ADDRESS OF ONLY FIRST ELEMENT

    // cout << ch << endl;
    // cout << cptr << endl;
    // cout << *cptr << endl;
    // cout << char((*cptr) + 1) << endl;
    // cout << *(cptr + 1) << endl;

    // POINTER TO CHARACTER
    // char ch = 'k';
    // char *cptr = &ch;
    // cout << cptr << endl;// IT WILL PRINT UNTIL NULL POINTER \0 IS ENCOUNTERED
    // cout << ch << endl;

    return 0;
}