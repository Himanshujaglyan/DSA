#include <iostream>
using namespace std;

void checkEvenOdd(int n)
{
    if (n & 1)
    {
        cout << "Odd" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
}

void getIthBit(int n, int i)
{
    int mask = (1 << i);
    if (n & mask)
    {
        cout << "One" << endl;
    }
    else
    {
        cout << "Zero" << endl;
    }
}

void setIthBit(int n, int i)
{
    int mask = (1 << i);
    int ans = n | mask;
    cout << ans << endl;
}

void clearIthBit(int n, int i)
{
    int mask = ~(1 << i);
    int ans = n & mask;
    cout << ans << endl;
}

void updateIthBit(int n, int i, int target)
{
    int mask = ~(1 << i);
    int ans = n & mask;
    mask = (target << i);
    ans = ans | mask;
    cout << ans << endl;
}

// LEETCODE 136 (SINGLE NUMBER)
int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int &num : nums)
    {
        ans ^= num;
    }
    return ans;
}

void clearLastIBits(int n, int i)
{
    int mask = (-1 << i);
    int ans = n & mask;
    cout << ans << endl;
}

void checkPowerOf2(int n)
{
    if ((n & (n - 1)) == 0)
        cout << "Power of 2" << endl;
    else
        cout << "Not a power of 2" << endl;
}

void countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n &= (n - 1);
    }
    cout << count << endl;
}

void exponentail(int n, int power)
{
    int ans = 1;
    while (power)
    {
        if (power & 1)
            ans *= n;
        n *= n;
        power >>= 1;
    }
    cout << ans << endl;
}

void clearBitsInRange(int n, int i, int j)
{
    int a = (-1 << (i + 1));
    int b = ~(-1 << j);
    int mask = a | b;
    int ans = n & mask;
    cout << ans << endl;
}

// WE ARE CLIMBING THE STAIRS FROM BOTTOM TO THE TOP AND EACH TIME WE CAN JUMP ONLY STEPS IN POWER OF 2 SO WE NEED TO RETURN MINIMUM NUMBER OF JUMPS NEEDED TO CLIMB TO THE TOP
// SO WE WILL COUNT THE NUMBER OF SET BITS OF THE NUMBER OF STAIRCASE AND THAT WILL BE THE NUMBER OF JUMPS NEEDED

void getSubsequence(string str)
{
    int n = str.length();
    vector<string> ans;
    for (int i = 0; i < (1 << n); i++)
    {
        string temp = "";
        int num = i;
        int index = 0;
        while (num)
        {
            if (num & 1)
            {
                temp.push_back(str[index]);
            }
            num >>= 1;
            index++;
        }
        ans.push_back(temp);
    }
    for (auto s : ans)
    {
        cout << s << endl;
    }
}

int main()
{
    int n = 35;
    int i = 2;
    int target = 1;
    // checkEvenOdd(n);
    // getIthBit(n, i);
    // setIthBit(n, i);
    // clearIthBit(n, i);
    // updateIthBit(n, i, target);
    // clearLastIBits(n, i);
    // checkPowerOf2(n);
    // countSetBits(n);
    // exponentail(2, 5);
    // clearBitsInRange(1023, 8, 1);
    getSubsequence("abc");
    return 0;
}