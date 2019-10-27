//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-10-23.
//

#include <vector>

int maxProfit(vector<int>& prices)
{
    int max_val = 0;
    int n = prices.size();
    for (int i = 1; i < n; ++i)
        max_val += prices[i] > prices[i-1] ? prices[i] - prices[i-1] : 0;
    return max_val;
}