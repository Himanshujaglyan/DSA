#include <iostream>
#include<string>
using namespace std;

class Testing
{
    static int z;
    // empty class
};
int Testing::z = 0;
class Student // Class can be called as a datatype
{
private:
    string gf;

public:
    static int z; // static variable does not contribute to size
    // States, attributes, Properties
    int id;
    int age;
    bool present;
    double marks;
    string name; // string is also a type of class with properties and behaviours // It takes 24 bytes of memory space
    int nos;     // here the ordering of varibale also matter while calculating the size of class and after string are used it will take the size of largest data type i.e double for padding not the size of string
    int *v;

    // constructor, ctor
    Student()
    {
        // default contructor // hence constructor is mandatory in a class and compiler already declares a constructor by itself
        cout << "Student ctor called" << endl;
    }

    // Parameterized Constructor
    Student(int _id, int _age, bool _present, double _marks, string _name, string _gfname)
    {
        id = _id;
        age = _age;
        present = _present;
        marks = _marks;
        name = _name;
        gf = _gfname;
        this->v = new int(102);
        cout << "Paramterized ctor is called" << endl;
    }
    Student(int id, int age, bool present, double marks, string name) // error // compiler with not know which id, age we are referring to
    {
        id = id;
        age = age;
        present = present;
        marks = marks;
        name = name;
        cout << "Parameterized constructor without gf" << endl;
    }
    Student(int id, int age, bool present, string name)
    {
        this->id = id;
        this->age = age;
        this->present = present;
        this->marks = marks;
        this->name = name;
        this->v = new int(102);
        cout << "Parameterized constructor without gf and marks" << endl;
    }

    // copy ctor // it is made public and also has no return type
    Student(const Student &srcobj) // Here we have used reference of the source object and used the const keyword
    {
        cout << "Student copy constructor is called" << endl;
        this->name = srcobj.name;
        this->age = srcobj.age;
        this->id = srcobj.id;
        this->present = srcobj.present;
        this->gf = srcobj.gf;
        this->nos = srcobj.nos;
    }

    // destructor : dtor // it also has no return type
    ~Student()
    {
        cout << "Student dtor is called." << endl;
        delete v;
    }

    // Functions, Meathods, Behaviours

    void game()
    {
        int gamer;
        cout << "Gaming" << endl;
    }
    void study()
    {
        cout << "Studying" << endl;
    }
    void bunk()
    {
        cout << "Bunking" << endl;
    }

    // Getter, Setter // Used to access the private variables
    string getGfName()
    {
        return this->gf;
        // return gf;
    }

    void setGfName(string gf)
    {
        this->gf = gf;
    }

private:
    void gfChatting()
    {
        cout << "Chatting" << endl;
    }
};

int Student ::z;

int main()
{
    Student s[2] = {Student(), Student()};
    Student s1; // object :- Instance of a class

    cout << s1.age << endl; // constructor sets the value to zero by default if it was the default constructor made by compiler not by us

    /* Size of empty class is 1 byte which is the smallest addressable space in the memory and this
    is necessary to identify and keep track of something like this exist */
    cout << sizeof(Testing) << endl;

    cout << sizeof(Student) << endl; // here the variables declared inside function does not come in account

    s1.name = "Om Jindal";
    s1.age = 20;
    s1.marks = 99;
    s1.id = 1222126;
    s1.present = 1;
    // s1.gf = "Single";// error

    Student s2(1222125, 19, 0, 31, "Nitin", "Single");
    cout << s2.id << endl;
    cout << s2.name << endl;

    Student s3(1222079, 19, 0, 45, "Jatin");
    cout << s3.id << endl;   // wrong value
    cout << s3.name << endl; // wrong value

    Student s4(1222197, 19, 1, "Vishal");
    cout << s4.id << endl;
    cout << s4.name << endl;

    int *a = new int(5);
    Student *s5 = new Student(1222123, 21, 0, "Nitin Kumar");

    // cout << s5.name << endl; // error
    cout << s5->id << endl;
    cout << (*s5).name << endl;
    // cout << *s5.name << endl;// error

    delete (s5); // NO LEAK OF MEMORY

    // copy ctor (in case we have not defined the copy constructor compiler makes a copy constructor of its own and makes a shallow copy)
    Student s6(1, 12, 1, 13.4, "Chotta Bheem", "Chutki");
    // Student s7 = s6; // copy constructor is called here
    Student s7(s6);
    // Student s7;
    // s7 = s6;// copy constructor is not called here as constructor get called only when the object is being made
    cout << s6.name << endl;
    cout << s7.name << endl;

    {
        Student s8(1, 12, 1, 13.4, "Chotta Bheem", "Chutki");
        cout << s8.name << endl;
    }
    Student s9;

    Student s10(1, 10, 1, 3.14, "Chotta Bheem", "Chutki");

    cout << s10.name << endl;
    cout << s10.getGfName() << endl;

    s10.setGfName("Indumati");

    cout << s10.getGfName() << endl;

    return 0;
}