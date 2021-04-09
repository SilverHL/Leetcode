#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
/**
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, dp[i]);
        }

        return res;
    }
    */
   /*
    int lengthOfLIS(vector<int>& nums) 
    {
        if (nums.empty())
            return 0;
        int n = nums.size();
        int piles = 0;
        vector<int> top(n, 0);

        for (int i = 0; i < n; ++i) {
            int poker = nums[i];
            int left = 0, right = piles;

            while (left < right) {
                int mid = left + ((right - left) >> 1);
                if (top[mid] < poker) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            if (left == piles) piles++;
            top[left] = poker;
        }

        return piles;
    }
    */

    int lengthOfLIS(vector<int>& nums) 
    {
        if (nums.empty()) 
            return 0;

        int n = nums.size();
        vector<int> cards(n, 0);
        int piles = 0;
        for (int i = 0; i < n; ++i) {
            int pk = nums[i];
            int left = 0, right = piles;
            while (left < right) 
            {
                int mid = left + ((right - left) >> 1);
                if (cards[mid] < pk) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            cards[left] = pk;
            if (left == piles) 
                piles++;
        }
        return piles;

    }
    
};
// @lc code=end

