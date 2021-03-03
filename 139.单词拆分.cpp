#include <vector>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

/* For the word "leetcode", it can be devided into these:
 *    wordBreak("")     && inDict("leetcode")
 * || wordBreak("l")    && inDict("eetcode")
 * || wordBreak("le")   && inDict("etcode")
 * || wordBreak("lee")  && inDict("tcode")
 * || wordBreak("leet") && inDict("code") 
 *  ......
 * || wordBreak("leetcode") && inDict("") 
 * 
 * thus, we remember the answer already calculated , 
 * next time we need to make sure if the word is inDict, we don't have to 
 * calculate it again.
 * */


// @lc code=start
class Solution {
    map<string, bool> _mp;
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return wordBreak(s, dict);
    }

    bool wordBreak(string s, unordered_set<string> &dict)
    {
        if (_mp.count(s))
            return _mp[s];

        if (dict.count(s))
            return _mp[s] = true;

        int n = s.length();
        for (int i = 1; i < n; ++i) {
            string left = s.substr(0, i);
            string right = s.substr(i);

            if (dict.count(left) && wordBreak(right, dict)) 
                return true;
        }

        return _mp[s] = false;
    }
};
// @lc code=end

