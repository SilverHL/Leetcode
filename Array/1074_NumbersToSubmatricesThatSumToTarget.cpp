//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-17.
//
#include <vector>
#include <unordered_map>

using namespace std;

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 1; j < m; j++)
            matrix[i][j] += matrix[i][j - 1];

    for (int l = 0; l < m; l++)
        for (int r = l; r < m; r++) {
            unordered_map<int, int> vis;
            vis[0] = 1;
            int tot = 0;
            for (int k = 0; k < n; k++) {
                if (l == 0) {
                    tot += matrix[k][r];
                } else {
                    tot += matrix[k][r] - matrix[k][l - 1];
                }
                if (vis.find(tot - target) != vis.end())
                    ans += vis[tot - target];
                vis[tot]++;
            }
        }
    return ans;
}

int test(vector<vector<int>>& matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 1; j < m; ++j)
            matrix[i][j] += matrix[i][j-1];

    for (int l = 0; l < m; ++l)
        for (int r = l; r < m; ++r) {
            int total = 0;
            unordered_map<int, int> mp;
            mp[0] = 1;

            for (int k = 0; k < n; ++k)
            {
                if (l == 0)
                    total += matrix[k][r];
                else
                    total += matrix[k][r] - matrix[k][l-1];
                if (mp.find(total - target) != mp.end())
                    ans += mp[total - target];
                mp[total]++;
            }
        }
    return ans;
}
