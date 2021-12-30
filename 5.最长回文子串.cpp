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
        string res = "";
        int len = s.length();
        for (int i = 0; i < len; i++) {
            string s1 = find_target(s, i, i);
            string s2 = find_target(s, i, i+1);
            
            if (s1.length() > res.length()) {
                res = s1;
            } 
            if (s2.length() > res.length()) {
                res = s2;
            }
        }
        return res;
    }

    string find_target(string s, int i, int j) {
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            i--,j++;
        }
        return s.substr(i+1, j - i - 1);
    }

};
// @lc code=end

