#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int n = nums.size();

        if (!n) return 0;
        if (n == 2) return 1;
        int fast = 0;
        int slow = 0;

        for (int i = 0; i < n; ++i) {

            if (i == nums[i]) 
                continue;
            fast = nums[nums[i]];
            slow = nums[i];

            while (slow != fast) {
                fast = nums[nums[fast]];
                slow = nums[slow];
            }

            fast = 0;
            while (fast != slow) {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }

        return 0;

    }
};
// @lc code=end

