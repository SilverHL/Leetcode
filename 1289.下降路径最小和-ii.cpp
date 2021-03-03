#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=1289 lang=cpp
 *
 * [1289] 下降路径最小和  II
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        if (arr.empty()) return 0;

        int n = arr.size();
        if (n == 1) return arr[0][0];

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            dp[0][i] = arr[0][i];
        }

        for (int i = 1; i < n; ++i) {
            vector<int> tmp = dp[i-1];
            int idx = min_element(tmp.begin(), tmp.end()) - tmp.begin();
            sort(tmp.begin(), tmp.end());
            for (int j = 0; j < n; ++j) {
                dp[i][j] = (j == idx ? tmp[1] : tmp[0]);
                dp[i][j] += arr[i][j];
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
// @lc code=end

