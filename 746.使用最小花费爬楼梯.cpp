#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 0);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; ++i) {
            dp[i] = min(dp[i-2], dp[i-1]) + cost[i];
        }

        return min(dp[n-2], dp[n-1]);
    }
};
// @lc code=end

