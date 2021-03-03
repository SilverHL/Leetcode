#include <vector>
#include <cstring>

using namespace std;
/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int mp[40005];
        memset(mp, 0, sizeof(mp));
        int n = tree.size();
        int k = 0;
        int total = 0;
        int j = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int tmp = tree[i];
            ++total;
            if (mp[tmp]++ == 0) {
                k++;
            } 

            if (k > 2) {
                while (k != 2) {
                    --total;
                    if (--mp[j++] == 0) 
                        ++k;
                }
            }
            res = max(res, i - j + 1);
        }

        return res;
    }
};
// @lc code=end

