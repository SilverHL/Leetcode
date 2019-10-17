//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-10-16.
//

#include <vector>

using std::vector;

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    int n = nums.size();
    for (auto i : nums) {
        int index = i > 0 ? i : -i;
        index--;
        if (nums[index] > 0)
            nums[index] = -nums[index];
    }

    vector<int> res;
    for (int i = 0 ; i < n; ++i)
        if (nums[i] > 0)
            res.push_back(i+1);

    return res;
}
