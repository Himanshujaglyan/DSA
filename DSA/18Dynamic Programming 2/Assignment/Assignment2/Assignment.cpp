#include <iostream>
#include <vector>
using namespace std;

// LEETCODE 983 (MINIMUM COST FOR TICKETS)
// TIME COMPLEXCITY :- O(3 POWER N) (CHECK IMAGE-1)
// SPACE COMPLEXCITY :- O(N)
int solve(vector<int> &days, vector<int> &costs, int index)
{
    if (index >= days.size())
        return 0;
    int currPos = days[index];

    // 1 day pass
    int newPos = currPos + 1 - 1;
    int cost1 = costs[0] + solve(days, costs, index + 1);

    // 7 day pass
    newPos = currPos + 7 - 1;
    while (index < days.size() && days[index] <= newPos)
    {
        index++;
    }
    int cost7 = costs[1] + solve(days, costs, index);

    // 30 day pass
    newPos = currPos + 30 - 1;
    while (index < days.size() && days[index] <= newPos)
    {
        index++;
    }
    int cost30 = costs[2] + solve(days, costs, index);

    int ans = min(cost1, min(cost7, cost30));
    return ans;
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int index = 0;
    return solve(days, costs, index);
}

// MEMOIZATION
// TIME COMPLEXCITY :- O(N POWER 2) (CHECK IMAGE-2)
// SPACE COMPLEXCITY :- O(N);
int solve(vector<int> &days, vector<int> &costs, int index, vector<int> &dp)
{
    if (index >= days.size())
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int currPos = days[index];
    int newIndex = index;

    // 1 day pass
    int newPos = currPos + 1 - 1;
    int cost1 = costs[0] + solve(days, costs, newIndex + 1, dp);

    // 7 day pass
    newPos = currPos + 7 - 1;
    while (newIndex < days.size() && days[newIndex] <= newPos)
    {
        newIndex++;
    }
    int cost7 = costs[1] + solve(days, costs, newIndex, dp);

    // 30 day pass
    newPos = currPos + 30 - 1;
    while (newIndex < days.size() && days[newIndex] <= newPos)
    {
        newIndex++;
    }
    int cost30 = costs[2] + solve(days, costs, newIndex, dp);

    dp[index] = min(cost1, min(cost7, cost30));
    return dp[index];
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int index = 0;
    vector<int> dp(days.size() + 1, -1);
    return solve(days, costs, index, dp);
}

// TABULATION
int solve(vector<int> &days, vector<int> &costs, int index, vector<int> &dp)
{
    for (int i = days.size() - 1; i >= 0; i--)
    {
        int currPos = days[i];
        int newIndex = i;

        // 1 day pass
        int newPos = currPos + 1 - 1;
        int cost1 = costs[0] + dp[newIndex + 1];

        // 7 day pass
        newPos = currPos + 7 - 1;
        while (newIndex < days.size() && days[newIndex] <= newPos)
        {
            newIndex++;
        }
        int cost7 = costs[1] + dp[newIndex];

        // 30 day pass
        newPos = currPos + 30 - 1;
        while (newIndex < days.size() && days[newIndex] <= newPos)
        {
            newIndex++;
        }
        int cost30 = costs[2] + dp[newIndex];

        dp[i] = min(cost1, min(cost7, cost30));
    }
    return dp[0];
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    vector<int> dp(days.size() + 1, 0);
    return solve(days, costs, 0, dp);
}
int main()
{
    return 0;
}