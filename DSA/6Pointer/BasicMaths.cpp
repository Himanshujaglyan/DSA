#include <iostream>
#include <conio.h>
#include <math.h>
#include <vector>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
bool isPrimeSqrt(int n)
{
    if (n <= 1)
    {
        return false;
    }
    int sqrtN = sqrt(n);
    for (int i = 2; i <= sqrtN; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int countPrime(int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(i))
        {
            count++;
        }
    }
    return count;
}
int countPrimeSeiveTheorem(int n)
{
    if (n == 0)
    {
        return 0;
    }
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;
            for (int j = 2 * i; j < n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    return count;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a == 0 ? b : a;
}
int slowExponential(int a, int b)
{
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans *= a;
    }
    return ans;
}
int fastExponential(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans *= a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}
// MODULAR EXPONENTIAL FOR LARGE NUMBERS GFG
long long int PowMod(long long int x, long long int n, long long int M)
{
    // Code here
    long long int ans = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            ans = (ans * x) % M;
        }
        x = (x * x) % M;
        n >>= 1;
    }
    return ans;
}
int main()
{
    cout << countPrimeSeiveTheorem(5) << endl;
    // int a = 24;
    // int b = 86;
    // cout << gcd(24, 86) << endl;
    // cout << slowExponential(2, 10) << endl;
    // cout << fastExponential(2, 10) << endl;
}