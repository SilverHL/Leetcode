#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=957 lang=cpp
 *
 * [957] N 天后的牢房
 */

// @lc code=start
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {

        int k = N % 14;
        if (!k) k = 14;
        vector<int> tmp(8, 0);
        while (k--) {
            vector<int> tmp(cells);
            for (int j = 1; j < 7; ++j) {
                cells[j] = tmp[j-1] ^ !tmp[j+1];
            }
            cells[0] = cells[7] = 0;
        }

        return cells;
    }
};
// @lc code=end

