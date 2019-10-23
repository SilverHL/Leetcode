//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-10-22.
//

#include <vector>

using std::vector;

bool containsDuplicate(vector<int>& nums)
{
    if (nums.empty())
        return false;
    sort(nums.begin(), nums.end());

    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        if (nums[i-1] == nums[i])
            return true;
    }

    return false;
}

