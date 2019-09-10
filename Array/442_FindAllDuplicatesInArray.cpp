//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-07.
//

#include <vector>
#include <iostream>

using std::vector;
using std::swap;

vector<int> findDuplicates(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; ) {
        if (nums[nums[i]-1] != nums[i])
            swap(nums[nums[i]-1], nums[i]);
        else
            i++;
    }

    vector<int> res;
    for (int i = 0; i < n; i++)
        if (i+1 != nums[i])
            res.push_back(nums[i]);

    return res;
}


