#include <vector>
#include <numeric>

using namespace std;

/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int n = stones.size();
        int target = sum / 2;
        // dp[i][j]  到第i块石头的时候 背包容量为j的最大重量
        vector<int> dp(target+1, 0);

        for (int i = 1; i <= n; ++i) {
            int tmp = stones[i-1];
            for (int j = target; j >= tmp; --j) {
                dp[j] = max(dp[j], dp[j-tmp]+tmp);
            }
        }

        return sum - 2 * dp[target];
            
    }
};
// @lc code=end

