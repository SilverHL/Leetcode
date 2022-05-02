#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {

        int row = s.length();
        int line = p.length();

        vector<vector<int>> dp(row+1, vector<int>(line+1));
        dp[0][0] = 1;
        for (int i = 1; i < line; ++i) {
            if (p[i] == '*' && dp[0][i-1]) 
                dp[0][+1] = 1;
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < line; ++j) {
                if (p[j] == s[i] || p[j] == '.') 
                    dp[i+1][j+1] = dp[i][j];
                if (p[j] == '*') {
                    if (p[j-1] != s[i] && p[j-1] != '.')  
                        dp[i+1][j+1] = dp[i+1][j-1];
                    else {
                        dp[i+1][j+1] = dp[i+1][j] ||    // aa a*  i = 1 j = 1
                                       dp[i][j+1] ||    // aaa a* i = 2 j = 1
                                       dp[i+1][j-1];
                    }
                }
            }
        }
        return dp[row][line]; 
    }
};
// @lc code=end

