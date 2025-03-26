#include <bits/stdc++.h>
using namespace std;

class abc
{
    mutable int x; // it is used only for debugging purposes // it allows the function to change the variables when it is constant
    int *y;
    int z;
    int x1;

public:
    abc()
    {
        x = 0;
        y = new int(0);
    }

    // ctor : old style
    // abc(int _x, int _y, int _z = 0) // default argument & always written to the right
    // {
    //     x = _x;
    //     y = new int(_y);
    //     z = _z;
    // }

    // INITIALIZATION LIST
    abc(int _x, int _y, int _z = 0) : x(_x), y(new int(_y)), z(_z) {}

    int getX() const
    {
        // x1 = 50;// error
        return x;
    }
    int getX1() const
    {
        x = 45;
        return x;
    }
    int getY() const
    {
        int f = 20;
        // y = &f; // error
        return *y;
    }
    int getZ()
    {
        return z;
    }
};

void printABC(const abc &a) // if a object is made constant it can call only those functions that are constant
{
    cout << a.getX() << " " << a.getY() << endl;
    // cout << a.getX() << " " << a.getY() << " " << a.getZ() << endl; // error as the fxn getZ is not constant
}

class test
{
    const int z;

public:
    // constructor does not allow the value to be assigned to constant z variable
    // test(int _z = 0)
    // {
    //     z = _z;// error
    // }

    // Initialization list allows the value to be assigned
    test(int _z = 0) : z(_z)
    {
        cout << "Successful Assignemnt" << endl;
        // z = 45; // error
    }
};

int main()
{
    // {
    //     const int x = 5;
    //     // x = 10;// error
    //     cout << x << endl;

    //     // int *ptr = &x;// error // works in old compiler to break the constness of variable
    //     // *ptr = 45;
    //     cout << x << endl;
    // }

    // {
    //     int *a = new int;
    //     *a = 5;
    //     cout << *a << endl;
    //     delete a; // TO AVOID MEMORY LEAK
    //     int b = 45;
    //     a = &b;
    //     cout << *a << endl;
    // }

    // { /* CONSTANT WITH POINTER */
    //     // const int *a = new int(2);// const data, non-const pointer
    //     int const *a = new int(2); // same as line 23
    //     cout << *a << endl;
    //     // *a = 5;//error
    //     int b = 45;
    //     a = &b;
    //     cout << *a << endl;
    // }

    // {
    //     int *const a = new int(10); // const pointer, non-const data
    //     cout << *a << endl;
    //     *a = 2;
    //     cout << *a << endl;
    //     int b = 88;
    //     // a = &b;// error
    // }
    // {
    //     const int *const a = new int(10);
    //     cout << *a << endl;
    //     // *a = 45;// error
    //     int b = 45;
    //     // a = &b;// error
    // }

    {
        abc a;
        cout << a.getX() << endl;
        cout << a.getY() << endl;

        abc a1(1, 2);
        printABC(a1);
        cout << a1.getX() << endl;
        cout << a1.getY() << endl;
        cout << a1.getZ() << endl;

        abc a2(1, 2, 3); // IT WILL OVERIDE THE DEFAULT ARGUMENT
        cout << a2.getX() << endl;
        cout << a2.getY() << endl;
        cout << a2.getZ() << endl;
    }

    return 0;
}