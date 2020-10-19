#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> vec;

        if (nums.empty()) return 0;

        vec.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) 
            if (vec.back() != nums[i]) 
                vec.push_back(nums[i]);

        int n = vec.size();

        if (n <= 2) {
            return n;
        }

        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; ++i) {
            if ((vec[i-1] - vec[i-2]) * (vec[i] - vec[i-1]) < 0) 
                dp[i] = dp[i-1] + 1;
            else 
                dp[i] = dp[i-1];
        }

        return dp[n-1];

    }

};
// @lc code=end

