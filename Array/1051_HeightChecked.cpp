//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-03.
//
#include <vector>

using std::vector;

int heightChecker(vector<int>& heights)
{
    if (heights.empty())
        return 0;
    vector<int>tmp(heights.begin(), heights.end());
    sort(tmp.begin(), tmp.end());
    int i = 0;
    int n = heights.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (tmp[i] != heights[i])
            res++;
    }

    return res;
}

