#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i+1 == nums[i]) continue;
            int x = nums[i];
            while (x < n && i+1 != nums[i]) {
                swap(i, nums[i]);
            }
        }
        
    }

};

// @lc code=end

