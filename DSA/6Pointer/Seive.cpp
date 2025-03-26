#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<bool> Sieve(int n)
{
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= n; i++) // outer loop optimization
    {
        if (sieve[i])
        {
            int j = i * i; // inner loop optimization
            for (; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    return sieve;
}
vector<bool> segmentedSeive(int L, int R)
{
    vector<bool> sieve = Sieve(sqrt(R));
    vector<int> basePrimes;
    for (int i = 0; i < sieve.size(); i++)
    {
        if (sieve[i])
        {
            basePrimes.push_back(i);
        }
    }
    vector<bool> segSeive(R - L + 1, true);
    if (L == 0)
    {
        segSeive[0] = segSeive[1] = false;
    }
    if (L == 1)
    {
        segSeive[0] = false;
    }
    for (auto prime : basePrimes)
    {
        int firstMultiple = (L / prime) * prime;
        if (firstMultiple < L)
        {
            firstMultiple += prime;
        }
        int j = max(firstMultiple, prime * prime);
        while (j <= R)
        {
            segSeive[j - L] = false;
            j += prime;
        }
    }
    return segSeive;
}
int main()
{
    // vector<bool> sieve = Sieve(25);
    // for (int i = 0; i < sieve.size(); i++)
    // {
    //     if (sieve[i])
    //     {
    //         cout << i << "\t";
    //     }
    // }
    // cout << endl;
    int left = 10;
    vector<bool> segSeive = segmentedSeive(10, 19);
    for (int i = 0; i < segSeive.size(); i++)
    {
        if (segSeive[i])
        {
            cout << i + left << "\t";
        }
    }
    return 0;
}