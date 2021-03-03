#include <vector>
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
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > n || nums[i] == nums[nums[i] - 1])
                    break;
                int idx = nums[i] - 1;
                nums[i] = nums[idx];
                nums[idx] = idx + 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != (i+1)) 
                return i+1;
        }

        return n+1;
    }

};

// @lc code=end

