#include <string>
#include <cstring>

using namespace std;
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.empty()) return 0;
        int n = s.length();

        int mp[128];
        memset(mp, 0, sizeof(mp));
        int res = 0;
        int j = 0;

        for (int i = 0; i < n; ++i) {
            mp[s[i]]++;

            while (j < i && mp[s[i]] > 1) {
                --mp[s[j++]];
            }
            if (res < i - j + 1) 
                res = i - j + 1;
        }
        return res;
    }
};
// @lc code=end

