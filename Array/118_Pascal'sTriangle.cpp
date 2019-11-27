//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019/11/25.
//

#include <vector>

using std::vector;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    if (numRows < 1)
        return res;
    res.push_back(vector<int>{1});
    for (int i = 1; i < numRows; ++i) {
        vector<int> tmp(i+1);
        for(int j = 0; j <= i; ++j)
            tmp[j] = (j != i ? res[i - 1][j] : 0) + (j > 0 ? res[i - 1][j - 1] : 0);
        res.push_back(tmp);
    }
    return res;
}

