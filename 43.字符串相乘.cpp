#include <string>
#include <vector>
#include <iostream>

using std::string;

/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {

        int m = num1.length();
        int n = num2.length();
        std::vector<int> res(n+m, 0);

        for (int i = m-1; i >= 0; --i)
            for (int j = n-1; j >= 0; --j)
            {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int pos1 = i + j, pos2 = i + j + 1;

                res[pos2] += mul;
                if (res[pos2] >= 10) 
                {
                    res[pos1] += res[pos2] / 10;
                    res[pos2] %= 10; 
                }
            }

        int i = 0; 
        while (i < m+n && res[i] == 0) i++;
        string s;
        for (; i < m+n; ++i)
        {
            s.push_back('0' + res[i]);
        }

        return s.empty() ? "0" : s;
    }
};
// @lc code=end

