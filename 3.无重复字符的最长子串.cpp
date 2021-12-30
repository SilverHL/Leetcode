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
        if (s.length() == 0) {
            return 0;
        }
        int mp[128];
        int total = s.length();
        memset(mp, 0, sizeof(mp));
        
        int i = 0, j = 0;
        int res = 0;
        for ( ; i < total; ++i) {
            mp[s[i]]++;
            if (mp[s[i]] > 1) {
                while (j < i && s[j] != s[i]) {
                    mp[s[j++]]--; 
                }
                mp[s[j++]]--;
            } 
            res = max(res, i -j + 1); 
        }
        return res;
    }
};
// @lc code=end

