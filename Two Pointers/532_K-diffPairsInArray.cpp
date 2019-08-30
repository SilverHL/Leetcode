//
// Created by neojxwang(王靖煊) on 2019-08-28.
//
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::unordered_map;

int findPairs(vector<int>& nums, int k)
{
    sort(nums.begin(), nums.end());
    int len = nums.size();
    int i = 0;
    int res = 0;
    int j = 0;
    for ( ; i < len; ++i)
    {
        j = std::max(j, i+1);
        while (j < len && nums[j] - nums[i] < k) ++j;
        if (j < len && nums[j] - nums[i] == k) ++res;
        while (i < len - 1 && nums[i] == nums[i+1]) ++i;
    }
    return res;
}

int findPairsUm(vector<int>& nums, int k)
{
    int res = 0, n = nums.size();
    unordered_map<int, int> mp;
    for (auto i : nums)
        mp[i]++;

    for (auto i : mp)
    {
        if (k == 0 && i.second > 1)
            res++;
        if (k > 0 && mp.count(k + i.first) > 0)
            res++;
    }

    return res;

}
