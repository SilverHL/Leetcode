#include <string>
#include <vector>

using std::vector;
using std::string;
/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> vec;
        int n = num.size();
        if (n == k) return "0";

        for (auto i : num) {
            int tmp = i - '0';
            while (!vec.empty() && k > 0 && vec.back() > tmp) {
                vec.pop_back();
                k--;
            }

            if (!(vec.empty() && tmp == 0)) 
                vec.push_back(tmp);
        }

        while (k-- && !vec.empty()) {
            vec.pop_back();
        }
        string s = "";
        if (vec.empty()) 
            return "0";
        for (auto i : vec) {
            s += (i + '0');
        }

        return s;
    }
};
// @lc code=end

