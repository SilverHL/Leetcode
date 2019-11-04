//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-11-02.
//

#include <vector>

using std::vector;

vector<int> constructArray(int n, int k)
{
    vector<int> res;
    int l = 1, r = n;

    while (l <= r) {
        if (k > 1) {
            if (k % 2 == 1) {
                res.push_back(l++);
            } else {
                res.push_back(r--);
            }
            k--;
        } else {
            res.push_back(l++);
        }
    }
    return res;
}

