#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int cnt = 0;
        int res = 0;
        int k = X;
        int n = customers.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
            k--;
            if (grumpy[i] == 1) 
                cnt += customers[i];

            if (k < 0) {
                if (grumpy[j] == 1) 
                    cnt -= customers[j];
                ++j;
                ++k;
            }
            if (cnt > res)  
                res = cnt;
        }

        for (int i = 0; i < n; ++i) {
            res += grumpy[i] == 0 ? customers[i] : 0;
        }

        return res;
    }
};
// @lc code=end

