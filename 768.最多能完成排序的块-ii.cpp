#include <vector>
#include <stack>

using namespace std;

/*
 * @lc app=leetcode.cn id=768 lang=cpp
 *
 * [768] 最多能完成排序的块 II
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if (arr.empty())
            return 0;

        stack<int> stk;
        int n = arr.size();

        stk.push(arr[0]);
        for (int i = 1; i < n; ++i) {
            if (stk.top() <= arr[i]) 
                stk.push(arr[i]);
            else {
                int cur_max = stk.top(); stk.pop();
                while (!stk.empty() && stk.top() > arr[i]) {
                    stk.pop();
                }
                stk.push(cur_max);
            }
        }

        return stk.size();
    }
};
// @lc code=end

