//
// Created by neojxwang(王靖煊) on 2019-07-13.
//

// LeetCode 424

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
int characterReplacement(string s, int k)
{
    int beg = 0, end = 0;
    int len = s.length();
    int same = 0;
    int mp[130];

    memset(mp, 0, sizeof(mp));

    while (end < len) {
        same = max(same, ++mp[s[end++]]);
        if (end - beg - same > k)
            --mp[s[beg++]];
    }

    return end - beg;
}

};