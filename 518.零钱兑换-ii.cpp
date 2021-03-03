#include <vector> 
using namespace std;

/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
// dp[i][j]  使用[0, i]硬币时 凑出金额j的次数
/** 
dp[i][j] =  dp[i-1][j - 0 * coins[i]] + 
            dp[i-1][j - 1 * coins[i]] + 
            ... 
            dp[i-1][j - k * coins[i]]

            (0 <= k <= j / coins[i])

将 j 用 j - coins[i] 替换后

dp[i][j-coins[i]] = dp[i-1][j - coins[i] - 0 * coins[i]] + 
                    dp[i-1][j - coins[i] - 1 * coins[i]] + 
                    dp[i-1][j - coins[i] - 2 * coins[i]] + 
                    ... 
                    dp[i-1][j - coins[i] - (k-1) * coins[i]]
            (0 <= k <= j / coins[i])


dp[i][j-coins[i]] = dp[i-1][j - 1 * coins[i]] + 
                    dp[i-1][j - 2 * coins[i]] + 
                    dp[i-1][j - 3 * coins[i]] + 
                    ... 
                    dp[i-1][j - k * coins[i]]

dp[i][j] - dp[i][j-coins[i]] = dp[i-1][j]
dp[i][j] = dp[i][j-coins[i]] + dp[i-1][j]
**/
    int change(int amount, vector<int>& coins) 
    {
        if (!amount) return 1;
        if (coins.empty()) return 0;
        int n = coins.size();
        vector<int> dp(amount+1, 0);

        dp[0] = 1;
        for (int i = 0; i < n; ++i)  {
            int tmp = coins[i];
            for (int j = 0; j <= amount; ++j) {
                if (j >= tmp) {
                    dp[j] += dp[j - tmp];
                }
            }
        }

        return dp[amount];
    }
};
// @lc code=end

