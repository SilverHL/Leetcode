#include <vector>
#include <climits>

using namespace std;

/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if (A.empty()) return 0;
        int n = A.size();

        if (n == 1) 
            return A[0][0];
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; ++i) {
            dp[0][i] = A[0][i];
        }

        for (int i = 1; i < n; ++i) 
            for (int j = 0; j < n; ++j) {
                int t1 = dp[i-1][j];

                if (j == 0 && j < n-1) {
                    dp[i][j] = min(t1, dp[i-1][j+1]);
                } else if (j == n-1 && j > 0) {
                    dp[i][j] = min(t1, dp[i-1][j-1]);
                } else{
                    int t2 = dp[i-1][j+1];
                    int t3 = dp[i-1][j-1];
                    dp[i][j] = min(t1, min(t2, t3));
                }

                dp[i][j] += A[i][j];
            }
        
        int res = INT_MAX;
        for (auto i : dp[n-1]) {
            if (i < res)
                res = i;
        }

        return res;
    }
};
// @lc code=end

