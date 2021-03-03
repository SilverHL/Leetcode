
#include <string>
#include <cstring>

using namespace std;

/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.empty()) return true;
        if (s2.empty()) return false;

        int mp[128];
        memset(mp, 0, sizeof(mp));

        for (auto i : s1) mp[i]++;
        int cnt = 0;
        int n = s2.length();
        int m = s1.length();
        int j = 0;

        for (int i = 0; i < n; ++i) {
            mp[s2[i]]--;

            if (mp[s2[i]] >= 0) {
                cnt++;
            }

            if (i >= m) {
                mp[s2[j]]++;
                if (mp[s2[j]] > 0) {
                    cnt--;
                }
                j++;
            }

            if (cnt == m) 
                return true;
        }

        return false;
    }
};
// @lc code=end

