#include <string>
#include <iostream>
#include <vector>

/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

using namespace std;

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        if (!n || n == 1) return s;

        vector<bool> visited(128, false);
        vector<int> mp(128, 0);
        string result = "0";

        for (auto c : s) mp[c]++;

        for (auto c : s) {
            mp[c]--;
            if (visited[c]) continue;
            while (c < result.back() && mp[result.back()]) {
                visited[result.back()] = false;
                result.pop_back();
            }
            result.push_back(c);
            visited[c] = true;
        }

        return  result.substr(1);

    }
};
// @lc code=end

