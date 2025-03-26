#include <iostream>
using namespace std;

void printdata(string name)
{
    for (int i = 0; i < 5; i++)
    {
        cout << name << endl;
    }
}

int sum(int a, int b);

void print()
{ // WE CAN USE RETURN IN VOID BUT WITHOUT RETURNING ANY VALUE
    cout << "message 1" << endl;
    return;
    cout << "message 2" << endl;
}

int main()
{

    // printdata("OM");
    // printdata("JINDAL");
    // printdata("NITN");
    // printdata("SHARMA");
    // printdata("VISHAL");

    cout << sum(5, 6) << endl;
    sum(6, 7);
    cout << sum(5, 6) << endl;

    print();
    return 0;
}

int sum(int a, int b)
{
    cout << "Inside sum." << endl;
    return a + b;
}