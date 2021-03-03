#include <vector>
#include <string>
#include <deque>
#include <set>

using namespace std;

/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string>  dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        deque<string> deq;
        set<string> vis;
        deq.push_back("0000");
        int step = 0;
        while (!deq.empty()) {
            int n = deq.size();

            while (n--) {
                string tmp = deq.front();
                deq.pop_front();
                if (tmp == target)
                    return step;
                for (int i = 0; i < 4; ++i) {
                    string res1 = Up(tmp, i);
                    if (!dead.count(res1) && !vis.count(res1))  {
                        deq.push_back(res1);
                        vis.insert(res1);
                    }
                    string res2 = Down(tmp, i);
                    if (!dead.count(res2) && !vis.count(res2)) {
                        deq.push_back(res2);
                        vis.insert(res2);
                    } 
                } 
            }
            step++;
        }

        return -1;
    }

    string Up(string s, int i) {
        string str = s;
        if (s[i] == '9')
            str[i] = '0';
        else 
            str[i] += 1;
        return str;
    }

    string Down(string s, int i) {
        string str = s;
        if (s[i] == '0') 
            str[i] = '9';
        else 
            str[i] -= 1;
        return str;
    }
};
// @lc code=end

