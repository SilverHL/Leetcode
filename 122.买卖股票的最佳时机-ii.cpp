#include <vector>

using namespace std;


/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int n = prices.size();

        for (int i = 1; i < n; ++i) {
            if (prices[i] > prices[i-1]) {
                maxPro += (prices[i] - prices[i-1]);
            }
        } 
        return maxPro;
    }
};
// @lc code=end

