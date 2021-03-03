#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=1053 lang=cpp
 *
 * [1053] 交换一次的先前排列
 */

// @lc code=start
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        for (int i = n-1; i > 0; --i) {
            if (A[i] < A[i-1]) {
                for (int j = n-1; j >= i; --j) {
                    if (A[j] < A[i-1]) {
                        while (A[j] == A[j-1]) {
                            --j;
                        }
                        swap(A[j], A[i-1]);
                        return A;
                    }
                }
            }
        }
        return A;
    }
};
// @lc code=end

