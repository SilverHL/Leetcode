#include <string>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

string predictPartyVictory(string senate) { 
    int p[2]; 
    int n = senate.length();
    memset(p, 0, sizeof(p)); 
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
        int tmp = senate[k] == 'D';
        if (stk.empty() || stk.top() == tmp) {
            stk.push(tmp);
        } else if (stk.top() != tmp) {
            vis[k] = 1;
            --p[tmp];
            stk.pop();
        }
        k = (k + 1) % n;
    }

    return p[0] ? "Radiant" : "Dire";
}
