#include <iostream>
using namespace std;

class A
{
    int x;

public:
    A(int _x) : x(_x) {}

    int getX() const { return x; }
    void setX(int _val) { x = _val; }
    void print() const
    {
        cout << x << endl;
    }
    friend class B;
    friend void print(const A &a);
};

class B
{
public:
    void print(const A &a)
    {
        cout << a.getX() << endl;
        cout << a.x << endl;
        a.print();
    }
};

void print(const A &a)
{
    cout << a.x << endl;
}
int main()
{
    A a(5);
    B b;
    b.print(a);
    print(a);
    return 0;
}