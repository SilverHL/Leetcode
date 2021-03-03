#include <algorithm>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        sort(piles.begin(), piles.end());
        int n = piles.size();

        if (n == 1) return (piles[0] + H - 1) / H;
        int left = 1;
        int right = piles[n-1];

        while (left < right) {
            int mid = left + ((right - left) >> 1);
            int cnt = 0;
            int idx = 0;
            int i = n-1;
            while (i >= 0 && piles[i] > mid) {
                cnt += (piles[i] + mid - 1) / mid;
                --i;
            }
            cnt += i+1;

            if (cnt <= H) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
// @lc code=end

