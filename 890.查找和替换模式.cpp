#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=890 lang=cpp
 *
 * [890] 查找和替换模式
 */

// @lc code=start
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(int i=0;i<words.size();i++){
           if(check(words[i],pattern)) res.push_back(words[i]); 
        }
        return res;
    }
    bool check(string word,string pattern)
    {
     if(word.length()!=pattern.length()) return false;
     for(int i=0;i<pattern.length();i++)
     {
         if(word.find(word[i])!=pattern.find(pattern[i])) return false;
     }
     return true;
    }
};
// @lc code=end

