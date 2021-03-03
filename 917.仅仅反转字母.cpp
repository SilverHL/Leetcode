#include <iostream>
#include <string>
#include <cctype>

using namespace std;
/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string S) {
        if (S.empty())
            return "";
        
        int n = S.length();
        int i = 0;
        int j = n-1;

        string res;

        while (j >= 0 && i < n) {
            if (!isalpha(S[j])) {
                --j;
                continue;
            } 

            if (isalpha(S[i])) {
                res += S[j];
                --j;
                ++i;
            } else {
                res += S[i];
                i++;
            }
        }

        while (i < n) 
            res += S[i++];
        return res;
    }
};
// @lc code=end

