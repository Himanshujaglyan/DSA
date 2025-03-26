#include <iostream>
using namespace std;

class Base
{
    int x;

public:
    Base()
    {
        cout << "Base ctor\n";
    }
    Base(int x)
    {
        this->x = x;
        cout << "Base new ctor\n";
    }
    virtual ~Base()
    {
        cout << "Base dtor\n";
    }
};
class Derived : public Base
{
    int *a;

public:
    Derived()
    {
        a = new int[1000];
        cout << "Derived ctor\n";
    }
    ~Derived()
    {
        delete[] a;
        cout << "Derived dtor\n";
    }
};

inline void numberShow(int num)
{
    cout << num << endl;
}
int main()
{
    Base *b = new Derived();
    Base *base = new Base();
    delete b;
    delete base;
    Derived d;
    Base b1 = 100;// correct syntax

    numberShow(10); // cout << num << endl;
    numberShow(10); // cout << 10 << endl; // at the time of executable this code is there
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    return 0;
}