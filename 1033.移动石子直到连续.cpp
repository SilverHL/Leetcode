#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=1033 lang=cpp
 *
 * [1033] 移动石子直到连续
 */

// @lc code=start
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if (a > b)
            swap(a, b);
        if (b > c) 
            swap(b, c);
        if (a > b) 
            swap(a, b);

        int mx = c - a - 2; 
        if (b - a == 1 && c - b == 1) 
            return {0, mx};
        if (c - b <= 2 || b - a <= 2)
            return {1, mx};
        return {2, mx};
    }
};
// @lc code=end

