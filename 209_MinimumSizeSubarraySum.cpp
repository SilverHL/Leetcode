//
// Created by neojxwang(王靖煊) on 2019-08-22.
//

#include <vector>

using namespace std;

int minimumSizeSubSum(int target, vector<int>& nums)
{

    if (nums.empty())
        return 0;

    if (nums.size() == 1)
    {
        if (nums[0] == target)
            return 1;
        else
            return 0;
    }

    int i = 0;
    int j = 0;
    int min = INT_MAX;
    int n = nums.size();
    int count = 0;

    while (j < n)
    {
        count += nums[j++];
        if (count < target)
            continue;
        while (count >= target && i < j)
        {
            if (min > j - i)
                min = j - i;
            count -= nums[i++];
        }
    }

    while (count >= target && i < j)
    {
        if (min < j - i)
            min = j - i;
        count -= nums[i++];
    }

    if (min == INT_MAX)
        return 0;
    else
        return min;
}
