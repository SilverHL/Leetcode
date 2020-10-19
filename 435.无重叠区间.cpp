#include <vector>
#include <algorithm>


using std::sort;
using std::vector;
/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int sht = intervals[0][1];
        int cnt = 1;
        int n = intervals.size(); 
        for (int i = 1; i < n; ++i) {
            if (sht <= intervals[i][0]) {
                cnt++;
                sht = intervals[i][1];
            }
        }

        return n - cnt;
    }
};
// @lc code=end

