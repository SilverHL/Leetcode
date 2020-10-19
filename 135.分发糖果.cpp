#include <vector>
/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

using namespace std;

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (!n) return 0;
        if (n == 1) return 1;
        vector<int> vec(n, 1);

        for (int i = 1; i <= n-1; ++i) {
            if (ratings[i-1] < ratings[i]) 
                vec[i] = vec[i-1] + 1;
        }

        for (int i = n-2; i >= 0; --i) {
            if (ratings[i+1] < ratings[i] && vec[i] <= vec[i+1]) {
                vec[i] = max(vec[i], vec[i+1]) + 1;
            }
        }
        int sum = 0;
        for (auto i : vec) {
            sum += i;
        }


        return sum;

    }
};
// @lc code=end

