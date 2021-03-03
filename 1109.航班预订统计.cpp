#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> v(n+1, 0);
        vector<int> res;
        for (auto b :bookings) {
             v[b[0]-1] += b[2];
             v[b[1]] -= b[2];
        }

        for (int i = 1; i < n; ++i) {
            v[i] += v[i-1];
        }

        return vector<int>(v.begin(), v.begin()+n);
    }
};
// @lc code=end

