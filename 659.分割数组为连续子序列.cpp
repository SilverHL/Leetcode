#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=659 lang=cpp
 *
 * [659] 分割数组为连续子序列
 */

// @lc code=start
class Solution {
public:

bool isPossible(vector<int>& nums) {
    unordered_map<int, int> mp;

    for (int i : nums)
        ++mp[i];

    for (int i : nums) {
        int cnt = 0;
        if (!mp[i+cnt]) continue;
        while (mp[i+cnt] > 0) {
            --mp[i+cnt];
            cnt++;
            if (mp[i+cnt-1] >= mp[i+cnt]) 
                break;
        } 

        if (cnt < 3)
            return false;
    }

    return true;
}

};
// @lc code=end

