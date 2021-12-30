#include <vector>
#include <algorithm>

using namespace std;
/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size())
            return 0;
        
        int n = prices.size();
        int left[n], right[n];
        int leftmin = prices[0], rightmax = prices[n-1], maxprofit = 0;


        left[0] = 0; right[n-1] = 0;
        int i, j;

        for (i = 1, j = n-2; i < n, j > 0; ++i, --j) {
            leftmin = min(leftmin, prices[i]);
            left[i] = max(left[i-1], prices[i] - leftmin);
            rightmax = max(rightmax, prices[j]);
            right[i] = max(right[j+1], rightmax - prices[j]);
        }


    }
};
// @lc code=end

