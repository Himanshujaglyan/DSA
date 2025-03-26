#include <iostream>
using namespace std;

void update(long long arr[], int size)
{
    *arr += 1;
}
void solve(long long *arr, int size) // HERE THE ADDRESS OF FIRST ELEMENT IS PASSED NOT THE WHOLE ARRAY
{
    cout << "Size of array inside function is : " << sizeof(arr) << endl; // IT WILL PRINT THE SIZE OF POINTER NOT THE SIZE OF ARRAY
    cout << arr << endl;
    cout << &arr << endl;
    cout << *arr << endl;
}
// void solve0(long long arr[], int size) // IN CASE OF SIMPLE DECLARATION SHOWS ERROR // HERE THE ADDRESS OF FIRST ELEMENT IS PASSED NOT THE WHOLE ARRAY
// {
//     cout << "Size of array inside function is : " << sizeof(arr) << endl; // IT WILL PRINT THE SIZE OF POINTER NOT THE SIZE OF ARRAY
//     cout << arr << endl;
//     cout << &arr << endl;
//     cout << *arr << endl;
// }
void solve1(int *p)
{
    *p = *p + 1;
}
void solve2(int *p)
{
    p = p + 1;
}
void solve3(int *&p)
{
    p = p + 1;
}
int main()
{

    // char arr[6] = {65, 67, 68, 69, 70, 71};

    // char *ptr = arr; // POINTER TO AN INTEGER
    // // int *ptr1 = &arr;// ERROR
    // char(*ptr1)[6] = &arr; // POINTER TO AN INTEGER ARRAY

    // cout << sizeof(ptr) << endl;
    // cout << sizeof(*ptr) << endl;
    // cout << sizeof(ptr1) << endl; // BUT SIZE OF POINTER REMAINS SAME WHETHER POINTING TO ARRAY OR INTEGER
    // cout << sizeof(*ptr1) << endl;
    // cout << sizeof((ptr1)[1]) << endl;// IT DISPLAY THE SIZE OF ARRAY 
    // cout << sizeof(*(ptr1)[1]) << endl;
    // cout << sizeof((*ptr1)[1]) << endl;

    // cout << *(ptr1)[1] << endl;
    // cout << (*ptr1)[1] << endl;

    // cout << (*ptr1)[0] << endl;
    // cout << int((ptr1)[0]) << endl;
    // cout << int(&arr[0]) << endl;

    // cout << (*ptr1)[1] << endl;
    // cout << int((ptr1)[1]) << endl;
    // cout << int(&arr[1]) << endl;

    // cout << (*ptr1)[2] << endl;
    // cout << int((ptr1)[2]) << endl;
    // cout << int(&arr[2]) << endl;

    // cout << (*ptr1)[3] << endl;
    // cout << int((ptr1)[3]) << endl;

    // cout << (*ptr1)[4] << endl;
    // cout << int((ptr1)[4]) << endl;

    // char ch[50] = "Om Jindal";
    // char *cptr = ch;
    // // char *cptr1 = &ch; // ERROR

    // long long arr[5] = {1, 2, 3, 4, 5};
    // cout << "Size of array is : " << sizeof(arr) << endl;
    // cout << arr << endl;
    // cout << &arr << endl;
    // solve(arr, 5);
    // update(arr, 5);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << "\t";
    // }

    // int a = 5;
    // int *ptr = &a;
    // cout << ptr << endl;
    // cout << &ptr << endl;
    // cout << *ptr << endl;
    // cout << endl;
    // solve1(ptr);
    // cout << ptr << endl;
    // cout << &ptr << endl;
    // cout << *ptr << endl;
    // cout << endl;
    // solve2(ptr);
    // cout << ptr << endl;
    // cout << &ptr << endl;
    // cout << *ptr << endl;
    // cout << endl;
    // solve3(ptr);
    // cout << ptr << endl;
    // cout << &ptr << endl;
    // cout << *ptr << endl;

    return 0;
}