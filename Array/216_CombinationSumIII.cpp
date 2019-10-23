//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-10-22.
//

#include <vector>

void dfs(int k, int n, int s, vector<int>& cur, vector<vector<int>>& res)
{
    for (auto i : cur)
        cout << i;
    cout << endl;
    if (k == 0) {
        if (n == 0)
            res.push_back(cur);
        return;
    }

    for (int i = s; i <= 9; ++i) {
        if (i > n)
            return;
        cur.push_back(i);
        dfs(k-1, n-i, i+1, cur, res);
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> res;
    vector<int> cur;
    dfs(k, n, 1, cur, res);
    return res;
}
