#include <bits/stdc++.h>
using namespace std;

class abc
{
public:
    int x;
    int *y;

    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    // // Default Dumb Copy Constructor
    // abc(const abc&obj){
    //     this-> x = obj.x;
    //     this-> y = obj.y;
    // }

    // Smart Deep Copy Constructor
    abc(const abc &obj)
    {
        this->x = obj.x;
        y = new int(*obj.y);
    }

    void print()
    {

        printf("X : %d\nPointer Y : %p\nValue Y : %d\n\n", x, y, *y);
    }

    ~abc()
    {
        delete y;
    }
};
int main()
{
    // abc obj(1, 2);
    // obj.print();

    // abc obj2(obj);
    // obj2.print();

    // *obj2.y = 20;

    // obj.print();
    // obj2.print();

    abc *a = new abc(1,2);
    abc b = *a;
    delete a;
    b.print();// double free the object in the heap in case of dump pointer
    return 0;
}