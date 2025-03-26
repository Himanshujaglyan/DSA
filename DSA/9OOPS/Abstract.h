#ifndef ABTRACT_H
#define ABSTRACT_H

#include <iostream>
using namespace std;

// abstract class
class Bird
{
public:
    void drink() { cout << "Bird is Drinking." << endl; }
    virtual void fly() = 0; // pure virtual function
    virtual void eat() = 0;
    // classes that inherit this class has to implement pure virtual function
};

class Sparrow : public Bird
{

    void eat()
    {
        cout << "Sparrow is Eating." << endl;
    }
    void fly()
    {
        cout << "Sparrow is flying" << endl;
    }
};
class Eagle : public Bird
{
    void eat()
    {
        cout << "Eagle is Eating." << endl;
    }
    void fly()
    {
        cout << "Eagle is flying" << endl;
    }
};

void birdDoesSomething(Bird *&bird)
{
    bird->eat();
    bird->fly();
    bird->eat();
}

#endif