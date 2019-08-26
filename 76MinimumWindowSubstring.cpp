#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

string minWindow(string s, string t)
{
    if (s.length() < t.length())
        return "";
    int mp[200];
    memset(mp, 0, sizeof(mp));
    for (auto i : t)
        mp[i]++;

    int l = 0, head = 0;
    int r = 0;
    int res = INT_MAX;
    int n = s.length();
    int len = t.length();

    while (r < n)
    {
        if (mp[s[r++]]-- > 0)
            len--;

        while (len == 0)
        {
            if (res > (r - l))
                res = r - (head = l);
            if (mp[s[l++]]++ == 0)
                len++;
        }
    }
    return res == INT_MAX ? "" : s.substr(head, res);

}
