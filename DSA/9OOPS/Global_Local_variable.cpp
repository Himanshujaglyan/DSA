#include <bits/stdc++.h>
using namespace std;

int x = 2;

void fun()
{
    cout << "Inside fun" << endl;
    cout << x << endl;
    int x = 100;
    ::x = 55;
    cout << x << endl;
    cout << ::x << endl;
}

int main()
{

    cout << x << endl;
    x = 20;
    cout << x << endl;
    int x = 40;
    cout << x << endl;
    // Accessing Global Variable
    cout << ::x << endl;
    {
        cout << x << endl;
        int x = 50;
        cout << x << endl;
        cout << ::x << endl; // Here it will access the global variable // there is no way to access x = 40 here
    }

    fun();
    return 0;
}