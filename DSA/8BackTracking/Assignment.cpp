#include <iostream>
using namespace std;

// GFG (INVERSION COUNT)
void merge(vector<int> &nums, vector<int> &temp, int start, int end, int &count)
{
    int mid = start + (end - start) / 2;
    int i = start;
    int j = mid + 1;
    int k = start;
    while (i <= mid && j <= end)
    {
        if (nums[i] <= nums[j])
        {
            temp[k++] = nums[i++];
        }
        else
        {
            count += (mid - i + 1); // logic
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = nums[i++];
    }
    while (j <= end)
    {
        temp[k++] = nums[j++];
    }

    for (i = start; i <= end; i++)
    {
        nums[i] = temp[i];
    }
}
void mergeSort(vector<int> &nums, vector<int> &temp, int start, int end, int &count)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(nums, temp, start, mid, count);
    mergeSort(nums, temp, mid + 1, end, count);
    merge(nums, temp, start, end, count);
}
int inversionCount(vector<int> &nums)
{
    int count = 0;
    int start = 0;
    int end = nums.size() - 1;
    vector<int> temp(nums.size(), 0);
    mergeSort(nums, temp, start, end, count);
    return count;
}

// INPLACE MERGE SORT
void merge(vector<int> &nums, int start, int end)
{
    int mid = start + (end - start) / 2;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (nums[i] > nums[j])
        {
            swap(nums[i], nums[j]);
            int k = j;
            while (j < end)
            {
                if (nums[j] > nums[j + 1])
                {
                    swap(nums[j], nums[j + 1]);
                }
                j++;
            }
            j = k;
        }
        i++;
    }
}
void mergeSort(vector<int> &nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);
    merge(nums, start, end);
}
vector<int> sortArray(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    mergeSort(nums, start, end);
    return nums;
}

// GAP METHOD
void merge(vector<int> &nums, int start, int end)
{
    int total_length = end - start + 1;
    int gap = (total_length / 2) + (total_length % 2); // ceil value
    while (gap > 0)
    {
        int i = start;
        int j = start + gap;
        while (j <= end)
        {
            if (nums[i] > nums[j])
            {
                swap(nums[i], nums[j]);
            }
            i++;
            j++;
        }
        gap = gap <= 1 ? 0 : ((gap / 2) + (gap % 2));
    }
}
void mergeSort(vector<int> &nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);
    merge(nums, start, end);
}
vector<int> sortArray(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    mergeSort(nums, start, end);
    return nums;
}

// Given two array Merge them
void mergeArray(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();
    int total_length = n + m;
    int gap = (total_length / 2) + (total_length % 2);
    while (gap > 0)
    {
        int i = 0;
        int j = gap;
        while (j < total_length)
        {
            if (j < n && a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
            if (j >= n && i < n && a[i] > b[j - n])
            {
                swap(a[i], b[j - n]);
            }
            if (j >= n && i >= n && b[i - n] > b[j - n])
            {
                swap(b[i - n], b[j - n]);
            }
            i++;
            j++;
        }
        gap = gap <= 1 ? 0 : ((gap / 2) + (gap % 2));
    }
}

// LEETCODE 53 (MAXIMUM SUBARRAY SUM)
int solve(vector<int> &nums, int start, int end)
{
    if (start == end)
        return nums[start];

    int mid = start + ((end - start) >> 1);
    int leftSum = solve(nums, start, mid);
    int rightSum = solve(nums, mid + 1, end);

    int leftBorderSum = 0, rightBorderSum = 0;
    int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
    for (int i = mid; i >= start; i--)
    {
        leftBorderSum += nums[i];
        if (leftBorderSum > maxLeftBorderSum)
        {
            maxLeftBorderSum = leftBorderSum;
        }
    }
    for (int i = mid + 1; i <= end; i++)
    {
        rightBorderSum += nums[i];
        if (rightBorderSum > maxRightBorderSum)
        {
            maxRightBorderSum = rightBorderSum;
        }
    }
    int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;

    return max(leftSum, max(rightSum, crossBorderSum));
}

int maxSubArray(vector<int> &nums)
{
    return solve(nums, 0, nums.size() - 1);
}

// LEETCODE 39 (COMBINATION SUM)
void solve(vector<int> &candidates, int target, vector<vector<int>> &ans, int index, vector<int> &temp)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (index >= candidates.size())
        return;

    if (candidates[index] <= target)
    {
        temp.push_back(candidates[index]);
        solve(candidates, target - candidates[index], ans, index, temp);
        temp.pop_back();
    }
    solve(candidates, target, ans, index + 1, temp);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(candidates, target, ans, 0, temp);
    return ans;
}

// LAKSHAY CODE
void solve(vector<int> &candidates, int target, vector<vector<int>> &ans, int index, vector<int> &temp)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (target < 0)
        return;
    for (int i = index; i < candidates.size(); i++)
    {
        temp.push_back(candidates[i]);
        solve(candidates, target - candidates[i], ans, i, temp);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(candidates, target, ans, 0, temp);
    return ans;
}

// LEETCODE 40 (COMBINATION SUM II)
void solve(vector<int> &candidates, int target, vector<vector<int>> &ans, int index, vector<int> &temp)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (target < 0)
        return;
    for (int i = index; i < candidates.size(); i++)
    {
        if (i > index && candidates[i] == candidates[i - 1])
            continue;
        temp.push_back(candidates[i]);
        solve(candidates, target - candidates[i], ans, i + 1, temp);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    solve(candidates, target, ans, 0, temp);
    return ans;
}

// LEETCODE 47 (PERMUTATIONS II)
void solve(vector<int> &nums, int index, vector<vector<int>> &ans)
{
    if (index >= nums.size() - 1)
    {
        ans.push_back(nums);
        return;
    }
    unordered_map<int, bool> visited;
    for (int i = index; i < nums.size(); i++)
    {
        if (visited.find(nums[i]) != visited.end())
        {
            continue;
        }
        visited[nums[i]] = true;
        swap(nums[index], nums[i]);
        solve(nums, index + 1, ans);
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    solve(nums, 0, ans);
    return ans;
}

// LEETCODE 526 (BEAUTIFUL ARRANGEMENT)
int solve(vector<bool> &marked, int index)
{
    if (index >= marked.size())
    {
        return 1;
    }
    int ans = 0;
    for (int i = 1; i <= marked.size() - 1; i++)
    {
        if (!marked[i])
        {
            if ((i % index == 0) || (index % i == 0))
            {
                marked[i] = true;
                ans += solve(marked, index + 1);
                marked[i] = false;
            }
        }
    }
    return ans;
}
int countArrangement(int n)
{
    vector<bool> marked(n + 1, false);
    return solve(marked, 1);
}

// LEETCODE 1655 (DISTRIBUTE REPEATING INTEGERS)
bool solve(vector<int> &count, vector<int> &quantity, int index)
{
    if (index >= quantity.size())
        return true;
    for (int i = 0; i < count.size(); i++)
    {
        if (count[i] >= quantity[index])
        {
            count[i] -= quantity[index];
            if (solve(count, quantity, index + 1))
            {
                return true;
            }
            count[i] += quantity[index];
        }
    }
    return false;
}
bool canDistribute(vector<int> &nums, vector<int> &quantity)
{
    sort(quantity.rbegin(), quantity.rend()); // sort in decscending order
    unordered_map<int, int> countMap;
    for (int i = 0; i < nums.size(); i++)
    {
        countMap[nums[i]]++;
    }
    vector<int> count;
    for (auto it : countMap)
    {
        count.push_back(it.second);
    }
    return solve(count, quantity, 0);
}

int main()
{
    vector<int> a = {10, 11, 12, 13};
    vector<int> b = {1, 2, 3, 4, 5};
    mergeArray(a, b);
    for (auto num : a)
    {
        cout << num << " ";
    }
    cout << endl;
    for (auto num : b)
    {
        cout << num << " ";
    }
    return 0;
}