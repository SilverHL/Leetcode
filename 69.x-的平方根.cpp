/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
int mySqrt(int x) {
    if (x == 0) return 0;
    if (x < 4) return 1;
    int left = 1;
    int right = x / 2;

    while (left < right) {
        int mid = left + ((right - left + 1) >> 1); 
        if (mid > x / mid) {
            right = mid - 1;
        } else if (mid < x / mid) {
            left = mid; 
        } else {
            return mid;
        }
    }

    return left;
}
};
// @lc code=end

