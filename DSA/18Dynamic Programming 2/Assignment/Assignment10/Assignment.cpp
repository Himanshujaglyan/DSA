#include <iostream>
using namespace std;

// LEETCODE 877 (STONE GAME)
bool solve(vector<int> &piles, int start, int end, int alice, int bob)
{
    if (start >= end)
    {
        if (alice > bob)
            return true;
        else
            return false;
    }
    // alice takes from start
    // bob takes from start
    int newAlice = alice + piles[start];
    int newBob = bob + piles[start + 1];
    bool case1 = solve(piles, start + 2, end, newAlice, newBob);

    // alice takes from start
    // bob takes from end
    newAlice = alice + piles[start];
    newBob = bob + piles[end];
    bool case2 = solve(piles, start + 1, end - 1, newAlice, newBob);

    // alice takes from end
    // bob takes from start
    newAlice = alice + piles[end];
    newBob = bob + piles[start];
    bool case3 = solve(piles, start + 1, end - 1, newAlice, newBob);

    // alice takes from end
    // bob takes from end
    newAlice = alice + piles[end];
    newBob = bob + piles[end - 1];
    bool case4 = solve(piles, start, end - 2, newAlice, newBob);

    return case1 || case2 || case3 || case4;
}

bool stoneGame(vector<int> &piles)
{
    return solve(piles, 0, piles.size() - 1, 0, 0);
}

// LAKSHAY CODE
bool stoneGame(vector<int> &piles)
{
    // Since the sum of total no. of stones is odd
    // There will be atleast one way by which Alice will always win
    // So we should return true, bcz problem is asking for is there any way alice can win the GAME
    return true;
}
int main()
{
    return 0;
}