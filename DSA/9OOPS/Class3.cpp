#include <bits/stdc++.h>
using namespace std;

class Animal1
{
public:
    Animal1()
    {
        cout << "Animal1 ctor" << endl;
    }
    void sound()
    {
        cout << "Animal1 making Sound." << endl;
    }
    ~Animal1()
    {
        cout << "Animal1 dtor." << endl;
    }
};

class Dog1 : public Animal1
{
public:
    Dog1()
    {
        cout << "Dog1 ctor" << endl;
    }
    void sound()
    {
        cout << "Dog1 Barking." << endl;
    }
    ~Dog1()
    {
        cout << "Dog1 dtor." << endl;
    }
};

void sound(Animal1 *&animal)
{
    animal->sound();
}

class Animal
{
public:
    Animal()
    {
        cout << "Animal ctor" << endl;
    }
    virtual void sound()
    {
        cout << "Animal making Sound." << endl;
    }
    virtual ~Animal()
    {
        cout << "Animal dtor." << endl;
    }
};

class Dog : public Animal
{
public:
    int x = 5;
    Dog()
    {
        cout << "Dog ctor" << endl;
    }
    void sound() override // we can add override keyword to increase the readability of the code but it is not compulsory
    {
        cout << "Dog Barking." << endl;
    }
    ~Dog() override
    {
        cout << "Dog dtor." << endl;
    }
};
class Cat : public Animal
{
public:
    Cat()
    {
        cout << "Cat ctor" << endl;
    }
    void sound()
    {
        cout << "Cat Meowing." << endl;
    }
    ~Cat()
    {
        cout << "Cat dtor." << endl;
    }
};

void sound(Animal *&animal)
{
    animal->sound();
}
int main()
{
    // {
    //     Dog *d = new Dog();
    //     d->sound();

    //     // Upcasting
    //     Animal1 *a = new Dog1();
    //     sound(a); // here the compiler will do early binding and bind it the sound of animal class
    //     delete a;

    //     cout << endl;

    //     Animal *animal = new Cat();
    //     sound(animal); // here we have used virtual keyword so compiler will do late binding and bind it to the sound of cat class
    //     delete animal;
    // }

    // {
    //     Animal *animal = new Dog();
    //     // cout << animal->x << endl;// ERROR does not have any variable x

    //     // downcasting // Not a good practise
    //     // Dog1 *dog = new Animal1();// ERROR
    //     Animal1 *a = new Dog1();
    // }
    return 0;
}