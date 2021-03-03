#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>

using namespace std;

/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty())
            return true;    
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int n = nums.size();
        int target = sum / 2;
        /*
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, 0));

        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }
        for (int i = 1; i < n; ++i) 
            for (int j = nums[i]; j <= target; ++j) {
                if (nums[i] == j) 
                    dp[i][j] = true;
                else {
                    dp[i][j] = dp[i-1][j-nums[i]] || dp[i-1][j];
                }
            }
            */            
        vector<int> dp(target+1, 0);

        dp[0] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }

        return dp[target];
    }


};
// @lc code=end

