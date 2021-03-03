#include <vector>
#include <cstring>

using namespace std;


/*
 * @lc app=leetcode.cn id=992 lang=cpp
 *
 * [992] K 个不同整数的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {

        auto f = [&A](int k) {
            int res = 0; 
            int n = A.size();
            int mp[20005];
            int cnt = 0;
            int j = 0;
            memset(mp, 0, sizeof(mp));
            for (int i = 0; i < n; ++i) {
                if (mp[A[i]]++ == 0) {
                    cnt++;
                }

                if (cnt > k) {
                    while (cnt != k) {
                        if (--mp[A[j++]] == 0) {
                            --cnt;
                        }
                    }
                }

                res += (i - j + 1);
            }

            return res;
        };

        return f(K) - f(K-1);
    }
};
// @lc code=end

