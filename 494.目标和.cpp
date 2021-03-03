#include <vector>
#include <numeric>

using namespace std;

/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S) return 0;
        sum += S;
        int n = nums.size();
        if (sum & 1) return 0;
        int target = sum >> 1;
        // 定义 dp[i][j] 的实际含义 (重要)
        // 
        vector<int> dp(target+1);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = target; j >=  nums[i]; --j) {
                dp[j] += dp[j-nums[i]];
            }
        }

        return dp[target];
        
    }
};
// @lc code=end

