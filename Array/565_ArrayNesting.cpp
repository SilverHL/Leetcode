//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-10-21.
//

#include <vector>

using std::vector;

int arrayNesting(vector<int>& nums)
{
    if (nums.empty())
        return 0;
    int n = nums.size();
    vector<bool> vis(n, true);
    int res = 0;

    for (int i = 0; i < n; ++i)
    {
        if (vis[i]) {
            int len = 0;
            int index = i;

            while (vis[index]) {
                len++;
                vis[index] = false;
                index = nums[index];
            }
            res = max(len, res);
        }
    }

    return res;
}
