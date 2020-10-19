#include <vector>
#include <climits>
#include <queue>
#include <map>

using namespace std;

/*
 * @lc app=leetcode.cn id=778 lang=cpp
 *
 * [778] 水位上升的泳池中游泳
 */

// @lc code=start
class Solution {
    vector<vector<int>> dir = { {1,0},{0,1},{0,-1},{-1,0}};
    int N;
public:
/*
    int swimInWater(vector<vector<int>>& grid) {
        int l = grid[0][0], r = 2500, ans = 0;
        N = grid.size();

        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            vector<vector<bool>> vis(N, vector<bool>(N, false));
            if (dfs(0, 0, vis, grid, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    bool dfs(int x, int y, vector<vector<bool>> &vis, vector<vector<int>>& grid, int MAX) {
        vis[x][y] = true;

        if (grid[x][y] > MAX) 
            return false;

        if (x == N-1 && y == N-1) 
            return true;
        
        for (int d = 0; d < 4; ++d) {
            int i = x + dir[d][0];
            int j = y + dir[d][1];
            if (0 <= i && i < N && 0 <= j && j < N && !vis[i][j]) {
                if (dfs(i, j, vis, grid, MAX)) 
                    return true;
            }
        }
        return false;
    }
    */

    int swimInWater(vector<vector<int>> &grid) {
        int n = grid.size();
        priority_queue<pair<int, int>> que;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<int> dir {0, -1, 0, 1, 0};
        que.push({-grid[0][0], 0});
        int ans = 0;

        while (!que.empty()) {
            auto tmp = que.top(); que.pop();
            int t = -tmp.first;
            int x = tmp.second % n;
            int y = tmp.second / n;

            vis[x][y] = 1;
            if (t > ans) 
                ans = t;
            if (x == n-1 && y == n-1) 
                return ans;

            for (int i = 0; i < 4; ++i) {
                int tx = x + dir[i];
                int ty = y + dir[i+1];

                if (tx < 0 || n <= tx || ty < 0 || n <= ty)
                    continue;
                if (vis[tx][ty])
                    continue;
                que.push({-grid[tx][ty], ty * n + tx});
            }
            
        }

        return -1;
        
    }

};
// @lc code=end

