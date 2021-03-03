#include <string> 

using namespace std;

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.length();
        string res = "";
        for (int i = 0; i < n; ++i) 
        {
            string res1 = find_target(i, i, s);
            string res2 = find_target(i, i+1, s);

            if (res1.length() > res.length()) 
                res = res1;
            if (res2.length() > res.length())
                res = res2;
        }

        return res;
    }

    string find_target(int l, int r, string &s)
    {
        int n = s.length();
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--, r++; 
        } 
        return s.substr(l+1, r-1-l);
    }
};
// @lc code=end

