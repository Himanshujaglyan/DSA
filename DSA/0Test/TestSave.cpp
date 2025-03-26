#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#define cube(b) b *b *b
using namespace std;

void swap1(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void swap2(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
void swap3(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
int main()
{

    int count = -30;
    count %= 26;
    cout << count << endl;

    // if ("")
    // {
    //     cout << "True" << endl;
    // }
    // else
    // {
    //     cout << "False" << endl;
    // }

    // char ch[] = "Hello World";
    // cout << ch[0] << endl;

    // char ch1[] = "HelloQuiz";
    // char ch2[] = {'H','e','l','l','o','Q','u','i','z'};

    // cout << sizeof(ch1) << endl;
    // cout << sizeof(ch2) << endl;
    // int a = printf("HelloWorld");
    // cout << endl
    //      << a << endl;

    // vector<int> v = {1, 2, 3, 4, 5};

    // vector<int> v1 = v;

    // vector<int> v1;
    // v1 = v;

    // vector<int> v1(v);

    // for (int i = 0; i < v1.size(); i++)
    // {
    //     cout << v1[i] << " ";
    // }

    // cout << cube(1 + 2) << endl;

    // int i = 0;
    // while (i < 5)
    // {
    //     float n = pow(10, i++);
    //     cout << n << endl;
    // }
    // cout << endl;
    // i = 0;
    // while (i < 5)
    // {
    //     int n = pow(10, i++);
    //     cout << n << endl;
    // }

    // std :: cout << "Hello World" << std :: endl;

    // int a;
    // cout << a << endl;
    // cin >> a;
    // cout << a << endl;
    // a = '65'; // 13877
    // cout << a << endl;

    // int num;
    // cin >> num << endl; // WE CANNOT USE ENDL IN CIN

    // int a = 5;
    // int b = 10;
    // cout << "a is : " << a << " and b is : " << b << endl;
    // swap1(a, b);
    // cout << "a is : " << a << " and b is : " << b << endl;
    // swap2(a, b);
    // cout << "a is : " << a << " and b is : " << b << endl;
    // swap3(a, b);
    // cout << "a is : " << a << " and b is : " << b << endl;

    // int a = -5;
    // cout << a * a << endl;
    return 0;
}