#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<vector<int>> dp(m+1, vector<int>(n+1, false));

        dp[0][0] = true;        

        for (int i = 1; i <= n; ++i) {
            if (p[i-1] == '*') {
                dp[0][i] = true;
            }
            else {
                break;
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[m][n];

    }
};
// @lc code=end

