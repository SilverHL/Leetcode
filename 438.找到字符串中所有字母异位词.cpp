#include <vector>
#include <string>
#include <cstring>

using namespace std;
/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        int mp[128];
        memset(mp, 0, sizeof(mp));

        for (auto i : p) 
            mp[i]++;
        
        int cnt = 0;

        int j = 0;
        int n = s.length();
        int pn = p.length();
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            mp[s[i]]--;
            if (mp[s[i]] >= 0) {
                cnt++;
            }

            if (i > pn - 1) {
                mp[s[j]]++;
                if (mp[s[j]] > 0) 
                    cnt--;
                j++;
            }

            if (cnt == pn) {
                res.push_back(j);
            }


        }

        return res;
    }
};
// @lc code=end

