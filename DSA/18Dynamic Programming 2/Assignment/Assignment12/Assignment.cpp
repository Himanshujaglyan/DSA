#include <iostream>
using namespace std;

// LEETCODE 1406 (STONE GAME 3)
int solve(vector<int> &stoneValue, int start, bool alice)
{
    if (start >= stoneValue.size())
        return 0;
    int ans = alice ? INT_MIN : INT_MAX;
    int total = 0;
    for (int i = start; i < start + 3; i++)
    {
        if (i >= stoneValue.size())
            break;
        total += stoneValue[i];
        if (alice)
        {
            ans = max(ans, total + solve(stoneValue, i + 1, !alice));
        }
        else
        {
            ans = min(ans, solve(stoneValue, i + 1, !alice));
        }
    }
    return ans;
}

string stoneGameIII(vector<int> &stoneValue)
{
    int total = 0;
    for (auto &val : stoneValue)
    {
        total += val;
    }
    int alice = solve(stoneValue, 0, true);
    int bob = total - alice;

    if (alice > bob)
        return "Alice";
    else if (bob > alice)
        return "Bob";
    else
        return "Tie";
}

// MEMOIZATION
int solve(vector<int> &stoneValue, int start, bool alice, vector<vector<int>> &dp)
{
    if (start >= stoneValue.size())
        return 0;
    if (dp[start][alice] != -1)
        return dp[start][alice];
    int ans = alice ? INT_MIN : INT_MAX;
    int total = 0;
    for (int i = start; i < start + 3; i++)
    {
        if (i >= stoneValue.size())
            break;
        total += stoneValue[i];
        if (alice)
        {
            ans = max(ans, total + solve(stoneValue, i + 1, !alice, dp));
        }
        else
        {
            ans = min(ans, solve(stoneValue, i + 1, !alice, dp));
        }
    }
    return dp[start][alice] = ans;
}

string stoneGameIII(vector<int> &stoneValue)
{
    int total = 0;
    for (auto &val : stoneValue)
    {
        total += val;
    }
    vector<vector<int>> dp(stoneValue.size() + 1, vector<int>(2, -1));

    int alice = solve(stoneValue, 0, true, dp);
    int bob = total - alice;

    if (alice > bob)
        return "Alice";
    else if (bob > alice)
        return "Bob";
    else
        return "Tie";
}

// TABULATION
string stoneGameIII(vector<int> &stoneValue)
{
    int total = 0;
    for (auto &val : stoneValue)
    {
        total += val;
    }

    vector<vector<int>> dp(stoneValue.size() + 1, vector<int>(2, 0));
    for (int start = stoneValue.size() - 1; start >= 0; start--)
    {
        for (int alice = 0; alice < 2; alice++)
        {
            int ans = alice ? INT_MIN : INT_MAX;
            int total = 0;
            for (int i = start; i < start + 3; i++)
            {
                if (i >= stoneValue.size())
                    break;
                total += stoneValue[i];
                if (alice)
                {
                    ans = max(ans, total + dp[i + 1][!alice]);
                }
                else
                {
                    ans = min(ans, dp[i + 1][!alice]);
                }
            }
            dp[start][alice] = ans;
        }
    }

    int alice = dp[0][true];
    int bob = total - alice;

    if (alice > bob)
        return "Alice";
    else if (bob > alice)
        return "Bob";
    else
        return "Tie";
}

// LAKSHAY APPROACH
// IF (ALICE - BOB > 0) RETURN ALICE
// IF (ALICE - BOB < 0) RETURN BOB
// ELSE RETURN TIE

// IN RECURSIVE RELATION WE WILL SUBTRACT BOB FROM ALICE AND REST THE RECURSIVE RELATION HANDLE ITSELF TO AGAIN ADD ALICE AND SUBTRACT BOB
int solve(vector<int> &stone, int index)
{
    if (index == stone.size())
        return 0;

    int ans = INT_MIN;
    int total = 0;
    for (int i = index; i < index + 3; i++)
    {
        if (i >= stone.size())
            break;
        total += stone[i];
        ans = max(ans, total - solve(stone, i + 1));
    }

    return ans;
}

string stoneGameIII(vector<int> &stoneValue)
{
    int ans = solve(stoneValue, 0);
    if (ans > 0)
        return "Alice";
    else if (ans < 0)
        return "Bob";
    else
        return "Tie";
}

// MEMOIZATION
int solve(vector<int> &stone, int index, vector<int> &dp)
{
    if (index == stone.size())
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int ans = INT_MIN;
    int total = 0;
    for (int i = index; i < index + 3; i++)
    {
        if (i >= stone.size())
            break;
        total += stone[i];
        ans = max(ans, total - solve(stone, i + 1, dp));
    }

    return dp[index] = ans;
}

string stoneGameIII(vector<int> &stoneValue)
{
    vector<int> dp(stoneValue.size() + 1, -1);
    int ans = solve(stoneValue, 0, dp);
    if (ans > 0)
        return "Alice";
    else if (ans < 0)
        return "Bob";
    else
        return "Tie";
}

// TABULATION
string stoneGameIII(vector<int> &stoneValue)
{
    vector<int> dp(stoneValue.size() + 1, 0);
    for (int index = stoneValue.size() - 1; index >= 0; index--)
    {
        int ans = INT_MIN;
        int total = 0;
        for (int i = index; i < index + 3; i++)
        {
            if (i >= stoneValue.size())
                break;
            total += stoneValue[i];
            ans = max(ans, total - dp[i + 1]);
        }

        dp[index] = ans;
    }
    int ans = dp[0];
    if (ans > 0)
        return "Alice";
    else if (ans < 0)
        return "Bob";
    else
        return "Tie";
}

// MORE SPACE OPTIMIZED
string stoneGameIII(vector<int> &stoneValue)
{
    int curr = 0;
    int next[3] = {0};
    for (int index = stoneValue.size() - 1; index >= 0; index--)
    {
        int ans = INT_MIN;
        int total = 0;
        for (int i = index; i < index + 3; i++)
        {
            if (i >= stoneValue.size())
                break;
            total += stoneValue[i];
            ans = max(ans, total - next[i - index]);
        }
        curr = ans;
        next[2] = next[1];
        next[1] = next[0];
        next[0] = curr;
    }
    int ans = curr;
    if (ans > 0)
        return "Alice";
    else if (ans < 0)
        return "Bob";
    else
        return "Tie";
}

// THERE ARE TWO APPROACHES FOR THE STONE PROBLEM
// WHERE WE PERFORM RECURSION IN THE WAY
// 1. MAX OF ALICE + MIN OF ALICE(AS BOB TAKES MAXIMUM) + ......
// 2. MAX OF ALICE - MAX OF BOB + MAX OF ALICE - MAX OF BOB + ......
int main()
{
    return 0;
}