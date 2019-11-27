//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019/11/26.
//

#include <vector>

int maxProfit(vector<int>& prices)
{
    int res = 0;
    int n = prices.size();
    int max_val = 0;
    int min_val = INT_MAX;

    for (int i = 0; i < n; ++i) {
        if (min_val > prices[i])
            min_val = prices[i];

        if (max_val < prices[i] - min_val)
            max_val = prices[i] - min_val;
    }

    return max_val;
}

