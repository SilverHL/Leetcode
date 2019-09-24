//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-20.
//

#include <vector>

using std::vector;

vector<int> productExceptSelf(vector<int>& nums)
{
    if (nums.empty())
        return {};

    int n = nums.size();
    vector<int> fwd(n, 1), bwd(n, 1), res(n);

    for (int i = 0; i < n-1; i++)
        fwd[i+1] = fwd[i] * nums[i];

    for (int i = n-1; i > 0; i++)
        bwd[i-1] = bwd[i] * nums[i];

    for (int i = 0; i < n; ++i)
        res[i] = fwd[i] * bwd[i];

    return res;

}

