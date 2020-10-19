#include <string>

using namespace std;
/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string t, string s) {
        int idx1 = 0;
        int idx2 = 0;

        if (t.empty()) return true;
        if (s.empty()) return false;

        int n1 = s.length();
        int n2 = t.length();

        int mp1[128];
        int mp2[128];

        memset(mp1, 0, sizeof(mp1));
        memset(mp2, 0, sizeof(mp2));

        for (auto i : s) 
            mp1[i]++;

        for (auto i : t) 
            mp2[i]++;

        for (int i = 'a'; i < 'z'; ++i)  
            if (mp1[i] < mp2[i])
                return false;
        

        while (idx2 < n2 && idx1 < n1) {
            while (idx1 < n1 && s[idx1] != t[idx2]) 
                idx1++;

            idx1++;
            idx2++; 
        }

        if (idx2 == n2) return true;
        else return false;
    }
};
// @lc code=end

