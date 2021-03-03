#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        int mp[128];
        memset(mp, 0, sizeof(mp));

        int j = 0; 
        int tn = t.length();
        int n = s.length();
        int cnt = 0;
        string res = "";

        for (auto &c : t) mp[c]++;

        for (int i = 0; i < n; ++i)
        {
            --mp[s[i]];
            if (mp[s[i]] >= 0) cnt++;
            while (j < i && mp[s[j]] < 0) ++mp[s[j++]];
            if (cnt == tn)
            {
                if (res == "" || res.length() > i - j + 1) 
                {
                    res = s.substr(j, i - j + 1);
                }
            }
        }
        return res;
    
   }
};
// @lc code=end

