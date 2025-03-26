#include <iostream>
using namespace std;

#define AUTHOR "OM JINDAL" // Here it is a Macro // it defines author as om jindal in pre processing

#define PI 3.1415 // it increases the readability of the code

#define MAXX(x, y) {x > y ? x : y}

float circleArea(float r)
{
    return PI * r * r;
}

void fun(){
    int a = 10;
    int b = 20;
    int c = MAXX(a,b);
    cout << c << endl;
}
int main()
{

    cout << "Written By : " << AUTHOR << endl;
    
    // int AUTHOR = 94;// ERROR
    // cout << AUTHOR << endl;

    // AUTHOR = "NITIN";// error

    cout << circleArea(4.5) << endl;

    fun();
    return 0;
}