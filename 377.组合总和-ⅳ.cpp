#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (!target)  return 1;
        if (nums.empty()) return 0;

        int n = nums.size();
        vector<unsigned long long> dp(target+1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; ++i) 
            for (int num : nums) 
                if (i >= num) 
                    dp[i] += dp[i-num];
            
        return dp[target];

    }
};
// @lc code=end

