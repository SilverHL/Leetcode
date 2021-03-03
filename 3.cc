#include <string>
#include <cstring>

using namespace std;

int lengthOfLongestSubstring(string s) 
{
    if (s.empty()) return 0;
    int n = s.length();

    int mp[128];
    memset(mp, 0, sizeof(mp));
    int res = 0;
    int j = 0;

    for (int i = 0; i < n; ++i) {
        mp[s[i]]++;

        while (j < i && mp[s[i]] > 1) {
            --mp[s[j++]];
        }
        if (res < i - j + 1) 
            res = i - j + 1;
    }
    return res;
}