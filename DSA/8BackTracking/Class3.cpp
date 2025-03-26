#include <bits/stdc++.h>
using namespace std;

// LEETCODE 213 (HOUSE ROBBER 2)

// int solve(vector<int> &nums, int index)
// {
//     if (nums.size() == 1)
//     {
//         return nums[0];
//     }
//     if (index >= nums.size())
//     {
//         return 0;
//     }
//     int option1 = 0 + solve(nums, index + 1);
//     if (index == 0)
//     {
//         nums[nums.size() - 1] = 0;
//     }
//     int option2 = nums[index] + solve(nums, index + 2);
//     return max(option1, option2);
// }

// int rob(vector<int> &nums)
// {
//     int ans = solve(nums, 0);
//     return ans;
// }

int solve(vector<int> &nums, int index, int size)
{
    if (index >= size)
    {
        return 0;
    }
    int option1 = 0 + solve(nums, index + 1, size);
    int option2 = nums[index] + solve(nums, index + 2, size);
    return max(option1, option2);
}

int rob(vector<int> &nums)
{
    int option1 = nums[0] + solve(nums, 2, nums.size() - 1);
    int option2 = solve(nums, 1, nums.size());
    return max(option1, option2);
}

// COUNT DEARRANGEMENTS (GFG)

int solve(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    return ((n - 1) * (solve(n - 1) + solve(n - 2)));
}

// PAINTING FENCE ALGORITHM (GFG)
long long countWays(int n, int k)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k + k * (k - 1);
    }

    return (k - 1) * (countWays(n - 1, k) + countWays(n - 2, k));
}

// LEETCODE 72 (EDIT DISTANCE)
int solve(string &word1, int ptr1, string &word2, int ptr2)
{
    // base case
    if (ptr1 >= word1.length())
    {
        return word2.length() - ptr2;
    }
    if (ptr2 >= word2.length())
    {
        return word1.length() - ptr1;
    }
    int ans = 0;
    if (word1[ptr1] == word2[ptr2])
    {
        ans = 0 + solve(word1, ptr1 + 1, word2, ptr2 + 1);
    }
    else
    {
        // insert
        int option1 = 1 + solve(word1, ptr1, word2, ptr2 + 1);
        // delete
        int option2 = 1 + solve(word1, ptr1 + 1, word2, ptr2);
        // replace
        int option3 = 1 + solve(word1, ptr1 + 1, word2, ptr2 + 1);
        ans = min(option1, min(option2, option3));
    }
    return ans;
}

int minDistance(string word1, string word2)
{
    int i = 0;
    int j = 0;
    int ans = solve(word1, i, word2, j);
    return ans;
}

// LEETCODE 221 (MAXIMAL SQUARE)
int solve(vector<vector<char>> &matrix, int &row, int &col, int x, int y,
          int &maximum)
{
    if (x >= row || y >= col)
    {
        return 0;
    }
    int right = solve(matrix, row, col, x, y + 1, maximum);
    int diagonal = solve(matrix, row, col, x + 1, y + 1, maximum);
    int down = solve(matrix, row, col, x + 1, y, maximum);

    if (matrix[x][y] == '1')
    {
        int ans = 1 + min(right, min(diagonal, down));
        maximum = max(ans, maximum);
        return ans;
    }
    else
    {
        maximum = max(0, maximum);
        return 0;
    }
}

int maximalSquare(vector<vector<char>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int x = 0;
    int y = 0;
    int maximum = INT_MIN;
    int ans = solve(matrix, row, col, x, y, maximum);
    return maximum * maximum;
}
int main()
{
    cout << solve((4)) << endl;
    return 0;
}