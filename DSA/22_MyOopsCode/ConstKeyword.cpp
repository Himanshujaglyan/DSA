//! Love Babber Lecture Number 126 (Batch-1.0) and Lecture Name (Const Keyword)
#include<bits/stdc++.h>
using namespace std;
# define PI 3.14
class Box{
     int length;//but hum yaha int se pahle mutable keyword likh ker const function me bhi 
    public:
    // Box(int l){
    //     length = l;
    // }

    //Initialization List = (Newly way of making Constructor)
    Box(int l):length(l){}

    int getLength()const{
        return length;
    }
    void setLength(int l)const{
        //length = l;//Modify nahi ker sakte error aayega or ager const hata de to object issue keraga ke vo sirf cosnt member function ko hi call ker sakta hai !!
    }
};

int main(){
    //! Const Keyword:
    //! (I) Const with Pointer:
    //1)Const data,non-const Pointer
        // const int*a = new int(2);
        // Note : yaha data dubara change nahi ker sakte per kahi or point ker sakte hai
        //a = 5;// showing error
        // int b = 5;
        // a = &b;
        // cout<<*a<<endl; output : *a = 5
    //-------------------------------------
    //2) Const Pointer ,Non-const Data
        // int* const a = new int(2);
        //Note: es case me hum a ko change ker sate hai dubara per kahi point nahi kera sakte
        // *a = 10;
        // cout<<*a<<endl;
        // int b = 20;
        // a = &b;we can't point in this case
        // cout<<*a<<endl;
    //--------------------------------------
    //3) Both Data and Pointer are Constant
        // const int* const a = new int(2);
        // *a = 20;//Data bhi change nahi hoga
        // int b = 30;
        // a = &b;//Pointer bhi change nahi hoga
        
        //! (II) Const with Functions:
        // const Box b(10);
        // cout<<b.getLength()<<endl;
        // b.setLength(20);
        // cout<<b.getLength()<<endl;
        
        //! Macros in CPP 
        //# define PI Upper kiya hai sabse!
        // float r = 5;
        // float area = PI * r * r;
        // cout << "Area of circle: " << area << endl;
        
      
        
        return 0;
}