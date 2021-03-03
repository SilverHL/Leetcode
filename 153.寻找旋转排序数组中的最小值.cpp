#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        if (nums[left] < nums[right])  return nums[left];

        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return nums[right];
    }
};
// @lc code=end

