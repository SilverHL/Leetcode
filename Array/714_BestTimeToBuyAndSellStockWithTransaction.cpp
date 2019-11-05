//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-11-05.
//

#include <vector>

using std::vector;

int maxProfit(vector<int>& prices, int fee)
{
    if (prices.empty())
        return 0;

    int n = prices.size();
    int have = -prices[0];
    int not_have = 0;


    for (int i = 1; i < n; i++) {
        int have_tmp = not_have - prices[i];
        int not_have_tmp = have + prices[i] - fee;
        have = std::max(have, have_tmp);
        not_have = std::max(not_have, not_have_tmp);
    }

    return not_have;

}

