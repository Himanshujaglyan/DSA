#include <iostream>
#include <string.h>
using namespace std;
int findLength(char ch[], int size)
{
    // int length = 0;
    // for (int i = 0; i < size; i++)
    // {
    //     if (ch[i] == '\0')// Null pointer
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         length++;
    //     }
    // }
    // return length;

    int index = 0;
    while (ch[index] != '\0')
    {
        index++;
    }

    return index;
}
void reverse(char ch[]) // PASSED BY REFERNCE
{
    int s = 0;
    int e = strlen(ch) - 1; // strlen(array_name) FUNCTION
    while (s < e)
    {
        swap(ch[s++], ch[e--]);
    }
}

void convertToUpperCase(char ch[])
{
    int index = 0;
    while (ch[index] != '\0')
    {
        if (ch[index] >= 'a' && ch[index] <= 'z')
        {
            ch[index] = ch[index] - 'a' + 'A';
        }
        index++;
    }
}
void convertToLowerCase(char ch[])
{
    int index = 0;
    while (ch[index] != '\0')
    {
        if (ch[index] >= 'A' && ch[index] <= 'Z')
        {
            ch[index] = ch[index] - 'A' + 'a';
        }
        index++;
    }
}
void replaceCharacter(char ch[])
{
    int index = 0;
    while (ch[index] != '\0')
    {
        if (ch[index] == '@')
        {
            ch[index] = ' ';
        }
        index++;
    }
}

bool checkPalindrome(char ch[])
{
    int i = 0;
    int j = strlen(ch) - 1;
    while (i <= j)
    {
        if (ch[i] == ch[j])
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
int main()
{

    // // ARRAY IN CASE OF INTEGER
    // int arr[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     cin >> arr[i];
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << endl;
    // }

    // ARRAY IN CASE OF CHARACTER
    // char ch[10];
    // cin >> ch;// INPUT : OMJINDAL
    // cout << ch << endl;

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << "The value at index " << i << " : " << ch[i] << endl;
    // }

    // int temp = ch[9];
    // cout << temp;

    // char ch[100];
    // // cin >> ch; // INPUT : (OM JINDAL)
    // cin.getline(ch, 100);                                // cin.getline(array_name, size) FUNCTION
    // cout << ch << endl;

    // // cout << "The length of string is : " << findLength(ch, 100) << endl;
    // // cout << "The length using function is : " << strlen(ch) << endl;

    // // reverse(ch);
    // // cout << "After reversing string is : " << ch << endl;

    // // convertToUpperCase(ch);
    // // cout << "After conversion : " << ch << endl;

    // // replaceCharacter(ch);
    // // cout << "After conversion : " << ch << endl;

    // if (checkPalindrome(ch))
    // {
    //     cout << "The string is a Palindrome." << endl;
    // }
    // else
    // {
    //     cout << "The string is not a Palindrome." << endl;
    // }

    // string name;
    // // cin >> name;
    // getline(cin, name);                                      // getline(cin, string_name) FUNCTION
    // cout << name << endl;

    // // for (int i = 0; name[i] != '\0'; i++)
    // // {
    // //     cout << name[i];
    // // }

    // // cout << endl;
    // // cout << int(name[6]);

    // string str;
    // cin >> str;
    // cout << "Length of string is : " << str.length() << endl;  // string_name.length() FUNCTION
    // cout << "If string is empty : " << str.empty() << endl;  // string_name.empty() FUNCTION
    // string temp = "";
    // cout << "If string is empty : " << temp.empty() << endl;
    // cout << "Character at position zero is : " << str.at(0) << endl;  // string_name.at(position) FUNCTION
    // cout << "Character at front is : " << str.front() << endl;  // string_name.front() FUNCTION
    // cout << "Character at back is : " << str.back() << endl;  // string_name.back() FUNCTION

    // string str1 = "Om";
    // string str2 = "Jindal";
    // cout << str1 << endl;
    // cout << str2 << endl;
    // str1.append(str2);  // string_name.append(string2_name) FUNCTION
    // cout << str1 << endl;
    // cout << str2 << endl;

    // string str = "This is Om Jindal";
    // cout << str << endl;
    // str.erase(4, 3);  // string_name.erase(position, number_of_character) FUNCTION
    // cout << str << endl;
    // string str2 = " is the";
    // str.insert(4, str2);  // string_name.insert(position, string_name) FUNCTION
    // cout << str << endl;

    // string name;
    // name.push_back('O');  // string_name.push_back(element) FUNCTION
    // name.push_back('J');
    // cout << name << endl;
    // name.pop_back();  // string_name.pop_back() FUNCTION
    // cout << name << endl;

    // string str1 = "My Name Is Om Jindal";
    // string str2 = "Om ";
    // if (str1.find(str2) == string::npos)  // string_name.find(string2_name) FUNCTION // NOT FOUND -> return string::npos
    // {
    //     cout << "Not found" << endl;
    // }
    // else
    // {
    //     cout << "Found." << endl;
    // }

    // string str1 = "Om";
    // string str2 = "Od";
    // if (str1.compare(str2) == 0)  // string_name.compare(string2_name) FUNCTION
    // {
    //     cout << "The string is equal." << endl;
    // }
    // else
    // {
    //     cout << "The string is not equal." << endl;
    // }

    // if (str1 == str2)// NOT TO BE USED
    // {
    //     cout << "Matching." << endl;
    // }

    // string str = "This is a car, big Daddy of all SUVs.";
    // cout << str.substr(19, 5) << endl;  // string_name.substr(position, number_of_character) FUNCTION
    return 0;
}