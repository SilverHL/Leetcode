#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        if (env.empty()) return 0;
        int n = env.size();
        sort(env.begin(), env.end(), [](vector<int>& a, vector<int>& b){
            if (a[0] == b[0]) 
                return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> vec(n, 0);
        for (int i = 0; i < n; ++i) {
            vec[i] = env[i][1];
        }

        int piles = 0;
        vector<int> top(n, 0);
        for (int i = 0; i < n; ++i) {
            int target = vec[i];
            int left = 0, right = piles;

            while (left < right) 
            {
                int mid = left + ((right - left) >> 1);
                if (top[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            if (left == piles) ++piles;
            top[left] = target;
        }

        return piles;
    }
};
// @lc code=end

