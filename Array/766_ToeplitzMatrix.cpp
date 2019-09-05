//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-05.
//

#include <vector>

using std::vector;

bool isToeplitzMatrix(vector<vector<int>>& matrix)
{
    if (matrix.empty())
        return true;
    int sz = matrix.size();
    int n = matrix[n].size();

    for (int i = 1; i < sz; ++i)
        for (int j = 1; j < n; ++j)
            if (matrix[i][j] != matrix[i-1][j-1])
                return false;

    return true;

}
