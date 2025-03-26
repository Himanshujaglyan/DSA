#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// K-DIFF PAIRS IN ARRAY
int findPairs(vector<int> &nums, int k) // LEETCODE 532
{
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;
    int i = 0;
    int j = 1;
    while (j < nums.size())
    {
        int diff = nums[j] - nums[i];
        if (diff == k)
        {

            ans.insert({nums[i], nums[j]});
            i++;
            j++;
        }
        else if (diff > k)
        {
            i++;
        }
        else
        {
            j++;
        }
        if (i == j)
        {
            j++;
        }
    }
    return ans.size();
}
int binarySearch(vector<int> nums, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
int findPairs2(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int index = binarySearch(nums, nums[i] + k, i + 1, nums.size() - 1);
        if (index != -1)
        {
            ans.insert({nums[i], nums[index]});
        }
    }
    return ans.size();
}
// FIND K-CLOSEST ELEMENT
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    vector<int> nums(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        nums[i] = abs(arr[i] - x);
    }
    vector<int> ans(nums);
    sort(ans.begin(), ans.end());
    vector<int> result;
    for (int i = 0; i < k; i++)
    {
        int element = ans[i];
        for (int i = 0; i < nums.size(); i++)
        {
            if (element == nums[i])
            {
                cout << i << endl;
                result.push_back(arr[i]);
                nums[i] = -1;
                break;
            }
        }
    }
    sort(result.begin(), result.end());
    return result;
}
vector<int> findClosestElements1(vector<int> &arr, int k, int x)
{
    vector<int> nums(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        nums[i] = abs(arr[i] - x);
    }

    int low = 0;
    int high = arr.size() - 1;
    while ((high - low + 1) != k)
    {
        if (nums[low] > nums[high])
        {
            low++;
        }
        else if (nums[high] > nums[low])
        {
            high--;
        }
        else
        {
            high--;
        }
    }
    vector<int> ans;
    for (int i = low; i <= high; i++)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}
vector<int> findClosestElements2(vector<int> &arr, int k, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    while ((high - low) >= k)
    {
        if (x - arr[low] > arr[high] - x)
        {
            low++;
        }
        else
        {
            high--;
        }
    }

    return vector<int>(arr.begin() + low, arr.begin() + high + 1);
}
int lowerBound(vector<int> arr, int x)
{
    int s = 0;
    int e = arr.size() - 1;
    int result = e;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] >= x)
        {
            result = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return result;
}
vector<int> findClosestElements3(vector<int> &arr, int k, int x)
{
    int high = lowerBound(arr, x);
    int low = high - 1;
    while (k--)
    {
        if (low < 0)
        {
            high++;
        }
        else if (high >= arr.size())
        {
            low--;
        }
        else if (x - arr[low] > arr[high] - x)
        {
            high++;
        }
        else
        {
            low--;
        }
    }

    return vector<int>(arr.begin() + low + 1, arr.begin() + high);
}
// EXPONENTIAL SEARCH
int exponentialSearch(vector<int> v, int target)
{
    if (v[0] == target)
    {
        return 0;
    }
    int i = 1;
    while (i < v.size() && v[i] <= target)
    {
        i *= 2; // i <<= 1;
    }
    int n = v.size() - 1;
    return binarySearch(v, target, i / 2, min(i, n));
}
// BOOK ALLOCATION
bool isPossible(int arr[], int n, int m, int sol)
{

    int c = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > sol)
        {
            return false;
        }
        if (sum + arr[i] > sol)
        {
            c++;
            sum = arr[i];
            if (c > m)
            {
                return false;
            }
        }
        else
        {
            sum += arr[i];
        }
    }
    return true;
}

int findPages(int A[], int N, int M)
{
    if (M > N)
    {
        return -1;
    }
    int start = 0;
    int end = accumulate(A, A + N, 0);
    int result = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(A, N, M, mid))
        {
            end = mid - 1;
            result = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return result;
}
// PAINTER PARTITION
bool isPossible1(int arr[], int n, int m, long long sol)
{

    int c = 1;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > sol)
        {
            return false;
        }
        if (sum + arr[i] > sol)
        {
            c++;
            sum = arr[i];
            if (c > m)
            {
                return false;
            }
        }
        else
        {
            sum += arr[i];
        }
    }
    return true;
}
long long minTime(int arr[], int n, int k)
{
    if (k > n)
    {
        return -1;
    }
    long long start = 0;
    long long end = 0;
    for (int i = 0; i < n; i++)
    {
        end += arr[i];
    }
    long long result = -1;
    while (start <= end)
    {
        long long mid = start + (end - start) / 2;
        if (isPossible1(arr, n, k, mid))
        {
            end = mid - 1;
            result = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return result;
}
// AGGRESSIVE COW
bool isPossible3(int n, int k, vector<int> stalls, int mid)
{
    int c = 1;
    int pos = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - pos >= mid)
        {
            pos = stalls[i];
            c++;
        }
        if (c == k)
        {
            return true;
        }
    }
    return false;
}
int solve(int n, int k, vector<int> &stalls)
{
    sort(stalls.begin(), stalls.end());
    int start = 0;
    int end = stalls[stalls.size() - 1] - stalls[0];
    int result = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible3(n, k, stalls, mid))
        {
            result = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return result;
}
// EKO - SPOJ
bool isPossible4(long long int m, vector<long long int> v, long long int sol)
{
    long long int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > sol)
        {
            sum += v[i] - sol;
        }
    }
    return sum >= m;
}
long long int heightOfBlade(long long int m, vector<long long int> v)
{
    long long int start = 0;
    long long int end = *max_element(v.begin(), v.end());
    long long int result = -1;
    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;
        if (isPossible4(m, v, mid))
        {
            result = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return result;
}
// PRATA - SPOJ
bool isPossible5(vector<int> rank, int nP, int sol)
{
    int pranthas_cooked = 0;
    for (int i = 0; i < rank.size(); i++)
    {
        int r = rank[i];
        int cooking_time = 0;
        int j = 2;
        while (true)
        {
            if (cooking_time + r <= sol)
            {
                cooking_time += r;
                r = rank[i] * j;
                j++;
                pranthas_cooked++;
            }
            else
            {
                break;
            }
        }
        if (pranthas_cooked >= nP)
        {
            return true;
        }
    }
    return false;
}
int minTimeToCompleteOrder(vector<int> rank, int nP)
{
    int start = 0;
    int highest_rank = *max_element(rank.begin(), rank.end());
    int end = highest_rank * (nP * (nP + 1) / 2);
    int result = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible5(rank, nP, mid))
        {
            result = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return result;
}
int main()
{
    // vector<int> v{3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    // cout << exponentialSearch(v, 13) << endl;
    // vector<long long int> v = {4,42,40,26,46};
    // cout << heightOfBlade(20, v) << endl;

    int testCase;
    cout << "Enter number of test cases : ";
    cin >> testCase;
    while (testCase--)
    {
        int nC, nP;
        cout << "Enter the number of cooks : ";
        cin >> nC;
        cout << "Enter the number of pranthas : ";
        cin >> nP;
        vector<int> rank;
        while (nC--)
        {
            cout << "Enter the rank of cook : ";
            int r;
            cin >> r;
            rank.push_back(r);
        }

        cout << minTimeToCompleteOrder(rank, nP) << endl;
    }
    return 0;
}