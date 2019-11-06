//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-11-05.
//

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

int findShortestSubArray(vector<int>& nums) {
    if (nums.empty())
        return 0;

    int n = nums.size();
    int num = 0;

    unordered_map<int, int> count;
    unordered_map<int, int> begin;
    unordered_map<int, int> end;

    for (int i = 0; i < n; i++) {
        if (count[nums[i]] == 0)
            begin[nums[i]] = i;

        count[nums[i]]++;
        end[nums[i]] = i;

        if (count[nums[i]] > num)
            num = count[nums[i]];
    }

    int res = INT_MAX;
    for (auto &item : count) {
        if (item.second == num)
            res = std::min(end[item.first] - begin[item.first] + 1, res);
    }

    return res;


}
