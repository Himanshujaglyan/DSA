//! Shallow and Deep copy
#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    int* x;
    A(int val){
        x = new int(val);
    }
    void show(){
        cout<<*x<<endl;
    }
};

class B{
    public:
    int* x;
    B(int val){
        x = new int(val);
    }

    //Deep Copy constructor
    B(const B& other){
        x = new int(*other.x);//inner object ya pointer ke ek copy bana ke uski value ke ab usme jo merji change kare actual value per impact nahi padega
    }

    void show(){
        cout<<*x<<endl;
    }
};

int main(){
    //! 1)Shallow Copy (Interviwer ko yahi example dena hai)
    // A a1(20);
    // A a2 = a1; // shallow copy (default)
    // *a2.x = 30;//mene kya kera inner pointer ko change kiya lekin by reference hai to orignal ko hi change ker dega
    // a1.show();//30
    // a2.show();//30

    //! 2) Deep Copy
    // B b1(10);
    // B b2 = b1;
    // *b2.x = 20;
    // b1.show();
    // b2.show();
    

    return 0;
}
