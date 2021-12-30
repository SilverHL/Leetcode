#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minCost = prices[0];
        for (auto i : prices) {
            minCost = min(minCost, i);
            maxPro = max(maxPro, i - minCost);
        }
        return maxPro;
    }
};
// @lc code=end

