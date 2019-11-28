//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019/11/27.
//
#include <vector>

using std::vector;
using std::min;

int minCostClimbingStairs(vector<int>& cost)
{
    int n = cost.size();
    int dp[n+1];

    memset(dp, 0, sizeof(dp));
    int tmp_1 = 0;
    int tmp_2 = 0;


    for (int i = 2; i <= n; ++i) {
        int tmp_11 = tmp_1 + cost[i-1];
        int tmp_22 = tmp_2 + cost[i-2];
        int tmp = min(tmp_11, tmp_22);
        tmp_2 = tmp_1;
        tmp_1 = tmp;
    }
    return tmp_1;
}

