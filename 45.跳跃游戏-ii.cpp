#include <vector>
#include <iostream>
#include <algorithm>

/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

using namespace std;

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int end = 0;
        int maxPos = 0;

        if (!n || n == 1) return 0;

        for (int i = 0; i < n-1; ++i) {
            maxPos = max(maxPos, nums[i] + i);
            if (i == end) {
                end = maxPos;
                cnt++;
            }
        }

        return cnt;
    
    }
};
// @lc code=end

int jump(vector<int>& nums)
{
    int n = nums.size();
    int end = 0;
    int cnt = 0;
    int pos = 0;

    if (!n || n == 1) return 0;
    while (pos < n-1) {
        if (pos + nums[pos] > n-1) {
            cnt++;
            break;
        } else {
            int step = *max_element(nums.begin()+pos, nums.begin()+pos+nums[pos]+1);
            pos += step;
            cnt++;
        }
    }

    return cnt;
    

}
