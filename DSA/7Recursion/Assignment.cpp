#include <bits/stdc++.h>
using namespace std;

// LEFT TO RIGHT
void findLastOccurence(string &s, char &element, int &ans, int index)
{
    if (index >= s.length())
    {
        return;
    }
    if (s[index] == element)
    {
        ans = index;
    }
    findLastOccurence(s, element, ans, index + 1);
}
// RIGHT TO LEFT
void findLastOccurence1(string &s, char &element, int &ans, int index)
{
    if (index < 0)
    {
        return;
    }
    if (s[index] == element)
    {
        ans = index;
        return;
    }
    findLastOccurence1(s, element, ans, index - 1);
}

// REVERSE A STRING
void reverse(string &s, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    swap(s[start++], s[end--]);
    reverse(s, start, end);
}
// LEETCODE 415 (ADD STRINGS)
void solve(string &num1, string &num2, string &ans, int p1, int p2, int carry)
{
    if (p1 < 0 && p2 < 0)
    {
        if (carry == 1)
        {
            ans.push_back('1');
        }
        return;
    }
    int nums1 = 0, nums2 = 0;
    if (p1 >= 0)
    {
        nums1 = num1[p1] - '0';
    }
    if (p2 >= 0)
    {
        nums2 = num2[p2] - '0';
    }
    int sum = nums1 + nums2 + carry;
    solve(num1, num2, ans, p1 - 1, p2 - 1, sum / 10);
    char digit = (sum % 10) + '0';
    ans.push_back(digit);
}

string addStrings(string num1, string num2)
{
    string ans = "";
    solve(num1, num2, ans, num1.size() - 1, num2.size() - 1, 0);
    return ans;
}

// PALINDROME CHECK

bool checkPalindrome(string &s, int start, int end)
{
    if (start >= end)
    {
        cout << "true" << endl;
        return true;
    }
    if (s[start++] != s[end--])
    {
        cout << "false" << endl;
        return false;
    }
    checkPalindrome(s, start, end);
}
// PRINT SUBARRAY
void printUtility(vector<int> &arr, int start, int end)
{
    if (end >= arr.size())
    {
        return;
    }
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    printUtility(arr, start, end + 1);
}
void printSubArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        printUtility(arr, i, i);
    }
}
// LEETCODE 1910 (REMOVE ALL OCCURRENCES)
void solve(string &s, string &part)
{
    if (s.find(part) == string::npos)
    {
        return;
    }
    int index = s.find(part);
    string s1 = s.substr(0, index);
    string s2 = s.substr(index + part.size(), s.size());
    s = s1 + s2;
    solve(s, part);
}

string removeOccurrences(string s, string part) // TIME COMPLEXCITY :- O(N/M)//WORST CASE RECURSIVE CALL * O(NM)//FIND FUNCTION = O(N2) // SPACE COMPLEXCITY :- O(N/M)
{
    solve(s, part);
    return s;
}

// LEETCODE 121(BEST TIME TO BUY AND SELL STOCKS)
void maxProfitFinder(vector<int> &prices, int i, int &min_price, int &max_profit)
{
    if (i == prices.size())
    {
        return;
    }
    if (prices[i] < min_price)
        min_price = prices[i];
    int today_profit = prices[i] - min_price;
    max_profit = max(today_profit, max_profit);
    maxProfitFinder(prices, i + 1, min_price, max_profit);
}

int maxProfit(vector<int> &prices)
{
    int min_price = INT_MAX;
    int max_profit = INT_MIN;
    maxProfitFinder(prices, 0, min_price, max_profit);
    return max_profit;
}

// LEETCODE 273 (INTEGER TO ENGLISH WORDS)
vector<pair<int, string>> mp = {{1000000000, "Billion"},
                                {1000000, "Million"},
                                {1000, "Thousand"},
                                {100, "Hundred"},
                                {90, "Ninety"},
                                {80, "Eighty"},
                                {70, "Seventy"},
                                {60, "Sixty"},
                                {50, "Fifty"},
                                {40, "Forty"},
                                {30, "Thirty"},
                                {20, "Twenty"},
                                {19, "Nineteen"},
                                {18, "Eighteen"},
                                {17, "Seventeen"},
                                {16, "Sixteen"},
                                {15, "Fifteen"},
                                {14, "Fourteen"},
                                {13, "Thirteen"},
                                {12, "Twelve"},
                                {11, "Eleven"},
                                {10, "Ten"},
                                {9, "Nine"},
                                {8, "Eight"},
                                {7, "Seven"},
                                {6, "Six"},
                                {5, "Five"},
                                {4, "Four"},
                                {3, "Three"},
                                {2, "Two"},
                                {1, "One"}};
string numberToWords(int num)
{
    if (num == 0)
    {
        return "Zero";
    }
    for (auto it : mp)
    {
        if (num >= it.first)
        {
            string a = "";
            if (num >= 100)
            {
                a = numberToWords(num / it.first) + " ";
            }
            string b = it.second;
            string c = "";
            if (num % it.first != 0)
            {
                c = " " + numberToWords(num % it.first);
            }
            return a + b + c;
        }
    }
    return "";
}
// LEETCODE 44 (WILDCARD MATCHING)
bool solve(string &s1, string &s2, int p1, int p2)
{
    if (p1 >= s1.length() && p2 >= s2.length())
    {
        return true;
    }
    if (p1 >= s1.length() && p2 < s2.length())
    {
        while (p2 < s2.length())
        {
            if (s2[p2++] != '*')
                return false;
        }
        return true;
    }
    // single char matching
    if (s1[p1] == s2[p2] || s2[p2] == '?')
    {
        return solve(s1, s2, p1 + 1, p2 + 1);
    }

    if (s2[p2] == '*')
    {
        // treat '*' as empty or null ('')
        bool r1 = solve(s1, s2, p1, p2 + 1);
        // '*' consume 1 character
        bool r2 = solve(s1, s2, p1 + 1, p2);
        return r1 || r2;
    }

    return false;
}

bool isMatch(string s, string p)
{
    bool ans = solve(s, p, 0, 0);
    return ans;
}

// LEETOCDE 1155 (NUMBER OF DICE ROLLS WITH TARGET)
int numRollsToTarget(int n, int k, int target)
{
    if (n == 0 && target == 0)
        return 1;
    if (n == 0 && target != 0)
        return 0;
    if (n != 0 && target == 0)
        return 0;
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += numRollsToTarget(n - 1, k, target - i);
    }
    return ans;
}
// LEETCODE 279 (PERFECT SQUARE)
// int solve(int n)
// {
//     // base case
//     if (n < 0)
//     {
//         return INT_MAX;
//     }
//     if (n == 0)
//     {
//         return 0;
//     }

//     int result = INT_MAX;
//     int count = 0;
//     for (int i = 1; i <= sqrt(n); i++)
//     {
//         if (i * i <= n)
//         {
//             int res = solve(n - (i * i));
//             if (res != INT_MAX)
//             {
//                 count = 1 + res;
//             }
//         }
//         result = min(count, result);
//     }
//     return result;
// }

// int numSquares(int n)
// {
//     int ans = solve(n);
//     return ans;
// }

int solve(int n)
{
    // base case
    if (n < 0)
        return 0;

    if (n == 0)
        return 1;

    int result = INT_MAX;
    int i = 1;
    while (i <= sqrt(n))
    {
        int ans = 1 + solve(n - (i * i));
        if (ans < result)
        {
            result = ans;
        }
        i++;
    }
    return result;
}

int numSquares(int n)
{
    int ans = solve(n);
    return ans - 1;
}

//  int solve(int n, int num){
//         if(num == 0){
//             return INT_MAX;
//         }
//         if(n == 0){
//             return 0;
//         }
//         if(n < 0){
//             return INT_MAX;
//         }
//         int r1 = solve(n - (num * num), num);
//         int r2 = solve(n , num - 1);
//         int ans = r1 < r2 ? 1 + r1 : r2;
//         return ans;
//     }
//     int numSquares(int n) {
//         int num = sqrt(n);
//         return solve(n, num);
//     }

// LEETCODE 983 (MINIMUM COSTS FOR TICKETS)
int solve(vector<int> &days, vector<int> &costs, int pos)
{
    if (pos >= days.size())
        return 0;

    int option1 = costs[0] + solve(days, costs, pos + 1);

    int validity1 = days[pos] + 6;
    int validity2 = days[pos] + 29;

    while (pos < days.size() && days[pos] <= validity1)
    {
        pos++;
    }
    int option2 = costs[1] + solve(days, costs, pos);
    while (pos < days.size() && days[pos] <= validity2)
    {
        pos++;
    }
    int option3 = costs[2] + solve(days, costs, pos);

    int ans = min(option1, min(option2, option3));
    return ans;
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int ans = solve(days, costs, 0);
    return ans;
}
int main()
{
    // string s = "abcddedg";
    // char element = 'd';
    // int ans = -1;
    // // findLastOccurence(s, element, ans, 0);
    // findLastOccurence1(s, element, ans, s.size() - 1);
    // cout << ans << endl;
    // reverse(s, 0, s.size() - 1);
    // cout << s << endl;

    // string s = "RACECAR";
    // bool check = checkPalindrome(s, 0, s.size() - 1);
    // cout << bool(check) << endl;

    vector<int> arr = {1, 2, 3, 4, 5}; // TIME COMPLEXCITY :- O(N2) || SPACE COMPLEXCITY :- O(N)
    printSubArray(arr);

    return 0;
}
