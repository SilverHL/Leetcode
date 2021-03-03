#include <algorithm>
#include <vector>
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        std::vector<int> l_max(n, 0); 
        std::vector<int> r_max(n, 0);

        int l = 0;
        int r = 0;
        for (int i = 0; i < n; ++i)
        {
            l = std::max(l, height[i]);
            l_max[i] = l;
        }

        for (int i = n-1; i >= 0; --i)
        {
            r = std::max(r, height[i]);
            r_max[i] = r;
        }

        int res = 0;
        for (int i = 1; i < n-1; i++)
        {
            res += (std::min(l_max[i], r_max[i]) - height[i]);
        }

        return res;
    }



};
// @lc code=end

