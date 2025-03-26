#include <iostream>
using namespace std;

bool checkSorted(int arr[], int size, int index)
{
    if (index >= size)
    {
        return true;
    }
    if (arr[index] < arr[index - 1])
    {
        return false;
    }
    checkSorted(arr, size, index + 1);
}

int binarySearch(int arr[], int target, int start, int end)
{
    if (start > end)
    {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (target > arr[mid])
    {
        return binarySearch(arr, target, mid + 1, end);
    }
    else
    {
        return binarySearch(arr, target, start, mid - 1);
    }
}

void subsequences(string str, string output, int index)
{
    if (index >= str.length())
    {
        cout << "String :  " << output << endl;
        return;
    }

    char ch = str[index];

    // exclude
    subsequences(str, output, index + 1);

    // include
    output.push_back(ch);
    subsequences(str, output, index + 1);
}

// GFG CUT INTO SEGMENTS

int maximizeTheCuts(int n, int x, int y, int z)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }

    int option1 = 1 + maximizeTheCuts(n - x, x, y, z);
    int option2 = 1 + maximizeTheCuts(n - y, x, y, z);
    int option3 = 1 + maximizeTheCuts(n - z, x, y, z);

    return max(option1, max(option2, option3));
}

// LEETCODE 322 (COIN EXCHANGE)

int solve(vector<int> &coins, int amount)
{
    if (amount == 0)
    {
        return 0;
    }
    int ans = INT_MAX;
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int coin = coins[i];
        if (coin <= amount)
        {
            int rec = solve(coins, amount - coin);
            if (rec != INT_MAX)
            {
                ans = 1 + rec;
            }
        }
        mini = min(ans, mini);
    }
    return mini;
}
int coinChange(vector<int> &coins, int amount)
{
    int ans = solve(coins, amount);

    if (ans == INT_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

// LEETCODE 198 (HOUSE ROBBER)

int solve1(vector<int> &nums, int index)
{
    if (index >= nums.size())
    {
        return 0;
    }
    // chori krri hei
    int option1 = nums[index] + solve1(nums, index + 2);
    // chori nahi krri hei
    int option2 = 0 + solve1(nums, index + 1);
    return max(option1, option2);
}

int rob(vector<int> &nums)
{
    return solve1(nums, 0);
}
int main()
{

    // int arr[] = {1, 2, 3, 5, 6, 7, 10};
    // int size = 7;
    // int index = 1;
    // bool sorted = checkSorted(arr, size, index);
    // if (sorted)
    // {
    //     cout << "Array is sorted" << endl;
    // }
    // else
    // {
    //     cout << "Array is not sorted" << endl;
    // }
    // cout << binarySearch(arr, 10, 0, 6);
    string s = "abc";
    string o = "";
    subsequences(s, o, 0);
    return 0;
}