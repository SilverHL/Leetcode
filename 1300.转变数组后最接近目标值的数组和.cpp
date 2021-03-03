#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=1300 lang=cpp
 *
 * [1300] 转变数组后最接近目标值的数组和
 */

// @lc code=start
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        if (arr.empty()) return 0;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int x = (target - sum) / (n - i);
            if (x < arr[i]) {
                double t = ((double)(target - sum)) / (n - i);
                if (t - x > 0.5) {
                    return x + 1;
                } else {
                    return x;
                }
            }
            sum += arr[i];
        }

        return arr[n-1];

    }
};

// @lc code=end

