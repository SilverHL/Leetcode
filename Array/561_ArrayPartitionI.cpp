//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-03.
//

#include <vector>
#include <algorithm>

using std::vector;

int arrayPairSum(vector<int>& nums)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i += 2)
        sum += min(nums[i], nums[i+1]);

    return sum;
}

