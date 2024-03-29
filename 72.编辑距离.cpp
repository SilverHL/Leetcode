#include <string>
#include <vector>
#include <algorithm>


using namespace std;

/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {

        word1 = "#" + word1;
        word2 = "#" + word2;

        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 1; i < m; ++i) {
            dp[i][0] = i;
        }

        for (int i = 1; i < n; ++i) {
            dp[0][i] = i;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                }
            }
        }

        return dp[m-1][n-1];
    }
};
// @lc code=end

