#include <string>
#include <vector>
#include <string.h>
#include <stack>


using namespace std;

/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参议院
 */

// @lc code=start

class Solution {
public:

    int p[2]; 
string predictPartyVictory(string senate) { 
    int n = senate.length();
    vector<int> vis(n, 0);
    stack<int> stk;

    for (auto &i : senate) {
        ++p[i == 'D'];
    }

    int k = 0;

    while (p[0] && p[1]) {
        if (vis[k]) {
            k = (k + 1) % n;
            continue;
        }
        char c = senate[k];
        if (stk.empty() || stk.top() == c) {
            stk.push(c);
        } else if (stk.top() != c) {
            vis[k] = 1;
            --p[c == 'D'];
            stk.pop();
        }
        k = (k + 1) % n;
    }

    return p[0] ? "Radiant" : "Dire";
}
};
// @lc code=end

