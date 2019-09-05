//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-05.
//

#include <vector>

using std::vector;

vector<vector<int>> transpose(vector<vector<int>>& A)
{
    if (A.empty())
        return {};

    int sz = A.size();
    int n = A[0].size();
    vector<vector<int> >res(n);
    for (int i = 0; i < n; ++i) {
        vector<int> tmp(sz);
        for (int j = 0; j < sz; ++j)
            tmp[j] = A[j][i];
        res[i] = tmp;
    }
    return res;
}

