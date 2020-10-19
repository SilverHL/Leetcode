#include <string>
#include <stack>

using namespace std;

/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int i;
        int n = s.length();
        int terminteIdx = 0;

        for (int i = n-1; i > 0; --i) {
            if (s[i] < s[i-1]) {
                terminteIdx = i;
                s[i-1]--;
            }
        }

        if (terminteIdx) {
            while (terminteIdx < n) { 
                s[terminteIdx++] = '9';
            }
        }

        return atoi(s.c_str());
    }
};
// @lc code=end

