//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019/12/10.
//

#include <vector>
#include <map>

using namespace std;

int leastInterval(vector<char>& tasks, int n)
{
    vector<int> count(26, 0);
    const int sz = tasks.size();
    for (char c : tasks)
        count[c - 'A']++;

    int mx = *max_element(begin(count), end(count));
    int ans = (mx - 1) * (n + 1);

    ans += count_if(begin(count), end(count), [&](int n) { return n == mx; });
    return max(ans, sz);

}

