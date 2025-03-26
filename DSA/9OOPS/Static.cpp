#include <iostream>
using namespace std;

class Student
{
public:
    int marks;
    int data;

    Student() {}
    Student(int x)
    {
        cout << "Constructor is called" << endl;
        marks = x;
    }
};
class abc
{
public:
    int x, y;

    void print() // here a hidden argument i.e this pointer is passed to know which object is calling the fxn or to access which object variables
    {
        cout << this->y << " " << this->x << endl;
    }
};

class ABC
{
public:
    static int x, y; // sets the default value to zero

    void print()
    {
        cout << this->x << " " << y << endl;
    }
};

int ABC ::x;
int ABC ::y;

class ABC1
{
    // static int a = 5;// error as we cannot directly initialize the value of static data members
    static int x, y;
    int z;

public:
    // ABC1() : x(0), y(0) {} // error as x must be a non-static data member
    ABC1(int _z = 0) : z(_z) {}

    static void printer() // const cannot be used in static
    {
        cout << x << " " << y << endl;
        // cout << z << endl;// error // The static fxn can access only satic data memebers
        // cout << this->x << endl; // error // It has no this pointer as it is common to all the instances
        cout << "This is static " << __FUNCTION__ << endl;
    }
};
int ABC1 ::x = 100;
int ABC1 ::y = 200;

int main()
{

    Student s1;
    Student s2(100);
    Student s3 = 100;
    cout << s3.marks << endl;

    abc obj0 = {1, 21};
    abc obj = {3, 4};
    obj0.print();
    obj.print();

    ABC obj1;
    obj1.print();
    obj1.x = 10;
    obj1.y = 20;
    obj1.print();
    ABC obj2;
    obj2.print();
    obj2.x = 30;
    obj2.y = 40;
    obj1.print();
    obj2.print();

    ABC1 obj3;
    ABC1::printer(); // using class name acess
    obj3.printer();  // using object to access
    return 0;
}

// A static member function is independent of any object of the class.
// A static member function can be called even if no objects of the class exist.
// A static member function can also be accessed using the class name through the scope resolution operator.
// A static member function can access static data members and static member functions inside or outside of the class.
// Static member functions have a scope inside the class and cannot access the current object pointer.
// You can also use a static member function to determine how many objects of the class have been created.

// The reason we need Static member function:
// Static members are frequently used to store information that is shared by all objects in a class.
// For instance, you may keep track of the quantity of newly generated objects of a specific class type using a static data member as a counter.
// This static data member can be increased each time an object is generated to keep track of the overall number of objects.