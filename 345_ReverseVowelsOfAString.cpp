//
// Created by neojxwang(王靖煊) on 2019-07-14.
//

// LeetCode 345 Reverse Vowels Of A String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        int beg = 0;
        int end = s.length();
        int mp[130];

        memset(mp, 0, sizeof(mp));
        mp['a'] = 1;
        mp['e'] = 1;
        mp['i'] = 1;
        mp['o'] = 1;
        mp['u'] = 1;

        while (beg < end) {
            if (mp[s[beg]] != 1)
                beg++;
            else if (mp[s[end]] != 1)
                end--;

            if (mp[s[beg]] == 1 && mp[s[end]] == 1)
            {
                swap(s[beg], s[end]);
                beg++;
                end--;
            }
        }

        return s;
    }
};
