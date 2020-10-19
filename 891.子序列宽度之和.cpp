#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=891 lang=cpp
 *
 * [891] 子序列宽度之和
 */

// @lc code=start
class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());
        const long kMod = 1e9+7;

        int n = A.size();
        long long p = 1;
        long long res = 0;

        for (int i = 0; i < n; ++i) {
            res = ((res + (A[i] - A[n-i-1]) * p) % kMod);
            p = (p << 1) % kMod;
        }

        return (res + kMod) % kMod;
    }
};
// @lc code=end

