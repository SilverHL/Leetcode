/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        if (nums[left] < nums[right]) return nums[left];

        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[right] == nums[mid]) {
                --right;
                continue;
            }

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

