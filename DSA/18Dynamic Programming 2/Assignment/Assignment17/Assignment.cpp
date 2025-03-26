#include <iostream>
using namespace std;

// LEETCODE 1671 (MINIMUM NUMBER OF REMOVALS TO MAKE MOUNTAIN ARRAY)
void lengthOfLIS(vector<int> &nums, vector<int> &lis)
{
    vector<int> ans;
    ans.push_back(nums[0]);
    lis.push_back(1);
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > ans.back())
        {
            ans.push_back(nums[i]);
            lis.push_back(ans.size());
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[index] = nums[i];
            lis.push_back(index + 1);
        }
    }
}
int minimumMountainRemovals(vector<int> &nums)
{
    vector<int> lis, lds;
    lengthOfLIS(nums, lis);
    reverse(nums.begin(), nums.end());
    lengthOfLIS(nums, lds);

    int maxLength = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (lis[i] == 1 || lds[nums.size() - i - 1] == 1)// Atleast 2 element is needed in both the cases to form mountain array
            continue;
        maxLength = max(maxLength, (lis[i] + lds[nums.size() - i - 1] - 1));
    }
    int minRemovals = nums.size() - maxLength;
    return minRemovals;
}
int main()
{
    return 0;
}