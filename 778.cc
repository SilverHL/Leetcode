#include <vector>
#include <climits>
#include <iostream>


using namespace std;


int swimInWater(vector<vector<int>>& grid) {
    int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int n = grid.size();
    int i = 0; 
    int j = 0;
    int res = INT_MIN;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vis[0][0] = 1;

    while (!(i == n-1 && j == n-1)) {
        int target = 0;
        int val = INT_MAX;
        int idx;
        for (idx = 0; idx < 4; ++idx) {
            int tmp_i = i + dir[idx][0];
            int tmp_j = j + dir[idx][1];

            if (!(0 <= tmp_i && tmp_i < n && 
                0 <= tmp_j && tmp_j < n && !vis[tmp_i][tmp_j])) {
                    continue;
                }
            if (grid[tmp_i][tmp_j] < val) {
                val = grid[tmp_i][tmp_j];
                target = idx;
            }
        }

        i += dir[target][0];
        j += dir[target][1];
        vis[i][j] = 1;

        cout << "i = " << i << endl;
        cout << "j = " << j << endl;

        if (grid[i][j] > res) 
            res = grid[i][j];
    }

    if (grid[i][j] > res) 
        res = grid[i][j];

    return res;
}