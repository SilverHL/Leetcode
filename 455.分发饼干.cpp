#include <vector>
#include <algorithm>

using namespace std;
/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        if (s.empty() || g.empty()) return 0;

        int idx1 = 0;
        int idx2 = 0;
        int n1 = g.size();
        int n2 = s.size();

        int cnt = 0;

        while (idx1 < n1 && idx2 < n2) { 
            if (g[idx1] <= s[idx2]) {
                ++idx1;
                ++idx2;
                cnt++;
            } else {
                ++idx2;
            }

        }

        return cnt;
    }
};
// @lc code=end

