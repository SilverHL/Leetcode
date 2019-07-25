//
// Created by neojxwang(王靖煊) on 2019-07-25.
//

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return 1;


    int left = 0;
    int right = left+1;
    int len = nums.size();
    int res = 1;

    while (left < len && right < len && nums[left] != nums[right])
    {
        left++;
        right++;
        res++;
    }

    left = right;
    for ( ; right < len-1; right++)
    {
        if (nums[right] != nums[right+1])
        {
            nums[left] = nums[right+1];
            left++;
            res++;
        }
    }
    return res;
}

