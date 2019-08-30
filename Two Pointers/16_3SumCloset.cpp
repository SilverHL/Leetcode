/*****************************
 * Leetcode 16 3SumCloset
 * Creator: Neo
 *
 * 本题和3Sum类似，但是有一点不同的是，3Sum可以通过将整个数组存在dict中，根据两个指针指向的数据和target可以求出第三个，
 * 只需要O(1)的复杂度就可以，但是这个方法不同于3Sum，因为第三个值不能确定，只能逐步靠近。
 * 首先排序整个数组，然后遍历，以当前遍历的数字为第一个值，然后以当前数字的下一个作为第二个，再以最后一个值作为第三个，
 * 求出离target最近的组合，求值就可以了。
 ****************************/

#include <iostream>
#include <vector>

class Solution
{
    public:
        int threeSumCloset(std::vector<int>& nums, int target)
        {
            int closet = nums[0] + nums[1] + nums[nums.size()-1];
            int sum;
            sort(begin(nums), end(nums));
            for (int i = 0; i < nums.size()-2; i++)
            {
                int j = i+1;
                int k = nums.size()-1;
                while (k > j)
                {
                    sum = nums[i] + nums[j] + nums[k];
                    closet = abs(target - sum) > abs(target - closet) ? closet : sum;
                    if (nums[j] + nums[k] == target - nums[i])
                        return closet;
                    else if (nums[j] + nums[k] > target - nums[i])
                        k--;
                    else
                        j++;
                }
            }
            return closet;
        }
};
