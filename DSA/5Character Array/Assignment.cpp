#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <map>
using namespace std;
// VALID ANAGRAM LEETCODE 242
bool isAnagram(string s, string v)
{
    sort(s.begin(), s.end());
    sort(v.begin(), v.end());
    if (s == v)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isAnagram1(string s, string v)
{
    int mapping1[150] = {0};
    int mapping2[150] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        mapping1[s[i]]++;
    }
    for (int i = 0; i < v.length(); i++)
    {
        mapping2[v[i]]++;
    }
    for (int i = 97; i < 123; i++)
    {
        if (mapping1[i] != mapping2[i])
        {
            return false;
        }
    }
    return true;
}
bool isAnagram2(string s, string v)
{
    if (s.length() != v.length())
    {
        return false;
    }
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < v.length(); j++)
        {
            if (v[j] != 'X' && s[i] == v[j])
            {
                v[j] = 'X';
                break;
            }
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (v[i] != 'X')
        {
            return false;
        }
    }
    return true;
}

bool isAnagram3(string s, string t)
{
    int freqTable[256] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        freqTable[s[i]]++;
    }
    for (int i = 0; i < t.length(); i++)
    {
        freqTable[t[i]]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (freqTable[i] != 0)
        {
            return false;
        }
    }
    return true;
}
// REVERSE ONLY LETTERS LEETCODE 917
string reverseOnlyLetters(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        char ch1 = s[i];
        char ch2 = s[j];
        if ((ch1 >= 'a' && ch1 <= 'z') || (ch1 >= 'A' && ch1 <= 'Z'))
        {
            if ((ch2 >= 'a' && ch2 <= 'z') || (ch2 >= 'A' && ch2 <= 'Z'))
            {
                swap(s[i++], s[j--]);
            }
            else
            {
                j--;
            }
        }
        else
        {
            i++;
        }
    }
    return s;
}
string reverseOnlyLetters1(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        if (isalpha(s[i]) && isalpha(s[j]))
        {
            swap(s[i++], s[j--]);
        }
        else if (!isalpha(s[i]))
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return s;
}
// LONGEST COMMON PREFIX LEETCODE 14
string longestCommonPrefix(vector<string> &v)
{
    string str = v[0];
    string ans;
    for (int i = 0; i < str.length(); i++)
    {
        bool flag = 1;
        for (int j = 0; j < v.size(); j++)
        {
            if (i >= v[j].size() || v[j][i] != str[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            ans.push_back(str[i]);
        }
        else
        {
            break;
        }
    }
    return ans;
}
string longestCommonPrefix1(vector<string> &v)
{
    string check;
    string ans;
    string str = v[0];
    for (int i = 0; i < str.size(); i++)
    {
        check.push_back(str[i]);
        bool flag = 1;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].find(check) != 0)
            {
                return ans;
            }
        }
        ans = check;
    }
    return ans;
}

// REVERSE VOWELS OF A STRING LEETCODE 345
string reverseVowels(string v)
{
    int i = 0;
    int j = v.length() - 1;
    while (i <= j)
    {
        if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' ||
            v[i] == 'u' || v[i] == 'A' || v[i] == 'E' || v[i] == 'I' ||
            v[i] == 'O' || v[i] == 'U')
        {
            if (v[j] == 'a' || v[j] == 'e' || v[j] == 'i' || v[j] == 'o' ||
                v[j] == 'u' || v[j] == 'A' || v[j] == 'E' || v[j] == 'I' ||
                v[j] == 'O' || v[j] == 'U')
            {
                swap(v[i++], v[j--]);
            }
            else
            {
                j--;
            }
        }
        else
        {
            i++;
        }
    }
    return v;
}
// ISOMORPHIC STRINGS LEETCODE 205
bool isIsomorphic(string s, string t)
{
    s = mapping(s);
    t = mapping(t);
    if (s == t)
    {
        return true;
    }
    else
    {
        return false;
    }
}
string mapping(string str)
{
    char mapping[150] = {0};
    char start = 'a';
    for (auto ch : str)
    {
        if (mapping[ch] == 0)
        {
            mapping[ch] = start++;
        }
    }
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = mapping[str[i]];
    }
    return str;
}

bool isIsomorphic2(string s, string t)
{
    int hash[256] = {0};
    bool isCharMapped[256] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        if (hash[s[i]] == 0 && isCharMapped[t[i]] == 0)
        {
            hash[s[i]] = t[i];
            isCharMapped[t[i]] = true;
        }
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (char(hash[s[i]]) != t[i])
        {
            return false;
        }
    }
    return true;
}
// GROUP ANAGRAMS LEETCODE 49
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<string> str = strs;
    for (int i = 0; i < str.size(); i++)
    {
        sort(str[i].begin(), str[i].end());
    }
    vector<vector<string>> ans;
    for (int i = 0; i < str.size(); i++)
    {
        vector<string> v;
        string ch = str[i];
        for (int j = i; j < str.size(); j++)
        {
            if (ch == str[j] && str[j] != " ")
            {
                v.push_back(strs[j]);
                str[j] = " ";
            }
        }
        if (v.size() != 0)
        {
            ans.push_back(v);
        }
    }
    return ans;
}

vector<vector<string>> groupAnagrams1(vector<string> &strs)
{
    map<string, vector<string>> mp;
    for (auto str : strs)
    {
        string s = str;
        sort(s.begin(), s.end());
        mp[s].push_back(str);
    }
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ans.push_back(it->second);
    }
    return ans;
}
std ::array<int, 256> hash1(string s)
{
    std ::array<int, 256> hash = {0};
    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i]]++;
    }
    return hash;
}
vector<vector<string>> groupAnagrams2(vector<string> &strs)
{
    map<std::array<int, 256>, vector<string>> mp;
    for (auto s : strs)
    {
        mp[hash1(s)].push_back(s);
    }
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ans.push_back(it->second);
    }
    return ans;
}
// LONGEST PALINDROMIC SUBSTRING LEETCODE 5
string longestPalindrome(string s)
{
    string ans;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        string odd = expand(s, i, i);
        string even = expand(s, i, i + 1);
        int oddL = odd.length();
        int evenL = even.length();
        if (count < oddL || count < evenL)
        {
            if (odd.length() > even.length())
            {
                ans = odd;
                count = oddL;
            }
            else
            {
                ans = even;
                count = evenL;
            }
        }
    }
    return ans;
}
string expand(string s, int i, int j)
{
    string ans;
    while (i >= 0 && j < s.length() && checkPalindrome(s, i, j))
    {
        i--;
        j++;
    }
    for (int k = i + 1; k < j; k++)
    {
        ans.push_back(s[k]);
    }
    return ans;
}
bool checkPalindrome(string &s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] == s[j])
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
string longestPalindrome1(string s)
{
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            if (checkPalindrome(s, i, j))
            {
                string t = s.substr(i, j - i + 1);
                ans = t.size() > ans.size() ? t : ans;
            }
        }
    }
    return ans;
}

// STRING TO INTEGER LEETCODE 8
int myAtoi1(string s)
{
    int integer = atoi(s.c_str());
    return integer;
}
int myAtoi(string s)
{
    int i = 0, num = 0, sign = 1; // positive
    while (s[i] == ' ')
    {
        i++;
    }
    if (i < s.length() && (s[i] == '+' || s[i] == '-'))
    {
        sign = s[i] == '+' ? 1 : -1;
        ++i;
    }
    while (i < s.length() && isdigit(s[i]))
    {
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7'))
        {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        else
        {
            num = num * 10 + (s[i] - '0');
            ++i;
        }
    }

    return num * sign;
}
// STRING COMPRESSION LEETCODE 443
int compress(vector<char> &chars)
{
    char ch = chars[0];
    int i = 0;
    int count = 0;
    int j = 0;
    char ch1[2000] = {0};
    while (i < chars.size())
    {
        if (chars[i] == ch)
        {
            count++;
            i++;
        }
        else
        {
            ch1[j++] = ch;
            if (count > 1)
            {
                if (count < 10)
                {
                    ch1[j++] = char(count + '0');
                }
                else
                {
                    int num = 0;
                    int digit = 0;
                    while (count > 0)
                    {
                        int remainder = count % 10;
                        num = num * 10 + remainder;
                        count = count / 10;
                        digit++;
                    }
                    while (digit--)
                    {
                        int value = num % 10;
                        ch1[j++] = char(value + '0');
                        num /= 10;
                    }
                }
            }
            ch = chars[i];
            count = 0;
        }
    }
    ch1[j++] = ch;
    if (count > 1)
    {
        if (count < 10)
        {
            ch1[j++] = char(count + '0');
        }
        else
        {
            int num = 0;
            int digit = 0;
            while (count > 0)
            {
                int remainder = count % 10;
                num = num * 10 + remainder;
                count = count / 10;
                digit++;
            }
            while (digit--)
            {
                int value = num % 10;
                ch1[j++] = char(value + '0');
                num /= 10;
            }
        }
    }
    int length = 0;
    int k = 0;
    while (ch1[k++] != 0)
    {
        length++;
    }
    for (int i = 0; i < length; i++)
    {
        chars[i] = ch1[i];
    }
    return length;
}

int compress1(vector<char> &chars)
{
    char ch = chars[0];
    int i = 0;
    int count = 0;
    int j = 0;
    while (i < chars.size())
    {
        if (chars[i] == ch)
        {
            count++;
            i++;
        }
        else
        {
            pushdata(chars, j, count, ch, i);
        }
    }
    pushdata(chars, j, count, ch, i);
    return j;
}
void pushdata(vector<char> &chars, int &j, int &count, char &ch, int &i)
{
    chars[j++] = ch;
    if (count > 1)
    {
        if (count < 10)
        {
            chars[j++] = char(count + '0');
        }
        else
        {
            int num = 0;
            int digit = 0;
            while (count > 0)
            {
                int remainder = count % 10;
                num = num * 10 + remainder;
                count = count / 10;
                digit++;
            }
            while (digit--)
            {
                int value = num % 10;
                chars[j++] = char(value + '0');
                num /= 10;
            }
        }
    }
    if (i < chars.size())
    {
        ch = chars[i];
    }
    count = 0;
}

int compress2(vector<char> &chars)
{
    int index = 0;
    int count = 1;
    char previous = chars[0];
    for (int i = 1; i < chars.size(); i++)
    {
        if (chars[i] == previous)
        {
            count++;
        }
        else
        {
            chars[index++] = previous;
            if (count > 1)
            {
                int start = index;
                while (count)
                {
                    chars[index++] = (count % 10) + '0';
                    count /= 10;
                }
                reverse(chars.begin() + start, chars.begin() + index);
            }
            previous = chars[i];
            count = 1;
        }
    }
    chars[index++] = previous;
    if (count > 1)
    {
        int start = index;
        while (count)
        {
            chars[index++] = (count % 10) + '0';
            count /= 10;
        }
        reverse(chars.begin() + start, chars.begin() + index);
    }
    return index;
}

// INTEGER TO ROMAN LEETCODE 12
string intToRoman(int num)
{
    string s = "";
    int count = 0;
    while (num)
    {
        cout << num << " " << s << endl;
        if (num >= 1000)
        {
            count = num / 1000;
            while (count--)
            {
                s.push_back('M');
                num -= 1000;
            }
        }
        else if (num >= 500)
        {
            if (num >= 900)
            {
                s.push_back('C');
                s.push_back('M');
                num -= 900;
            }
            else
            {
                s.push_back('D');
                num -= 500;
            }
        }
        else if (num >= 100)
        {
            count = num / 100;
            if (count == 4)
            {
                s.push_back('C');
                s.push_back('D');
                num -= 400;
            }
            else
            {
                while (count--)
                {
                    s.push_back('C');
                    num -= 100;
                }
            }
        }
        else if (num >= 50)
        {
            if (num >= 90)
            {
                s.push_back('X');
                s.push_back('C');
                num -= 90;
            }
            else
            {
                s.push_back('L');
                num -= 50;
            }
        }
        else if (num >= 10)
        {
            count = num / 10;
            if (count == 4)
            {
                s.push_back('X');
                s.push_back('L');
                num -= 40;
            }
            else
            {
                while (count--)
                {
                    s.push_back('X');
                    num -= 10;
                }
            }
        }
        else if (num >= 5)
        {
            if (num >= 9)
            {
                s.push_back('I');
                s.push_back('X');
                num -= 9;
            }
            else
            {
                s.push_back('V');
                num -= 5;
            }
        }
        else if (num >= 1)
        {
            count = num;
            if (count == 4)
            {
                s.push_back('I');
                s.push_back('V');
                num -= 4;
            }
            else
            {
                while (count--)
                {
                    s.push_back('I');
                    num -= 1;
                }
            }
        }
    }
    return s;
}
string intToRoman1(int num)
{
    string ans = "";
    string romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L",
                             "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    for (int i = 0; i < 13; i++)
    {
        while (num >= values[i])
        {
            ans += romanSymbols[i];
            num -= values[i];
        }
    }
    return ans;
}

// ZIGZAG CONVERSION LEETCODE 6
string convert(string s, int rows)
{
    int cols = 0;
    int check1 = s.length();
    while (check1 > 0)
    {
        cols += 2;
        check1 -= 2 * (rows - 1);
    }
    cout << cols << endl;
    vector<vector<char>> v(rows, vector<char>(cols, '0'));
    int i = 0;
    int j = 0;
    int count = s.length();
    int index = 0;
    int check = 1;
    while (count--)
    {
        cout << count << endl;
        v[i][j] = s[index++];
        i = check == 1 ? i + 1 : i - 1;
        j = check == 1 ? j : j + 1;
        if (i == rows)
        {
            i -= 2;
            j++;
            check = -1;
        }
        if (i == 0)
        {
            check = 1;
        }
    }
    string ans = "";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (v[i][j] != '0')
            {
                ans.push_back(v[i][j]);
                cout << ans << endl;
            }
        }
    }
    return ans;
}
string convert1(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }
    vector<string> zigzag(numRows);
    int i = 0, row = 0;
    bool direction = 1;
    while (true)
    {
        if (direction)
        {
            while (i < s.length() && row < numRows)
            {
                zigzag[row++].push_back(s[i++]);
            }
            row = numRows - 2;
        }
        else
        {
            while (i < s.length() && row >= 0)
            {
                zigzag[row--].push_back(s[i++]);
            }
            row = 1;
        }

        if (i >= s.length())
        {
            break;
        }
        direction = !direction;
    }
    string ans = "";
    for (int i = 0; i < numRows; i++)
    {
        ans += zigzag[i];
    }
    return ans;
}
// LARGEST NUMBER LEETCODE 179
static bool myComp(string s1, string s2)
{
    string t1 = s1 + s2;
    string t2 = s2 + s1;
    return t1 > t2;
}
string largestNumber(vector<int> &nums)
{
    vector<string> snums;
    for (auto n : nums)
    {
        snums.push_back(to_string(n));
    }

    sort(snums.begin(), snums.end(), myComp);
    if (snums[0] == "0")
        return "0";
    string ans = "";
    for (auto str : snums)
    {
        ans += str;
    }
    return ans;
}

// REORGANIZE STRING LEETCODE 767
string reorganizeString(string s)
{
    int hash[26] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;
    }

    char max_character;
    int max_char_frequency = INT_MIN;
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > max_char_frequency)
        {
            max_char_frequency = hash[i];
            max_character = i + 'a';
        }
    }

    int index = 0;
    while (max_char_frequency--)
    {
        if (index >= s.size())
        {
            return "";
        }
        s[index] = max_character;
        index += 2;
    }

    hash[max_character - 'a'] = 0;

    for (int i = 0; i < 26; i++)
    {

        while (hash[i] > 0)
        {
            index = index >= s.size() ? 1 : index;
            s[index] = i + 'a';
            hash[i]--;
            index += 2;
        }
    }

    return s;
}
// FIRST OCCURRENCE IN A STRING LEETCODE 28
int strStr(string haystack, string needle)
{
    int index = haystack.find(needle);
    if (index != string::npos)
    {
        return index;
    }
    else
    {
        return -1;
    }
}
int strStr1(string haystack, string needle)
{
    int n = haystack.length();
    int m = needle.length();
    for (int i = 0; i <= n - m; i++)
    {
        if (haystack[i] == needle[0])
        {
            int j = 1;
            bool flag = 1;
            while (j < needle.length())
            {
                if (needle[j] == haystack[j + i])
                {
                    j++;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                return i;
            }
        }
    }
    return -1;
}
// REMOVE ALL ADJACENT DUPLICATES IN STRING II LEETCODE 1209

string removeDuplicates(string s, int k)
{
    int i = 0;
    int count = 10;
    while (count--)
    {
        bool flag = 1;
        char ch = s[i];
        for (int j = 1; j < k; j++)
        {
            if (ch != s[j + i])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            cout << i << endl;
            s.erase(s.begin() + i, s.begin() + k);
            i = 0;
        }
        else
        {
            i++;
        }
        cout << s << endl;
    }
    return s;
}
bool duplicatesExist10(string &ans, int &k, char &ch)
{
    int it = ans.size() - 1;
    for (int i = 0; i < k - 1; i++)
    {
        if (ans[it] != ch)
        {
            return false;
        }
        it--;
    }
    return true;
}
string removeDuplicates2(string s, int k)
{
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (ans.size() < k - 1)
        {
            ans.push_back(s[i]);
        }
        else
        {
            if (duplicatesExist10(ans, k, s[i]))
            {
                for (int j = 0; j < k - 1; j++)
                {
                    ans.pop_back();
                }
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
    }
    return ans;
}
string removeDuplicates3(string s, int k)
{
    int i = 0, j = 0;
    vector<int> count(s.size());
    while (j < s.length())
    {
        s[i] = s[j];
        count[i] = 1;
        if (i > 0 && s[i - 1] == s[i])
        {
            count[i] += count[i - 1];
        }
        if (count[i] == k)
        {
            i -= k;
        }
        i++;
        j++;
    }
    return s.substr(0, i);
}

// MINIMUM TIME DIFFERENCE LEETCODE 539
int convertToMin(string &time)
{
    int hour = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hour * 60 + minutes;
}
int findMinDifference(vector<string> &timePoints)
{
    vector<int> absMin;
    for (auto time : timePoints)
    {
        absMin.push_back(convertToMin(time));
    }
    sort(absMin.begin(), absMin.end());
    int ans = INT_MAX;
    for (int i = 0; i < absMin.size() - 1; i++)
    {
        ans = min(ans, absMin[i + 1] - absMin[i]);
    }
    int lastDiff = 1440 + absMin[0] - absMin[absMin.size() - 1];
    return min(ans, lastDiff);
}
// NUMBER OF LASER BEAMS IN A BANK LEETCODE 2125
int numberOfBeams(vector<string> &bank)
{
    int size = bank.size();
    vector<int> laserExist(size, 0);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < bank[i].size(); j++)
        {
            if (bank[i][j] == '1')
            {
                {
                    laserExist[i]++;
                }
            }
        }
    }
    int i = 0, j = 0;
    int count = 0;
    while (i < size && j < size)
    {
        while (i < size)
        {
            if (laserExist[i] == 0)
            {
                i++;
            }
            else
            {
                break;
            }
        }
        j = i + 1;
        while (j < size)
        {
            if (laserExist[j] == 0)
            {
                j++;
            }
            else
            {
                break;
            }
        }
        if (i < size && j < size)
        {
            count += laserExist[i] * laserExist[j];
        }
        else
        {
            break;
        }
        i = j;
    }
    return count;
}
int main()
{
    // vector<vector<char>> v(5, vector<char>(5, 5));
    cout << convert("PAYPALISHIRING", 3);
    return 0;
}