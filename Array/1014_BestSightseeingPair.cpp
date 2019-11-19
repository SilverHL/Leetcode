//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-11-13.
//
#include <vector>

using std::vector;

int maxScoreSightseeingPair(vector<int>& A)
{
    int bst = 0;
    int res = 0;

    for (auto a : A) {
        res = std::max(res, bst + a);
        bst = std::max(bst, a) - 1;
    }

    return res;
}

