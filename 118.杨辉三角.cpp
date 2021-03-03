#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) 
            return res;
        res.push_back({1});
        if (numRows == 1) 
            return res;
        res.push_back({1,1});
        if (numRows == 2) 
            return res;

        for (int i = 2; i < numRows; ++i) {
            vector<int> tmp(i+1);
            tmp[0] = tmp[i] = 1;
            for (int j = 1; j < i; ++j) {
                tmp[j] = res[i-1][j] + res[i-1][j-1];
            }
            res.push_back(tmp);
        }

        return res;
    }
};
// @lc code=end

