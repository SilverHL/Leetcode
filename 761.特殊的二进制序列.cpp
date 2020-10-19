#include <string>
#include <vector>
#include <algorithm>

using namespace std;


/*
 * @lc app=leetcode.cn id=761 lang=cpp
 *
 * [761] 特殊的二进制序列
 */

// @lc code=start
class Solution {
public:
    string makeLargestSpecial(string S) {
        string res = "";
        if (S.empty()) return res;
        vector<string> v;
        int cnt = 0, i = 0;
        int n = S.length();

        for (int j = 0; j < n; ++j) {
            cnt += (S[j] == '1' ? 1 : -1);
            if (cnt == 0) {
                v.push_back('1' + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }

        sort(v.begin(), v.end(), greater<string>());
        for (auto s : v) res += s;
        return res;
    }
};
// @lc code=end

