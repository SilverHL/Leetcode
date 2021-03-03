#include <vector>
#include <string>

using namespace std;

/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        if (s.empty()) return 0;
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n-2; i >= 0; --i) {
            for (int j = 1; j < n; ++j) {
                if (i >= j) 
                    continue;
                if (s[i] == s[j]) 
                    dp[i][j] = dp[i+1][j-1];
                else 
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;

            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

