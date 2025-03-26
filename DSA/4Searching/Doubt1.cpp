#include <iostream>
#include <string.h>
using namespace std;

int sqrt(int n)
{
    int ans = -1;
    int s = 0;
    int e = n;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid > n)
        {
            e = mid - 1;
        }
        else
        {
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}
double squareroot(int n)
{
    double answer = sqrt(n);
    double step = 0.1;

    for (int i = 0; i < 10; i++)
    {
        double j = answer;
        while (j * j <= n)
        {
            answer = j;
            j += step;
        }
        step /= 10;
    }
    return answer;
}
int main()
{
    char ch[10];
    cin >> ch;// 10 character elements
    int index = 0;
    while (ch[index] != '\0')
    {
        cout << ch[index] << endl;
        index++;
        cout << index << endl;
    }
    cout << "Number of elements are : " << index << endl;
    cout << "Number of elements are : " << strlen(ch) << endl;

    char c = 'a';
    char new_c = toupper(c);
    cout << c << endl;
    cout << new_c << endl;

    cout << squareroot(51) << endl;

    string str = "This is Om Jindal.";
    string str2 = "Om";
    string str3 = "   ";
    cout << str.find(str2) << endl; // return index
    cout << str.find(str3) << endl; // npos return value 4294967295
    return 0;
}