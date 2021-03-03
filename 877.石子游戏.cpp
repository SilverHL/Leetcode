#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */

// @lc code=start
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<pair<int,int>>> dp(n ,vector<pair<int, int>>(n, pair<int, int>(0, 0)));
        for (int i = 0; i < n; ++i) {
            dp[i][i].first = piles[i];
            dp[i][i].second = 0;
        }

        for (int i = n-1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (i == n-1 || j == 0 || i == j) 
                    continue;
                int left = piles[i] + dp[i+1][j].second;
                int right = piles[j] + dp[i][j-1].second;

                if (left > right) {
                    dp[i][j].first = left;
                    dp[i][j].second = dp[i+1][j].first;
                } else {
                    dp[i][j].first = right;
                    dp[i][j].second = dp[i][j-1].first;
                }
            }
        }

        return dp[0][n-1].first > dp[0][n-1].second ? true : false;
    }
};
// @lc code=end

