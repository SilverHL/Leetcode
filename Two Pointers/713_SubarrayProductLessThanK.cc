//
// Created by neojxwang(王靖煊) on 2019-08-18.
//

#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int> nums, int k)
{
    int i = 0;
    int j = 0;
    int pro = 1;
    int size = nums.size();
    int count = 0;
    while (j < size)
    {
        pro *= nums[j++];
        while (i != j && pro >= k)
        {
            pro /= nums[i];
            i++;
        }
        count += (j - i);
    }
    return count;
}
