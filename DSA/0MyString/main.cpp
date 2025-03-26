#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
    MyString s("codehelp");
    MyString t = "CodeHelp";
    cout << s << endl;
    cout << s[0] << endl;
    cout << s.find("dehe") << endl;
    cout << s.find("dehed") << endl;

    MyString a = "Lakshay";
    MyString b = " Kumar";
    a += b;
    cout << a << endl;

    a.erase(70, 1);
    cout << a << endl;

    // string a = "Lakshay";
    // string b = " Kumar";
    // string c = a + b;
    // cout<<c<<endl;
    return 0;
}