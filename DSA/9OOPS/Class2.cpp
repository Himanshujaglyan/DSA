#include <bits/stdc++.h>
using namespace std;

class Bird
{
private:
    int nol;

protected:
    string colour;

public:
    int age, weight;

    void eat()
    {
        cout << "Bird is Eating." << endl;
    }

    void fly()
    {
        cout << "Bird is flying." << endl;
    }
};

class Sparrow : public Bird
{
public:
    Sparrow(int age, int weight, string colour)
    {
        this->age = age;
        this->weight = weight;
        this->colour = colour;
    }
    void grassing()
    {
        cout << "Bird is grassing." << endl;
    }
};

class Pegion : protected Bird
{
public:
    void guttering()
    {
        cout << "Pegion is guttering." << endl;
    }
};

class Parrot : private Bird
{
public:
    int getAge()
    {
        return this->age;
    }
    void speaking()
    {
        cout << "Parrot is Speaking." << endl;
    }
};

class Person
{
public:
    void walk()
    {
        cout << "Walking...." << endl;
    }
};

class Teacher : virtual public Person
{
public:
    void teach()
    {
        cout << "Teaching...." << endl;
    }
};

class Researcher : virtual public Person
{
public:
    void research()
    {
        cout << "Researching...." << endl;
    }
};

class Professor : public Teacher, public Researcher, virtual public Person
{
public:
    void bore()
    {
        cout << "Boring...." << endl;
    }
};

// Function Overloading
int add(int a, int b)
{
    cout << "Integer Data" << endl;
    return a + b;
}

double add(double a, double b)
{
    cout << "Double Data" << endl;

    return a + b;
}

int add(int a, int b, int c)
{
    cout << "Integer Data with 3 variables" << endl;
    return a + b + c;
}

class Vector
{
    int x, y;

public:
    // Vector(int x, int y)
    // {
    //     this->x = x;
    //     this->y = y;
    // }
    Vector(int x, int y) : x(x), y(y) {}
    void display()
    {
        cout << "x : " << x << " ";
        cout << "y : " << y << endl;
    }

    void operator+(const Vector &src)
    {
        this->x += src.x;
        this->y += src.y;
    }
    void operator-(const Vector &src)
    {
        this->x -= src.x;
        this->y -= src.y;
    }
    void operator++()
    {
        this->x += 1;
        this->y++;
    }
};

int main()
{
    // {
    //     Sparrow s1(1, 12, "blue");
    //     cout << s1.age << endl;
    //     // cout << s1.colour << endl;// inaccessible protected data
    //     // cout << s1.nol << endl; // inaccessible private data
    //     s1.eat();
    //     s1.grassing();

    //     Pegion p1;
    //     // p1.eat();// inaccessible protected data
    //     p1.guttering();

    //     Parrot pa1;
    //     // pa1.eat();// inaccessible private data
    //     // cout << pa1.nol << endl;// inaccessible
    //     cout << pa1.getAge() << endl;
    //     pa1.speaking();
    // }

    // {
    //     Professor p;
    //     // p.walk();// error ambiguity

    //     // Solution 1 :- Scope Resolution Operator
    //     p.Teacher::walk();
    //     p.Researcher::walk();

    //     // Solution 2 :- Virtually Inherit
    //     p.walk();
    // }

    // {// Compile Time Polymorphism
    // cout << add(1, 5) << endl;
    // cout << add(4.5, 5.6) << endl;
    // cout << add(1, 2, 3) << endl;

    // // Operator Overloading
    // Vector v1(1, 4);
    // Vector v2(5, 6);
    // v1.display();
    // v1 + v2;
    // v1.display();
    // v1 - v2;
    // v1.display();
    // ++v1;
    // v1.display();}
    return 0;
}