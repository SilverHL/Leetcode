#include <vector>
#include <map>
#include <algorithm>

using namespace std;
/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
class Solution {
    int m_;
    int n_;
    vector<vector<int>> dp_;
public:
    /*
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        m_ = matrix.size();
        n_ = matrix[0].size();
        dp_ = vector<vector<int>>(m_, vector<int>(n_, -1));

        int mx = 0;
        for (int i = 0; i < m_; ++i) 
            for (int j = 0; j < n_; ++j) {
                mx = max(mx, dfs(i, j, matrix));
            }
        return mx;
    }

    int dfs(int x, int y, vector<vector<int>> &m) 
    {
        if (dp_[x][y] != -1)
            return dp_[x][y];
        dp_[x][y] = 1;
        static int dir[] = {-1, 0, 1, 0, -1};
        for (int i = 0; i < 4; ++i) {
            int tx = dir[i] + x;
            int ty = dir[i+1] + y;

            if (tx < 0 || tx >= m_ || ty < 0 || ty >= n_ || m[x][y] <= m[tx][ty])
                continue;
            dp_[x][y] = max(dp_[x][y], 1 + dfs(tx, ty, m));
        }

        return dp_[x][y];
    }
    */
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        vector<pair<int, pair<int, int>>> cells;
        m_ = matrix.size();
        n_ = matrix[0].size();
        dp_ = vector<vector<int>>(m_, vector<int>(n_, 1));

        for (int i = 0; i < m_; ++i) 
            for (int j = 0; j < n_; ++j) {
                cells.push_back({matrix[i][j], {i, j}});
            }
        sort(cells.rbegin(), cells.rend());

        int mx = 0;
        static int dir[] = {-1, 0, 1, 0, -1};
        for (auto cell : cells) {
            int x = cell.second.first;
            int y = cell.second.second;

            if (dp_[x][y] > 1)  
                continue;

            for (int i = 0; i < 4; ++i) {
                int tx = dir[i] + x;
                int ty = dir[i+1] + y;

                if (tx < 0 || tx >= m_ || 
                    ty < 0 || ty >= n_ || 
                    matrix[tx][ty] <= cell.first) 
                    continue;

                dp_[x][y] = max(dp_[x][y], dp_[tx][ty] + 1);
            }
            mx = max(mx, dp_[x][y]);
        }
        
        return mx;
    }

};
// @lc code=end

