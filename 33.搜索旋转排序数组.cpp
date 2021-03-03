#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n-1; 
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;kkkkkk
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}
};
// @lc code=end

