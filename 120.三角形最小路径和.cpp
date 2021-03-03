#include <vector>
#include <climits>

using namespace std;

/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;

        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i-1][0] + triangle[i][0];
        }

        int res = INT_MAX;

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            if (res > dp[n-1][i]) 
                res = dp[n-1][i];
        }

        return res;
    }
};
// @lc code=end

