#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

// @lc code=start


class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });

        priority_queue<int, vector<int>, std::less<int>> que;
        int res = 0;
        int end_time = 0;

        for (auto vec : courses) {
            end_time += vec[0]; 
            que.push(vec[0]);
            if (end_time > vec[1]) {
                end_time -= que.top();
                que.pop();
            }
        }

        return que.size();
    }
};
// @lc code=end

