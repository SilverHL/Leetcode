#include <vector>
#include <string>
#include <cstring>

using namespace std;

/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int* cnt1(string& s) 
    {
        int count[2];
        for (auto c : s) {
            count[c-'0']++;
        }
        return count;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();

        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < sz; ++i) {
            vector<int> count(2, 0);
            for (auto c : strs[i]) {
                count[c-'0']++;
            }
            for (int j = m; j >= 0; --j) {
                for (int k = n; k >= 0; --k) {
                    if (count[0] > j || count[1] > k) {
                        dp[j][k] = dp[j][k];
                    } else {
                        dp[j][k] = max(dp[j][k], dp[j-count[0]][k-count[1]]+1);
                    }
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

