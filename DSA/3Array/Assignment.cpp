#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits.h>
#include <set>
using namespace std;

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// KEY PAIR OR TWO SUM
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}
// KEY PAIR OR TWO SUM
bool twoSumUsingTwoPointer(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int low = 0;
    int high = nums.size() - 1;
    while (low < high)
    {
        int sum = nums[low] + nums[high];
        if (sum == target)
        {
            return true;
        }
        else if (sum > target)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
    return false;
}

// PIVOT INDEX
int pivotIndex(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int leftSum = 0;
        int rightSum = 0;
        // leftSum
        for (int j = 0; j < i; j++)
        {
            leftSum += nums[j];
        }
        // rightSum
        for (int j = i + 1; j < nums.size(); j++)
        {
            rightSum += nums[j];
        }
        if (leftSum == rightSum)
        {
            return i;
        }
    }
    return -1;
}

// PIVOT INDEX
int pivotIndexUsingPrefixSum(vector<int> &nums)
{
    vector<int> lsum(nums.size(), 0);
    vector<int> Rsum(nums.size(), 0);
    // Left Sum
    for (int i = 1; i < nums.size(); i++)
    {
        lsum[i] = lsum[i - 1] + nums[i - 1];
    }
    // Right Sum
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        Rsum[i] = Rsum[i + 1] + nums[i + 1];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (lsum[i] == Rsum[i])
        {
            return i;
        }
    }
    return -1;
}

// REMOVE DUPLICATES
int findDuplicate(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                return nums[i];
            }
        }
    }
    return -1;
}

int findDuplicate2(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return nums[i];
        }
    }
    return -1;
}

int findDuplicate3(vector<int> &nums) // VISITED METHOD
{
    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]);
        if (nums[index] < 0)
        {
            return index;
        }
        else
        {
            nums[index] *= -1;
        }
    }
    return -1;
}

int findDuplicate4(vector<int> &nums) // POSITIONING METHOD
{
    while (nums[0] != nums[nums[0]])
    {
        swap(nums[0], nums[nums[0]]);
    }
    return nums[0];
}

void missingElement(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        int index = abs(a[i]);
        if (a[index - 1] > 0)
        {
            a[index - 1] *= -1;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (a[i] > 0)
        {
            cout << i + 1 << " ";
        }
    }
}

void missingElement2(int *a, int size)
{
    int i = 0;
    while (i < size)
    {
        if (a[i] != a[a[i] - 1])
        {
            swap(a[i], a[a[i] - 1]);
        }
        else
        {
            i++;
        }
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        if (a[i] != (i + 1))
        {
            cout << i + 1 << " ";
        }
    }
}

// FIRST REPEATED ELEMENT
int firstRepeated(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return i + 1;
            }
        }
    }
    return -1;
}
int firstRepeated2(int arr[], int n)
{
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << hash[arr[i]] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] > 1)
        {
            return i + 1;
        }
    }
    return -1;
}

// int firstRepeated3(int arr[], int n)
// {
//     int max1 = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         max1 = max(arr[i], max1);
//     }
//     max1++;
//     int brr[max1] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         brr[arr[i]]++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (brr[arr[i]] > 1)
//         {
//             return i + 1;
//         }
//     }
//     return -1;
// }

// COMMON ELEMENT IN THREE SORTED ARRAY
vector<int> commonElements(vector<int> A, vector<int> B, vector<int> C, int n1, int n2, int n3)
{
    set<int> st;
    vector<int> ans;
    int i, j, k;
    i = j = k = 0;
    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            st.insert(A[i]);
            i++;
            j++;
            k++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else if (B[j] < C[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    for (auto i : st)
    {
        ans.push_back(i);
    }

    return ans;
}

void wavePrint(int arr[][4], int rows, int cols = 4)
{
    for (int i = 0; i < cols; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < rows; j++)
            {
                cout << arr[j][i] << " ";
            }
        }
        else
        {
            for (int j = rows - 1; j >= 0; j--)
            {
                cout << arr[j][i] << " ";
            }
        }
    }
}

vector<int> spiralPrint(vector<vector<int>> &v)
{
    vector<int> ans;
    int rows = v.size();
    int cols = v[0].size();
    int startRow = 0;
    int endCol = cols - 1;
    int endRow = rows - 1;
    int startCol = 0;
    int totalElements = rows * cols;
    int count = 0;
    while (count < totalElements)
    {
        // starting Row
        for (int i = startCol; i <= endCol && count < totalElements; i++)
        {
            ans.push_back(v[startRow][i]);
            count++;
        }
        startRow++;
        // ending Col
        for (int i = startRow; i <= endRow && count < totalElements; i++)
        {
            ans.push_back(v[i][endCol]);
            count++;
        }
        endCol--;
        // ending Row
        for (int i = endCol; i >= startCol && count < totalElements; i--)
        {
            ans.push_back(v[endRow][i]);
            count++;
        }
        endRow--;
        // starting Col
        for (int i = endRow; i >= startRow && count < totalElements; i--)
        {
            ans.push_back(v[i][startCol]);
            count++;
        }
        startCol++;
    }
    return ans;
}

string calc_Sum(int *a, int n, int *b, int m)
{
    // Complete the function
    int i = n - 1;
    int j = m - 1;
    int carry = 0;
    string ans;
    while (i >= 0 && j >= 0)
    {
        int sum = a[i] + b[j] + carry;
        carry = sum / 10;
        int digit = sum % 10;
        ans.push_back(digit + '0');
        i--;
        j--;
    }
    while (i >= 0)
    {
        int sum = a[i] + 0 + carry;
        carry = sum / 10;
        int digit = sum % 10;
        ans.push_back(digit + '0');
        i--;
    }
    while (j >= 0)
    {
        int sum = 0 + b[j] + carry;
        carry = sum / 10;
        int digit = sum % 10;
        ans.push_back(digit + '0');
        j--;
    }
    if (carry)
    {
        ans.push_back(carry + '0');
    }
    while (ans[ans.size() - 1] == '0')
    {
        ans.pop_back();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

void fact(vector<int> &v, int multiplier)
{
    vector<int> ans;
    int i = v.size() - 1;
    int carry = 0;
    while (i >= 0)
    {
        int product = v[i] * multiplier + carry;
        carry = product / 10;
        int digit = product % 10;
        ans.push_back(digit);
        i--;
    }
    while (carry)
    {
        ans.push_back(carry % 10);
        carry /= 10;
    }
    reverse(ans.begin(), ans.end());
    v = ans;
}
vector<int> factorial(int N)
{
    vector<int> ans = {1};
    for (int i = 2; i <= N; i++)
    {
        fact(ans, i);
    }
    return ans;
}

vector<int> factorial2(int N)
{
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            int product = ans[j] * i + carry;
            carry = product / 10;
            ans[j] = product % 10;
        }
        while (carry)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int removeDuplicates(vector<int> &nums)
{
    int j = 0;
    for (int i = 0; i < nums.size();)
    {
        int a = nums[i];
        while (nums[i] == a && i < nums.size())
        {
            i++;
        }
        nums[j] = a;
        j++;
    }
    return nums.size();
}
int removeDuplicates(vector<int> &nums)
{
    int i = 1;
    int j = 0;
    while (i < nums.size())
    {
        if (nums[i] == nums[j])
        {
            i++;
        }
        else
        {
            nums[++j] = nums[i++];
        }
    }
    return j + 1;
}

double findMaxAverage(vector<int> &nums, int k)
{
    double sum = INT_MIN;
    for (int i = 0; i + k - 1 < nums.size(); i++)
    {
        double total = 0;
        for (int j = i; j < i + k; j++)
        {
            total += nums[j];
        }
        cout << total << endl;
        sum = max(sum, total);
    }
    cout << sum << endl;
    sum /= k;
    return sum;
}

double findMaxAverage2(vector<int> &nums, int k)
{ // SLIDING WINDOW METHOD
    int i = 0;
    int j = k - 1;
    double sum = 0;
    for (int y = i; y <= j; y++)
    {
        sum += nums[y];
    }
    j++;
    double maxSum = sum;
    while (j < nums.size())
    {
        sum = sum + nums[j++] - nums[i++];
        maxSum = max(maxSum, sum);
    }
    return maxSum / k;
}
int main()
{
    // vector<int> v = {1, 5, 7, 1};
    // bool ans = twoSumUsingTwoPointer(v, 6);
    // if (ans)
    // {
    //     cout << "True" << endl;
    // }
    // else
    // {
    //     cout << "False " << endl;
    // }
    // vector<int> v1 = {1, 7, 3, 6, 5, 6};
    // cout << pivotIndexUsingPrefixSum(v1);

    // int arr[] = {1, 3, 5, 3, 4};
    // missingElement2(arr, 5);

    // int arr[] = {1};
    // cout << firstRepeated3(arr, 1);

    // vector<int> v1 = {1, 5, 10, 20, 40, 80};
    // vector<int> v2 = {6, 7, 20, 80, 100};
    // vector<int> v3 = {3, 4, 15, 20, 30, 70, 80, 120};
    // vector<int> ans = commonElements(v1, v2, v3, v1.size(), v2.size(), v3.size());
    // cout << "Printing vector : " << endl;
    // print(ans);

    // int arr[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    // wavePrint(arr, 4, 4);

    vector<int> ans = {1};
    cout << removeDuplicates(ans) << endl;
    print(ans);
    return 0;
}