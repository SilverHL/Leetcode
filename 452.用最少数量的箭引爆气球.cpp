#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](vector<int> v1, vector<int> v2) {
            return v1[1] < v2[1];
        });

        int sht = points[0][1];
        int cnt = 1;

        for (int i = 1; i < points.size(); i++) {
            if (sht < points[i][0]) {
                cnt++;
                sht = points[i][1];
            }
        }

        return cnt;
    }
};
// @lc code=end

