//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-11.
//
#include <vector>

using std::vector;

int res = INT_MIN;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int dfs(int i, int j, vector<vector<int>>& grid, int bound_r, int bound_l)
{
    int cnt = 1;
    grid[i][j] = 0;
    for (int idx = 0; idx < 4; ++idx) {
        int n_i = i + dir[idx][0];
        int n_j = j + dir[idx][1];

        if (n_i >= 0 &&
            n_i < bound_r &&
            n_j >= 0 &&
            n_j < bound_l &&
            grid[n_i][n_j] == 1) {
            cnt += dfs(n_i, n_j, grid, bound_r, bound_l);
        }
    }
    return cnt;
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
    const int r = grid.size();
    const int l = grid[0].size();

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < l; ++j) {
            if (grid[i][j] == 1) {
                res = max(dfs(i, j, grid, r, l), res);
            }
        }
    }
    return res;
}


int getIslandSize(int i, int j, vector<vector<int>>& grid) {
    if (i<0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 0) {return 0;}
    grid[i][j] = 0;
    int size = 1;
    size += getIslandSize(i, j-1, grid);
    size += getIslandSize(i, j+1, grid);
    size += getIslandSize(i-1, j, grid);
    size += getIslandSize(i+1, j, grid);
    return size;
}

int maxAreaOfIsland1(vector<vector<int>>& grid) {
    int max = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == 1) {
                int islandSize = getIslandSize(i, j, grid);
                max = std::max(max, islandSize);
            }
        }
    }
    return max;
}
