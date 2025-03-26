#include <iostream>
using namespace std;

class Box
{
    int width;
    Box(int _w) : width(_w) {} // Constructor can be made private

public:
    int getWidth() const
    {
        return width;
    }

    void setWidth(int _val)
    {
        width = _val;
    }

    friend class BoxFactory;
};

class BoxFactory
{

    int count;

public:
    Box getABox(int _w)
    {
        ++count;
        return Box(_w);
    }
};
int main()
{
    // Box b(5);// error
    // cout << b.getWidth() << endl;

    BoxFactory bf;
    Box b = bf.getABox(5);
    cout << b.getWidth() << endl;
    return 0;
}