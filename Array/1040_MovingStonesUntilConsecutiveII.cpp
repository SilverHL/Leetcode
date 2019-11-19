//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-11-18.
//

#include <vector>

using std::vector;
vector<int> numMovesStonesII(vector<int>& stones)
{
    const int n = static_cast<int>(stones.size());
    sort(begin(stones), end(stones));

    int max_steps = std::max(stones[n-2] - stones[0] + 2 - n, stones[n-1] - stones[1] + 2 -n);

    int min_steps = INT_MAX;
    int i = 0;
    int j = 0;
    for (i = 0; i < n; ++i) {
        while (j + 1 < n && stones[j+1] - stones[i] + 1 <= n)
            j++;
        int cost = n - (j - i + 1);
        if (j - i + 1 == n-1 && stones[j] - stones[i] + 1 == n-1)
            cost = 2;
        min_steps = std::min(min_steps, cost);
    }

    return {min_steps, max_steps};
}
