//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-09.
//

#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;
using std::max_element;

vector<int> pancakeSort(vector<int> &A)
{
    vector<int> res;
    auto beg = A.begin();

    for (auto i = A.end(); i > beg; --i) {
        auto max_it = max_element(beg, i);

        if (max_it + 1 != i) {
            res.push_back(max_it + 1 - beg);
            reverse(beg, max_it + 1);
            res.push_back(i - beg);
            reverse(beg, i);
        }
    }

    return res;

}

