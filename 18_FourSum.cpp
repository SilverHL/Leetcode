//
// Created by neojxwang(王靖煊) on 2019-08-26.
//
#include <vector>

using std::vector;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    if (nums.size() < 4)
        return res;
    int n = nums.size();

    for (int i = 0; i < n-3; i++)
    {
        if (i > 0 && nums[i] == nums[i-1])
            continue;

        for (int j = i+1; j < n-2; j++)
        {
            if (j > i+1 && nums[j] == nums[j-1])
                continue;
            int l = j+1;
            int r = n-1;

            while (l < r)
            {
                int sum = nums[i] + nums[j] + nums[r] + nums[l];
                if (sum == target)
                {
                    res.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l+1]) l++;
                    while (l < r && nums[r] == nums[r-1]) r--;
                    l++,r--;
                }

                else if (sum < target)
                    l++;
                else
                    r--;
            }
        }
    }
    return res;
}

void twoSum(const vector<int>& nums, int left, int right, int target,
            vector<int>& soFar, vector<vector<int>>& result) {
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            result.push_back(soFar);
            vector<int>& last = result.back();
            last.push_back(nums[left]);
            last.push_back(nums[right]);
            left++;
            while (left < right && nums[left-1] == nums[left])
                left++;
        } else if (sum < target)
            left++;
        else
            right--;
    }
}

void nSum(const vector<int>& nums, int left, int right, int n, int target,
          vector<int>& soFar, vector<vector<int>>& result) {
    int sz = right - left + 1;
    if (sz < n || n < 2 || target < (n * nums[left]) || target > (n * nums[right]))
        return;

    if (n == 2) {
        twoSum(nums, left, right, target, soFar, result);
    } else {
        for (int i = left; i <= right - n + 1; i++) {
            if (i == left || (i > left && nums[i] != nums[i - 1])) {
                soFar.push_back(nums[i]);
                nSum(nums, i + 1, right, n - 1, target - nums[i], soFar, result);
                soFar.pop_back();
            }
        }
    }
}

void nSum(const vector<int>& nums, int left, int right, int n, int target,
        vector<int>& soFar, vector<vector<int>>& result)
{
    int sz = right - left + 1;
    if (sz < n || n < 2 || target < (n * nums[left]) || target > (n * nums[right]))
        return;

    if (n == 2)
        twoSum(nums, left, right, target, soFar, result);
    else
        for (int i = left; i <= right - n + 1; i++)
            if (i == left || (i > left && nums[i] != nums[i-1]))
            {
                soFar.push_back(nums[i]);
                nSum(nums, i+1, right, n-1, target - nums[i], soFar, result);
                soFar.pop_back();
            }
}

vector<vector<int>> fourSum1(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> soFar;
    vector<vector<int>> result;
    nSum(nums, 0, nums.size() - 1, 4, target, soFar, result);
    return result;
}
