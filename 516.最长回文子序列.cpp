#include <string>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;
        int n = s.length();
        // dp[i][j] s[i, i+1, .... j-1, j] 中的最长回文子序列长度
        vector<vector<int>> dp(n, vector<int>(n, 0));

        /**
         * dp[i][j] 取决于 dp[i+1][j-1] 如果s[i] == s[j] 那么  dp[i][j] = dp[i+1][j-1] 
         * 否则 将s[i] 及 s[j] 分别加入到 [i+1, ... j-1] 中，看哪个得到的回文字串较大即为dp[i][j]
         * */

        for (int i = 0; i < n; ++i) 
            dp[i][i] = 1;

        for (int i = n-1; i >= 0; --i) {
            for (int j = i+1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};
// @lc code=end

