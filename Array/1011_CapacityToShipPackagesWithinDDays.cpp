//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-10-15.
//

#include <vector>

using std::vector;


int shipWithinDays(vector<int>& weights, int D)
{
    if (weights.empty())
         return 0;

    int total = 0;
    for (auto w : weights)
        total += w;

    int l = max(total / D, *max_element(begin(weights), end(weights)));
    int r = total;
    int mid = 0;

    while (l <= r) {
        mid = (r - l) / 2 + l;
        int tmp = 0;
        int days = D;
        for (auto w : weights) {
            tmp += w;
            if (tmp > mid) {
                days--;
                tmp = w;
            }
        }

        if (days > 0) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;

}