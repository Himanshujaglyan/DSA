#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// THOSE WHO DO NOT REMEMBER THE PAST ARE CONDEMN TO REPEAT IT

// SIMPLE PLAIN RECURSION
int solve(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    int ans = solve(n - 1) + solve(n - 2);
    return ans;
}

int fib(int n)
{
    return solve(n);
}

// DP

/* TOP-DOWN APPROACH (RECURSION + MEMOIZATION) */
/*
Step 1 :- Create DP Array
Step 2 :- store and return answer in DP Array
Step 3 :- if answer already exist in DP Array then return it
*/
int solveUsingMemoization(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = solveUsingMemoization(n - 1, dp) + solveUsingMemoization(n - 2, dp);
    return dp[n];
}

int fib(int n)
{
    vector<int> dp(n + 1, -1);
    return solveUsingMemoization(n, dp);
}

/* BOTTOM-UP APPROACH (TABULATION METHOD) */
/*
Step 1 :- Create DP Array
Step 2 :- analyze base case and fill DP Array to maintain a initial state
Step 3 :- fill remaining DP array using formula/ logic of recursive relation
*/

int solveUsingTabulation(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    if (n == 0)
        return dp[0];
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fib(int n)
{
    return solveUsingTabulation(n);
}

// SPACE OPTIMIZATION :- CHECK ON WHAT VALUES OUR RECURSIVE RELATION DEPENDS
int solveUsingTabulationSpaceOptimized(int n)
{
    int prev = 0;
    if (n == 0)
        return 0;
    int curr = 1;
    if (n == 1)
        return 1;
    int ans;
    for (int i = 2; i <= n; i++)
    {
        ans = curr + prev;
        prev = curr;
        curr = ans;
    }
    return ans;
}

int fib(int n)
{
    return solveUsingTabulationSpaceOptimized(n);
}

// GFG (MAXIMISE THE CUT SEGMENTS)
int solveUsingRec(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int option1 = 1 + solveUsingRec(n - x, x, y, z, dp);
    int option2 = 1 + solveUsingRec(n - y, x, y, z, dp);
    int option3 = 1 + solveUsingRec(n - z, x, y, z, dp);

    dp[n] = max(option1, max(option2, option3));
    return dp[n];
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    int ans = solveUsingRec(n, x, y, z, dp);
    return ans > 0 ? ans : 0;
}

int main()
{

    return 0;
}