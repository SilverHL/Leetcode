#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int a = nums[0];
        int b = max(nums[0], a);

        for (int i = 2; i < n-1; ++i) {
            int tmp = b;
            b = max(tmp, a + nums[i]);
            a = tmp;
        }

        a = nums[1];
        int c = max(a, nums[2]);
        for (int i = 3; i < n; ++i) {
            int tmp = c;
            c = max(c, a + nums[i]);
            a = tmp;
        }

        return max(b, c);
    

    }
};
// @lc code=end

