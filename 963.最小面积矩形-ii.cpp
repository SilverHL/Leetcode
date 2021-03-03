#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=963 lang=cpp
 *
 * [963] 最小面积矩形 II
 */

// @lc code=start

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> mp;
        for (auto v : points) {
            if (mp.count(v[0]) == 0) 
                mp.insert({v[0], {}});
            mp[v[0]].insert(v[1]);
        }

        int n = points.size();
        int min_area = 0;

        for (int i = 0; i < n-2; ++i) {
            for (int j = i+1; j < n-1; ++j) {
                for (int k = j+1; k < n; ++k) {
                    
                }
            }
        }
    }
};
// @lc code=end

