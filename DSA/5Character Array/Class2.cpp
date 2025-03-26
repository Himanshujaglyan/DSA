#include <iostream>
#include <string.h>
using namespace std;
bool checkPalindrome(string str, int i, int j);
int expand(string str, int i, int j);
string removeAdjacentDuplicates(string str)
{
    string temp = "";
    int index = 0;
    while (index <= str.length() - 1)
    {
        if (temp[temp.length() - 1] == str[index] && (temp.length() - 1) >= 0)
        {
            temp.pop_back();
        }
        else
        {
            temp.push_back(str[index]);
        }
        index++;
    }
    return temp;
}
string removeAdjacentDuplicates1(string str)
{
    string temp = "";
    int index = 0;
    while (str[index] != '\0')
    {
        if (temp.back() != str[index])
        {
            temp.push_back(str[index]);
        }
        else
        {
            temp.pop_back();
        }
        index++;
    }
    return temp;
}
string removeAllOccurences(string str, string part) // string does not get passed by reference
{
    while (str.find(part) != string::npos)
    {
        str.erase(str.find(part), part.length());
    }
    return str;
}
bool checkPalindrome2(string str)// WHETHER IT IS A PALINDROME AFTER REMOVING ATMOST 1 ELEMENT
{
    int i = 0;
    int j = str.length() - 1;
    while (i <= j)
    {
        if (str[i] == str[j])
        {
            i++;
            j--;
        }
        else
        {
            bool ans1 = checkPalindrome(str, i, (j - 1));
            bool ans2 = checkPalindrome(str, (i + 1), j);
            return (ans1 || ans2);
        }
    }
    return true;
}

bool checkPalindrome(string str, int i, int j)
{
    while (i <= j)
    {
        if (str[i] == str[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int countSubstringPalindrome(string str)
{
    int total = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int odd = expand(str, i, i);
        int even = expand(str, i, i + 1);
        total = total + even + odd;
    }
    return total;
}
int expand(string str, int i, int j)
{
    int count = 0;
    while (i >= 0 && j < str.length() && str[i] == str[j])
    {
        count++;
        i--;
        j++;
    }
    return count;
}
int main()
{
    string str = "azxxzy";
    str = removeAdjacentDuplicates1(str);
    cout << str << endl;

    string str1 = "daabcbaabcbc";
    string part = "abc";
    str1 = removeAllOccurences(str1, part);
    cout << str1 << endl;

    string str2 = "MADKMADAM"; // Time Complexcity : O(2N) = O(N)
    if (checkPalindrome2(str2))
    {
        cout << "The string is a Palindrome." << endl;
    }
    else
    {
        cout << "The string is not a Palindrome." << endl;
    }

    string str3 = "aaa";
    cout << countSubstringPalindrome(str3) << endl;
    return 0;
}