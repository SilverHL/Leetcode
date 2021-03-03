#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=1301 lang=cpp
 *
 * [1301] 最大得分的路径数目
 */

// @lc code=start
class Solution {

    void prnt(vector<vector<int>> &dp) 
    {
        for (auto v : dp)  {
            for (auto i : v) {
                if (i == -1) 
                    cout << "X ";
                else 
                    cout << i << " ";
            }

            cout << endl;
        }
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int k = 1000000007;
        int n = board.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        vector<vector<int>> path(n+1, vector<int>(n+1, 0));

        board[0][0] = board[n-1][n-1] = '0';
        path[n-1][n-1] = 1;

        for (int i = n-1; i >= 0; --i) 
            for (int j = n-1; j >= 0; --j) {
                if (board[i][j] != 'X') {
                    int m = max({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});

                    dp[i][j] = (m + board[i][j] - '0');

                    if (dp[i][j+1] == m) {
                        path[i][j] = (path[i][j] + path[i][j+1]) % k;
                    }

                    if (dp[i+1][j+1] == m) {
                        path[i][j] = (path[i][j] + path[i+1][j+1]) % k;
                    }
                    if (dp[i+1][j] == m) {
                        path[i][j] = (path[i][j] + path[i+1][j]) % k;
                    }
                }
            }

        prnt(dp);
        if (path[0][0] == 0) 
            return {0, 0};
        else 
            return {dp[0][0], path[0][0]}; 
    }
};
// @lc code=end

