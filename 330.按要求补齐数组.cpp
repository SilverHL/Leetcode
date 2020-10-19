#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=330 lang=cpp
 *
 * [330] 按要求补齐数组
 */

// @lc code=start
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int pos = 0;
        long max_range = 0;
        long res = 0;
        int m = nums.size();

        for (long i = 1; i <= n;) {
            if (pos < m && nums[pos] <= i) {
                max_range += nums[pos];
                ++pos;
            } else {
                max_range += i;
                ++res;
            }
            i = max_range + 1;
        }
        return res;
    }
};
// @lc code=end

