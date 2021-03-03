#include <vector>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
    map<string, vector<string>> mem_;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return wordBreak(s, dict);
    }

    vector<string> append(const vector<string> &prefix, string tail)
    {
        vector<string> ans;
        for (string i : prefix)
            ans.push_back(i + " " + tail);
        return ans;
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict)
    {
        if (mem_.count(s))
            return mem_[s];
        
        vector<string> ans;
        if (dict.count(s))  
            ans.push_back(s);

        int n = s.length();
        for (int i = 1; i < n; ++i) {
            string right = s.substr(i);
            if (!dict.count(right)) continue;
            const string &left = s.substr(0, i);
            vector<string> left_ans = append(wordBreak(left, dict), right);
            ans.insert(ans.begin(), left_ans.begin(), left_ans.end());
        }

        mem_[s].swap(ans);
        return mem_[s];

    }
};

// @lc code=end

