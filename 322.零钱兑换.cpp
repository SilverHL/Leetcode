#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
/*
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int mx = amount + 1;
        vector<int> dp(amount+1, 1001);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] = min(dp[j], dp[j-coins[i]]+1);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
    */
   void coinChange(vector<int>& coins, int amount, int c_index, int count, int& ans)
    {
        if (amount == 0)
        {
            ans = min(ans, count);
            return;
        }
        if (c_index == coins.size()) return;
    
        for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)
        {
            coinChange(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
        }
    }

    int coinChange(vector<int>& coins, int amount)
    {
        if (amount == 0) return 0;
        sort(coins.rbegin(), coins.rend());
        int ans = INT_MAX;
        coinChange(coins, amount, 0, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end

